/*
 * bison.y - analyze and build AST
 * This file will process the AST to make it easeier to compile.
 * So it will delete some useless nodes in compiling and merge
 * some nodes together, such as some kind of lists and the
 * complex changing between different types of exps. In some
 * special cases, it will add some nodes or use other nodes'
 * type.
 * Besides, once the program find an error in the input file, it
 * will stop building AST and only analyze the grammar in the
 * remaining part of the file. So the compile will also been
 * canceled in this case.
 * I don't think this file need more comments. It is easy to
 * understand.
 */

%{
    #include <stdio.h>
    #include <string.h>
    #include <iostream>
    #include <vector>
    #include <cstdlib>
    #include <sstream>
    #include "bison.hpp"
    int yylex(void);
    void yyerror(const char *s);
    int nodeid = 0;
    int error = 0;
    FILE* file = NULL;
    FILE* detail = NULL;
    extern int lines;
    extern int columns;
    AST tree;
%}

%token kconst_ kint_ kvoid_ kif_ kelse_ kwhile_ kbreak_ kcontinue_ kreturn_
%token <str> Ident_ Number_ ErrIdent_ HeaderStmt_ String_
%token <str> opadd_ opmul_ oprel_ opeq_ opland_ oplor_
%token '!' ',' ';' '=' '{' '}'
%token '(' ')' '[' ']'
%token unknown_

%type <id> Ident__ Number__ HeaderStmt__ String__
%type <id> opadd__ opmul__ oprel__ opeq__

%type <id> CompUnit_ Decl_ ConstDecl_ ConstDef_ ConstInitVal_
%type <id> VarDecl_ VarDef_ InitVal_ FuncDef_ FuncFParams_
%type <id> FuncFParam_ Block_ BlockItem_ Stmt_ Exp_ Cond_ LVal_
%type <id> PrimaryExp_ UnaryExp_ UnaryOp_ FuncRParams_ FuncRParam_
%type <id> MulExp_ AddExp_ RelExp_ EqExp_ LAndExp_ LOrExp_ ConstExp_
%type <id> OtherCompUnit_ ConstDefs_ ConstExps_ ConstInitVals_
%type <id> VarDefs_ InitVals_ Exps_ BlockItems_ Address_ BoolExp_

%union {
    char* str;
    int id;
}

%start CompUnit_
%expect 1

%%

Ident__ : Ident_ {$$ = tree.add_node(NType::Ident, std::string($1)); free($1);}
Number__ : Number_ {$$ = tree.add_node(NType::Number, std::string($1)); free($1);}
HeaderStmt__ : HeaderStmt_ {
    char *begin = strchr($1, '<')+1;
    char *end = strrchr($1, '>');
    $$ = tree.add_node(NType::HeaderStmt, std::string(begin, end-begin));
    free($1);
}
String__ : String_ {$$ = tree.add_node(NType::String, std::string($1)); free($1);}
opadd__ : opadd_ {$$ = tree.add_node(NType::opadd, std::string($1)); free($1);}
opmul__ : opmul_ {$$ = tree.add_node(NType::opmul, std::string($1)); free($1);}
oprel__ : oprel_ {$$ = tree.add_node(NType::oprel, std::string($1)); free($1);}
opeq__ : opeq_ {$$ = tree.add_node(NType::opeq, std::string($1)); free($1);}

CompUnit_ :
CompUnit_ OtherCompUnit_ {$$ = $1; tree.add_edge($$, $2);}
| OtherCompUnit_ {$$ = tree.add_node(NType::Root); tree.add_edge($$, $1); tree.set_root($$);}
| CompUnit_ error {$$ = tree.error_node(); fprintf(stderr, "Wrong CompUnit_\n\n");}
| error {$$ = tree.error_node(); fprintf(stderr, "Wrong CompUnit_\n\n");}

OtherCompUnit_
: Decl_ {$$ = $1;}
| FuncDef_ {$$ = $1;}
| HeaderStmt__ {$$ = $1;}
| error Block_ {$$ = tree.error_node(); fprintf(stderr,"Wrong CompUnit_(may be FuncDef_)\n\n");}
| error ';' {$$ = tree.error_node(); fprintf(stderr,"Wrong CompUnit_(may be Decl_)\n\n");}

Decl_
: ConstDecl_ {$$ = $1;}
| VarDecl_ {$$ = $1;}

