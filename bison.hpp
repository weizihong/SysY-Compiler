/*
 * bison.hpp - structure and simple functions for compiler
 * All of the structures used in bison.cpp are defined here.
 * No direct temp global variables are allowed in this program,
 * all the temp global variables should be defined in the AST
 * structure. This means that we can build and compile multiple
 * ASTs in one program without any conflicts(though it is not
 * necessary).
 */
#ifndef BISON_HPP
#define BISON_HPP

#include <vector>
#include <string>
#include <map>
#include <array>
#include <initializer_list>

#define regnum 14 //regnum can't be more than 14

struct AST;

//必须让逻辑相关的Exp等放到BoolExp后，且这些位于最后，有一处代码比较了int值
enum class NType{
    kint, kvoid, kif, kwhile, kbreak, kcontinue, kreturn, 
    opadd, opmul, oprel, opeq, oplnot,
    Ident, Number, HeaderStmt, String, Address,
    Root, Stmt, Lval, Exps, BlockItems, Exp, Cond, ASS,
    ConstDecl, VarDecl, VarDefs, VarDef, InitVals,
    FuncDef, FuncFParams, FuncFParam, FuncRParams,
    UnaryExp, MulExp, AddExp, 
    BoolExp, RelExp, EqExp, LAndExp, LOrExp
};

struct Node {
    int id;
    Node* parent;
    std::vector<Node*> children;
    NType type;
    std::string svalue;
    int ivalue;
    std::vector<std::string> ass;
};

struct Var{
    std::string name;
    std::vector<int> shape;
    std::vector<int> value;
    int offset;
    int range;
    int type; //0:pointer, 1:int, 2:array
    bool isconst;
    bool isinited;
    int size;
};

struct VarList{
    std::vector<std::map<std::string, Var>> vars;
    void insert(Var &var, std::string name, int range);
    bool find(std::string name, int range);
    Var* find(std::string name);
};

struct Func{
    std::vector<std::vector<int>> paramstype;
    int returntype;//0: void, 1: int
    int call = 0;//0: no stdcall, 1: stdcall
    int offset = 0;
    int retl = -1;
    int range;
    int maxstack = 0;
};

struct Reg{
    bool isused = false;
    int nodeid;
    int time;
};

struct RegList{
    std::array<Reg,regnum> regs;
    enum class Reg32{
        eax, ebx, ecx, edx, esi, edi, r8d, r9d, r10d, r11d, r12d, r13d, r14d, r15d
    };
    enum class Reg64{
        rax, rbx, rcx, rdx, rsi, rdi, r8, r9, r10, r11, r12, r13, r14, r15
    };
    static const std::string reg32_name[14];
    static const std::string reg64_name[14];
    int request(AST* AST, Node* ASS, int id);
    void free(int reg);
    void force_get(AST* AST, Node* ASS, int id, int reg);
    void save(Node* node);
    void load(Node* node);
    bool isempty();
    void clear();
    std::string reg32_64(std::string regname);
};

struct Range{
    int id;
    int value[2];
};

struct RangeList{
    std::vector<Range> ranges;
    void push_back(Range range);
    void push_back(int range);
    Range pop_back(VarList &vars);
    Range back();
};

struct AST{
    static const std::string debug_names[43];
    std::vector<Node*> nodes;
    Node* root = nullptr;
    int size = 0;
    bool error = false;
    int add_node(NType type);
    Node* add_node_(NType type);
    int add_node(NType type, std::string value);
    void add_edge(int parent, int child);
    void add_edges(int parent, std::initializer_list<int> children);
    int error_node();
    void set_root(int root);
    VarList vars;
    std::vector<std::string> strs;
    std::map<std::string, Func*> funcs;
    RangeList ranges;
    RegList regs;
    int Lcount = 0;
    int Rcount = 0;
    Func* curfunc;
    int curstack;
    std::string start;
    bool message[16];
    void global_compile();
    void func_compile(Node* funcdef);
    void block_compile(Node* blockitems, bool is_func);
    void stmt_compile(Node* stmt, bool is_last);
    bool is_const(Node* constexp);
    int cal_const(Node* constexp);
    int set_var(Var &var, Node* node, int depth, int offset);
    void make_cond(Node* cond, int ltruel, int lfalse, int next);
    void cal_offset(Node* Lval, bool allow_array);
    std::string get_Lval(Node* node, Node* Lval, bool is_left);
    void free_Lval(Node* Lval);
    void eval_exp(Node* node, bool need_res);
    std::string get_exp(Node* node, Node* exp, int need_reg); //need_reg: 0:no limit, 1:number or reg 2:reg
    inline void free_exp(Node* exp); 
    bool part_array(Node* Lval, Func* func, int i);
    void simple_ass(Node* ass, Node* left, Node* right, char oper);
    void simple_ass(Node* ass, Node* left, int right, char oper);
    void debug_node(bool detail);
    void debug_var();
    void debug_reg();
    void debug_ass(int x);
    void print_ass();
    void print_ass(Node* node);
};

#endif