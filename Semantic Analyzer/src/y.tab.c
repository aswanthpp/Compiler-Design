/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntaxChecker.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
#include "semantic.h"



extern FILE *yyin;
extern int lineCount;
extern char *tablePtr;
extern char *tablePtr;
extern int nestedCommentCount;
extern int commentFlag;





char *sourceCode=NULL;
int errorFlag=0;
void makeList(char *,char,int);

#line 91 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO = 272,
    IF = 273,
    INT = 274,
    LONG = 275,
    REGISTER = 276,
    RETURN = 277,
    SHORT = 278,
    SIGNED = 279,
    SIZEOF = 280,
    STATIC = 281,
    STRUCT = 282,
    SWITCH = 283,
    TYPEDEF = 284,
    UNION = 285,
    UNSIGNED = 286,
    VOID = 287,
    VOLATILE = 288,
    WHILE = 289,
    IDENTIFIER = 290,
    CONSTANT = 291,
    STRING_LITERAL = 292,
    ELLIPSIS = 293,
    PTR_OP = 294,
    INC_OP = 295,
    DEC_OP = 296,
    LEFT_OP = 297,
    RIGHT_OP = 298,
    LE_OP = 299,
    GE_OP = 300,
    EQ_OP = 301,
    NE_OP = 302,
    AND_OP = 303,
    OR_OP = 304,
    MUL_ASSIGN = 305,
    DIV_ASSIGN = 306,
    MOD_ASSIGN = 307,
    ADD_ASSIGN = 308,
    SUB_ASSIGN = 309,
    LEFT_ASSIGN = 310,
    RIGHT_ASSIGN = 311,
    AND_ASSIGN = 312,
    XOR_ASSIGN = 313,
    OR_ASSIGN = 314,
    TYPE_NAME = 315,
    LOWER_THAN_ELSE = 316
  };
