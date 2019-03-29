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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./moon.y" /* yacc.c:339  */

/**
 * This Grammar is designed for moon script.
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "moon_parser_bison.h"
#include "moon_parser_flex.h"

/*
 * We provide parse error includes error message, first line, first column of error lex for debug
 */
int yyerror(YYLTYPE* llocp, ParseResult* result, yyscan_t scanner, const char *msg) {
    //result->accept = false;
    result->errFirstLine = llocp->first_line;
    result->errFirstColumn = llocp->first_column;
    result->errDetail = msg;
	return 0;
}



#line 91 "moon_parser_bison.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "moon_parser_bison.h".  */
#ifndef YY_YY_MOON_PARSER_BISON_H_INCLUDED
# define YY_YY_MOON_PARSER_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 29 "./moon.y" /* yacc.c:355  */

// %code requires block

#include "syntax_tree.h"

#line 127 "moon_parser_bison.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INTNUM = 259,
    STRING = 260,
    BREAK = 261,
    ELSE = 262,
    END_P = 263,
    ERROR = 264,
    FALSE = 265,
    IF = 266,
    INT = 267,
    NIL = 268,
    RETURN = 269,
    STRING_ = 270,
    STRUCT = 271,
    TRUE = 272,
    TYPEDEF = 273,
    VOID = 274,
    WHILE = 275,
    OR = 276,
    AND = 277,
    EQ = 278,
    NEQ = 279,
    LE = 280,
    LT = 281,
    GT = 282,
    GE = 283,
    PLUS = 284,
    MINUS = 285,
    TIMES = 286,
    DIVIDE = 287,
    UMINUS = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "./moon.y" /* yacc.c:355  */

    struct SyntaxMoonStmtsList *moon_stmts_list;
    struct SyntaxMoonStmt *moon_stmt;
    struct SyntaxTypeFieldsList *type_fields_list;
    struct SyntaxLeftV *left_val;
    struct SyntaxTypeField *type_field;
    SyntaxType *type;
    SyntaxExp *expr;
    SyntaxExpsList *exps_list;
    Symbol *symbol;
    int ival;
    char *sval;

#line 187 "moon_parser_bison.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (ParseResult* result, yyscan_t scanner);