ConstDecl_
: kconst_ kint_ ConstDefs_ ';' {$$ = tree.add_node(NType::ConstDecl); tree.add_edges($$, {tree.add_node(NType::kint), $3});}
| kconst_ error ';' {$$ = tree.error_node(); fprintf(stderr, "Wrong ConstDecl_\n\n");}

ConstDefs_
: ConstDefs_ ',' ConstDef_ {$$ = $1; tree.add_edge($$, $3);}
| ConstDef_ {$$ = tree.add_node(NType::VarDefs); tree.add_edge($$, $1);}

ConstDef_
: Ident__ ConstExps_ '=' ConstInitVal_ {$$ = tree.add_node(NType::VarDef); tree.add_edges($$, {$1, $2, $4});}
| Ident__ '=' ConstInitVal_ {$$ = tree.add_node(NType::VarDef); tree.add_edges($$, {$1, $3});}

ConstExps_
: ConstExps_ '[' ConstExp_ ']' {$$ = $1; tree.add_edge($$, $3);}
| '[' ConstExp_ ']' {$$ = tree.add_node(NType::Exps); tree.add_edge($$, $2);}

ConstInitVal_
: ConstExp_ {$$ = $1;}
| '{' '}' {$$ = tree.add_node(NType::InitVals);}
| '{' ConstInitVals_ '}' {$$ = $2;}

ConstInitVals_
: ConstInitVals_ ',' ConstInitVal_ {$$ = $1; tree.add_edge($$, $3);}
| ConstInitVal_ {$$ = tree.add_node(NType::InitVals); tree.add_edge($$, $1);}

VarDecl_
: kint_ VarDefs_ ';' {$$ = tree.add_node(NType::VarDecl); tree.add_edges($$, {tree.add_node(NType::kint), $2});}
| kint_ error ';' {$$ = tree.error_node(); fprintf(stderr,"Wrong Vardef in VarDecline\n\n");}

VarDefs_
: VarDefs_ ',' VarDef_ {$$ = $1; tree.add_edge($$, $3);}
| VarDef_ {$$ = tree.add_node(NType::VarDefs); tree.add_edge($$, $1);}

VarDef_
: Ident__ {$$ = tree.add_node(NType::VarDef); tree.add_edge($$, $1);}
| Ident__ ConstExps_ {$$ = tree.add_node(NType::VarDef); tree.add_edges($$, {$1, $2});}
| Ident__ '=' InitVal_ {$$ = tree.add_node(NType::VarDef); tree.add_edges($$, {$1, $3});}
| Ident__ ConstExps_ '=' InitVal_ {$$ = tree.add_node(NType::VarDef); tree.add_edges($$, {$1, $2, $4});}

InitVal_
: Exp_ {$$ = $1;}
| '{' '}' {$$ = tree.add_node(NType::InitVals);}
| '{' InitVals_ '}' {$$ = $2;}

InitVals_
: InitVals_ ',' InitVal_ {$$ = $1; tree.add_edge($$, $3);}
| InitVal_ {$$ = tree.add_node(NType::InitVals); tree.add_edge($$, $1);}

FuncDef_
: kvoid_ Ident__ '(' ')' Block_ {$$ = tree.add_node(NType::FuncDef); tree.add_edges($$, {tree.add_node(NType::kvoid), $2, $5});}
| kvoid_ Ident__ '(' FuncFParams_ ')' Block_ {$$ = tree.add_node(NType::FuncDef); tree.add_edges($$, {tree.add_node(NType::kvoid), $2, $4, $6});}
| kint_ Ident__ '(' ')' Block_ {$$ = tree.add_node(NType::FuncDef); tree.add_edges($$, {tree.add_node(NType::kint), $2, $5});}
| kint_ Ident__ '(' FuncFParams_ ')' Block_ {$$ = tree.add_node(NType::FuncDef); tree.add_edges($$, {tree.add_node(NType::kint), $2, $4, $6});}
| kint_ error Block_ {$$ = tree.error_node(); fprintf(stderr, "Wrong FuncDef_\n\n");}
| kvoid_ error Block_ {$$ = tree.error_node(); fprintf(stderr, "Wrong FuncDef_\n\n");}

