/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 17 "bison.y"

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

/* Line 371 of yacc.c  */
#line 87 "bison.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.tab.h".  */
#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     kconst_ = 258,
     kint_ = 259,
     kvoid_ = 260,
     kif_ = 261,
     kelse_ = 262,
     kwhile_ = 263,
     kbreak_ = 264,
     kcontinue_ = 265,
     kreturn_ = 266,
     Ident_ = 267,
     Number_ = 268,
     ErrIdent_ = 269,
     HeaderStmt_ = 270,
     String_ = 271,
     opadd_ = 272,
     opmul_ = 273,
     oprel_ = 274,
     opeq_ = 275,
     opland_ = 276,
     oplor_ = 277,
     unknown_ = 278
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 54 "bison.y"

    char* str;
    int id;


/* Line 387 of yacc.c  */
#line 159 "bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 187 "bison.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,     2,     2,     2,    34,     2,
      29,    30,     2,     2,    24,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
       2,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    22,    24,    27,    29,    31,    33,    35,    38,    41,
      43,    45,    50,    54,    58,    60,    65,    69,    74,    78,
      80,    83,    87,    91,    93,    97,   101,   105,   107,   109,
     112,   116,   121,   123,   126,   130,   134,   136,   142,   149,
     155,   162,   166,   170,   174,   176,   179,   184,   190,   195,
     199,   202,   206,   209,   211,   213,   215,   220,   222,   225,
     227,   233,   241,   247,   250,   253,   256,   260,   263,   265,
     267,   269,   272,   276,   278,   280,   283,   285,   290,   294,
     297,   299,   303,   305,   307,   309,   311,   313,   317,   319,
     323,   325,   328,   330,   334,   336,   340,   342,   346,   348,
     352
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    12,    -1,    13,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    44,
      45,    -1,    45,    -1,    44,     1,    -1,     1,    -1,    46,
      -1,    58,    -1,    38,    -1,     1,    62,    -1,     1,    25,
      -1,    47,    -1,    53,    -1,     3,     4,    48,    25,    -1,
       3,     1,    25,    -1,    48,    24,    49,    -1,    49,    -1,
      36,    50,    26,    51,    -1,    36,    26,    51,    -1,    50,
      31,    82,    32,    -1,    31,    82,    32,    -1,    82,    -1,
      27,    28,    -1,    27,    52,    28,    -1,    52,    24,    51,
      -1,    51,    -1,     4,    54,    25,    -1,     4,     1,    25,
      -1,    54,    24,    55,    -1,    55,    -1,    36,    -1,    36,
      50,    -1,    36,    26,    56,    -1,    36,    50,    26,    56,
      -1,    66,    -1,    27,    28,    -1,    27,    57,    28,    -1,
      57,    24,    56,    -1,    56,    -1,     5,    36,    29,    30,
      62,    -1,     5,    36,    29,    59,    30,    62,    -1,     4,
      36,    29,    30,    62,    -1,     4,    36,    29,    59,    30,
      62,    -1,     4,     1,    62,    -1,     5,     1,    62,    -1,
      59,    24,    60,    -1,    60,    -1,     4,    36,    -1,     4,
      36,    31,    32,    -1,     4,    36,    31,    32,    61,    -1,
      61,    31,    66,    32,    -1,    31,    66,    32,    -1,    27,
      28,    -1,    27,    63,    28,    -1,    63,    64,    -1,    64,
      -1,    46,    -1,    65,    -1,    68,    26,    66,    25,    -1,
      25,    -1,    66,    25,    -1,    62,    -1,     6,    29,    67,
      30,    65,    -1,     6,    29,    67,    30,    65,     7,    65,
      -1,     8,    29,    67,    30,    65,    -1,     9,    25,    -1,
      10,    25,    -1,    11,    25,    -1,    11,    66,    25,    -1,
       1,    25,    -1,    81,    -1,    81,    -1,    36,    -1,    36,
      61,    -1,    29,    81,    30,    -1,    68,    -1,    37,    -1,
      34,    68,    -1,    69,    -1,    36,    29,    73,    30,    -1,
      36,    29,    30,    -1,    72,    71,    -1,    40,    -1,    73,
      24,    74,    -1,    74,    -1,    66,    -1,    39,    -1,    70,
      -1,    71,    -1,    75,    41,    71,    -1,    75,    -1,    76,
      40,    75,    -1,    76,    -1,    23,    71,    -1,    77,    -1,
      78,    42,    77,    -1,    78,    -1,    79,    43,    78,    -1,
      79,    -1,    80,    21,    79,    -1,    80,    -1,    81,    22,
      80,    -1,    76,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    65,    66,    72,    73,    74,    75,    76,
      79,    80,    81,    82,    85,    86,    87,    88,    89,    92,
      93,    96,    97,   100,   101,   104,   105,   108,   109,   112,
     113,   114,   117,   118,   121,   122,   125,   126,   129,   130,
     131,   132,   135,   136,   137,   140,   141,   144,   145,   146,
     147,   148,   149,   152,   153,   156,   157,   158,   161,   162,
     165,   166,   169,   170,   173,   174,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   191,   194,
     197,   198,   201,   202,   203,   206,   209,   210,   211,   212,
     215,   218,   219,   222,   223,   224,   227,   228,   231,   232,
     235,   236,   239,   240,   243,   244,   247,   248,   251,   252,
     254
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "kconst_", "kint_", "kvoid_", "kif_",
  "kelse_", "kwhile_", "kbreak_", "kcontinue_", "kreturn_", "Ident_",
  "Number_", "ErrIdent_", "HeaderStmt_", "String_", "opadd_", "opmul_",
  "oprel_", "opeq_", "opland_", "oplor_", "'!'", "','", "';'", "'='",
  "'{'", "'}'", "'('", "')'", "'['", "']'", "unknown_", "'&'", "$accept",
  "Ident__", "Number__", "HeaderStmt__", "String__", "opadd__", "opmul__",
  "oprel__", "opeq__", "CompUnit_", "OtherCompUnit_", "Decl_",
  "ConstDecl_", "ConstDefs_", "ConstDef_", "ConstExps_", "ConstInitVal_",
  "ConstInitVals_", "VarDecl_", "VarDefs_", "VarDef_", "InitVal_",
  "InitVals_", "FuncDef_", "FuncFParams_", "FuncFParam_", "Exps_",
  "Block_", "BlockItems_", "BlockItem_", "Stmt_", "Exp_", "Cond_", "LVal_",
  "PrimaryExp_", "Address_", "UnaryExp_", "UnaryOp_", "FuncRParams_",
  "FuncRParam_", "MulExp_", "AddExp_", "BoolExp_", "RelExp_", "EqExp_",
  "LAndExp_", "LOrExp_", "ConstExp_", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    33,    44,    59,    61,   123,   125,    40,
      41,    91,    93,   278,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    44,    44,    44,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      55,    55,    56,    56,    56,    57,    57,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      68,    68,    69,    69,    69,    70,    71,    71,    71,    71,
      72,    73,    73,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     2,     2,     1,
       1,     4,     3,     3,     1,     4,     3,     4,     3,     1,
       2,     3,     3,     1,     3,     3,     3,     1,     1,     2,
       3,     4,     1,     2,     3,     3,     1,     5,     6,     5,
       6,     3,     3,     3,     1,     2,     4,     5,     4,     3,
       2,     3,     2,     1,     1,     1,     4,     1,     2,     1,
       5,     7,     5,     2,     2,     2,     3,     2,     1,     1,
       1,     2,     3,     1,     1,     2,     1,     4,     3,     2,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,     0,     0,     0,     4,    16,     0,    11,    14,
      19,    20,    15,    18,     0,    17,     0,     0,     0,     2,
      38,     0,    37,     0,     0,     1,    12,    10,     0,     0,
       0,     0,     0,     0,     0,     3,     6,     0,    67,    60,
       0,    80,    84,    90,    64,    69,     0,    63,    65,     0,
      83,    86,    96,     0,    98,   100,   102,   104,   106,   108,
      78,    22,     0,     0,    24,    35,    51,     0,     0,     0,
      39,     0,    34,    52,     0,    77,     0,    38,     0,     0,
      73,    74,    75,     0,    83,   101,     0,     0,     0,    81,
      61,    62,    68,     0,    89,     7,     0,     0,     8,     0,
       9,     0,     0,     0,     0,     0,     0,    21,     0,    40,
      42,     0,     0,     0,    54,   110,     0,     0,     0,    36,
       0,     0,     0,    79,     0,    76,    82,     5,    88,     0,
      94,    93,    95,     0,    92,     0,     0,     0,    97,    99,
     103,   105,   107,   109,     0,    26,    29,     0,    23,    43,
      46,     0,    55,    49,     0,     0,    28,    41,     0,    47,
       0,     0,     0,    80,    85,     0,    87,    59,     0,    66,
      30,    33,     0,    25,     0,    44,     0,    53,    50,    27,
      48,    70,    72,    91,    58,     0,    31,    45,    56,     0,
      32,    57,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    41,    42,     6,   130,    43,    96,    99,   101,     7,
       8,     9,    10,    63,    64,    70,   145,   172,    11,    21,
      22,   109,   151,    12,   113,   114,    89,    45,    46,    47,
      48,    49,   122,    84,    51,   132,    52,    53,   133,   134,
      54,    55,    56,    57,    58,    59,    60,   146
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -146
static const yytype_int16 yypact[] =
{
     245,    39,    33,    21,    27,  -146,  -146,   239,  -146,  -146,
    -146,  -146,  -146,  -146,   153,  -146,    58,    15,    47,  -146,
      67,   119,  -146,    79,    -5,  -146,    39,  -146,    86,    29,
      87,   100,   107,   113,   203,  -146,  -146,   155,  -146,  -146,
     224,    71,  -146,  -146,  -146,  -146,   182,  -146,  -146,   115,
     104,  -146,  -146,   155,   131,   133,  -146,   139,   132,   148,
     149,  -146,    19,   121,  -146,  -146,  -146,   206,    10,   155,
      51,    15,  -146,  -146,    16,  -146,   152,    66,   224,   224,
    -146,  -146,  -146,   154,  -146,  -146,    -1,   105,   224,   142,
    -146,  -146,  -146,   224,  -146,  -146,   155,   155,  -146,   224,
    -146,   224,   224,   224,   124,    68,    15,  -146,   185,  -146,
    -146,    15,    79,    12,  -146,   133,   157,   206,   155,  -146,
      79,    30,   144,   149,   166,  -146,  -146,  -146,  -146,    15,
    -146,  -146,  -146,    41,  -146,   168,   224,   162,  -146,   131,
    -146,   139,   132,   148,    97,  -146,  -146,   124,  -146,  -146,
    -146,    23,   170,  -146,   199,    79,  -146,  -146,   172,  -146,
      79,    78,    78,   175,  -146,    46,  -146,  -146,   189,  -146,
    -146,  -146,    99,  -146,   206,  -146,   190,  -146,  -146,  -146,
    -146,   210,  -146,  -146,  -146,   124,  -146,  -146,   175,    78,
    -146,   142,  -146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,     2,  -146,  -146,  -146,   -48,  -146,  -146,  -146,  -146,
     217,    -3,  -146,  -146,   125,   163,  -132,  -146,  -146,  -146,
     156,  -104,  -146,  -146,   160,    76,    50,     0,  -146,   205,
    -145,   -32,   173,   -14,  -146,  -146,   -28,  -146,  -146,    80,
     158,   -66,   159,   161,   164,   165,   -30,   -61
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      50,    15,    83,   115,   150,    20,    24,    97,   116,    85,
      86,    44,   171,   157,   111,   173,   181,   182,    66,    62,
     111,   103,    18,    73,    74,    94,    15,    19,    23,   126,
      76,    77,    50,    19,    16,   110,   154,    17,   115,    19,
     112,    19,   155,    44,   192,   104,   120,   174,   123,   123,
      69,   175,   115,   190,   154,   131,   135,   158,    19,    35,
     160,   137,   127,    36,    13,   165,    14,    97,   138,    37,
     187,   166,    65,    77,    14,    40,   110,   117,   115,    28,
     129,   115,   118,    61,    30,   110,    31,    32,    33,    34,
      19,    35,    67,    67,   147,    36,    68,    69,    69,   118,
      87,    37,    88,    38,   168,    14,    14,    40,    62,    19,
      35,    75,   153,   152,    36,   164,    78,    19,    35,   115,
     159,   127,    36,   185,   144,   170,    40,   186,    37,    79,
      93,   163,    80,   131,    40,   128,    19,    35,    81,   129,
      92,    36,   110,    71,    72,   106,   107,    50,    50,    95,
      36,   144,   100,    40,    28,   178,     2,    29,    98,    30,
     180,    31,    32,    33,    34,    19,    35,    19,    35,   102,
      36,   103,    36,   136,   161,    50,    37,    65,    38,   125,
      14,    39,    40,    28,    40,     2,    29,   169,    30,   156,
      31,    32,    33,    34,    19,    35,   162,    19,    35,    36,
     167,   176,    36,   111,   179,    37,    88,    38,    37,    14,
      90,    40,   108,   149,    40,    19,    35,   189,    19,    35,
      36,   184,   188,    36,    27,   105,    37,   119,    82,    37,
     177,   148,    40,   108,   121,    40,    19,    35,   191,    25,
      26,    36,     2,     3,     4,   183,     1,    37,     2,     3,
       4,    91,   124,    40,     5,   139,     0,     0,   140,     0,
       5,     0,   141,     0,     0,     0,   142,     0,   143
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      14,     1,    34,    69,   108,     3,     4,    55,    69,    37,
      40,    14,   144,   117,     4,   147,   161,   162,    18,    17,
       4,    22,     1,    23,    29,    53,    26,    12,     1,    30,
       1,    29,    46,    12,     1,    67,    24,     4,   104,    12,
      30,    12,    30,    46,   189,    26,    30,    24,    78,    79,
      31,    28,   118,   185,    24,    87,    88,   118,    12,    13,
      30,    93,    16,    17,    25,    24,    27,   115,    96,    23,
     174,    30,    25,    71,    27,    29,   108,    26,   144,     1,
      34,   147,    31,    25,     6,   117,     8,     9,    10,    11,
      12,    13,    26,    26,    26,    17,    29,    31,    31,    31,
      29,    23,    31,    25,   136,    27,    27,    29,   106,    12,
      13,    25,   112,   111,    17,   129,    29,    12,    13,   185,
     120,    16,    17,    24,    27,    28,    29,    28,    23,    29,
      26,   129,    25,   165,    29,    30,    12,    13,    25,    34,
      25,    17,   174,    24,    25,    24,    25,   161,   162,    18,
      17,    27,    20,    29,     1,   155,     3,     4,    19,     6,
     160,     8,     9,    10,    11,    12,    13,    12,    13,    21,
      17,    22,    17,    31,    30,   189,    23,    25,    25,    25,
      27,    28,    29,     1,    29,     3,     4,    25,     6,    32,
       8,     9,    10,    11,    12,    13,    30,    12,    13,    17,
      32,    31,    17,     4,    32,    23,    31,    25,    23,    27,
      28,    29,    27,    28,    29,    12,    13,     7,    12,    13,
      17,    32,    32,    17,     7,    62,    23,    71,    25,    23,
     154,   106,    29,    27,    74,    29,    12,    13,   188,     0,
       1,    17,     3,     4,     5,   165,     1,    23,     3,     4,
       5,    46,    79,    29,    15,    97,    -1,    -1,    99,    -1,
      15,    -1,   101,    -1,    -1,    -1,   102,    -1,   103
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,    15,    38,    44,    45,    46,
      47,    53,    58,    25,    27,    62,     1,     4,     1,    12,
      36,    54,    55,     1,    36,     0,     1,    45,     1,     4,
       6,     8,     9,    10,    11,    13,    17,    23,    25,    28,
      29,    36,    37,    40,    46,    62,    63,    64,    65,    66,
      68,    69,    71,    72,    75,    76,    77,    78,    79,    80,
      81,    25,    36,    48,    49,    25,    62,    26,    29,    31,
      50,    24,    25,    62,    29,    25,     1,    36,    29,    29,
      25,    25,    25,    66,    68,    71,    81,    29,    31,    61,
      28,    64,    25,    26,    71,    18,    41,    40,    19,    42,
      20,    43,    21,    22,    26,    50,    24,    25,    27,    56,
      66,     4,    30,    59,    60,    76,    82,    26,    31,    55,
      30,    59,    67,    81,    67,    25,    30,    16,    30,    34,
      39,    66,    70,    73,    74,    66,    31,    66,    71,    75,
      77,    78,    79,    80,    27,    51,    82,    26,    49,    28,
      56,    57,    36,    62,    24,    30,    32,    56,    82,    62,
      30,    30,    30,    36,    68,    24,    30,    32,    66,    25,
      28,    51,    52,    51,    24,    28,    31,    60,    62,    32,
      62,    65,    65,    74,    32,    24,    28,    56,    32,     7,
      51,    61,    65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 64 "bison.y"
    {(yyval.id) = tree.add_node(NType::Ident, std::string((yyvsp[(1) - (1)].str))); free((yyvsp[(1) - (1)].str));}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 65 "bison.y"
    {(yyval.id) = tree.add_node(NType::Number, std::string((yyvsp[(1) - (1)].str))); free((yyvsp[(1) - (1)].str));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 66 "bison.y"
    {
    char *begin = strchr((yyvsp[(1) - (1)].str), '<')+1;
    char *end = strrchr((yyvsp[(1) - (1)].str), '>');
    (yyval.id) = tree.add_node(NType::HeaderStmt, std::string(begin, end-begin));
    free((yyvsp[(1) - (1)].str));
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 72 "bison.y"
    {(yyval.id) = tree.add_node(NType::String, std::string((yyvsp[(1) - (1)].str))); free((yyvsp[(1) - (1)].str));}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 73 "bison.y"
    {(yyval.id) = tree.add_node(NType::opadd, std::string((yyvsp[(1) - (1)].str))); free((yyvsp[(1) - (1)].str));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 74 "bison.y"
    {(yyval.id) = tree.add_node(NType::opmul, std::string((yyvsp[(1) - (1)].str))); free((yyvsp[(1) - (1)].str));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 75 "bison.y"
    {(yyval.id) = tree.add_node(NType::oprel, std::string((yyvsp[(1) - (1)].str))); free((yyvsp[(1) - (1)].str));}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 76 "bison.y"
    {(yyval.id) = tree.add_node(NType::opeq, std::string((yyvsp[(1) - (1)].str))); free((yyvsp[(1) - (1)].str));}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 79 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (2)].id); tree.add_edge((yyval.id), (yyvsp[(2) - (2)].id));}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 80 "bison.y"
    {(yyval.id) = tree.add_node(NType::Root); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id)); tree.set_root((yyval.id));}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 81 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr, "Wrong CompUnit_\n\n");}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 82 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr, "Wrong CompUnit_\n\n");}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 85 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 86 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 87 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 88 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr,"Wrong CompUnit_(may be FuncDef_)\n\n");}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 89 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr,"Wrong CompUnit_(may be Decl_)\n\n");}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 92 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 93 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 96 "bison.y"
    {(yyval.id) = tree.add_node(NType::ConstDecl); tree.add_edges((yyval.id), {tree.add_node(NType::kint), (yyvsp[(3) - (4)].id)});}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 97 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr, "Wrong ConstDecl_\n\n");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 100 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (3)].id); tree.add_edge((yyval.id), (yyvsp[(3) - (3)].id));}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 101 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDefs); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 104 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDef); tree.add_edges((yyval.id), {(yyvsp[(1) - (4)].id), (yyvsp[(2) - (4)].id), (yyvsp[(4) - (4)].id)});}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 105 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDef); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id)});}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 108 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (4)].id); tree.add_edge((yyval.id), (yyvsp[(3) - (4)].id));}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 109 "bison.y"
    {(yyval.id) = tree.add_node(NType::Exps); tree.add_edge((yyval.id), (yyvsp[(2) - (3)].id));}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 112 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 113 "bison.y"
    {(yyval.id) = tree.add_node(NType::InitVals);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 114 "bison.y"
    {(yyval.id) = (yyvsp[(2) - (3)].id);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 117 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (3)].id); tree.add_edge((yyval.id), (yyvsp[(3) - (3)].id));}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 118 "bison.y"
    {(yyval.id) = tree.add_node(NType::InitVals); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 121 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDecl); tree.add_edges((yyval.id), {tree.add_node(NType::kint), (yyvsp[(2) - (3)].id)});}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 122 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr,"Wrong Vardef in VarDecline\n\n");}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 125 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (3)].id); tree.add_edge((yyval.id), (yyvsp[(3) - (3)].id));}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 126 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDefs); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 129 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDef); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 130 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDef); tree.add_edges((yyval.id), {(yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].id)});}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 131 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDef); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id)});}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 132 "bison.y"
    {(yyval.id) = tree.add_node(NType::VarDef); tree.add_edges((yyval.id), {(yyvsp[(1) - (4)].id), (yyvsp[(2) - (4)].id), (yyvsp[(4) - (4)].id)});}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 135 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 136 "bison.y"
    {(yyval.id) = tree.add_node(NType::InitVals);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 137 "bison.y"
    {(yyval.id) = (yyvsp[(2) - (3)].id);}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 140 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (3)].id); tree.add_edge((yyval.id), (yyvsp[(3) - (3)].id));}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 141 "bison.y"
    {(yyval.id) = tree.add_node(NType::InitVals); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 144 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncDef); tree.add_edges((yyval.id), {tree.add_node(NType::kvoid), (yyvsp[(2) - (5)].id), (yyvsp[(5) - (5)].id)});}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 145 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncDef); tree.add_edges((yyval.id), {tree.add_node(NType::kvoid), (yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].id), (yyvsp[(6) - (6)].id)});}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 146 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncDef); tree.add_edges((yyval.id), {tree.add_node(NType::kint), (yyvsp[(2) - (5)].id), (yyvsp[(5) - (5)].id)});}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 147 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncDef); tree.add_edges((yyval.id), {tree.add_node(NType::kint), (yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].id), (yyvsp[(6) - (6)].id)});}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 148 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr, "Wrong FuncDef_\n\n");}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 149 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr, "Wrong FuncDef_\n\n");}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 152 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (3)].id); tree.add_edge((yyval.id), (yyvsp[(3) - (3)].id));}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 153 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncFParams); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 156 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncFParam); tree.add_edges((yyval.id), {tree.add_node(NType::kint), (yyvsp[(2) - (2)].id)});}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 157 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncFParam); tree.add_edges((yyval.id), {tree.add_node(NType::kint), (yyvsp[(2) - (4)].id), tree.add_node(NType::Exps)});}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 158 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncFParam); tree.add_edges((yyval.id), {tree.add_node(NType::kint), (yyvsp[(2) - (5)].id), (yyvsp[(5) - (5)].id)});}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 161 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (4)].id); tree.add_edge((yyval.id), (yyvsp[(3) - (4)].id));}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 162 "bison.y"
    {(yyval.id) = tree.add_node(NType::Exps); tree.add_edge((yyval.id), (yyvsp[(2) - (3)].id));}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 165 "bison.y"
    {(yyval.id) = tree.add_node(NType::BlockItems);}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 166 "bison.y"
    {(yyval.id) = (yyvsp[(2) - (3)].id);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 169 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (2)].id); tree.add_edge((yyval.id), (yyvsp[(2) - (2)].id));}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 170 "bison.y"
    {(yyval.id) = tree.add_node(NType::BlockItems); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 173 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 174 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 177 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edges((yyval.id), {(yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].id)});}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 178 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt);}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 179 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edge((yyval.id), (yyvsp[(1) - (2)].id));}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 180 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 181 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edges((yyval.id), {tree.add_node(NType::kif), (yyvsp[(3) - (5)].id), (yyvsp[(5) - (5)].id)});}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 182 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edges((yyval.id), {tree.add_node(NType::kif), (yyvsp[(3) - (7)].id), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].id)});}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 183 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edges((yyval.id), {tree.add_node(NType::kwhile), (yyvsp[(5) - (5)].id), (yyvsp[(3) - (5)].id)});}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 184 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edge((yyval.id), tree.add_node(NType::kbreak));}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 185 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edge((yyval.id), tree.add_node(NType::kcontinue));}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 186 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edge((yyval.id), tree.add_node(NType::kreturn));}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 187 "bison.y"
    {(yyval.id) = tree.add_node(NType::Stmt); tree.add_edges((yyval.id), {tree.add_node(NType::kreturn), (yyvsp[(2) - (3)].id)});}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 188 "bison.y"
    {(yyval.id) = tree.error_node(); fprintf(stderr, "Wrong Stmt_\n\n");}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 191 "bison.y"
    {(yyval.id) = tree.add_node(NType::Exp); tree.add_edges((yyval.id), {(yyvsp[(1) - (1)].id)});}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 194 "bison.y"
    {(yyval.id) = tree.add_node(NType::Cond); tree.add_edges((yyval.id), {(yyvsp[(1) - (1)].id)});}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 197 "bison.y"
    {(yyval.id) = tree.add_node(NType::Lval); tree.add_edges((yyval.id), {(yyvsp[(1) - (1)].id)});}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 198 "bison.y"
    {(yyval.id) = tree.add_node(NType::Lval); tree.add_edges((yyval.id), {(yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].id)});}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 201 "bison.y"
    {(yyval.id) = (yyvsp[(2) - (3)].id);}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 202 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 203 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 206 "bison.y"
    {(yyval.id) = tree.add_node(NType::Address); tree.add_edge((yyval.id), (yyvsp[(2) - (2)].id));}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 209 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 210 "bison.y"
    {(yyval.id) = tree.add_node(NType::UnaryExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].id)});}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 211 "bison.y"
    {(yyval.id) = tree.add_node(NType::UnaryExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), tree.add_node(NType::FuncRParams)});}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 212 "bison.y"
    {(yyval.id) = tree.add_node(NType::UnaryExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].id)});}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 215 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 218 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (3)].id); tree.add_edge((yyval.id), (yyvsp[(3) - (3)].id));}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 219 "bison.y"
    {(yyval.id) = tree.add_node(NType::FuncRParams); tree.add_edge((yyval.id), (yyvsp[(1) - (1)].id));}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 222 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 223 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 224 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 227 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 228 "bison.y"
    {(yyval.id) = tree.add_node(NType::MulExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].id)});}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 231 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 232 "bison.y"
    {(yyval.id) = tree.add_node(NType::AddExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].id)});}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 235 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 236 "bison.y"
    {(yyval.id) = tree.add_node(NType::BoolExp); tree.add_edges((yyval.id), {tree.add_node(NType::oplnot), (yyvsp[(2) - (2)].id)});}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 239 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 240 "bison.y"
    {(yyval.id) = tree.add_node(NType::RelExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].id)});}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 243 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 244 "bison.y"
    {(yyval.id) = tree.add_node(NType::EqExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].id)});}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 247 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 248 "bison.y"
    {(yyval.id) = tree.add_node(NType::LAndExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id)});}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 251 "bison.y"
    {(yyval.id) = (yyvsp[(1) - (1)].id);}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 252 "bison.y"
    {(yyval.id) = tree.add_node(NType::LOrExp); tree.add_edges((yyval.id), {(yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id)});}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 254 "bison.y"
    {(yyval.id) = tree.add_node(NType::Exp); tree.add_edges((yyval.id), {(yyvsp[(1) - (1)].id)});}
    break;


/* Line 1792 of yacc.c  */
#line 2234 "bison.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 256 "bison.y"


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