#endif /* !YY_YY_MOON_PARSER_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "moon_parser_bison.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   340

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    39,     2,    42,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   149,   153,   154,   158,   159,   160,   164,
     165,   169,   170,   174,   175,   176,   177,   178,   179,   183,
     184,   188,   189,   193,   194,   198,   199,   203,   204,   208,
     209,   213,   217,   218,   222,   225,   226,   227,   231,   235,
     236,   237,   238,   248,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   279,   280
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTNUM", "STRING",
  "BREAK", "ELSE", "END_P", "ERROR", "FALSE", "IF", "INT", "NIL", "RETURN",
  "STRING_", "STRUCT", "TRUE", "TYPEDEF", "VOID", "WHILE", "'['", "'='",
  "OR", "AND", "EQ", "NEQ", "LE", "LT", "GT", "GE", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "UMINUS", "';'", "'{'", "'}'", "','", "'('", "')'",
  "'.'", "']'", "$accept", "moon", "moon_body1", "moon_stmts1",
  "moon_stmt1", "moon_body", "moon_stmts", "moon_stmt",
  "declare_variable_stmt", "struct_elem_list", "declare_type_stmt",
  "type_fields", "declare_function_stmt", "if_stmt", "while_stmt",
  "return_stmt", "break_stmt", "left_value", "type_field", "type",
  "expression", "expression_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    91,    61,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,    59,   123,   125,    44,
      40,    41,    46,    93
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-40)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,     5,    32,   -62,    55,     8,    64,    57,   -62,    83,
      30,    31,   -62,   -18,    65,    36,    35,    71,   -62,   -62,
     -62,   -62,   -62,    44,    72,    29,   -62,     8,   -62,    15,
     -62,   -62,   -62,   -62,   -62,   159,   159,   -62,    41,    43,
     177,   -62,   159,     1,    47,    78,   102,   -27,   198,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   -62,   286,    45,    49,    53,    85,   -62,
      61,   -62,   255,    59,   -62,   286,    66,    96,   296,   306,
     306,   306,   306,   306,   306,   -27,   -27,   -62,   -62,   141,
      76,     8,   -62,     8,   159,   -62,   -62,   -62,    62,   159,
      69,    80,   -62,   141,    97,   -62,   -62,    99,   100,     9,
     272,   141,   -62,   -62,   -62,   159,   286,   159,   -62,   -62,
     -62,   -62,   -62,    94,   -62,   101,   217,   236,   -62,   103,
     104,   141,   141,   110,   111,   130,   -62,   113,   141,   119,
     -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,    40,    41,     0,     0,     0,     0,     3,     4,
       0,     0,     8,     0,     0,     0,     0,     0,     1,     2,
       5,     6,     7,     0,     0,    19,    43,     0,    23,    35,
      44,    48,    47,    45,    46,     0,     0,    42,    49,     0,
       0,    36,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    20,     0,     0,    25,     0,    24,
       0,    51,    68,     0,    67,    52,     0,    54,    55,    64,
      65,    58,    56,    57,    59,    60,    61,    62,    63,     9,
       0,     0,    38,    21,     0,    50,    66,    34,     0,    32,
       0,     0,    10,    11,     0,    14,    15,     0,     0,     0,
       0,     9,    26,    22,    69,     0,    33,     0,    28,    12,
      13,    17,    18,    19,    16,     0,     0,     0,    27,     0,
       0,     9,     9,     0,     0,    29,    31,     0,     9,     0,
      30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   150,   -62,   -61,    63,   -62,    10,    67,
     -62,    74,   -62,   -62,   -62,   -62,   -62,    17,   -62,     0,
     -21,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,   101,   102,   103,   104,    44,
      11,    66,    12,   105,   106,   107,   108,    38,    67,    39,
     110,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    76,    40,    23,     1,    17,    61,    62,   -39,    14,
      10,     1,   123,     2,    47,    48,     3,    13,   -39,    10,
       2,    64,    13,     3,    24,    72,    13,    45,    75,    72,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    65,    68,    13,   114,    50,    29,    30,    31,
     125,    42,   -39,    15,    32,    46,     2,    33,    16,     3,
      13,    34,    23,    49,    18,    19,    21,    22,    25,    43,
     133,   134,    27,    72,    28,    41,    35,   139,   116,    26,
      50,    70,    89,    24,    36,    69,     1,    37,    92,   109,
      90,    68,    91,    45,   126,     2,   127,    93,     3,     4,
      95,     5,   115,   109,    96,    29,    30,    31,    13,   117,
      13,   109,    32,   111,     2,    33,    42,     3,   118,    34,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   109,   109,   120,    35,   121,   122,   137,   109,   128,
     131,   132,    36,    71,    29,    30,    31,    97,   135,   136,
     138,    32,    98,     2,    33,    99,     3,   140,    34,    20,
     113,   100,    29,    30,    31,   112,   119,     0,     0,    32,
       0,     2,    33,    35,     3,     0,    34,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,    36,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,    74,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,   129,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,   130,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    94,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,   124,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   -40,   -40,   -40,   -40,   -40,   -40,    59,    60,    61,
      62
};