FuncFParams_
: FuncFParams_ ',' FuncFParam_ {$$ = $1; tree.add_edge($$, $3);}
| FuncFParam_ {$$ = tree.add_node(NType::FuncFParams); tree.add_edge($$, $1);}

FuncFParam_
: kint_ Ident__ {$$ = tree.add_node(NType::FuncFParam); tree.add_edges($$, {tree.add_node(NType::kint), $2});}
| kint_ Ident__ '[' ']' {$$ = tree.add_node(NType::FuncFParam); tree.add_edges($$, {tree.add_node(NType::kint), $2, tree.add_node(NType::Exps)});}
| kint_ Ident__ '[' ']' Exps_ {$$ = tree.add_node(NType::FuncFParam); tree.add_edges($$, {tree.add_node(NType::kint), $2, $5});}

Exps_
: Exps_ '[' Exp_ ']' {$$ = $1; tree.add_edge($$, $3);}
| '[' Exp_ ']' {$$ = tree.add_node(NType::Exps); tree.add_edge($$, $2);}

Block_
: '{' '}' {$$ = tree.add_node(NType::BlockItems);}
| '{' BlockItems_ '}' {$$ = $2;}

BlockItems_
: BlockItems_ BlockItem_ {$$ = $1; tree.add_edge($$, $2);}
| BlockItem_ {$$ = tree.add_node(NType::BlockItems); tree.add_edge($$, $1);}

BlockItem_
: Decl_ {$$ = $1;}
| Stmt_ {$$ = $1;}

Stmt_
: LVal_ '=' Exp_ ';' {$$ = tree.add_node(NType::Stmt); tree.add_edges($$, {$1, $3});}
| ';' {$$ = tree.add_node(NType::Stmt);}
| Exp_ ';' {$$ = tree.add_node(NType::Stmt); tree.add_edge($$, $1);}
| Block_ {$$ = tree.add_node(NType::Stmt); tree.add_edge($$, $1);}
| kif_ '(' Cond_ ')' Stmt_ {$$ = tree.add_node(NType::Stmt); tree.add_edges($$, {tree.add_node(NType::kif), $3, $5});}
| kif_ '(' Cond_ ')' Stmt_ kelse_ Stmt_ {$$ = tree.add_node(NType::Stmt); tree.add_edges($$, {tree.add_node(NType::kif), $3, $5, $7});}
| kwhile_ '(' Cond_ ')' Stmt_ {$$ = tree.add_node(NType::Stmt); tree.add_edges($$, {tree.add_node(NType::kwhile), $5, $3});}
| kbreak_ ';' {$$ = tree.add_node(NType::Stmt); tree.add_edge($$, tree.add_node(NType::kbreak));}
| kcontinue_ ';' {$$ = tree.add_node(NType::Stmt); tree.add_edge($$, tree.add_node(NType::kcontinue));}
| kreturn_ ';' {$$ = tree.add_node(NType::Stmt); tree.add_edge($$, tree.add_node(NType::kreturn));}
| kreturn_ Exp_ ';' {$$ = tree.add_node(NType::Stmt); tree.add_edges($$, {tree.add_node(NType::kreturn), $2});}
| error ';' {$$ = tree.error_node(); fprintf(stderr, "Wrong Stmt_\n\n");}

Exp_
: LOrExp_ {$$ = tree.add_node(NType::Exp); tree.add_edges($$, {$1});}

Cond_
: LOrExp_ {$$ = tree.add_node(NType::Cond); tree.add_edges($$, {$1});}

LVal_
: Ident__ {$$ = tree.add_node(NType::Lval); tree.add_edges($$, {$1});}
| Ident__ Exps_ {$$ = tree.add_node(NType::Lval); tree.add_edges($$, {$1, $2});}

PrimaryExp_
: '(' LOrExp_ ')' {$$ = $2;}
| LVal_ {$$ = $1;}
| Number__ {$$ = $1;}

Address_
: '&' LVal_ {$$ = tree.add_node(NType::Address); tree.add_edge($$, $2);}

UnaryExp_
: PrimaryExp_ {$$ = $1;}
| Ident__ '(' FuncRParams_ ')' {$$ = tree.add_node(NType::UnaryExp); tree.add_edges($$, {$1, $3});}
| Ident__ '(' ')' {$$ = tree.add_node(NType::UnaryExp); tree.add_edges($$, {$1, tree.add_node(NType::FuncRParams)});}
| UnaryOp_ UnaryExp_ {$$ = tree.add_node(NType::UnaryExp); tree.add_edges($$, {$1, $2});}

