/*
 * bison.cpp - compile the AST
 * The node type(NType) is this code has different meaning 
 * from the bison.y. It is normal that some different
 * nonterminal symbols in bison.y now have the same NType.
 * It is also common that some nonterminal symbols disappear
 * or merge into other nodes. So the grammar in AST is 
 * different from that in bison and will be given in the 
 * comments of this file.
 * Some functions in this file have complex logic, even the
 * writer of this file get confused sometimes. So there is
 * a excel named "note.xlsx" to describe them clearly.
 * The comments are write with UTF-8 encoding.
 * （要补写的注释好多...懒得翻译了，剩下的直接用中文好了，反正编码也说了）
 */
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <map>
#include <sstream>
#include <cstring>
#include <algorithm>

#include "bison.hpp"

/*简化调试*/
#define PP {fprintf(stderr,"testpoint\n");fflush(stderr);}
#define PN {debug_node(false);}
#define PV {debug_var();}
#define PR {debug_reg();}
#define PD {debug_node(true);}
#define PI(x)   {fprintf(stderr," %d ",x);fflush(stderr);}
#define PA(x)   {debug_ass(x);}
// #define comment

using std::to_string;

//寄存器在代码中同时以编号形式和名字形式存储
const std::string RegList::reg32_name[14] = {"%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "%r8d", "%r9d", "%r10d", "%r11d", "%r12d", "%r13d", "%r14d", "%r15d"};

const std::string RegList::reg64_name[14] = {"%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi", "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};

//这些名字必须与bison.hpp中的名字顺序一致，否则报错信息会乱掉
const std::string AST::debug_names[43] = {
        "kint", "kvoid", "kif", "kwhile", "kbreak", "kcontinue", "kreturn", 
        "opadd", "opmul", "oprel", "opeq", "oplnot",
        "Ident", "Number", "HeaderStmt", "String", "Address",
        "Root", "Stmt", "Lval", "Exps", "BlockItems", "Exp", "Cond", "ASS",
        "ConstDecl", "VarDecl", "VarDefs", "VarDef", "InitVals",
        "FuncDef", "FuncFParams", "FuncFParam", "FuncRParams",
        "UnaryExp", "MulExp", "AddExp", 
        "BoolExp", "RelExp", "EqExp", "LAndExp", "LOrExp"
    };

inline void VarList::insert(Var &var, std::string name, int range){
    if (vars.size() < range + 2){
        vars.resize(range + 2);
    }
    vars[range+1][name] = var;
}

inline bool VarList::find(std::string name, int range){
    if(vars.size() < range + 2) return false;
    return vars[range+1].find(name) != vars[range+1].end();
}

inline Var* VarList::find(std::string name){
    for(int i = vars.size() - 1; i >= 0; i--){
        if(vars[i].find(name) != vars[i].end())
            return &vars[i][name];
    }
    return nullptr;
}

/*
  为id对应的节点申请寄存器，可能导致的push操作存于ASS节点。
  不会为id对应的节点设置svalue，如果id对于节点有入栈可能，
  那么必须在调用申请函数后手动设置svalue与ivalue
*/
int RegList::request(AST* AST, Node* ASS, int id){
    for(int i = 0; i < regnum; i++){
        if(!regs[i].isused){
            regs[i].isused = true;
            regs[i].nodeid = id;
            regs[i].time = AST->Rcount++;
            return i;
        }
    }
    //No free register, need to release one
    int last = 0;
    for(int i = 0; i < regnum; i++){
        if(regs[i].time < regs[last].time){
            last = i;
        }
    }
    //change the data in the node
    Node* evict = AST->nodes[regs[last].nodeid];
    evict->svalue = "onstack";
    evict->ivalue = ++AST->curstack;
    ASS->ass.push_back("    push    "+reg64_name[last]);
    regs[last].nodeid = id;
    regs[last].time = AST->Rcount++;
    return last;
}

void RegList::free(int reg){
    regs[reg].isused = false;
}
/*
  强制获取指定的寄存器给id对应的node，如果其中有数据，会被
  挪到空闲处,产生的汇编存储于ASS。
  不会为id对应的节点设置svalue，如果id对于节点有入栈可能，
  那么必须在调用申请函数后手动设置svalue与ivalue
*/
void RegList::force_get(AST* AST, Node* ASS, int id, int reg){
    if(!regs[reg].isused){
        regs[reg].isused = true;
        regs[reg].nodeid = id;
        regs[reg].time = AST->Rcount++;
        return;
    }
    int temp = request(AST, ASS, id);
    if(temp == reg) return;
    Node* move = AST->nodes[regs[reg].nodeid];
    regs[temp].nodeid = regs[reg].nodeid;
    regs[temp].time = regs[reg].time;
    move -> svalue = reg32_name[temp];
    move -> ivalue = temp;
    ASS->ass.push_back("    movl    "+reg32_name[reg]+", "+reg32_name[temp]);
    regs[reg].nodeid = id;
    regs[reg].time = AST->Rcount++;
}

void RegList::save(Node* node){
    for(int i = 0;i<regnum;i++){
        if(regs[i].isused){
            node->ass.push_back("    push    "+reg64_name[i]);
            regs[i].isused = false;
        }
    }
}

void RegList::load(Node* node){
    for(int i = 0;i<regnum;i++){
        if(regs[i].isused){
            node->ass.push_back("    pop     "+reg64_name[i]);
        }
    }
}

bool RegList::isempty(){
    for(int i = 0;i<regnum;i++){
        if(regs[i].isused){
            return false;
        }
    }
    return true;
}

void RegList::clear(){
    for(int i = 0;i<regnum;i++){
        regs[i].isused = false;
    }
}

std::string RegList::reg32_64(std::string regname){
    if(regname[0]!='%') return regname;
    for(int i = 0; i < regnum;i++){
        if(regname == reg32_name[i])
            return reg64_name[i];
    }
    return regname;
}

void RangeList::push_back(Range range){
    ranges.push_back(range);
}

void RangeList::push_back(int range){
    //不设置value(仅while语句需要设置)时，初始化为-1，-1
    ranges.push_back({range, {-1,-1}});
}

Range RangeList::pop_back(VarList &vars){
    Range range = ranges.back();
    ranges.pop_back();
    if(vars.vars.size() > range.id + 1){
        vars.vars[range.id+1].clear();
    }
    return range;
}

Range RangeList::back(){
    return ranges.back();
}

int AST::add_node(NType type){
    if (error) return -1;
    Node* node = new Node;
    node -> id = size;
    node -> parent = nullptr;
    node -> type = type;
    node -> svalue = "";
    nodes.push_back(node);
    size++;
    return node -> id;
}

Node* AST::add_node_(NType type){
    Node* node = new Node;
    node -> id = size;
    node -> parent = nullptr;
    node -> type = type;
    node -> svalue = "";
    nodes.push_back(node);
    size++;
    return node;
}

int AST::add_node(NType type, std::string value){
    if (error) return -1;
    Node* node = new Node;
    node -> id = size;
    node -> parent = nullptr;
    node -> type = type;
    node -> svalue = value;
    nodes.push_back(node);
    size++;
    return node -> id;
}

void AST::add_edge(int parent, int child){
    if (error) return;
    nodes[child] -> parent = nodes[parent];
    nodes[parent] -> children.push_back(nodes[child]);
}

void AST::add_edges(int parent, std::initializer_list<int> children){
    if (error) return;
    for(auto child : children){
        add_edge(parent, child);
    }
}

int AST::error_node(){
    error = true;
    return -1;
}

void AST::set_root(int root){
    this->root = nodes[root];
}

void AST::global_compile(){
    ranges.push_back(-1);
    Node* global_code = add_node_(NType::ASS);
    //root -> [ConstDecl | VarDecl | FuncDef | HeaderStmt]+
    if(root == nullptr){
        fprintf(stderr, "Error: No root node in AST.\n");
        exit(1);
    }
    //func仅做占位使用，其结果目前代码中未使用
    Func* func = new(Func);
    func -> returntype = -1;
    func -> range = -1;
    funcs["-global-"] = func; //使用非法标识符，减少冲突(反正也不会输出)
    Func* curfunc = func;
    for(int i = 0; i < root -> children.size(); i++){
        switch(root->children[i]->type){
            case NType::ConstDecl:
            case NType::VarDecl:
            {
                //ConstDecl | VarDecl -> int VarDefs
                Node* vardefs = root->children[i]->children[1];
                //VarDefs -> VarDef+
                for(int j = 0; j < vardefs->children.size(); j++){
                    std::string var_name = vardefs->children[j]->children[0]->svalue;
                    if(vars.find(var_name, -1)){
                        fprintf(stderr, "Error: Variable %s has been declared in global.\n", var_name.c_str());
                        exit(1);
                    }
                    if(funcs.find(var_name) != funcs.end()){
                        fprintf(stderr, "Error: Global Variable is not allowed to have the same name with a function.\n");
                        exit(1);
                    }
                    if(var_name == "__global_init__"){
                        fprintf(stderr,"Error: The name \"__global_init__\" is not allowed to use.\n");
                        exit(1);
                    }
                    Var tempvar;
                    tempvar.name = var_name;
                    tempvar.range = -1;
                    tempvar.offset = -1;
                    int size = 1;
                    //VarDef -> Ident Exps? (InitVals|Exp)?
                    if (vardefs->children[j]->children.size() >= 2 &&
                        vardefs->children[j]->children[1]->type == NType::Exps){
                        Node* constexps = vardefs->children[j]->children[1];
                        //Exps -> Exp+
                        for(int dim = 0; dim < constexps->children.size(); dim++){
                            int res = cal_const(constexps->children[dim]);
                            if (res <= 0){
                                fprintf(stderr, "Error: Try to declare an array with size less or equal than zero.\n");
                                exit(1);
                            }
                            tempvar.shape.push_back(res);
                            size *= res;
                        }
                        tempvar.type = 2;
                    }
                    else{
                        tempvar.type = 1;
                    }
                    tempvar.size = size;
                    if(root->children[i]->type == NType::ConstDecl)
                        tempvar.isconst = true;
                    else
                        tempvar.isconst = false;
                    if(vardefs->children[j]->children.back()->type == NType::Exp ||
                        vardefs->children[j]->children.back()->type == NType::InitVals){
                        tempvar.isinited = true;
                        tempvar.value.resize(size);
                        memset(&tempvar.value[0], 0, size * sizeof(int));
                        message[0] = false; //需要动态初始化时，如int a = func(), message[0]会置为true
                        set_var(tempvar, vardefs->children[j]->children.back(), 0, 0);
                        if(message[0]){ //InitVals中存储了动态初始化的汇编，移至global_code
                            add_edge(global_code->id, vardefs->children[j]->children.back()->id);
                            vardefs->children[j]->children.pop_back();
                        }
                    }
                    else{
                        tempvar.isinited = false;
                    }
                    vars.insert(tempvar, var_name, -1);
                }
                break;
            }
            case NType::FuncDef:{
                func_compile(root->children[i]);
                break;
            }
            case NType::HeaderStmt:{
                //needn't compile
                break;
            }
            default:{
                fprintf(stderr, "Error: Unexpected node type %s in global_compile.\n", debug_names[(int)root->children[i]->type].c_str());
                exit(1);
            }
        }
    }
    int check = ranges.back().id;
    if(check != -1){
        fprintf(stderr, "Error: Range check error in global_compile, got %d(expected -1).\n", check);
        exit(1);
    }
    if(ranges.ranges.size() != 1){
        fprintf(stderr, "Error:  Unmatched range in global compile.\n");
        exit(1);
    }
    if(funcs.find("main") == funcs.end()){
        fprintf(stderr, "Error: Not found main function.\n");
        exit(1);
    }
    //如果有动态初始化，将其放在main函数开始，使用jmp调用以简化逻辑
    if(global_code->children.size()){
        int label = Lcount++;
        Node* assnode = add_node_(NType::ASS);
        assnode->ass.push_back("__global_init__:");
        global_code->ass.push_back("    jmp     .L"+to_string(label));
        add_edge(root->id, global_code->id);
        assnode->parent = global_code;
        global_code->children.emplace(global_code->children.begin(),assnode);
        Node* main_node = nodes[funcs["main"]->range];
        Node* jmp_node = add_node_(NType::ASS);
        jmp_node->ass.push_back("    jmp     __global_init__");
        jmp_node->ass.push_back(".L"+to_string(label)+":");
        jmp_node->parent = main_node;
        main_node->children.emplace(main_node->children.begin()+1,jmp_node);//jmp放在传参、ebp、esp等处理完之后
    }
    return;
}

void AST::func_compile(Node* funcdef){
    std::string funcname = funcdef->children[1]->svalue;
    if(funcname == "__global_init__"){
        fprintf(stderr,"Error: The name \"__global_init__\" is not allowed to use.\n");
        exit(1);
    }
    if(funcs.find(funcname) != funcs.end()){
        fprintf(stderr, "Error: Func %s has been decleared.\n", funcname.c_str());
        exit(1);
    }
    if(vars.find(funcname, -1)){
        fprintf(stderr, "Error: Func is not allowed to have the same name with a global varibale.\n");
        exit(1);
    }
    ranges.push_back(funcdef -> id);
    Func* func = new(Func);
    func -> range = funcdef -> id;
    //funcdef -> [void int] Ident FuncFParams? BlockItems
    if(funcdef->children[0]->type == NType::kint) func->returntype = 1;
    else func->returntype = 0;
    if (funcdef->children.size() == 4){
        //FuncFparams -> FuncFparam+
        for(int i = 0; i < funcdef->children[2]->children.size(); i++){
            Node* funcfparam = funcdef->children[2]->children[i];
            std::string var_name = funcfparam->children[1]->svalue;
            Var* checkvar = vars.find(var_name);
            if(checkvar != nullptr){
                if(checkvar -> range != -1){
                    fprintf(stderr, "Error: Variable %s has been declared in range %d.\n", var_name.c_str(), checkvar -> range);
                    exit(1);
                }
            }
            Var tempvar;
            tempvar.name = var_name;
            tempvar.range = funcdef -> id;
            tempvar.isconst = false;
            tempvar.isinited = false;
            // FuncFparam -> int Ident Exps?
            // Exps -> Exp*
            if (funcfparam->children.size() == 2){
                tempvar.type = 1;
                if(i<4){
                    func->offset -= 4;
                    tempvar.offset = func->offset;
                    std::string code = "    movl    ";
                    if(i == 0) code += "%ecx, ";
                    else if(i == 1) code += "%edx, ";
                    else if(i == 2) code += "%r8d, ";
                    else code += "%r9d, ";
                    code += std::to_string(tempvar.offset) + "(%rbp)";
                    funcfparam->ass.push_back(code);
                }
                tempvar.size = 1;
            }
            else {
                tempvar.shape.push_back(-1);
                for (int j = 0; j< funcfparam->children[2]->children.size();j++){
                    tempvar.shape.push_back(cal_const(funcfparam->children[2]->children[j]));
                }
                tempvar.type = 0;
                if(i<4){
                    func->offset = -((-func->offset+7) / 8 * 8 + 8); //指针8字节对齐
                    tempvar.offset = func->offset;
                    std::string code = "    movq    ";
                    if(i == 0) code += "%rcx, ";
                    else if(i == 1) code += "%rdx, ";
                    else if(i == 2) code += "%r8, ";
                    else code += "%r9, ";
                    code += std::to_string(tempvar.offset) + "(%rbp)";
                    funcfparam->ass.push_back(code);
                }
                tempvar.size = 2; //8字节
            }
            if (i >= 4) tempvar.offset = (i-2)*8;
            vars.insert(tempvar, var_name, funcdef->id);
            func->paramstype.push_back(tempvar.shape);
        }
    }
    funcs[funcname] = func;
    curfunc = func;
    block_compile(funcdef->children.back(), true);
    int check = ranges.pop_back(vars).id;
    if (check != funcdef->id){
        fprintf(stderr, "Error: Range check error in func_compile, got %d(expected %d)\n", check, funcdef -> id);
        exit(1);
    }
    funcdef->children[0]->ass.push_back(".globl "+funcname);
    funcdef->children[0]->ass.push_back(funcname+":");
    funcdef->children[0]->ass.push_back("    pushq   %rbp");
    funcdef->children[0]->ass.push_back("    movq    %rsp, %rbp");
    int rsp_sub = (-func->offset+15)/16*16; //16字节对齐
    //Win64上，函数的栈空间大于4kb时需要调___chkstk_ms来初始化页表（我寻思这也不是ics课啊...）
    //本来应该算一算会不会超4000的，但不确认printf的栈调整和push会不会影响，直接判小一点得了
    if(rsp_sub >= 4000 - 256){
        funcdef->children[0]->ass.push_back("    movl    $"+to_string(rsp_sub)+", %eax");
        funcdef->children[0]->ass.push_back("    call    ___chkstk_ms");
        funcdef->children[0]->ass.push_back("    subq    %rax, %rsp");
    }
    else{
        funcdef->children[0]->ass.push_back("    subq    $"+to_string(rsp_sub)+", %rsp");
    }
    if(func->retl != -1){
        funcdef->ass.push_back(".L"+to_string(func->retl)+":");
    }
    funcdef->ass.push_back("    leave");
    funcdef->ass.push_back("    ret");
    curfunc = funcs["-global-"];
}

void AST::block_compile(Node* blockitems, bool is_func){
    int range;
    if(is_func) range = ranges.back().id; //如果是函数体，range应该按照funcdef的算
    else{
        range = blockitems->id;
        ranges.push_back(range);
    }
    //Blockitems -> [ConstDecl VarDecl Stmt]*
    for (int i = 0; i< blockitems->children.size();i++){
        switch(blockitems->children[i]->type){
            case NType::ConstDecl:
            case NType::VarDecl:
            {
                //ConstDecl | VarDecl -> int VarDefs
                Node* vardefs = blockitems->children[i]->children[1];
                //VarDefs -> VarDef+
                for(int j = 0; j < vardefs->children.size(); j++){
                    std::string var_name = vardefs->children[j]->children[0]->svalue;
                    Var* checkvar = vars.find(var_name);
                    if(checkvar != nullptr){
                        if(checkvar -> range != -1){
                            fprintf(stderr, "Error: Variable %s has been declared in range %d.\n", var_name.c_str(), checkvar -> range);
                            exit(1);
                        }
                    }
                    Var tempvar;
                    tempvar.range = range;
                    tempvar.name = var_name;
                    int size = 1;
                    //VarDef -> Ident Exps? (InitVals|Exp)?
                    if (vardefs->children[j]->children.size() >= 2 &&
                        vardefs->children[j]->children[1]->type == NType::Exps){
                        Node* constexps = vardefs->children[j]->children[1];
                        //Exps -> Exp+
                        for(int dim = 0; dim < constexps->children.size(); dim++){
                            int res = cal_const(constexps->children[dim]);
                            if (res <= 0){
                                fprintf(stderr, "Error: Try to declare an array with size less or equal than zero.\n");
                                exit(1);
                            }
                            tempvar.shape.push_back(res);
                            size *= res;
                        }
                        tempvar.type = 2;
                    }
                    else{
                        tempvar.type = 1;
                    }
                    tempvar.size = size;
                    if(blockitems->children[i]->type == NType::ConstDecl){
                        tempvar.isconst = true;
                        tempvar.isinited = true;
                        curfunc->offset -= size * 4;
                        tempvar.offset = curfunc->offset;
                    }
                    else{
                        tempvar.isconst = false;
                        tempvar.isinited = false;
                        curfunc->offset -= size * 4;
                        tempvar.offset = curfunc->offset;
                    }
                    if(vardefs->children[j]->children.back()->type == NType::Exp
                        || vardefs->children[j]->children.back()->type == NType::InitVals){
                        tempvar.value.resize(size);
                        memset(&tempvar.value[0], 0, size * sizeof(int));
                        set_var(tempvar, vardefs->children[j]->children.back(), 0, 0);
                    }
                    vars.insert(tempvar, var_name, range);
                }
                break;
            }
            case NType::Stmt:{
                stmt_compile(blockitems->children[i], (i==blockitems->children.size()-1) && is_func);
                break;
            }
            default:{
                fprintf(stderr, "Error: Unexpected node type %s in block_compile.\n", debug_names[(int)root->children[i]->type].c_str());
                exit(1);
            }
        }
    }
    if(!is_func){
        int check = ranges.pop_back(vars).id;
        if (check != blockitems->id){
            fprintf(stderr, "Error: Range check error in block_compile, got %d(expected %d).\n", check, blockitems -> id);
            exit(1);
        }
    }
}

void AST::stmt_compile(Node* stmt, bool is_last){
    //Stmt -> ... | empty
    if (stmt->children.size() == 0) return;
    switch(stmt -> children[0] -> type){
        //Stmt -> ... | Lval Exp
        case NType::Lval:{
            std::string name = stmt->children[0]->children[0]->svalue;
            Var *checkvar = vars.find(name);
            if(checkvar->isconst){
                fprintf(stderr, "Error: You are trying to change a const value %s.\n", name.c_str());
                exit(1);
            }
            cal_offset(stmt -> children[0], false);
            eval_exp(stmt -> children[1], true);
            std::string code = "    movl    " + get_exp(stmt, stmt->children[1], 1) + ", " + get_Lval(stmt, stmt->children[0],true);
            free_exp(stmt->children[1]);
            free_Lval(stmt->children[0]);
            stmt -> ass.push_back(code);
            break;
        }
        //Stmt -> ... | Exp
        case NType::Exp:{
            eval_exp(stmt -> children[0], false); //when use need_reg = false, the exp will free itself.
            break;
        }
        //Stmt -> ... | Block
        case NType::BlockItems:{
            block_compile(stmt -> children[0], false);
            break;
        }
        //Stmt -> ... | if Cond Stmt Stmt?
        case NType::kif:{
            ranges.push_back(stmt->id);
            int Ltrue = Lcount++, Lfalse = Lcount++;
            make_cond(stmt->children[1],Ltrue,Lfalse,1);
            Node* labelnode = add_node_(NType::ASS);
            labelnode->ass.push_back(".L"+to_string(Ltrue)+":");
            labelnode->parent = stmt;
            stmt->children.emplace(stmt->children.begin()+2,labelnode);
            stmt_compile(stmt->children[3], false);
            if(stmt->children.size() == 4){
                stmt->ass.push_back(".L"+to_string(Lfalse)+":");
            }
            else{
                int Lend = Lcount++;
                Node* labelnode2 = add_node_(NType::ASS);
                labelnode2->ass.push_back("    jmp     .L"+to_string(Lend));
                labelnode2->ass.push_back(".L"+to_string(Lfalse)+":");
                labelnode2->parent = stmt;
                stmt->children.emplace(stmt->children.begin()+4,labelnode2);
                stmt->ass.push_back(".L"+to_string(Lend)+":");
                stmt_compile(stmt->children[5],false);
            }
            ranges.pop_back(vars);
            //vars must be declared in block, not stmt, so no need to check vars.
            break;
        }
        //Stmt -> ... | while Stmt Cond
        case NType::kwhile:{
            int Ltrue = Lcount++, Ltest = Lcount++, Lfalse = Lcount++;
            Range range;
            range.id = stmt->id;
            range.value[0] = Ltest;
            range.value[1] = Lfalse;
            ranges.push_back(range);
            stmt_compile(stmt->children[1], false);
            make_cond(stmt->children[2],Ltrue,Lfalse,-1);
            Node* labelnode = add_node_(NType::ASS);
            labelnode->ass.push_back("    jmp     .L"+to_string(Ltest));
            labelnode->ass.push_back(".L"+to_string(Ltrue)+":");
            labelnode->parent = stmt;
            stmt->children.emplace(stmt->children.begin()+1,labelnode);
            Node* labelnode2 = add_node_(NType::ASS);
            labelnode2->ass.push_back(".L"+to_string(Ltest)+":");
            labelnode2->parent = stmt;
            stmt->children.emplace(stmt->children.begin()+3,labelnode2);
            stmt->ass.push_back(".L"+to_string(Lfalse)+":");
            ranges.pop_back(vars);
            break;
        }
        //Stmt -> ... | break | continue
        case NType::kcontinue:
        case NType::kbreak:{
            for(int i=ranges.ranges.size()-1; i >=0; i--){
                Range range = ranges.ranges[i];
                NType type = nodes[range.id]->type;
                if(type == NType::FuncDef || type == NType::Root){
                    fprintf(stderr, "Error: Use break out of while block.\n");
                    exit(1);
                }
                else if(range.value[0] != -1){
                    if(stmt -> children[0] -> type == NType::kbreak)
                        stmt->ass.push_back("    jmp     .L"+to_string(range.value[1]));
                    else
                        stmt->ass.push_back("    jmp     .L"+to_string(range.value[0]));
                    break;
                }
            }
            break;
        }
        //Stmt -> ... | return Exp?
        case NType::kreturn:{
            if(curfunc->returntype==-1){
                fprintf(stderr, "Error: Use return stmt in global.\n");
                exit(1);
            }
            if(stmt->children.size()==2){
                if(curfunc->returntype==0){
                    fprintf(stderr, "Warning: return a value in void function.\n");
                    fflush(stderr);
                }
                eval_exp(stmt->children[1], true);
                if(stmt->children[1]->svalue!="%eax"){
                    stmt->ass.push_back("    movl    " + get_exp(stmt, stmt->children[1],0) + ", %eax");
                }
                free_exp(stmt->children[1]);
            }
            if(!is_last){
                if(curfunc->retl==-1) curfunc->retl = Lcount++;
                stmt->ass.push_back("    jmp     .L"+to_string(curfunc->retl));
            }
            break;
        }
        default:{
            fprintf(stderr, "Error: Unexpected node type %s in stmt_compile.\n", debug_names[(int)stmt -> children[0] -> type].c_str());
            exit(1);
        }
    }
    if(!regs.isempty()){
        //按照正常逻辑，处理完一条命令后，寄存器中不应该有值
        fprintf(stderr, "Warning: Regs is not empty.\n");
        fflush(stderr);
        regs.clear();
    }
    if(curstack){
        fprintf(stderr, "Warning: Tempdata stack is not empty.\n");
        fflush(stderr);
    }
}

bool AST::is_const(Node* constexp){
    switch(constexp->type){
        case NType::Exp:
            //Exp -> ??Exp
            return is_const(constexp->children[0]);
        case NType::AddExp:
        case NType::MulExp:
            //AddExp|MulExp -> ??Exp oper ??Exp
            return is_const(constexp->children[0]) && is_const(constexp->children[2]);
        case NType::UnaryExp:{
            //UnaryExp -> (Ident FuncRParams) | (UnaryOp UnaryExp)
            if (constexp->children[0]->type == NType::Ident){
                return false;
            }
            return is_const(constexp->children[1]);
        }
        case NType::Number:
            return true;
        case NType::Lval:{
            // LVal -> Ident [Exps]
            std::string name = constexp->children[0]->svalue;
            Var *var = vars.find(name);
            if(var == nullptr){
                fprintf(stderr, "Error: Variable %s used in constexp is not declared.\n", name.c_str());
                exit(1);
            }
            if(var->isconst == false){
                return false;
            }
            if(constexp->children.size() == 2){
                for(int i = 0; i < constexp->children[1]->children.size(); i++){
                    if(!is_const(constexp->children[1]->children[i])){
                        return false;
                    }
                }
            }
            return true;
        }
        case NType::BoolExp:{
            // BoolExp -> ! ??Exp
            return is_const(constexp->children[1]);
        }
        case NType::RelExp:
        case NType::EqExp:
        case NType::LAndExp:
        case NType::LOrExp:{
            // RelExp|EqExp|LAndExp|LOrExp -> ??Exp oper ??Exp
            return is_const(constexp->children[0]) && is_const(constexp->children[2]);
        }
        default:{
            fprintf(stderr, "Error: Unexpected node type %s in is_const.\n", debug_names[(int)constexp->type].c_str());
            exit(1);
        }
    }
}

int AST::cal_const(Node* constexp){
    switch(constexp->type){
        case NType::Exp:
            return cal_const(constexp->children[0]);
        case NType::AddExp:{
            // AddExp -> ??Exp [+|-] ??Exp
            if (constexp->children[1]->svalue == "+")
                return cal_const(constexp->children[0]) + cal_const(constexp->children[2]);
            else
                return cal_const(constexp->children[0]) - cal_const(constexp->children[2]);
        }
        case NType::MulExp:{
            // MulExp -> ??Exp [*|/|%] ??Exp
            if (constexp->children[1]->svalue == "*")
                return cal_const(constexp->children[0]) * cal_const(constexp->children[2]);
            else if (constexp->children[1]->svalue == "/")
                return cal_const(constexp->children[0]) / cal_const(constexp->children[2]);
            else
                return cal_const(constexp->children[0]) % cal_const(constexp->children[2]);
        }
        case NType::UnaryExp:{
            // UnaryExp -> Ident FuncRParams --- but illegal here
            // UnaryExp -> [+|-] $Exp
            if (constexp->children[0]->type == NType::Ident){
                fprintf(stderr, "Error: Function call is illegal in ConstExp.\n");
                exit(1);
            }
            if (constexp->children[0]->svalue == "+")
                return cal_const(constexp->children[1]);
            else
                return -cal_const(constexp->children[1]);
        }
        case NType::Number:{
            // Number可以为8进制、10进制、16进制
            if (constexp->svalue[0] != '0')
                return stoi(constexp->svalue);
            else if (constexp->svalue[1] == 'x')
                return stoi(constexp->svalue, nullptr, 16);
            else
                return stoi(constexp->svalue, nullptr, 8);
        }
        case NType::Lval:{
            // LVal -> Ident [Exps]
            std::string name = constexp->children[0]->svalue;
            Var *var = vars.find(name);
            if(var == nullptr){
                fprintf(stderr, "Error: Variable %s used in constexp is not declared.\n", name.c_str());
                exit(1);
            }
            if(var -> isconst == false){
                fprintf(stderr, "Error: Variable %s used in constexp is not a const variable.\n", name.c_str());
                exit(1);
            }
            //Exps -> Exp+
            if(var->shape.size() == 0){
                if(constexp->children.size() == 1){
                    return var->value[0];
                }
                else{
                    fprintf(stderr, "Error: Variable %s used in constexp is a number (not an array).\n", name.c_str());
                    exit(1);
                }
            }
            else{
                if(constexp->children.size() == 1){
                    fprintf(stderr, "Error: Variable %s used in constexp is an array (not a number).\n", name.c_str());
                    exit(1);
                }
                if(constexp->children[1]->children.size() != var->shape.size()){
                    fprintf(stderr, "Error: Variable %s used in constexp is a %d-dim array (not %d-dim).\n", name.c_str(), (int)var->shape.size(), (int)constexp->children[1]->children.size());
                    exit(1);
                }
                int index = 0;
                for(int i = 0; i < var->shape.size(); i++){
                    int res = cal_const(constexp->children[1]->children[i]);
                    if(res < 0 || res >= var->shape[i]){
                        fprintf(stderr, "Error: Array index out of range.\n");
                        exit(1);
                    }
                    index = index * var->shape[i] + res;
                }
                return var->value[index];
            }
        }
        case NType::BoolExp:{
            if(cal_const(constexp->children[1])){
                return 0;
            }
            else{
                return 1;
            }
        }
        case NType::RelExp:{
            int left = cal_const(constexp->children[0]);
            int right = cal_const(constexp->children[2]);
            if (constexp->children[1]->svalue == ">")
                return left > right ? 1 : 0;
            else if (constexp->children[1]->svalue == "<")
                return left < right ? 1 : 0;
            else if (constexp->children[1]->svalue == ">=")
                return left >= right ? 1 : 0;
            else
                return left <= right ? 1 : 0;
        }
        case NType::EqExp:{
            int left = cal_const(constexp->children[0]);
            int right = cal_const(constexp->children[2]);
            if (constexp->children[1]->svalue == "==")
                return left == right ? 1 : 0;
            else
                return left != right ? 1 : 0;
        }
        case NType::LAndExp:{
            int left = cal_const(constexp->children[0]);
            int right = cal_const(constexp->children[2]);
            if(left && right){
                return 1;
            }
            else{
                return 0;
            }
        }
        case NType::LOrExp:{
            int left = cal_const(constexp->children[0]);
            int right = cal_const(constexp->children[2]);
            if(left || right){
                return 1;
            }
            else{
                return 0;
            }
        }
        default:{
            fprintf(stderr, "Error: Unexpected node type %s in cal_const.\n", debug_names[(int)constexp->type].c_str());
            exit(1);
        }
    }
}

int AST::set_var(Var &var, Node* node, int depth, int offset){
    //InitVals -> (InitVals | Exp)*
    if (depth == var.shape.size()){
        /* This means we need a exp here, not a array */
        if(node->type == NType::InitVals){
            fprintf(stderr, "Error: Use an array(should be number) to set the var %s at depth %d, offset %d.\n",var.name.c_str(), depth, offset);
            exit(1);
        }
        //这一块的逻辑比较复杂，建议参考笔记.xls中的图示
        if(is_const(node)){
            int res = cal_const(node);
            if(var.isinited){
                var.value[offset] = cal_const(node);
            }
            if(var.range != -1){
                std::string code = "    movl    $" + std::to_string(res) + ", " + std::to_string(var.offset + 4*offset) + "(%rbp)";
                node->ass.push_back(code);
            }
        }
        else{
            if(var.isconst){
                fprintf(stderr,"Error: Use no-const exp to set the value of const var %s", var.name.c_str());
                exit(1);
            }
            else{
                eval_exp(node, true);
                if(var.range == -1){
                    std::string code = "    movl    " + get_exp(node, node, 1) + ", " + var.name;
                    free_exp(node);
                    if(offset != 0){
                        code += "+" + std::to_string(4*offset);
                    }
                    code += "(%rip)";
                    node -> ass.push_back(code);
                    message[0] = true;
                }
                else{
                    std::string code = "    movl    " + get_exp(node, node, 1) + ", " + to_string(var.offset + 4*offset) + "(%rbp)";
                    free_exp(node);
                    node->ass.push_back(code);
                }
            }
        }
        return 1;
    }
    else{
        /* The var is an array or part of an array*/
        if(node -> type == NType::Exp){
            fprintf(stderr, "Error: Use an number(should be array) to set the var %s.\n",var.name.c_str());
            exit(1);
        }
        int maxsize = 1;
        int fillsize = 0;
        for(int i = depth; i < var.shape.size(); i++){
            maxsize *= var.shape[i];
        }
        for(int i = 0; i < node->children.size(); i++){
            if(fillsize >= maxsize){
                fprintf(stderr, "Error: Too many values to set the var at depth %d, offset %d.\n", depth, offset);
                exit(1);
            }
            if(node->children[i]->type == NType::Exp){
                set_var(var, node->children[i], var.shape.size(), offset+fillsize);
                fillsize++;
            }
            else{
                //计算下一个花括号对应的数组层数
                int nextdepth = var.shape.size();
                int tempfillsize = fillsize;
                while(nextdepth > depth + 1){
                    if(tempfillsize % var.shape[nextdepth - 1] == 0){
                        tempfillsize /= var.shape[nextdepth - 1];
                        nextdepth--;
                    }
                    else{
                        break;
                    }
                }
                fillsize += set_var(var, node->children[i], nextdepth, offset + fillsize);
            }
        }
        if(fillsize < maxsize){
            if(var.isinited){
                for(int i = fillsize; i < maxsize; i++){
                    var.value[offset+i] = 0;
                }
            }
            if(var.range != -1){
                if(maxsize - fillsize < 8){
                    Node* zero = add_node_(NType::ASS);
                    for(int i = fillsize; i < maxsize; i++){
                        std::string code = "    movl    $0, " + std::to_string(var.offset + 4*(offset+i)) + "(%rbp)";
                        zero->ass.push_back(code);
                    }
                    add_edge(node->id,zero->id);
                }
                else{
                    Node* manyzeros = add_node_(NType::ASS);
                    manyzeros->ass.push_back("    movl    $0, %eax");
                    manyzeros->ass.push_back("    movl    $" + std::to_string(maxsize - fillsize) + ", %ecx");
                    manyzeros->ass.push_back("    leaq    " + std::to_string(var.offset + 4*(offset+fillsize)) + "(%rbp), %rdi");
                    manyzeros->ass.push_back("    rep stosl");
                    add_edge(node->id,manyzeros->id);
                }
            }
        }
        return maxsize;
    }
}

void AST::make_cond(Node* cond, int ltrue, int lfalse, int next){
    switch(cond->type){
        case NType::Cond:{
            make_cond(cond->children[0],ltrue,lfalse,next);
            break;
        }
        case NType::LOrExp:{
            int L1 = Lcount++;
            Node* labelnode = add_node_(NType::ASS);
            labelnode->ass.push_back(".L"+to_string(L1)+":");
            make_cond(cond->children[0],ltrue,L1,-1);
            make_cond(cond->children[1],ltrue,lfalse,next);
            labelnode->parent = cond;
            cond->children.emplace(cond->children.begin()+1,labelnode);
            break;
        }
        case NType::LAndExp:{
            int L1 = Lcount++;
            Node* labelnode = add_node_(NType::ASS);
            labelnode->ass.push_back(".L"+to_string(L1)+":");
            make_cond(cond->children[0],L1,lfalse,1);
            make_cond(cond->children[1],ltrue,lfalse,next);
            labelnode->parent = cond;
            cond->children.emplace(cond->children.begin()+1,labelnode);
            break;
        }
        case NType::EqExp:{
            if(cond->children[1]->svalue[0]=='!'){
                int temp = ltrue;
                ltrue = lfalse;
                lfalse = temp;
                next = -next;
            }
            eval_exp(cond->children[0], true);
            eval_exp(cond->children[2], true);
            if(cond->children[2]->svalue[0]=='$'){
                if(cond->children[0]->svalue[0]=='$'){
                    int res = cond->children[0]->ivalue == cond->children[2]->ivalue ? 1 : -1;
                    if(res == next){
                        return;
                    }
                    else{
                        if(res == 1){
                            cond->ass.push_back("    jmp     .L"+to_string(ltrue));
                        }
                        else{
                            cond->ass.push_back("    jmp     .L"+to_string(lfalse));
                        }
                    }
                }
                else{
                    cond->ass.push_back("    cmpl    "+get_exp(cond, cond->children[2], 0)+", "+get_exp(cond, cond->children[0], 2));
                    free_exp(cond->children[2]);
                    free_exp(cond->children[0]);
                }
            }
            else{
                cond->ass.push_back("    cmpl    "+get_exp(cond, cond->children[0], 0)+", "+get_exp(cond, cond->children[2], 2));
                free_exp(cond->children[2]);
                free_exp(cond->children[0]);
            }
            if(next == 1){
                cond->ass.push_back("    jne     .L"+to_string(lfalse));
            }
            else if(next == -1){
                cond->ass.push_back("    je      .L"+to_string(ltrue));
            }
            else{
                cond->ass.push_back("    je      .L"+to_string(ltrue));
                cond->ass.push_back("    jmp     .L"+to_string(lfalse));
            }
            break;
        }
        case NType::RelExp:{
            std::string oper = cond->children[1]->svalue;
            eval_exp(cond->children[0], true);
            eval_exp(cond->children[2], true);
            if(cond->children[0]->svalue[0]=='$'){
                if(cond->children[2]->svalue[0]=='$'){
                    int res = 0; 
                    if(oper == "<") res = cond->children[0]->ivalue < cond->children[2]->ivalue ? 1 : -1;
                    if(oper == "<=") res = cond->children[0]->ivalue <= cond->children[2]->ivalue ? 1 : -1;
                    if(oper == ">") res = cond->children[0]->ivalue > cond->children[2]->ivalue ? 1 : -1;
                    if(oper == ">=") res = cond->children[0]->ivalue >= cond->children[2]->ivalue ? 1 : -1;
                    if(res == next){
                        return;
                    }
                    else{
                        if(res == 1){
                            cond->ass.push_back("    jmp     .L"+to_string(ltrue));
                        }
                        else{
                            cond->ass.push_back("    jmp     .L"+to_string(lfalse));
                        }
                    }
                }
                else{
                    cond->ass.push_back("    cmpl    "+get_exp(cond, cond->children[0], 0)+", "+get_exp(cond, cond->children[2], 2));
                    free_exp(cond->children[2]);
                    free_exp(cond->children[0]);
                    //其中只有一个是立即值时，互换位置并改符号即可
                    oper[0] = oper[0]^'<'^'>';
                }
            }
            else{
                cond->ass.push_back("    cmpl    "+get_exp(cond, cond->children[2], 0)+", "+get_exp(cond, cond->children[0], 2));
                free_exp(cond->children[2]);
                free_exp(cond->children[0]);
            }
            std::string truestr,falsestr;
            if(oper=="<"){
                truestr = "    jl      .L";
                falsestr = "    jge     .L";
            }
            else if(oper=="<="){
                truestr = "    jle     .L";
                falsestr = "    jg      .L";
            }
            if(oper==">"){
                truestr = "    jg      .L";
                falsestr = "    jle     .L";
            }
            else if(oper==">="){
                truestr = "    jge     .L";
                falsestr = "    jl      .L";
            }
            if(next == 1){
                cond->ass.push_back(falsestr+to_string(lfalse));
            }
            else if(next == -1){
                cond->ass.push_back(truestr+to_string(ltrue));
            }
            else{
                cond->ass.push_back(truestr+to_string(ltrue));
                cond->ass.push_back(falsestr+to_string(lfalse));
            }
            break;
        }
        case NType::BoolExp:{
            int temp = ltrue;
            ltrue = lfalse;
            lfalse = temp;
            next = -next;
            make_cond(cond->children.back(),ltrue,lfalse,next);
            break;
        }
        default:{
            eval_exp(cond, true);
            if(cond->svalue[0]=='$'){
                int res = cond->ivalue != 0 ? 1 : -1;
                if(res == next){
                    return;
                }
                else{
                    if(res == 1){
                        cond->ass.push_back("    jmp     .L"+to_string(ltrue));
                    }
                    else{
                        cond->ass.push_back("    jmp     .L"+to_string(lfalse));
                    }
                }
            }
            else{
                cond->ass.push_back("    cmpl    $0, "+get_exp(cond, cond, 2));
                free_exp(cond);
            }
            if(next == 1){
                cond->ass.push_back("    je     .L"+to_string(lfalse));
            }
            else if(next == -1){
                cond->ass.push_back("    jne      .L"+to_string(ltrue));
            }
            else{
                cond->ass.push_back("    jne      .L"+to_string(ltrue));
                cond->ass.push_back("    jmp     .L"+to_string(lfalse));
            }
        }
    }
}

void AST::cal_offset(Node* Lval, bool allow_array){
    // LVal -> Ident [Exps]
    std::string name = Lval->children[0]->svalue;
    Var *var = vars.find(name);
    if(var == nullptr){
        fprintf(stderr, "Error: Variable %s used is not declared.\n", name.c_str());
        exit(1);
    }
    //Exps -> Exp+
    if(var->type == 1){
        if(Lval->children.size() == 1){
            //这意味着执行完一次后childre.size就不再为1，因此cal_offset不得多次调用
            Node* exps = add_node_(NType::ASS);
            Node* exp = add_node_(NType::ASS);
            exp -> svalue = "$0";
            exp -> ivalue = 0;
            add_edge(exps->id,exp->id);
            add_edge(Lval->id,exps->id);
            return;
        }
        else{
            fprintf(stderr, "Error: Variable %s used in Lval is a number (not an array).\n", name.c_str());
            exit(1);
        }
    }
    else{
        if(Lval->children.size() == 1){
            if(!allow_array){
                fprintf(stderr, "Error: Variable %s used in Lval is an array (not a number).\n", name.c_str());
                exit(1);
            }
            else{
                Node* exps = add_node_(NType::ASS);
                Node* exp = add_node_(NType::ASS);
                exp -> svalue = "$0";
                exp -> ivalue = 0;
                add_edge(exps->id,exp->id);
                add_edge(Lval->id,exps->id);
                return;
            }
        }
        if(Lval->children[1]->children.size() != var->shape.size()){
            if(!allow_array || Lval->children[1]->children.size() > var->shape.size()){
                fprintf(stderr, "Error: Variable %s used in Lval is a %d-dim array (not %d-dim).\n", name.c_str(), (int)var->shape.size(), (int)Lval->children[1]->children.size());
                exit(1);
            }
        }
        eval_exp(Lval->children[1]->children[0], true);
        for(int i = 1; i < Lval->children[1]->children.size();i++){
            simple_ass(Lval->children[1]->children[i-1], Lval->children[1]->children[i-1], var->shape[i], '*');
            eval_exp(Lval->children[1]->children[i], true);
            simple_ass(Lval->children[1]->children[i], Lval->children[1]->children[i-1], Lval->children[1]->children[i], '+');
        }
        //传递子数组，后几个维度的偏移量记作0，为了简化计算，先将后几维大小相乘
        int extra = 1;
        for(int i = Lval->children[1]->children.size(); i < var->shape.size(); i++){
            extra *= var->shape[i];
        }
        if(extra != 1){
            simple_ass(Lval->children[1]->children.back(), Lval->children[1]->children.back(), extra, '*');
        }
        
    }
}

std::string AST::get_Lval(Node* node, Node* Lval, bool is_left){
    std::string name = Lval->children[0]->svalue;
    Var *var = vars.find(name);
    //本处逻辑较为复杂，建议参考笔记.xls
    if(var->type==1){
        if(var->range==-1){
            if(var->isconst&&(!is_left)){
                return "$"+to_string(var->value[0]);
            }
            else{
                return name+"(%rip)";
            }
        }
        else{
            if(var->isconst&&(!is_left)){
                return "$"+to_string(var->value[0]);
            }
            else{
                return to_string(var->offset)+"(%rbp)";
            }
        }
    }
    else if(var->type==0){
        Node* offsetnode = Lval->children[1]->children.back();
        int reg = regs.request(this, node, Lval->id);
        node->ass.push_back("    movq    "+to_string(var->offset)+"(%rbp), "+RegList::reg64_name[reg]);
        Lval->svalue = RegList::reg64_name[reg];
        Lval->ivalue = reg;
        if(offsetnode->svalue[0]=='$'){
            if(offsetnode->ivalue==0){
                return "(" + RegList::reg64_name[reg] + ")";
            }
            else{
                return to_string(offsetnode->ivalue*4)+"(" + RegList::reg64_name[reg] + ")";
            }
        }
        else{
            return "(" + RegList::reg64_name[reg] + ", " +  regs.reg32_64(get_exp(node, offsetnode, 2)) + ", 4)";
        }
    }
    else{
        Node* offsetnode = Lval->children[1]->children.back();
        if(var->range == -1){
            if(offsetnode->svalue[0]=='$'){        
                if(var->isconst&&(!is_left)){
                    return "$"+to_string(var->value[offsetnode->ivalue]);
                }
                else if(offsetnode->ivalue==0){
                    return name + "(%rip)";
                }
                else{
                    return name + "+" + to_string(offsetnode->ivalue*4) + "(%rip)";
                }
            }
            else{
                int reg = regs.request(this, node, Lval->id);
                node->ass.push_back("    leaq    "+name +"(%rip), "+regs.reg64_name[reg]);
                Lval->svalue = RegList::reg64_name[reg];
                Lval->ivalue = reg;
                return "("+regs.reg64_name[reg]+", " + regs.reg32_64(get_exp(node, offsetnode, 2)) + ", 4)";
            }
        }
        else{
            if(offsetnode->svalue[0]=='$'){        
                if(var->isconst&&(!is_left)){
                    return "$"+to_string(var->value[offsetnode->ivalue]);
                }
                else{
                    return to_string(var->offset+offsetnode->ivalue*4) + "(%rbp)";
                }
            }
            else{
                return to_string(var->offset) + "(%rbp, " + regs.reg32_64(get_exp(node, offsetnode, 2)) + ", 4)";
            }
        }
    }
}

void AST::free_Lval(Node* Lval){
    //Lval中的offset也同样需要free处理
    std::string name = Lval->children[0]->svalue;
    Var *var = vars.find(name);
    if(var->type!=1){
        free_exp(Lval->children[1]->children.back());
    }
    free_exp(Lval);
}

void AST::eval_exp(Node* node, bool need_res){
    switch(node->type){
        case NType::Exp:{
            eval_exp(node->children[0], need_res);
            if(need_res){
                node->svalue = node->children[0]->svalue;
                node->ivalue = node->children[0]->ivalue;
                if(node->svalue[0] == '%'){
                    regs.regs[node->ivalue].nodeid = node->id;
                }
            }
            break;
        }
        case NType::AddExp:
        case NType::MulExp:{
            eval_exp(node->children[0], need_res);
            eval_exp(node->children[2], need_res);
            if(need_res){
                simple_ass(node, node->children[0], node->children[2], node->children[1]->svalue[0]);
            }
            break;
        }
        case NType::Number:{
            if(need_res){
                if (node->svalue[0] != '0')
                    node->ivalue = stoi(node->svalue);
                else if (node->svalue[1] == 'x')
                    node->ivalue = stoi(node->svalue, nullptr, 16);
                else
                    node->ivalue = stoi(node->svalue, nullptr, 8);
                node->svalue = "$" + to_string(node->ivalue);
            }
            break;
        }
        case NType::Lval:{
            cal_offset(node, false);
            if(!need_res){
                free_Lval(node);
                break;
            }
            //get_Lval因内部申请寄存器原因，同样不能多次调用，因此存值使用
            //必须在设置node的svalue和ivalue之前释放掉之前的存储内容，再之后存储的就是exp（而不是lval)数据了
            std::string lval = get_Lval(node, node, false);
            if(lval[0]=='$'){
                free_Lval(node);
                node->svalue = lval;
                node->ivalue = stoi(lval.substr(1));
            }
            else{
                int reg = regs.request(this, node, node->id);
                node->ass.push_back("    movl    "+lval+", "+RegList::reg32_name[reg]);
                free_Lval(node);
                node->svalue = RegList::reg32_name[reg];
                node->ivalue = reg;
            }
            break;
        }
        case NType::UnaryExp:{
            if (node->children[0]->type != NType::Ident){
                eval_exp(node->children[1], need_res);
                if(need_res){
                    if(node->children[0]->svalue[0]=='-')
                        simple_ass(node, node->children[1], -1, '*');  
                    else{
                        node->svalue = node->children[1]->svalue;
                        node->ivalue = node->children[1]->ivalue;
                        if(node->svalue[0] == '%'){
                            regs.regs[node->ivalue].nodeid = node->id;
                        }
                    }
                }
            }
            else{
                int lib_call = 0;
                if(node->children[0]->svalue=="printf"){
                    lib_call = 1;
                }
                else if(node->children[0]->svalue=="scanf"){
                    lib_call = 2;
                }
                std::string func_name = node->children[0]->svalue;
                Func* func = nullptr;
                if(!lib_call){
                    if(funcs.find(func_name) == funcs.end()){
                        fprintf(stderr, "Error: The function %s is not defined.\n", func_name.c_str());
                        exit(1);
                    }
                    func = funcs[func_name];
                    if (need_res && !(func->returntype)){
                        fprintf(stderr, "Error: The function %s don't return a value.\n", func_name.c_str());
                        exit(1);
                    }
                    if(func->paramstype.size()!=node->children[1]->children.size()){
                        fprintf(stderr, "Error: The function %s need %d params, but %d given.\n", func_name.c_str(), (int)func->paramstype.size(), (int)node->children[1]->children.size());
                        exit(1);
                    }
                }
                //解析函数前执行的放在ass_begin里，解析后执行的放在node里
                Node* ass_begin = add_node_(NType::ASS);
                //确保%eax是空闲的，可以存储函数的返回值，即使返回值不使用，也应保证%eax的原有值不被覆盖
                regs.force_get(this, ass_begin, ass_begin->id, 0);
                regs.free(0);
                RegList save_reg = regs;
                regs.save(ass_begin);
                int align = 0;
                int back = 0;
                align += curstack * 8;
                if(node->children[1]->children.size() > 4){
                    align += (node->children[1]->children.size() - 4) * 8;
                    back += (node->children[1]->children.size() - 4) * 8;
                }
                if(align % 16 != 0){//16字节对齐
                    ass_begin->ass.push_back("    subq    $8, %rsp");
                    back += 8;
                }
                int i;
                //大于4的参数，计算完成立即入栈，避免影响后续计算
                for(i = node->children[1]->children.size() - 1;i>=4;i--){
                    Node* param = node->children[1]->children[i];
                    if(param->type == NType::String){
                        if(!lib_call){
                            fprintf(stderr,"Error: string param is only allowed to use in libcall.\n");
                            exit(1);
                        }
                        strs.push_back(param->svalue);
                        int reg = regs.request(this, param, param->id);
                        param->ass.push_back("    leaq    .LC"+to_string(strs.size()-1)+"(%rip), "+RegList::reg64_name[reg]);
                        param->ass.push_back("    pushq   "+RegList::reg64_name[reg]);
                        regs.free(reg);
                    }
                    else if(param->type == NType::Exp){
                        if(param->children[0]->type == NType::Lval){
                            if(part_array(param->children[0], func, i)){
                                cal_offset(param->children[0], true);
                                int reg = regs.request(this, param->children[0], param->children[0]->id);
                                param->ass.push_back("    leaq    "+get_Lval(param->children[0], param->children[0], true)+", "+RegList::reg64_name[reg]);
                                param->ass.push_back("    pushq   "+RegList::reg64_name[reg]);
                                regs.free(reg);
                                free_Lval(param->children[0]);
                                continue;
                            }
                        }
                        if(!lib_call){
                            if(func->paramstype[i].size()!=0){
                                fprintf(stderr,"Error: The func %s need a array param, not int", func_name.c_str());
                                exit(1);
                            }
                        }
                        eval_exp(param, true);
                        param->ass.push_back("    push    "+ regs.reg32_64(get_exp(param, param, 1)));
                        free_exp(param);
                    }
                    else if(param->type == NType::Address){
                        if(!lib_call){
                            fprintf(stderr,"Error: & is only allowed to use in scanf and printf.\n");
                            exit(1);
                        }
                        std::string name = param->children[0]->children[0]->svalue;
                        Var *checkvar = vars.find(name);
                        if(checkvar->isconst && lib_call == 2){
                            fprintf(stderr, "Warning: You are trying to pass a const array %s to scanf.\n", name.c_str());
                            fprintf(stderr, "         This will cause undefined behavior.\n");
                        }
                        cal_offset(param->children[0], true);
                        int reg = regs.request(this, param, param->id);
                        param->ass.push_back("    leaq    "+get_Lval(param, param->children[0], true)+", "+RegList::reg64_name[reg]);
                        param->ass.push_back("    pushq   "+RegList::reg64_name[reg]);
                        regs.free(reg);
                        free_Lval(param->children[0]);
                    }
                }
                for(int k = 1; k <= 4; k++){
                    message[k]=false;
                }
                //剩余参数，因需要寄存器传参，所以都计算完后再放到寄存器上(可能有嵌套函数调用之类的，提前放了也白放)
                for(int j = i;j >= 0; j--){
                    Node* param = node->children[1]->children[j];
                    if(param->type == NType::String){
                        if(!lib_call){
                            fprintf(stderr,"Error: string param is only allowed to use in libcall.\n");
                            exit(1);
                        }
                        continue;
                    }
                    else if(param->type == NType::Exp){
                        if(param->children[0]->type == NType::Lval){
                            if(part_array(param->children[0], func, j)){
                                //因part_array计算两边很麻烦，所以存到message里了
                                message[j+1] = true;
                                cal_offset(param->children[0], true);
                                continue;
                            }
                        }
                        if(!lib_call){
                            if(func->paramstype[j].size()!=0){
                                fprintf(stderr,"Error: The func %s need a array param, not int", func_name.c_str());
                                exit(1);
                            }
                        }
                        eval_exp(param, true);
                    }
                    else if(param->type == NType::Address){
                        if(!lib_call){
                            fprintf(stderr,"Error: & is only allowed to use in scanf.\n");
                            exit(1);
                        }
                        std::string name = param->children[0]->children[0]->svalue;
                        Var *checkvar = vars.find(name);
                        if(checkvar->isconst && lib_call == 2){
                            fprintf(stderr, "Warning: You are trying to pass a const array %s to scanf.\n", name.c_str());
                            fprintf(stderr, "         This will cause undefined behavior.\n");
                        }
                        cal_offset(param->children[0], true);
                    }
                }
                //考虑到栈后进先出，此处正序遍历
                for(int j = 0;j <= i; j++){
                    Node* param = node->children[1]->children[j];
                    int reg = j == 0 ? 2 :
                                j == 1 ? 3 :
                                j == 2 ? 6 : 7;
                    if(param->type == NType::String){
                        strs.push_back(param->svalue);
                        regs.force_get(this, node, param->id, reg);
                        node->ass.push_back("    leaq    .LC"+to_string(strs.size()-1)+"(%rip), "+RegList::reg64_name[reg]);
                    }
                    else if(param->type == NType::Exp){
                        if(param->children[0]->type == NType::Lval){
                            if(message[j+1]){
                                regs.force_get(this, node, param->children[0]->id, reg);
                                node->ass.push_back("    leaq    "+get_Lval(node, param->children[0], true)+", "+RegList::reg64_name[reg]);
                                free_Lval(param->children[0]);
                                continue;
                            }
                        }
                        if(get_exp(node, param, 0) != RegList::reg32_name[reg]){
                            regs.force_get(this, node, param->id, reg);
                            node->ass.push_back("    movl    "+get_exp(node, param, 0)+", "+RegList::reg32_name[reg]);
                            free_exp(param);
                        }
                    }
                    else if(param->type == NType::Address){
                        regs.force_get(this, node, param->id, reg);
                        node->ass.push_back("    leaq    "+get_Lval(node, param->children[0], true)+", "+RegList::reg64_name[reg]);
                        free_Lval(param->children[0]);
                    }
                }
                if(lib_call){
                    node -> ass.push_back("    subq    $32, %rsp");
                    back+=32;
                }
                node -> ass.push_back("    call    "+func_name);
                if(back){
                    node -> ass.push_back("    addq    $"+to_string(back)+", %rsp");
                }
                regs = save_reg;
                regs.load(node);
                if(need_res){
                    regs.force_get(this, node, node->id ,0);
                    node->svalue = "%eax";
                    node->ivalue = 0;
                }
                //总的来说，节点是逆序计算的，但是节点打印时是正序，所以把节点reverse一下
                std::reverse(node->children[1]->children.begin(),node->children[1]->children.end());
                ass_begin -> parent = node;
                node->children.emplace(node->children.begin(),ass_begin);
            }
            break;
        }
        case NType::BoolExp:
        case NType::RelExp:
        case NType::EqExp:
        case NType::LAndExp:
        case NType::LOrExp:{
            int ltrue = Lcount++, lfalse = Lcount++, lend = Lcount++;
            //因为make_cond并不具有编译期计算的功能，所以只能调用is_const了
            if(is_const(node)){
                if(cal_const(node)){
                    node->svalue="$1";
                    node->ivalue=1;
                }
                else{
                    node->svalue="$0";
                    node->ivalue=0;
                }
                return;
            }
            make_cond(node, ltrue, lfalse, 1);
            int reg = regs.request(this, node, node->id);
            node->ass.push_back(".L"+to_string(ltrue)+":");
            node->ass.push_back("    movl    $1, "+regs.reg32_name[reg]);
            node->ass.push_back("    jmp     .L"+to_string(lend));
            node->ass.push_back(".L"+to_string(lfalse)+":");
            node->ass.push_back("    movl    $0, "+regs.reg32_name[reg]);
            node->ass.push_back(".L"+to_string(lend)+":");
            node->svalue = regs.reg32_name[reg];
            node->ivalue = reg;
            break;
        }
        default:{
            fprintf(stderr, "Error: Unexpected node type %s in eval_exp.\n", debug_names[(int)node->type].c_str());
            exit(1);
        }
    }
}

std::string AST::get_exp(Node* node, Node* exp, int need_reg){
    //参数取用时的类型转换，是在node执行时进行的，所以汇编应该放到node里
    if (exp->svalue[0] == '%'){
        regs.regs[exp->ivalue].time=Rcount++;
        return exp->svalue;
    }
    else if (exp->svalue[0] == '$'){
        if(need_reg != 2)
            return exp->svalue;
        else{
            int reg = regs.request(this, node, exp->id);
            node->ass.push_back("    movl    "+ exp->svalue +", "+ RegList::reg32_name[reg]);
            exp->svalue = RegList::reg32_name[reg];
            exp->ivalue = reg;
            return exp->svalue;
        }
    }
    else if(exp->svalue == "onstack"){
        if(exp->ivalue != curstack){
            fprintf(stderr, "Error: Use a value on tempstack but not on the top.\n");
            exit(1);
        }
        int reg = regs.request(this, node, exp->id);
        node->ass.push_back("    pop    " + RegList::reg64_name[reg]);
        exp->svalue = RegList::reg32_name[reg];
        exp->ivalue = reg;
        curstack--;
        return exp->svalue;
    }
    else{
        if(!need_reg)
            return exp->svalue;
        else{
            int reg = regs.request(this, node, exp->id);
            node->ass.push_back("    movl    "+ exp->svalue +", " + RegList::reg32_name[reg]);
            exp->svalue = RegList::reg32_name[reg];
            exp->ivalue = reg;
            return exp->svalue;
        }
    }
}

inline void AST::free_exp(Node* exp){
    if (exp->svalue[0] == '%'){
        regs.free(exp->ivalue);
        return;
    }
}

bool AST::part_array(Node* Lval, Func* func, int i){
    std::string name = Lval->children[0]->svalue;
    Var *var = vars.find(name);
    if(var == nullptr){
        fprintf(stderr, "Error: Variable %s used in funcRparam is not declared.\n", name.c_str());
        exit(1);
    }
    if(var->shape.size()==0) return false;
    int Lval_div = 0;
    if(Lval->children.size()==2) Lval_div=Lval->children[1]->children.size();
    if(var->shape.size() <= Lval_div) return false;
    if(func != nullptr){
        if(var->shape.size() - Lval_div != func->paramstype[i].size()){
            fprintf(stderr,"Error: The func need a %dd array param, not %d.\n", (int)func->paramstype[i].size(),(int)var->shape.size()-Lval_div);
            exit(1);
        }
        for(int j = 1; j < func->paramstype[i].size(); j++){
            if(func->paramstype[i][j] != var->shape[j + Lval_div]){
                fprintf(stderr,"Error: The array parse to func has unmatched length.\n");
                exit(1);
            }
        }
    }
    if(var->isconst){
        fprintf(stderr, "Warning: You are trying to pass a const array %s to a function.\n", name.c_str());
        fprintf(stderr, "         If you changed the value of the const array in the function, it will cause undefined behavior.\n");
    }
    return true;
}

void AST::simple_ass(Node* node, Node* left, Node* right, char oper){
    switch(oper){
        case '+':
        case '-':
        case '*':{
            if(left->svalue[0]=='$'){
                if(right->svalue[0]=='$'){
                    if(oper=='+'){
                        node->ivalue = left->ivalue + right->ivalue;
                    }
                    else if(oper=='-'){
                        node->ivalue = left->ivalue - right->ivalue;
                    }
                    else{
                        node->ivalue = left->ivalue * right->ivalue;
                    }
                    node->svalue = "$" + to_string(node->ivalue);
                    return;
                }
                else{
                    if(oper!='-'){
                        std::string operass = oper=='+'?"addl ":"imull";
                        node->ass.push_back("    " + operass + "   " + get_exp(node, left, 0) + ", " + get_exp(node, right, 2));
                        free_exp(left);
                        node->ivalue=right->ivalue;
                        node->svalue=right->svalue;
                        regs.regs[node->ivalue].nodeid = node->id;
                        return;
                    }
                }
            }
            std::string operass = oper=='+' ? "addl ": oper=='-' ? "subl ": "imull";
            node->ass.push_back("    " + operass + "   " + get_exp(node, right, 0) + ", " + get_exp(node, left, 2));
            free_exp(right);
            node->ivalue=left->ivalue;
            node->svalue=left->svalue;
            regs.regs[node->ivalue].nodeid = node->id;
            break;
        }
        case '/':
        case '%':{
            std::string leftres = get_exp(node,left,0);
            if(left->svalue!="%eax"){
                regs.force_get(this, node, node->id, 0);
                node->ass.push_back("    movl    "+leftres+", %eax");
                free_exp(left);
            }
            regs.force_get(this, node, node->id, 3);
            node->ass.push_back("    cltd");
            node->ass.push_back("    idivl   "+get_exp(node, right, 2));
            free_exp(right);
            if(oper=='/'){
                node->ivalue = 0;
                node->svalue = "%eax";
                regs.free(3);
            }
            else{
                node->ivalue = 3;
                node->svalue = "%edx";
                regs.free(0);
            }
            break;
        }
    }
}

void AST::simple_ass(Node* node, Node* left, int right, char oper){
    //这个函数只在cal_offset时用到了，而且只用到了加号和乘号
    if(oper == '+' || oper == '*'){
        if(left->svalue[0]=='$'){
            if(oper=='+'){
                node->ivalue = left->ivalue + right;
            }
            else{
                node->ivalue = left->ivalue * right;
            }
            node->svalue = "$" + to_string(node->ivalue);
            return;
        }
        else{
            std::string operass = oper=='+'?"addl ":"imull";
            node->ass.push_back("    " + operass + "   $" + to_string(right) + ", " + get_exp(node, left, 2));
            node->ivalue=left->ivalue;
            node->svalue=left->svalue;
            regs.regs[node->ivalue].nodeid = node->id;
        }
    }
    else{
        fprintf(stderr,"Error: Sorry, I haven't write how to deal with other opers in simple_ass(Node* Node* int char).\n");
        fprintf(stderr,"But this case is not reachable in my design.\n");
        exit(1);
    }
}

void AST::print_ass(){
    printf(".section .rdata\n");
    for(int i = 0;i < strs.size();i++){
        printf(".LC%d:\n    .string %s\n",i,strs[i].c_str());
    }
    if(vars.vars.size()){
        auto global_vars = vars.vars[0];
        for (auto i : global_vars){
            if(!i.second.isinited) continue;
            if(!i.second.isconst) continue;
            printf("%s:",i.second.name.c_str());
            for(int j = 0; j < i.second.value.size();j++){
                if(j%8==0){
                    int zeronum = 0;
                    for(int k = j; k < i.second.value.size();k++){
                        if(i.second.value[k] == 0)
                            zeronum++;
                        else
                            break;
                    }
                    if(zeronum >= 16){
                        printf("\n    .zero %d",4*zeronum);
                        j += zeronum - 1;
                    }
                    else{
                        printf("\n    .long %d",i.second.value[j]);
                    }
                }
                else{
                    printf(", %d",i.second.value[j]);
                }
            }
            printf("\n");
        }
    }
    printf(".section .data\n");
    if(vars.vars.size()){
        auto global_vars = vars.vars[0];
        for (auto i : global_vars){
            if(!i.second.isinited) continue;
            if(i.second.isconst) continue;
            printf("%s:",i.second.name.c_str());
            for(int j = 0; j < i.second.value.size();j++){
                if(j%8==0){
                    int zeronum = 0;
                    for(int k = j; k < i.second.value.size();k++){
                        if(i.second.value[k] == 0)
                            zeronum++;
                        else
                            break;
                    }
                    if(zeronum >= 16){
                        printf("\n    .zero %d",4*zeronum);
                        j += zeronum - 1;
                    }
                    else{
                        printf("\n    .long %d",i.second.value[j]);
                    }
                }
                else{
                    printf(", %d",i.second.value[j]);
                }
            }
            printf("\n");
        }
        printf(".section .bss\n");
        for (auto i : global_vars){
            if(i.second.isinited) continue;
            printf("    .lcomm %s, %d\n", i.second.name.c_str(), i.second.size * 4);
        }
    }
    printf(".section .text\n");
    print_ass(root);
}

void AST::print_ass(Node* node){
    for(int i = 0;i<node->children.size();i++){
        print_ass(node->children[i]);
    }
    #ifdef comment
    printf("    # Node %2d:\n",node->id);
    #endif
    for(int i = 0;i<node->ass.size();i++){
        printf("%s\n",node->ass[i].c_str());
    }
}


void AST::debug_node(bool detail){
    fprintf(stderr, "Nodes:\n");
    for(auto node : nodes){
        fprintf(stderr, "\nNode %d: type %s, svalue: %s\n", node->id, debug_names[(int)(node->type)].c_str(), node->svalue.c_str());
        fprintf(stderr, "Children: ");
        for(auto child : node->children){
            fprintf(stderr, "%d ", child->id);
        }
        fprintf(stderr, "\n");
        fprintf(stderr, "Parent: ");
        if(node->parent == nullptr){
            fprintf(stderr, "NULL\n");
        }
        else{
            fprintf(stderr, "%d\n", node->parent->id);
        }
        if(detail){
            debug_ass(node->id);
        }
    }
    fprintf(stderr, "Nodes end.\n\n");
}

void AST::debug_var(){
    fprintf(stderr, "Vars:\n");
    for(int i = 0;i < vars.vars.size(); i++){
        if(vars.vars[i].size() == 0) continue;
        fprintf(stderr, "Range %d:\n", i-1);
        for(auto var : vars.vars[i]){    
            fprintf(stderr, "  Var %s: ", var.first.c_str());
            fprintf(stderr, "    shape: ");
            for(auto shape : var.second.shape){
                fprintf(stderr, "%d ", shape);
            }
            fprintf(stderr, "\n");
            fprintf(stderr, "    value: ");
            for(auto value : var.second.value){
                fprintf(stderr, "%d ", value);
            }
            fprintf(stderr, "\n");
            fprintf(stderr, "    isconst: %d, isinited: %d\n", (int)var.second.isconst, (int)var.second.isinited);
        }
    }
    fprintf(stderr, "vars end.\n\n");
}

void AST::debug_reg(){
    fprintf(stderr, "Regs:\n");
    for(int i =0;i<regnum;i++){
        Reg reg = regs.regs[i];
        fprintf(stderr,"reg%d: %s nodeid:%d time:%d\n",i,reg.isused?"using":"free",reg.nodeid,reg.time);
    }
}

void AST::debug_ass(int x){
    fprintf(stderr,"ASS of Node %d:\n",x);
    Node* node = nodes[x];
    for(int i = 0;i<node->ass.size();i++){
        fprintf(stderr,"str%2d: %s\n",i,node->ass[i].c_str());
    }
    fprintf(stderr,"ASS End.\n");
}