static const yytype_int16 yycheck[] =
{
       0,    50,    23,    21,     3,     5,    33,    34,     3,     9,
       0,     3,     3,    12,    35,    36,    15,     0,     3,     9,
      12,    42,     5,    15,    42,    46,     9,    27,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    41,    43,    27,    94,    37,     3,     4,     5,
     111,    22,    37,    21,    10,    40,    12,    13,     3,    15,
      43,    17,    21,    22,     0,     8,    36,    36,     3,    40,
     131,   132,    37,    94,     3,     3,    32,   138,    99,    43,
      37,     3,    37,    42,    40,    38,     3,    43,     3,    89,
      41,    91,    39,    93,   115,    12,   117,    36,    15,    16,
      41,    18,    40,   103,    38,     3,     4,     5,    91,    40,
      93,   111,    10,    37,    12,    13,    22,    15,    38,    17,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   131,   132,    36,    32,    36,    36,     7,   138,    38,
      37,    37,    40,    41,     3,     4,     5,     6,    38,    38,
      37,    10,    11,    12,    13,    14,    15,    38,    17,     9,
      93,    20,     3,     4,     5,    91,   103,    -1,    -1,    10,
      -1,    12,    13,    32,    15,    -1,    17,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    39,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    12,    15,    16,    18,    45,    46,    47,    48,
      52,    54,    56,    61,    63,    21,     3,    63,     0,     8,
      47,    36,    36,    21,    42,     3,    43,    37,     3,     3,
       4,     5,    10,    13,    17,    32,    40,    43,    61,    63,
      64,     3,    22,    40,    53,    63,    40,    64,    64,    22,
      37,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    43,    64,    41,    55,    62,    63,    38,
       3,    41,    64,    65,    41,    64,    65,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    37,
      41,    39,     3,    36,    39,    41,    38,     6,    11,    14,
      20,    49,    50,    51,    52,    57,    58,    59,    60,    63,
      64,    37,    55,    53,    65,    40,    64,    40,    38,    50,
      36,    36,    36,     3,    36,    49,    64,    64,    38,    41,
      41,    37,    37,    49,    49,    38,    38,     7,    37,    49,
      38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    60,    61,    61,    61,    62,    63,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     2,     2,     1,     0,
       1,     1,     2,     2,     1,     1,     2,     2,     2,     2,
       4,     3,     4,     3,     5,     1,     3,     8,     7,     7,
      11,     7,     1,     2,     1,     1,     3,     4,     2,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     1,     3
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
      yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParseResult* result, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParseResult* result, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, scanner);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, ParseResult* result, yyscan_t scanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, ParseResult* result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ParseResult* result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 47 "./moon.y" /* yacc.c:1429  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
}

#line 1358 "moon_parser_bison.cpp" /* yacc.c:1429  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 145 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmts_list) = (yyvsp[-1].moon_stmts_list); accept((yyval.moon_stmts_list), result); YYACCEPT; }
#line 1547 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 153 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmts_list) = make_moon_stmts((yyvsp[0].moon_stmt), nullptr); }
#line 1553 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 154 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmts_list) = make_moon_stmts((yyvsp[-1].moon_stmt), (yyvsp[0].moon_stmts_list)); }
#line 1559 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 164 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmts_list) = nullptr; }
#line 1565 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 169 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmts_list) = make_moon_stmts((yyvsp[0].moon_stmt), nullptr); }
#line 1571 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 170 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmts_list) = make_moon_stmts((yyvsp[-1].moon_stmt), (yyvsp[0].moon_stmts_list)); }
#line 1577 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_exp_stmt((yyvsp[-1].expr)); }
#line 1583 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 183 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_decl_var_stmt((yyvsp[-1].type), (yyvsp[0].symbol), nullptr); }
#line 1589 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 184 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_decl_var_stmt((yyvsp[-3].type), (yyvsp[-2].symbol), (yyvsp[0].expr)); }
#line 1595 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 188 "./moon.y" /* yacc.c:1646  */
    { auto t = make_type_field((yyvsp[-2].type), (yyvsp[-1].symbol)); (yyval.type_fields_list) = make_type_fields(t, nullptr);  }
#line 1601 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 189 "./moon.y" /* yacc.c:1646  */
    { auto t = make_type_field((yyvsp[-3].type), (yyvsp[-2].symbol)); (yyval.type_fields_list) = make_type_fields(t, (yyvsp[0].type_fields_list)); }
#line 1607 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 193 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_decl_type_typedef_stmt((yyvsp[-1].type), (yyvsp[0].symbol)); }
#line 1613 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 194 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_decl_type_struct_stmt((yyvsp[-1].type_fields_list), (yyvsp[-3].symbol)); }
#line 1619 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 198 "./moon.y" /* yacc.c:1646  */
    { (yyval.type_fields_list) = make_type_fields((yyvsp[0].type_field), nullptr); }
#line 1625 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 199 "./moon.y" /* yacc.c:1646  */
    { (yyval.type_fields_list) = make_type_fields((yyvsp[-2].type_field), (yyvsp[0].type_fields_list)); }
#line 1631 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 203 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_decl_func_stmt((yyvsp[-7].type), (yyvsp[-6].symbol), (yyvsp[-4].type_fields_list), (yyvsp[-1].moon_stmts_list));  }
#line 1637 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 204 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_decl_func_stmt((yyvsp[-6].type), (yyvsp[-5].symbol), nullptr, (yyvsp[-1].moon_stmts_list));  }
#line 1643 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 208 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_if_stmt((yyvsp[-4].expr), (yyvsp[-1].moon_stmts_list), nullptr); }
#line 1649 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 209 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_if_stmt((yyvsp[-8].expr), (yyvsp[-5].moon_stmts_list), (yyvsp[-1].moon_stmts_list)); }
#line 1655 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 213 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_while_stmt((yyvsp[-4].expr), (yyvsp[-1].moon_stmts_list)); }
#line 1661 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 217 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_return_stmt(nullptr); }
#line 1667 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 218 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_return_stmt((yyvsp[0].expr)); }
#line 1673 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 222 "./moon.y" /* yacc.c:1646  */
    { (yyval.moon_stmt) = make_break_stmt(); }