UnaryOp_
: opadd__ {$$ = $1;}

FuncRParams_
: FuncRParams_ ',' FuncRParam_ {$$ = $1; tree.add_edge($$, $3);}
| FuncRParam_ {$$ = tree.add_node(NType::FuncRParams); tree.add_edge($$, $1);}

FuncRParam_
: Exp_ {$$ = $1;}
| String__ {$$ = $1;}
| Address_ {$$ = $1;}

MulExp_
: UnaryExp_ {$$ = $1;}
| MulExp_ opmul__ UnaryExp_ {$$ = tree.add_node(NType::MulExp); tree.add_edges($$, {$1, $2, $3});}

AddExp_
: MulExp_ {$$ = $1;}
| AddExp_ opadd__ MulExp_ {$$ = tree.add_node(NType::AddExp); tree.add_edges($$, {$1, $2, $3});}

BoolExp_
: AddExp_ {$$ = $1;}
| '!' UnaryExp_ {$$ = tree.add_node(NType::BoolExp); tree.add_edges($$, {tree.add_node(NType::oplnot), $2});}

RelExp_
: BoolExp_ {$$ = $1;}
| RelExp_ oprel__ BoolExp_ {$$ = tree.add_node(NType::RelExp); tree.add_edges($$, {$1, $2, $3});}

EqExp_
: RelExp_ {$$ = $1;}
| EqExp_ opeq__ RelExp_ {$$ = tree.add_node(NType::EqExp); tree.add_edges($$, {$1, $2, $3});}

LAndExp_
: EqExp_ {$$ = $1;}
| LAndExp_ opland_ EqExp_ {$$ = tree.add_node(NType::LAndExp); tree.add_edges($$, {$1, $3});}

LOrExp_
: LAndExp_ {$$ = $1;}
| LOrExp_ oplor_ LAndExp_ {$$ = tree.add_node(NType::LOrExp); tree.add_edges($$, {$1, $3});}

ConstExp_ : AddExp_ {$$ = tree.add_node(NType::Exp); tree.add_edges($$, {$1});}

%%

void yyerror(const char *s)
{
    fprintf(stderr, "line %d, columns %d: ", lines, columns);
    error++;
}
int main(int argc, char **argv)
{   
    if(argc==2){
        if(strcmp(argv[1],"-v")==0){
            fprintf(stderr, "SysY Compiler v3.5(Win64), independently developed by WZH\n");
            fprintf(stderr, "No code from other sources is used (or referenced) in this compiler\n");
            return 0;
        }
    }
    if(argc!=3 && argc!=4){
        fprintf(stderr, "Usage: %s <SysyFile> <AssFile> <ExeFile>\n", argv[0]);
        fprintf(stderr, "If you don't want to compile the assembly code to executable file, just ignore the <ExeFile>\n");
        fprintf(stderr, "For more information, please use option -v\n");
        return 1;
    }
    FILE* inputfile = freopen(argv[1], "r", stdin);
    if(inputfile==NULL){
        fprintf(stderr, "Open File Error\n");
        return 1;
    }
    yyparse();
    fclose(inputfile);
    if(error > 0){
        fprintf(stderr, "Find %d errors\n", error);
        return 1;
    }
    fprintf(stderr, "Parse Success\n");
    FILE* outputfile = freopen(argv[2], "w", stdout);
    if(outputfile==NULL){
        fprintf(stderr, "Open File Error\n");
        return 1;
    }
    tree.global_compile();
    fprintf(stderr, "Compile Success\n");
    fflush(stderr);
    tree.print_ass();
    fprintf(stderr, "Print Success\n");
    fclose(outputfile);
    if(argv[3]!=NULL){
        #if defined(_WIN64)
            std::stringstream ss;
            ss<< "g++ " << argv[2] << " -o " << argv[3];
            system(ss.str().c_str());
        #else
            fprintf(stderr, "This compiler generates assembly code on WIN64.\n");
            fprintf(stderr, "But we found you are not using a WIN64 system.\n");
            fprintf(stderr, "Please compile the assembly code to executable file by yourself.\n");
        #endif
    }
    return 0;
}