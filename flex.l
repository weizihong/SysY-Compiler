%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>

#include "bison.tab.h"

int lines = 1;
int columns = 1;
extern int error;
%}

IdentBegin [a-zA-Z_]
IdentChar [0-9a-zA-Z_]
DexBegin [1-9]
DexChar [0-9]
OctChar [0-7]
HexPrefix (0x|0X)
HexChar [0-9a-fA-F]

%%

const {columns += yyleng; return kconst_;}
int {columns += yyleng; return kint_;}
void {columns += yyleng; return kvoid_;}
if {columns += yyleng; return kif_;}
else {columns += yyleng; return kelse_;}
while {columns += yyleng; return kwhile_;}
break {columns += yyleng; return kbreak_;}
continue {columns += yyleng; return kcontinue_;}
return {columns += yyleng; return kreturn_;}

{IdentBegin}{IdentChar}* {yylval.str = strdup(yytext); columns += yyleng; return Ident_;}

{DexBegin}{DexChar}* {yylval.str = strdup(yytext); columns += yyleng; return Number_;}
0{OctChar}* {yylval.str = strdup(yytext); columns += yyleng; return Number_;}
{HexPrefix}{HexChar}+ {yylval.str = strdup(yytext); columns += yyleng; return Number_;}

{IdentChar}+ {
    fprintf(stderr, "Invalid identifier at line %d, column %d\n", lines, columns);
    columns += yyleng;
    return ErrIdent_;
}

\"([^\"\\\n]|\\.)*\" {yylval.str = strdup(yytext); columns += yyleng; return String_;}

\"([^\"\\\n]|\\.)* {
    fprintf(stderr, "Get unclosed string at line %d, column %d\n", lines, columns);
    fprintf(stderr, "This line will be ignored\n");
    columns += yyleng;
    error++;
}

[\+-] {yylval.str = strdup(yytext); columns += yyleng; return opadd_;}
[\*\/\%] {yylval.str = strdup(yytext); columns += yyleng; return opmul_;}
[<>]=? {yylval.str = strdup(yytext); columns += yyleng; return oprel_;}
(==|!=) {yylval.str = strdup(yytext); columns += yyleng; return opeq_;}
&& {yylval.str = strdup(yytext); columns += yyleng; return opland_;}
\|\| {yylval.str = strdup(yytext); columns += yyleng; return oplor_;}

[!,;=\{\}\(\)\[\]&] {columns += yyleng; return yytext[0];}

^#[ \t]*include[ \t]*<.+>$ {yylval.str = strdup(yytext); columns += yyleng; return HeaderStmt_;}

#.* {
    fprintf(stderr, "Get invalid preprocessor directive at line %d, column %d\n", lines, columns);
    fprintf(stderr, "This line will be ignored\n");
    columns += yyleng;
    error++;
}

\/\/.* {
    columns += yyleng;
}

\/\*([^*]|\*[^/])*\*\/ {
    int last_line = lines;
    int last_column = columns;
    for(int i = 0; i < yyleng; i++){
        if(yytext[i]!='\n'){
            columns += 1;
        }
        else{
            columns = 1;
            lines += 1;
        }
    }
}

\/\*([^*\n]|\*[^/\n])*\** {
    fprintf(stderr, "Get unclosed multi-line comment at line %d, column %d", lines, columns);
    fprintf(stderr, "This line will be ignored\n");
    columns += yyleng;
    error++;
}

\n|\r\n {
    columns = 1;
    lines += 1;
}

[ \t] {
    columns += 1;
}

. {columns += yyleng; return unknown_;}

%%