#endif
/* Tokens.  */
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define FOR 271
#define GOTO 272
#define IF 273
#define INT 274
#define LONG 275
#define REGISTER 276
#define RETURN 277
#define SHORT 278
#define SIGNED 279
#define SIZEOF 280
#define STATIC 281
#define STRUCT 282
#define SWITCH 283
#define TYPEDEF 284
#define UNION 285
#define UNSIGNED 286
#define VOID 287
#define VOLATILE 288
#define WHILE 289
#define IDENTIFIER 290
#define CONSTANT 291
#define STRING_LITERAL 292
#define ELLIPSIS 293
#define PTR_OP 294
#define INC_OP 295
#define DEC_OP 296
#define LEFT_OP 297
#define RIGHT_OP 298
#define LE_OP 299
#define GE_OP 300
#define EQ_OP 301
#define NE_OP 302
#define AND_OP 303
#define OR_OP 304
#define MUL_ASSIGN 305
#define DIV_ASSIGN 306
#define MOD_ASSIGN 307
#define ADD_ASSIGN 308
#define SUB_ASSIGN 309
#define LEFT_ASSIGN 310
#define RIGHT_ASSIGN 311
#define AND_ASSIGN 312
#define XOR_ASSIGN 313
#define OR_ASSIGN 314
#define TYPE_NAME 315
#define LOWER_THAN_ELSE 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 264 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1585

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,     2,     2,    75,    68,     2,
      62,    63,    69,    70,    67,    71,    66,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    83,
      76,    82,    77,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    79,    85,    72,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    53,    54,    55,    59,    60,    61,    62,
      63,    64,    65,    66,    70,    71,    75,    76,    77,    78,
      79,    80,    80,    85,    86,    87,    88,    89,    90,    94,
      95,    99,   100,   101,   102,   106,   107,   108,   112,   113,
     114,   118,   119,   120,   121,   122,   126,   127,   128,   132,
     133,   137,   138,   142,   143,   147,   148,   152,   153,   157,
     158,   162,   163,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   181,   182,   186,   190,   191,   195,
     196,   197,   198,   199,   200,   204,   205,   209,   210,   214,
     215,   216,   217,   218,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   237,   238,   239,   243,
     244,   248,   249,   253,   257,   258,   259,   260,   264,   265,
     269,   270,   271,   275,   276,   277,   281,   282,   286,   287,
     291,   292,   296,   297,   301,   302,   303,   304,   305,   306,
     307,   311,   312,   313,   314,   318,   319,   324,   325,   329,
     330,   334,   335,   336,   340,   341,   345,   346,   350,   351,
     352,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     368,   369,   370,   374,   375,   379,   380,   381,   382,   383,
     384,   388,   389,   390,   394,   395,   396,   397,   401,   402,
     406,   407,   411,   412,   416,   418,   421,   426,   428,   431,
     433,   438,   439,   440,   441,   442,   446,   447,   451,   452,
     456,   457,   458,   459
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN", "SHORT",
  "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION",
  "UNSIGNED", "VOID", "VOLATILE", "WHILE", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "ELLIPSIS", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "LOWER_THAN_ELSE", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "$@1", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    40,    41,    91,    93,    46,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -165

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-165)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1052,  -165,  -165,  -165,  -165,   -27,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,    13,    10,  -165,   -13,  1311,  1311,  -165,   -22,
    -165,  1311,   631,    55,    15,   805,  -165,  -165,   -66,     6,
     -19,  -165,  -165,    10,  -165,    20,  -165,   599,  -165,  -165,
      -4,  1342,  -165,   301,  -165,   -13,  -165,   631,  1096,  1343,
      55,  -165,  -165,     6,    -9,   -30,  -165,  -165,  -165,  -165,
      13,  -165,  1160,  -165,   631,  1342,  1342,   736,  -165,    -3,
    1342,    47,  1460,    58,    18,   662,   107,   140,   118,  1179,
    1499,   121,   129,   113,  -165,  -165,  1512,  1512,   853,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,   146,   293,
    1460,  -165,    74,    75,   178,    62,   187,   120,   131,   152,
     193,   -26,  -165,  -165,    44,  -165,  -165,  -165,   384,   454,
    -165,  -165,  -165,  -165,   161,  -165,  -165,  -165,  -165,     3,
     186,   188,  -165,    69,  -165,  -165,  -165,  -165,   194,    16,
    1460,     6,  -165,  -165,  1160,  -165,  -165,  -165,   767,  -165,
    -165,  -165,  1460,    45,  -165,   172,  -165,  -165,   177,  -165,
     662,   226,  1202,   179,  1460,  -165,    51,   853,  -165,  1460,
    1460,   662,  1460,  -165,  -165,   114,    78,   198,   228,  -165,
    -165,  1356,  1460,   229,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  1460,  -165,  1460,  1460,  1460,
    1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,
    1460,  1460,  1460,  1460,  1460,  1460,  1460,  -165,  -165,   524,
    -165,  -165,   924,  1395,  -165,    12,  -165,   155,  -165,  1273,
    -165,   232,  -165,  -165,  -165,  -165,  -165,    31,  -165,  -165,
      -3,  -165,  1460,   662,  -165,   206,  1202,  -165,   115,  -165,
     207,   126,   133,  -165,  -165,   988,   165,  -165,  1460,  -165,
    -165,   134,  -165,   163,  -165,  -165,  -165,  -165,  -165,    74,
      74,    75,    75,   178,   178,   178,   178,    62,    62,   187,
     120,   131,   152,   193,    43,  -165,  -165,  -165,   208,   209,
    -165,   210,   155,  1131,  1408,  -165,  -165,  -165,  1140,  -165,
    -165,  -165,  -165,  1460,  1447,   662,  -165,   662,   662,  -165,
    -165,  1460,  -165,  1460,  -165,  -165,  -165,  -165,   211,  -165,
     214,  -165,  -165,   136,   662,   139,   268,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,   199,  -165,   662,   662,  -165,  -165,
    -165
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    92,    95,   130,   100,     0,    90,    99,    97,    98,
      93,    96,   101,    91,   109,    89,   110,   102,    94,   131,
     134,   105,     0,   141,   209,     0,    79,    81,   103,     0,
     104,    83,     0,   133,     0,     0,   206,   208,   125,     0,
       0,   145,   143,   142,    77,     0,    85,    87,    80,    82,
     108,     0,    84,     0,   188,     0,   213,     0,     0,     0,
     132,     1,   207,     0,   128,     0,   126,   135,   146,   144,
       0,    78,     0,   211,     0,     0,   115,     0,   111,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     0,     0,     0,    23,
      24,    25,    26,    27,    28,   192,   184,     6,    16,    29,
       0,    31,    35,    38,    41,    46,    49,    51,    53,    55,
      57,    59,    61,    74,     0,   190,   175,   176,     0,     0,
     177,   178,   179,   180,    87,   189,   212,   154,   140,   153,
       0,   147,   149,     0,     2,   137,    29,    76,     0,     0,
       0,     0,   123,    86,     0,   170,    88,   210,     0,   114,
     107,   112,     0,     0,   118,   120,   116,   203,     0,   202,
       0,     0,     0,     0,     0,   204,     0,     0,    20,     0,
       0,     0,     0,    17,    18,     0,   156,     0,     0,    12,
      13,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    63,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   186,     0,
     185,   191,     0,     0,   151,   158,   152,   159,   138,     0,
     139,     0,   136,   124,   129,   127,   173,     0,   106,   121,
       0,   113,     0,     0,   183,     0,     0,   201,     0,   205,
       0,     0,     0,   181,     5,     0,   158,   157,     0,    11,
       8,     0,    14,     0,    10,    62,    32,    33,    34,    36,
      37,    39,    40,    44,    45,    42,    43,    47,    48,    50,
      52,    54,    56,    58,     0,    75,   187,   166,     0,     0,
     162,     0,   160,     0,     0,   148,   150,   155,     0,   171,
     119,   122,   182,     0,     0,     0,    21,     0,     0,    30,
       9,     0,     7,     0,   167,   161,   163,   168,     0,   164,
       0,   172,   174,     0,     0,     0,   194,    22,   196,   197,
      15,    60,   169,   165,     0,   199,     0,     0,   198,   200,
     195
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,  -165,  -165,   -57,  -165,  -165,   -94,    25,    33,
      -1,    19,    63,    67,    68,    61,    65,  -165,   -54,   -21,
    -165,   -88,   -62,     7,     0,  -165,   221,  -165,    46,  -165,
    -165,   217,   -73,   -46,  -165,    48,  -165,   230,   143,   201,
     -10,   -28,   -14,  -165,   -55,  -165,    56,  -165,   119,  -125,
    -164,  -135,  -165,   -61,  -165,   -11,    37,   169,  -161,  -165,
    -165,  -165,  -165,   266,  -165
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   109,   337,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     205,   124,   148,    54,    55,    45,    46,    26,    27,    28,
      29,    77,    78,    79,   163,   164,    30,    65,    66,    31,
      32,    33,    34,    43,   298,   141,   142,   143,   187,   299,
     237,   156,   247,   125,   126,   127,    57,   129,   130,   131,
     132,   133,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      25,   176,   146,   140,   161,   147,    60,    24,    38,    42,
     185,   256,    40,    50,   236,    47,   206,     3,    63,   246,
     168,    56,    20,   224,   171,   146,    48,    49,   147,    69,
     159,    52,    20,   178,   166,    25,    73,   151,    20,   183,
     184,    64,    24,    19,    67,   134,   136,    20,    20,    22,
      20,   155,   186,   146,   225,   152,    23,    39,   139,    22,
     134,   267,    51,   157,   135,   232,    23,   233,   231,   165,
      44,   302,    23,   150,   232,    22,   233,    22,   162,    23,
      75,   135,    23,   151,    74,   161,   258,    70,   244,   185,
     128,   261,   262,   146,   185,   314,   147,    76,   308,   170,
     249,   243,   302,    71,   273,   146,   214,   215,   147,   254,
     226,   226,   250,   276,   277,   278,   309,    58,   226,    59,
     263,    76,    76,    76,   323,   235,    76,   227,   251,   234,
     167,   186,   240,   155,   259,   135,   241,   294,   216,   217,
     265,   169,   233,   207,    76,   210,   211,    23,   208,   209,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   231,   172,
     272,   301,   266,   332,   319,   173,   146,   264,   315,   147,
     174,   226,   226,   179,   275,   188,   189,   190,   220,   317,
     311,   180,   312,   226,   181,   146,   318,   320,   147,   344,
     226,   321,   346,   226,    76,   295,   226,    60,   191,   221,
     192,   146,   193,   283,   284,   285,   286,   303,   235,   304,
     212,   213,    40,    76,    41,   333,   335,   265,   322,   233,
     226,   222,   139,   218,   219,   279,   280,   287,   288,   139,
     165,   223,   330,    72,    68,   281,   282,   146,   328,   238,
     147,   266,    80,   252,   336,   239,   338,   339,   253,   242,
     255,   268,   257,   269,   274,   139,   146,   307,   313,   341,
     316,   324,   325,   345,   342,   326,    80,    80,    80,   343,
     347,    80,   348,   289,   292,   349,   350,   155,   290,   293,
     291,   153,   158,   149,   245,   306,   260,   229,   310,    80,
     340,    62,     0,   139,     1,    81,    82,     2,     3,    83,
      84,    85,     4,     0,     5,     6,     7,    86,    87,    88,
       8,     9,    10,    89,    11,    12,    90,    13,    14,    91,
      15,    16,    17,    18,    19,    92,    93,    94,    95,     0,
       0,    96,    97,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,     0,     0,     0,     0,     0,    80,
       0,    21,     0,    98,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   204,     0,     0,    80,     0,
       0,     0,     0,     0,   105,    53,   106,     1,    81,    82,
       2,     3,    83,    84,    85,     4,     0,     5,     6,     7,
      86,    87,    88,     8,     9,    10,    89,    11,    12,    90,
      13,    14,    91,    15,    16,    17,    18,    19,    92,    93,
      94,    95,     0,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,    81,    82,
       0,     0,    83,    84,    85,     0,     0,   105,    53,   228,
      86,    87,    88,     0,     0,     0,    89,     0,     0,    90,
       0,     0,    91,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,    81,    82,
       0,     0,    83,    84,    85,     0,     0,   105,    53,   230,
      86,    87,    88,     0,     0,     0,    89,     0,     0,    90,
       0,     0,    91,     0,     0,     0,     0,     0,    92,    93,
      94,    95,     0,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,     0,
       0,     0,     1,     0,     0,     2,     3,   105,    53,   296,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,     0,    11,    12,     0,    13,    14,     0,    15,    16,
      17,    18,    19,     0,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,     0,    11,    12,     0,    13,    14,    21,
      15,    16,    17,    18,    19,     0,    81,    82,     0,     0,
      83,    84,    85,     0,     0,     0,     0,     0,    86,    87,
      88,    72,     0,    53,    89,     0,     0,    90,     0,     0,
      91,    21,     0,     0,     0,     0,    92,    93,    94,    95,
       0,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     2,     3,     0,   105,    53,     4,     0,     5,
       0,     7,     0,     0,     0,     8,     9,     0,     0,    11,
      12,     0,     0,    14,     0,     0,    16,    17,    18,    19,
       0,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     0,     7,     0,     0,     0,     8,     9,     0,     0,
      11,    12,     0,     0,    14,     0,    21,    16,    17,    18,
      19,     0,     0,     0,     0,    61,     0,     0,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,   160,     0,     0,     8,     9,    10,    21,    11,    12,
       0,    13,    14,     0,    15,    16,    17,    18,    19,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     4,    21,     5,    22,     7,     0,
       0,     0,     8,     9,    23,     0,    11,    12,    90,     0,
      14,     0,     0,    16,    17,    18,    19,     0,   144,    94,
      95,     0,     0,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,     0,    11,    12,     0,
      13,    14,     0,    15,    16,    17,    18,    19,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,   232,   297,   233,     0,
       0,     1,     0,    23,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
       0,    11,    12,     0,    13,    14,     0,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
     265,   297,   233,     0,     0,     1,     0,    23,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,     0,    11,    12,     0,    13,    14,
       0,    15,    16,    17,    18,    19,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,    21,     0,    22,     8,     9,    10,     0,    11,
      12,    23,    13,    14,     0,    15,    16,    17,    18,    19,
       0,   137,     0,     0,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,     0,    11,    12,    21,    13,    14,   138,
      15,    16,    17,    18,    19,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,    94,    95,     0,     0,
      96,    97,     0,     0,     0,    90,     0,     0,     0,     0,
       0,    21,     0,     0,   327,   144,    94,    95,     0,     0,
      96,    97,    98,     0,    90,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   144,    94,    95,     0,     0,    96,
      97,     0,    98,     0,   154,   331,     0,    90,    99,   100,
     101,   102,   103,   104,     0,     0,     0,   144,    94,    95,
       0,    98,    96,    97,   154,     0,     0,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,     0,    98,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     1,     0,     0,     2,
       3,     0,     0,     0,     4,   105,     5,     6,     7,     0,
       0,     0,     8,     9,    10,     0,    11,    12,     0,    13,
      14,     0,    15,    16,    17,    18,    19,     0,     0,     0,
       0,   305,     0,     0,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    21,    11,    12,     0,    13,    14,     0,
      15,    16,    17,    18,    19,     0,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     0,     7,     0,     0,
       0,     8,     9,     0,     0,    11,    12,     0,    90,    14,
       0,    21,    16,    17,    18,    19,     0,     0,   144,    94,
      95,    90,     0,    96,    97,     0,     0,     0,     0,     0,
       0,   144,    94,    95,     0,     0,    96,    97,     0,     0,
       0,     0,    21,     0,     0,    98,     0,     0,   145,     0,
       0,    99,   100,   101,   102,   103,   104,     0,    98,   270,
      90,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     144,    94,    95,    90,     0,    96,    97,     0,     0,     0,
       0,     0,     0,   144,    94,    95,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
     300,     0,     0,    99,   100,   101,   102,   103,   104,     0,
      98,     0,    90,   329,     0,     0,    99,   100,   101,   102,
     103,   104,   144,    94,    95,    90,     0,    96,    97,     0,
       0,     0,     0,     0,     0,   144,    94,    95,     0,     0,
      96,    97,     0,     0,     0,     0,     0,     0,     0,    98,
     334,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,    98,     0,    90,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   144,    94,    95,    90,     0,    96,
      97,     0,     0,     0,     0,     0,     0,   144,    94,    95,
       0,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,   177,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,   182,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
       0,    89,    59,    58,    77,    59,    34,     0,    35,    23,
      98,   172,    22,    35,   139,    25,   110,     7,    84,   154,
      82,    32,    35,    49,    85,    82,    26,    27,    82,    43,
      76,    31,    35,    90,    80,    35,    47,    67,    35,    96,
      97,    35,    35,    33,    63,    55,    57,    35,    35,    62,
      35,    72,    98,   110,    80,    85,    69,    84,    58,    62,
      70,   186,    84,    74,    57,    62,    69,    64,   129,    79,
      83,   235,    69,    82,    62,    62,    64,    62,    81,    69,
      84,    74,    69,    67,    47,   158,   174,    67,   150,   177,
      53,   179,   180,   150,   182,   256,   150,    51,    67,    81,
     162,    85,   266,    83,   192,   162,    44,    45,   162,   170,
      67,    67,    67,   207,   208,   209,    85,    62,    67,    64,
     181,    75,    76,    77,    81,   139,    80,    83,    83,   139,
      83,   177,    63,   154,    83,   128,    67,   225,    76,    77,
      62,    83,    64,    69,    98,    70,    71,    69,    74,    75,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   229,    62,
     191,   233,   186,   308,   268,    35,   233,    63,    63,   233,
      62,    67,    67,    62,   205,    39,    40,    41,    68,    63,
     252,    62,   253,    67,    81,   252,    63,    63,   252,    63,
      67,    67,    63,    67,   158,   226,    67,   235,    62,    78,
      64,   268,    66,   214,   215,   216,   217,    62,   232,    64,
      42,    43,   232,   177,    23,   313,   314,    62,    65,    64,
      67,    79,   232,    46,    47,   210,   211,   218,   219,   239,
     250,    48,   304,    82,    43,   212,   213,   304,   303,    63,
     304,   265,    51,    81,   315,    67,   317,   318,    81,    65,
      34,    63,    83,    35,    35,   265,   323,    35,    62,   323,
      63,    63,    63,   334,    63,    65,    75,    76,    77,    65,
      12,    80,    83,   220,   223,   346,   347,   308,   221,   224,
     222,    70,    75,    63,   151,   239,   177,   128,   250,    98,
     321,    35,    -1,   303,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,   158,
      -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    82,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,     4,     5,
      -1,    -1,     8,     9,    10,    -1,    -1,    83,    84,    85,
      16,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,     4,     5,
      -1,    -1,     8,     9,    10,    -1,    -1,    83,    84,    85,
      16,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,     7,    83,    84,    85,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    -1,    23,    24,    -1,    26,    27,    -1,    29,    30,
      31,    32,    33,    -1,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    -1,    23,    24,    -1,    26,    27,    60,
      29,    30,    31,    32,    33,    -1,     4,     5,    -1,    -1,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    82,    -1,    84,    22,    -1,    -1,    25,    -1,    -1,
      28,    60,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    83,    84,    11,    -1,    13,
      -1,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    -1,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,
      23,    24,    -1,    -1,    27,    -1,    60,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,     0,    -1,    -1,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    85,    -1,    -1,    19,    20,    21,    60,    23,    24,
      -1,    26,    27,    -1,    29,    30,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    60,    13,    62,    15,    -1,
      -1,    -1,    19,    20,    69,    -1,    23,    24,    25,    -1,
      27,    -1,    -1,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    -1,    23,    24,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    63,    64,    -1,
      -1,     3,    -1,    69,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      -1,    23,    24,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      62,    63,    64,    -1,    -1,     3,    -1,    69,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    -1,    23,    24,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    60,    -1,    62,    19,    20,    21,    -1,    23,
      24,    69,    26,    27,    -1,    29,    30,    31,    32,    33,
      -1,    35,    -1,    -1,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    -1,    23,    24,    60,    26,    27,    63,
      29,    30,    31,    32,    33,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      40,    41,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    63,    35,    36,    37,    -1,    -1,
      40,    41,    62,    -1,    25,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    35,    36,    37,    -1,    -1,    40,
      41,    -1,    62,    -1,    84,    85,    -1,    25,    68,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    35,    36,    37,
      -1,    62,    40,    41,    84,    -1,    -1,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    83,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    -1,    23,    24,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    60,    23,    24,    -1,    26,    27,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    24,    -1,    25,    27,
      -1,    60,    30,    31,    32,    33,    -1,    -1,    35,    36,
      37,    25,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    68,    69,    70,    71,    72,    73,    -1,    62,    63,
      25,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      35,    36,    37,    25,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      65,    -1,    -1,    68,    69,    70,    71,    72,    73,    -1,
      62,    -1,    25,    65,    -1,    -1,    68,    69,    70,    71,
      72,    73,    35,    36,    37,    25,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    -1,    62,    -1,    25,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    35,    36,    37,    25,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    23,    24,    26,    27,    29,    30,    31,    32,    33,
      35,    60,    62,    69,   109,   110,   113,   114,   115,   116,
     122,   125,   126,   127,   128,   148,   149,   150,    35,    84,
     126,   125,   128,   129,    83,   111,   112,   126,   110,   110,
      35,    84,   110,    84,   109,   110,   141,   142,    62,    64,
     127,     0,   149,    84,    35,   123,   124,    63,   125,   128,
      67,    83,    82,   141,   142,    84,   114,   117,   118,   119,
     125,     4,     5,     8,     9,    10,    16,    17,    18,    22,
      25,    28,    34,    35,    36,    37,    40,    41,    62,    68,
      69,    70,    71,    72,    73,    83,    85,    87,    88,    90,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   107,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   126,   109,   141,    35,    63,   110,
     130,   131,   132,   133,    35,    65,    90,   104,   108,   123,
      82,    67,    85,   112,    84,   105,   137,   141,   117,   119,
      85,   118,    81,   120,   121,   126,   119,    83,   108,    83,
      81,   139,    62,    35,    62,    83,   107,    62,    90,    62,
      62,    81,    62,    90,    90,   107,   119,   134,    39,    40,
      41,    62,    64,    66,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    82,   106,    93,    69,    74,    75,
      70,    71,    42,    43,    44,    45,    76,    77,    46,    47,
      68,    78,    79,    48,    49,    80,    67,    83,    85,   143,
      85,   139,    62,    64,   126,   128,   135,   136,    63,    67,
      63,    67,    65,    85,   108,   124,   137,   138,    85,   108,
      67,    83,    81,    81,   139,    34,   144,    83,   107,    83,
     134,   107,   107,   139,    63,    62,   128,   135,    63,    35,
      63,    89,   105,   107,    35,   105,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    97,    97,    98,
      99,   100,   101,   102,   107,   105,    85,    63,   130,   135,
      65,   108,   136,    62,    64,    38,   132,    35,    67,    85,
     121,   108,   139,    62,   144,    63,    63,    63,    63,    93,
      63,    67,    65,    81,    63,    63,    65,    63,   130,    65,
     108,    85,   137,   107,    63,   107,   139,    91,   139,   139,
     105,   104,    63,    65,    63,   139,    63,    12,    83,   139,
     139
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    91,    90,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    94,    94,    95,    95,    95,    96,    96,
      96,    97,    97,    97,    97,    97,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   138,   138,   139,   139,   139,   139,   139,
     139,   140,   140,   140,   141,   141,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   145,   146,   146,   146,
     146,   147,   147,   147,   147,   147,   148,   148,   149,   149,
     150,   150,   150,   150
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 52 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 'v', lineCount); (yyval)=context_check(tablePtr,lineCount); }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 53 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 'c', lineCount);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 54 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 's', lineCount);}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 55 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); (yyval)=(yyvsp[-1]); }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 62 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 63 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 'v', lineCount);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 64 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 'v', lineCount);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 65 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 'o', lineCount);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 66 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 'o', lineCount);}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 70 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 71 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(",",'p', lineCount); }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 76 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("++",'o', lineCount); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 77 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("--",'o', lineCount); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 79 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("sizeof",'o', lineCount); }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 80 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("sizeof",'o', lineCount); }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 81 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 85 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("&",'o', lineCount); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 86 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("*",'o', lineCount); }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 87 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("+",'o', lineCount); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 88 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("-",'o', lineCount); }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 89 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("~",'o', lineCount); }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 90 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("!",'o', lineCount); }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 95 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 99 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("*",'o', lineCount); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 101 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("/",'o', lineCount); }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 102 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("%",'o', lineCount); }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 106 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 107 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("+",'o', lineCount); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 108 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("-",'o', lineCount); }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 112 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 113 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("<<",'o', lineCount); }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 114 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(">>",'o', lineCount); }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 118 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 121 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("<=",'o', lineCount); }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 122 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(">=",'o', lineCount); }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 126 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 127 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("==",'o', lineCount); }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 128 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("!=",'o', lineCount); }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 132 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 133 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("&", 'o', lineCount);}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 137 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 138 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("^", 'o', lineCount); }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 142 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 143 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("|", 'o', lineCount); }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 147 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 148 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("&&", 'o', lineCount); }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 152 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 153 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("||", 'o', lineCount); }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 157 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 158 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("?:",'o', lineCount); }
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 162 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 163 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]); checkType((yyvsp[-2]),(yyvsp[0]),lineCount);}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 167 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("=",'o', lineCount); }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 168 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("*=",'o', lineCount); }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 169 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("/=",'o', lineCount); }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 170 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("%=",'o', lineCount); }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 171 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("+=",'o', lineCount); }
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 172 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("-=",'o', lineCount); }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 173 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("<<=",'o', lineCount); }
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 174 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(">==",'o', lineCount); }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 175 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("&=",'o', lineCount); }
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 176 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("^=",'o', lineCount); }
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 177 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("|=",'o', lineCount); }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 181 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 182 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(",", 'p', lineCount); }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 190 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(";", 'p', lineCount);typeBuffer=' '; }
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 191 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(";", 'p', lineCount); typeBuffer=' ';}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 205 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(",", 'p', lineCount); }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 210 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("=", 'o', lineCount); }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 214 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("typedef", 'k', lineCount);}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 215 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("extern", 'k', lineCount);}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 216 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("static", 'k', lineCount);}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 217 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("auto", 'k', lineCount);}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 218 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("register", 'k', lineCount);}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 222 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("void", 'k', lineCount);typeBuffer='v';}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 223 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("char", 'k', lineCount); typeBuffer='c';}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 224 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("short", 'k', lineCount);}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 225 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("int", 'k', lineCount); typeBuffer='i';}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 226 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("long", 'k', lineCount);}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 227 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("float", 'k', lineCount);	typeBuffer='f';}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 228 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("double", 'k', lineCount);}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 229 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("signed", 'k', lineCount);}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 230 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("unsigned", 'k', lineCount);}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 243 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("struct", 'k', lineCount);}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 244 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("union", 'k', lineCount);}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 253 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(";", 'p', lineCount); }
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 265 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(",", 'p', lineCount); }
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 270 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(":", 'p', lineCount); }
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 271 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(":", 'p', lineCount); }
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 275 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("enum", 'k', lineCount);}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 276 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("enum", 'k', lineCount); makeList(tablePtr, 'v', lineCount); }
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 277 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("enum", 'k', lineCount); makeList(tablePtr, 'v', lineCount); }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 282 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(",", 'p', lineCount); }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 286 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 'v', lineCount); }
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 287 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("=", 'o', lineCount); makeList("tablePtr", 'v', lineCount); }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 291 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("const", 'k', lineCount); }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 292 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("volatile", 'k', lineCount); }
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 301 "syntaxChecker.y" /* yacc.c:1646  */
    { checkDeclaration(tablePtr,lineCount);}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 302 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 303 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 304 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 305 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 306 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 307 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 311 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("*", 'o', lineCount); }
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 312 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("*", 'o', lineCount); }
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 313 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("*", 'o', lineCount); }
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 314 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("*", 'o', lineCount); }
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 325 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(",", 'p', lineCount); makeList("::", 'o', lineCount); }
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 330 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(",", 'p', lineCount); }
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 340 "syntaxChecker.y" /* yacc.c:1646  */
    { checkDeclaration(tablePtr,lineCount);}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 341 "syntaxChecker.y" /* yacc.c:1646  */
    { checkDeclaration(tablePtr,lineCount);makeList(",", 'p', lineCount); }
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 356 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 357 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
#line 2585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 358 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 359 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
#line 2597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 360 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 361 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 362 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 363 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 364 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 368 "syntaxChecker.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 375 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(",", 'p', lineCount); }
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 388 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(tablePtr, 'v', lineCount);  }
#line 2645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 389 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(":", 'p', lineCount); makeList("case", 'k', lineCount);}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 390 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(":", 'p', lineCount); makeList("default", 'k', lineCount); }
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 411 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(";", 'p', lineCount); }
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 412 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList(";", 'p', lineCount); }
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 417 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("if", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount);}
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 419 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("if", 'k', lineCount);  makeList("else", 'k', lineCount); makeList("(", 'p', lineCount); 					  makeList(")", 'p', lineCount); 
  				}
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 422 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("switch", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 427 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("while", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 429 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("do", 'k', lineCount); makeList("while", 'k', lineCount); makeList("(", 'p', lineCount);         				  makeList(")", 'p', lineCount); makeList(";", 'p', lineCount); 
			}
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 432 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("for", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 434 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("for", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 438 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("goto", 'k', lineCount); makeList(";", 'p', lineCount); makeList(tablePtr, 'v', lineCount);}
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 439 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("continue", 'k', lineCount); makeList(";", 'p', lineCount); }
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 440 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("break", 'k', lineCount); makeList(";", 'p', lineCount);}
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 441 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("return", 'k', lineCount); makeList(";", 'p', lineCount);}
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 442 "syntaxChecker.y" /* yacc.c:1646  */
    { makeList("return", 'k', lineCount); makeList(";", 'p', lineCount);}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 456 "syntaxChecker.y" /* yacc.c:1646  */
    {typeBuffer='p';}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2753 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 462 "syntaxChecker.y" /* yacc.c:1906  */