#line 1679 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 225 "./moon.y" /* yacc.c:1646  */
    { (yyval.left_val) = make_simple_left_value((yyvsp[0].symbol)); }
#line 1685 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 226 "./moon.y" /* yacc.c:1646  */
    { (yyval.left_val) = make_struct_field_left_value((yyvsp[-2].left_val), (yyvsp[0].symbol)); }
#line 1691 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 227 "./moon.y" /* yacc.c:1646  */
    { (yyval.left_val) = make_array_index_left_value((yyvsp[-3].left_val), (yyvsp[-1].expr)); }
#line 1697 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 231 "./moon.y" /* yacc.c:1646  */
    { (yyval.type_field) = make_type_field((yyvsp[-1].type), (yyvsp[0].symbol)); }
#line 1703 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 235 "./moon.y" /* yacc.c:1646  */
    { (yyval.type) = make_named_type((yyvsp[0].symbol)); }
#line 1709 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 236 "./moon.y" /* yacc.c:1646  */
    { (yyval.type) = make_int_type(); }
#line 1715 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 237 "./moon.y" /* yacc.c:1646  */
    { (yyval.type) = make_string_type(); }
#line 1721 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 239 "./moon.y" /* yacc.c:1646  */
    {
    /* ???? */
    /* because it will be reduced by left_value : IDENTIFIER */
    if ((yyvsp[-2].left_val)->kind_ != SyntaxLeftV::Simple) {
        yyerror(&(yylsp[-2]), result, scanner, "type use error");
        YYABORT;
    }
    (yyval.type) = make_named_arr_type((yyvsp[-2].left_val)->u.name_, 0);
}
#line 1735 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 248 "./moon.y" /* yacc.c:1646  */
    { (yyval.type) = make_int_arr_type(0); }
#line 1741 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 252 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_int_const((yyvsp[0].ival)); }
#line 1747 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 253 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_nil_const(); }
#line 1753 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 254 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_bool_const(true); }
#line 1759 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 255 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_bool_const(false); }
#line 1765 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 256 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_str_const((yyvsp[0].sval)); }
#line 1771 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 257 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_left_value((yyvsp[0].left_val)); }
#line 1777 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 258 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_func_call((yyvsp[-3].symbol), (yyvsp[-1].exps_list)); }
#line 1783 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 259 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_func_call((yyvsp[-2].symbol), nullptr); }
#line 1789 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 260 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_assign((yyvsp[-2].left_val), (yyvsp[0].expr)); }
#line 1795 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 261 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(NEGATIVE_OP, (yyvsp[0].expr), nullptr); }
#line 1801 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 262 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(OR_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1807 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 263 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(AND_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1813 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 264 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(LT_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1819 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 265 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(GT_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1825 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 266 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(LE_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1831 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 267 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(GE_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1837 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 268 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(PLUS_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1843 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 269 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(MINUS_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1849 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 270 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(TIMES_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1855 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 271 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(DIVIDE_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1861 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 272 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(EQ_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1867 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 273 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_op(NEQ_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1873 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 274 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr_struct_array_init((yyvsp[-1].exps_list), (yyvsp[-3].type)); }
#line 1879 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 275 "./moon.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1885 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 279 "./moon.y" /* yacc.c:1646  */
    { (yyval.exps_list) = make_expr_list((yyvsp[0].expr), nullptr); }
#line 1891 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 280 "./moon.y" /* yacc.c:1646  */
    { (yyval.exps_list) = make_expr_list((yyvsp[-2].expr), (yyvsp[0].exps_list)); }
#line 1897 "moon_parser_bison.cpp" /* yacc.c:1646  */
    break;


#line 1901 "moon_parser_bison.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
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
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, result, scanner);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, result, scanner);
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
#line 282 "./moon.y" /* yacc.c:1906  */




    
