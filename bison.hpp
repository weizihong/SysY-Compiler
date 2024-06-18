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

#define regnum 14 //使用的寄存器数量，不得超过14，较小时（如小于6，具体边界未测定）可能出现各种异常

struct AST;

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
    /* exp的svalue表示其结果所在位置，如"$1","%eax","onstack", 终结符的svalue表示字符串具体内容。
       svalue同时也被用于寄存器管理与回收，当exp结果所在的寄存器被占用时，svalue的值也会对应修改 */
    std::string svalue;
    /* 作为svalue的辅助信息，简化运算，如$1对应的ivalue为1，%eax对应的ivalue为0(寄存器编号)，
       onstack对应的ivalue为临时变量入栈顺序(本代码中临时变量出栈只能用pop,ivalue用于检查临时变量位于
       栈顶) */
    int ivalue;
    /* 存储汇编代码，在语法树上以后序遍历输出汇编。
       需要强调的是，汇编代码放到哪个节点，取决于哪个节点期间进行了这一操作，而不是哪个节点受到影响：
       比如123号节点调用124号节点的数据，124号节点中的立即数被放入了寄存器ebx，而寄存器空间不够，
       112号节点在ebx内的数据被迫入栈，那么112的数据入栈和124的数据放入寄存器，都应该写在123节点的
       ass里，这也是本代码很多函数传参会传一个ASS Node（部分变量名为node的也是ASS Node)的原因。*/
    std::vector<std::string> ass;
};

struct Var{
    std::string name;
    std::vector<int> shape;
    std::vector<int> value;
    int offset; //作为局部变量时使用，记录数组起始位置
    int range; //作用域。在本代码中，range是用node->id直接赋值（全局例外，range为-1）
    int type; //0:pointer, 1:int, 2:array
    bool isconst;
    bool isinited; //作为全局变量时使用，记录数组位于bss段还是.data段
    int size; //字节数(单位为4字节)，不是元素数，虽然一般可以混用
};

struct VarList{
    //外层为按range+1索引（毕竟有个range是-1）的数组，内层为map
    std::vector<std::map<std::string, Var>> vars;
    void insert(Var &var, std::string name, int range);
    bool find(std::string name, int range);
    Var* find(std::string name);
};

struct Func{
    //函数参数只有数和数组，因此存储每个参数的每个维度大小
    std::vector<std::vector<int>> paramstype;
    int returntype; //0: void, 1: int
    int offset = 0; //记录其中所有局部变量的总偏移
    int retl = -1; //函数的return执行方式为设置%eax后跳转到leave ret，retl为leave ret的Label编号，如果不需要跳转则不生成label
    int range; //作用域
};

struct Reg{
    bool isused = false;
    int nodeid;
    /*指令的操作数一般为两个，如果临时变量因等待后续计算而入栈，那么只能是a op ( b op ( c op ...
      这种形式，因此按照 *后进先出* 的规则管理; 操作数为3个的指令，在本代码中会在创建第三个寄存器后尽快
      执行运算，创建和运算之间其他操作占用的寄存器数量有限，第三个寄存器不会入栈*/
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
    int request(AST* AST, Node* ASS, int id); //寄存器由id对应的node使用，这一操作的汇编存储于ASS
    void free(int reg);
    void force_get(AST* AST, Node* ASS, int id, int reg); //强制获取指定的寄存器给id对应的node，如果其中有数据，会被挪到空闲处,产生的汇编存储于ASS
    void save(Node* node); //调用函数时寄存器入栈，这一操作的汇编存储于node
    void load(Node* node); //调用函数结束时寄存器恢复，这一操作的汇编存储于node
    bool isempty();
    void clear();
    std::string reg32_64(std::string regname); //32位寄存器名称转至64位名称，非合法寄存器名称返回原值
};

struct Range{
    int id;
    int value[2]; //value仅用于while语句
};

struct RangeList{
    std::vector<Range> ranges;
    void push_back(Range range);
    void push_back(int range);
    Range pop_back(VarList &vars); //pop时自动清理vars中对应的变量（别pop全局定义域!)
    Range back();
};

struct AST{
    static const std::string debug_names[43]; //NType转String，用于输出报错信息
    std::vector<Node*> nodes; //节点列表，提供了使用id访问Node的接口
    Node* root = nullptr; 
    int size = 0; //节点数量
    bool error = false; //语法阶段出错后置为true，后续语法分析时不再创建语法树
    int add_node(NType type); //语法阶段创建节点用，返回节点id
    Node* add_node_(NType type); //语义阶段创建节点用
    int add_node(NType type, std::string value);
    void add_edge(int parent, int child); //会导致child为parent的最后一个子节点，如果需要在其他位置插入，需手动使用emplace(并设置parent)
    void add_edges(int parent, std::initializer_list<int> children);
    int error_node(); //语义阶段出错后调用，设置error并返回id=-1
    void set_root(int root);
    VarList vars; //变量表
    std::vector<std::string> strs; //字符串表，存储printf和scanf的字符串参数
    std::map<std::string, Func*> funcs; //函数表
    RangeList ranges; //作用域表
    RegList regs; //寄存器表
    int Lcount = 0; //Label计数
    int Rcount = 0; //Reg.time计数
    Func* curfunc; //当前函数
    int curstack; //当前栈中临时变量数量
    bool message[16]; //某些时候需要跨函数返回信息，但不想大改代码(0在全局数组初始化时使用，1-4在函数传参时使用，其它未使用)，构思借鉴了linux的报错机制
    void global_compile();
    void func_compile(Node* funcdef);
    void block_compile(Node* blockitems, bool is_func); //is_func:是否为函数体，在range表中不同处理
    void stmt_compile(Node* stmt, bool is_last); //is_last:是否为函数的最后一个stmt(优化用，未知则设为false)
    bool is_const(Node* constexp);
    int cal_const(Node* constexp);
    int set_var(Var &var, Node* node, int depth, int offset);
    void make_cond(Node* cond, int ltrue, int lfalse, int next); //next:判断结束后是true分支(next=1)还是false分支(next=-1)(优化用，未知则next=0)
    /*为避免嵌套计算导致寄存器使用出现问题，本代码的Lval和exp均按照 *计算-取用-释放* 方式使用，取用与释放间其他操作使用的寄存器数量有限*/
    void cal_offset(Node* Lval, bool allow_array); //allow_array:设置后逻辑有小幅变动，数组传参时的特殊处理
    std::string get_Lval(Node* node, Node* Lval, bool is_left); //is_left:是否为左值，为true时一定返回地址
    void free_Lval(Node* Lval);
    void eval_exp(Node* node, bool need_res); //need_res:是否需要返回值(优化用，未知则设为true)
    std::string get_exp(Node* node, Node* exp, int need_reg); //need_reg: 对返回值的要求(0:no limit, 1:number or reg 2:reg)
    inline void free_exp(Node* exp); 
    bool part_array(Node* Lval, Func* func, int i); //判断传参时参数是否为数组，以及长度是否匹配
    void simple_ass(Node* ass, Node* left, Node* right, char oper); //加减乘除的底层实现
    void simple_ass(Node* ass, Node* left, int right, char oper); //仅实现了加乘，别的用不到
    void debug_node(bool detail);
    void debug_var();
    void debug_reg();
    void debug_ass(int x);
    void print_ass();
    void print_ass(Node* node);
};

#endif