void yyerror()
{
	errorFlag=1;
	fflush(stdout);
	printf("\n%s : %d :Syntax error \n",sourceCode,lineCount);
}
void main(int argc,char **argv){
	if(argc<=1){
		
		printf("Invalid ,Expected Format : ./a.out <\"sourceCode\"> \n");
		return 0;
	}
	
	yyin=fopen(argv[1],"r");
	sourceCode=(char *)malloc(strlen(argv[1])*sizeof(char));
	sourceCode=argv[1];
	yyparse();
	
	if(nestedCommentCount!=0){
		errorFlag=1;
    		printf("%s : %d : Comment Does Not End\n",sourceCode,lineCount);
    		
	}
	if(commentFlag==1){
		errorFlag=1;
		printf("%s : %d : Nested Comment\n",sourceCode,lineCount);
    	}
	
		
	
	if(!errorFlag  && !semanticErr){
		
		printf("\n\n\t\t%s Parsing Completed\n\n",sourceCode);
		
		
	
		
		
  		FILE *writeSymbol=fopen("symbolTable.txt","w");
    		fprintf(writeSymbol,"\n\t\t\t\tSymbolTable\n\n\t\tToken\t\t\t\t\t\tType\t\t\t\t\t\t\tLine Number\n");
      		for(tokenList *ptr=symbolPtr;ptr!=NULL;ptr=ptr->next){
  			fprintf(writeSymbol,"\n%20s%30.30s%60s",ptr->token,ptr->type,ptr->line);
		}
		
		FILE *writeConstant=fopen("constantTable.txt","w");
    		fprintf(writeConstant,"\n   \t\t\t\t\t\t\t\tConstant Table \n\n \t\t\t\t\t\tValue\t\t\t\t\t\t\tLine Number\n");
    		for(tokenList *ptr=constantPtr;ptr!=NULL;ptr=ptr->next)
  		fprintf(writeConstant,"\n%50s%60s",ptr->token,ptr->line);
  	
  	
  		fclose(writeSymbol);
		fclose(writeConstant);
	}
printf("\n\n");	
}


