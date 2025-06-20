/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

    #include<cstdio>
    #include<string>
    #include<iostream>
    #include<vector>

    #include "code.h"

    using namespace std;

    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;
    extern Code code;

    void yyerror(const char* s);

    struct sym_lit{ //koriste literali i simboli kod word direktive
	    bool jesteSimbol;
	    string simbol;
	    int vrednost;
    };

    extern int red; 
    unsigned int pc=0;
    vector<string> symList; //lista simbola 
    vector<sym_lit> symLitList; //lista simbola i literala
    

    extern bool gotovo;
    extern bool prviProlaz;

    enum ADDR{
        NEPOSR=0, REGDIR=1, REGIND=2, REGINDPOM=3, MEM=4, REGDIRPOM=5
    };

    typedef struct Operand{
        int reg;
        unsigned short vrednost;
        int up; 
        ADDR adresiranje;
        bool jesteSimbol=false;
        string simbol;
        int tipRel;
    } Operand;
   
    Operand trenOp;

#line 119 "src/bison.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INC_BISON_HPP_INCLUDED
# define YY_YY_INC_BISON_HPP_INCLUDED
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
    GLOBAL = 258,
    EXTERN = 259,
    SECTION = 260,
    WORD = 261,
    SKIP = 262,
    EQU = 263,
    END = 264,
    SYMBOL = 265,
    NUMBER = 266,
    REG = 267,
    PLUS = 268,
    MINUS = 269,
    COLON = 270,
    DOT = 271,
    COMMA = 272,
    STAR = 273,
    COMMENT = 274,
    DOLLAR = 275,
    PERCENT = 276,
    BRACKET_L = 277,
    BRACKET_R = 278,
    SQBRACKET_L = 279,
    SQBRACKET_R = 280,
    MULTIP = 281,
    NOVI_RED = 282,
    QUIT = 283,
    JMP = 284,
    JEQ = 285,
    JNE = 286,
    JGT = 287,
    CALL = 288,
    PUSH = 289,
    POP = 290,
    INT = 291,
    NOT = 292,
    HALT = 293,
    RET = 294,
    IRET = 295,
    XCHG = 296,
    ADD = 297,
    SUB = 298,
    MUL = 299,
    DIV = 300,
    CMP = 301,
    AND = 302,
    OR = 303,
    XOR = 304,
    TEST = 305,
    SHL = 306,
    SHR = 307,
    LDR = 308,
    STR = 309,
    DIVIDE = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "src/parser.y"

	int ival;
	char *sval;

#line 232 "src/bison.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_BISON_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    85,    89,    90,    91,    92,    93,    96,
     100,   101,   104,   110,   116,   131,   147,   156,   160,   173,
     174,   192,   193,   196,   214,   223,   224,   225,   228,   229,
     230,   231,   232,   235,   236,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   253,   254,   257,
     258,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   283,
     284,   287,   288,   289,   292,   297,   303,   307
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GLOBAL", "EXTERN", "SECTION", "WORD",
  "SKIP", "EQU", "END", "SYMBOL", "NUMBER", "REG", "PLUS", "MINUS",
  "COLON", "DOT", "COMMA", "STAR", "COMMENT", "DOLLAR", "PERCENT",
  "BRACKET_L", "BRACKET_R", "SQBRACKET_L", "SQBRACKET_R", "MULTIP",
  "NOVI_RED", "QUIT", "JMP", "JEQ", "JNE", "JGT", "CALL", "PUSH", "POP",
  "INT", "NOT", "HALT", "RET", "IRET", "XCHG", "ADD", "SUB", "MUL", "DIV",
  "CMP", "AND", "OR", "XOR", "TEST", "SHL", "SHR", "LDR", "STR", "DIVIDE",
  "$accept", "program", "line", "label", "inst_dir", "Direktiva",
  "Instrukcija", "instr0", "jmp_instr", "instr1", "instr2", "instr_mem",
  "push_pop", "operand_jmp", "operand_mem", "sym_list", "Literal",
  "sym_lit_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      33,   -12,    23,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,    10,    33,    72,   -48,   -48,   -48,    -9,     4,    12,
      25,    28,   -48,    24,    24,    36,    31,    22,    45,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,    79,    -3,   -48,   -48,
       5,    73,   -48,   -48,    74,    74,   -48,   -48,   -48,    81,
      82,   -48,    77,   -48,    78,   -48,   -48,   -48,   -48,    84,
      85,    -6,    88,   -48,   -48,    37,    22,    -2,   -48,   -48,
     -48,   -48,     9,    89,   115,   -48,   -48,   -48,   -48,   -48,
      48,   -48,   -48,   -48,   -48,     0,    75,   103,    43,   -48,
     -48,   -48,   104,   105,   -48,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     7,     8,    29,    30,    31,    32,    28,
      49,    50,    33,    34,    25,    27,    26,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     2,     4,     5,    10,    19,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,    18,
      11,     1,     3,     6,    52,    51,     0,     0,    20,    21,
       0,     0,    24,    69,    12,    13,    14,    74,    71,     0,
       0,    75,    15,    16,     0,    53,    55,    54,    56,     0,
       0,     0,     0,    72,    73,     0,     0,     0,    22,    63,
      62,    65,     0,     0,     0,    23,    70,    76,    77,    17,
       0,    57,    61,    60,    64,     0,     0,     0,     0,    66,
      59,    58,     0,     0,    68,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,    99,   -48,   -48,   100,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,    90,   -47,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    31,    32,    33,    34,    50,    35,    36,    37,    38,
      39,    40,    41,    58,    95,    64,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      73,    54,    55,    42,    89,    90,    91,    76,    77,    78,
      51,   100,    56,   108,    92,    93,    59,    57,    94,   102,
     103,    79,    80,   101,    60,   109,    43,    44,    45,    46,
      47,    48,    49,    68,    63,    69,    70,    61,    98,    99,
      62,    67,    68,     1,    69,    70,    66,    97,    68,     2,
      69,    70,     3,   112,    68,    74,    69,    70,   106,   107,
       4,   113,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     2,    75,
      81,    82,    83,    84,    85,    86,    87,    88,    96,   104,
     110,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   105,   111,   114,
     115,    52,     0,    53,    65
};

static const yytype_int8 yycheck[] =
{
      47,    10,    11,    15,    10,    11,    12,    10,    11,    12,
       0,    13,    21,    13,    20,    21,    12,    26,    24,    10,
      11,    24,    17,    25,    12,    25,     3,     4,     5,     6,
       7,     8,     9,    11,    10,    13,    14,    12,    85,    86,
      12,    10,    11,    10,    13,    14,    10,    10,    11,    16,
      13,    14,    19,    10,    11,    10,    13,    14,    10,    11,
      27,   108,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    16,    10,
      17,    17,    11,    11,    17,    17,    12,    12,    10,    10,
      25,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    12,    25,    25,
      25,    32,    -1,    33,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    16,    19,    27,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    57,    58,    59,    60,    62,    63,    64,    65,    66,
      67,    68,    15,     3,     4,     5,     6,     7,     8,     9,
      61,     0,    57,    60,    10,    11,    21,    26,    69,    12,
      12,    12,    12,    10,    71,    71,    10,    10,    11,    13,
      14,    72,    73,    72,    10,    10,    10,    11,    12,    24,
      17,    17,    17,    11,    11,    17,    17,    12,    12,    10,
      11,    12,    20,    21,    24,    70,    10,    10,    72,    72,
      13,    25,    10,    11,    10,    12,    10,    11,    13,    25,
      25,    25,    10,    72,    25,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    58,    58,    58,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     1,     2,
       1,     2,     2,     2,     2,     2,     2,     4,     1,     1,
       2,     2,     4,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     4,     6,     6,
       2,     2,     1,     1,     2,     1,     3,     5,     5,     1,
       3,     1,     2,     2,     1,     1,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 9:
#line 96 "src/parser.y"
                  { //cout<<"Labelaa red="<<red<<endl;
     if(prviProlaz) code.dodajSimbol(string((yyvsp[-1].sval)), code.trenSekcija, pc, false); }
#line 1497 "src/bison.cpp"
    break;

  case 12:
#line 104 "src/parser.y"
                  {
        if(!prviProlaz){
            for(std::string simb:symList){
                code.tabelaSimbola[simb].globalan=true;
            }
        } }
#line 1508 "src/bison.cpp"
    break;

  case 13:
#line 110 "src/parser.y"
                    {
          if(!prviProlaz){
              for(std::string simb:symList){
                  if(!code.postojiSimbol(simb)) code.dodajSimbol(simb, "UNDEF", 0, true); 
              }
          }}
#line 1519 "src/bison.cpp"
    break;

  case 14:
#line 116 "src/parser.y"
                   { 
      if(!prviProlaz){
          //cout<<".SEKCIJA "<<$2<<"drugiProlaz red="<<red<<" pc="<<pc<<" trenSekcija="<<code.trenSekcija<<endl;
          code.dodajSekciju(); //dodajem prethodnu sekciju
          code.trenSekcija=(yyvsp[0].sval);
          pc=0;
      }
      else{
          //cout<<".SEKCIJA "<<$2<<"prviProlaz red="<<red<<" pc="<<pc<<" trenSekcija="<<code.trenSekcija<<endl;
          code.promeniVelicinu(code.trenSekcija, pc); //postavlja velicinu prethodne sekcije
          code.trenSekcija=(yyvsp[0].sval); //i menjam da je sada trenutna sekcija ova $2
          pc=0;
          code.dodajSimbol((yyvsp[0].sval),(yyvsp[0].sval),0, false); //dodajem sekciju u tabelu simbola
      }
  }
#line 1539 "src/bison.cpp"
    break;

  case 15:
#line 131 "src/parser.y"
                      {
    for(sym_lit i:symLitList){
        //cout<<".WORD jesteSimbol="<<i.jesteSimbol<<" vrednost "<<i.vrednost<<" simbol="<<i.simbol<<" red="<<red<<endl;
        if(!prviProlaz){ //u drugom prolazu
            if(i.jesteSimbol){
                //cout<<"DODAJEM SIMBOL U TABELU REALOKACIJA "<<i.simbol<<endl;
                code.dodajRel(i.simbol, code.trenSekcija, pc, 0); //za simbole se dodaje apsolutna realokacija 
            }
            else{
                unsigned short w=(unsigned short) i.vrednost;
                code.dodajWord(w); //asemblerska direktiva alocirani prostor inicijalizujje vrednoscu literala
            }
        }
        pc+=2;
    } 
  }
#line 1560 "src/bison.cpp"
    break;

  case 16:
#line 147 "src/parser.y"
                 { 
      pc+=(yyvsp[0].ival);
      //cout<<".SKIP "<<$2<<" red"<<red<<endl;
      if(!prviProlaz){
          for(int i=0; i<(yyvsp[0].ival); i++){
              code.dodajByte(0); //asemblerska direktiva alocirani prostor inicijalizuje nulama
          }
      }
  }
#line 1574 "src/bison.cpp"
    break;

  case 17:
#line 156 "src/parser.y"
                             { 
      //cout<<".EQU "<<$2<<" "<<$4<<" red="<<red<<endl;
      if(prviProlaz) code.dodajSimbol((yyvsp[-2].sval), "ABS", (yyvsp[0].ival), false);
   }
#line 1583 "src/bison.cpp"
    break;

  case 18:
#line 160 "src/parser.y"
       {
      if(prviProlaz){
        //cout<<"END U PRVOM PROLAZU"<<" red="<<red<<" pc="<<pc<<endl;
        code.promeniVelicinu(code.trenSekcija, pc); //menjam velicinu zadnje sekcije
      }
      else{
        //cout<<"END U DRUGOM PROLAZU"<<" red="<<red<<" pc="<<pc<<endl;
        code.dodajSekciju(); //dodajem poslednju sekciju
      }
      YYACCEPT;
  }
#line 1599 "src/bison.cpp"
    break;

  case 19:
#line 173 "src/parser.y"
         { pc += 1; }
#line 1605 "src/bison.cpp"
    break;

  case 20:
#line 174 "src/parser.y"
                          { 
      pc+=3;
      if(!prviProlaz){
        code.dodajByte(trenOp.reg | 0xF0); //F0=1111 0000
        code.dodajByte(trenOp.adresiranje | (trenOp.up << 4));
        if(trenOp.adresiranje==NEPOSR || trenOp.adresiranje==REGDIRPOM || trenOp.adresiranje==REGINDPOM || trenOp.adresiranje==MEM){
            if(trenOp.jesteSimbol){
                code.dodajRel(trenOp.simbol,code.trenSekcija, (unsigned char) pc, trenOp.tipRel);
            }
            else{
              code.dodajWord(trenOp.vrednost);
            }
        }
      }
       if(trenOp.adresiranje==NEPOSR || trenOp.adresiranje==REGDIRPOM || trenOp.adresiranje==REGINDPOM || trenOp.adresiranje==MEM){
           pc+=2;
       }
    }
#line 1628 "src/bison.cpp"
    break;

  case 21:
#line 192 "src/parser.y"
               { pc+=2; if(!prviProlaz) code.dodajByte(0x0F | ((yyvsp[0].ival) << 4)); }
#line 1634 "src/bison.cpp"
    break;

  case 22:
#line 193 "src/parser.y"
                         { 
   
   pc+=2; if(!prviProlaz) code.dodajByte((yyvsp[0].ival) | ((yyvsp[-2].ival)<<4)); }
#line 1642 "src/bison.cpp"
    break;

  case 23:
#line 196 "src/parser.y"
                                    { 
      pc+=3;
      if(!prviProlaz){
        code.dodajByte(trenOp.reg | ((yyvsp[-2].ival) << 4));
        code.dodajByte(trenOp.adresiranje | (trenOp.up << 4));
        if(trenOp.adresiranje==NEPOSR || trenOp.adresiranje==REGDIRPOM || trenOp.adresiranje==REGINDPOM || trenOp.adresiranje==MEM){
            if(trenOp.jesteSimbol){
                code.dodajRel(trenOp.simbol, code.trenSekcija, (unsigned char)pc, trenOp.tipRel);
            }
            else{
                code.dodajWord(trenOp.vrednost);
            }
        }
      }
      if(trenOp.adresiranje==NEPOSR || trenOp.adresiranje==REGDIRPOM || trenOp.adresiranje==REGINDPOM || trenOp.adresiranje==MEM){
        pc+=2;          
      }
    }
#line 1665 "src/bison.cpp"
    break;

  case 24:
#line 214 "src/parser.y"
                 { 
      pc+=3;
      if(!prviProlaz){
          code.dodajByte(0x6 | ((yyvsp[0].ival) << 4)); //sp=r6
          code.dodajByte(REGIND | (trenOp.up << 4));
      }
    }
#line 1677 "src/bison.cpp"
    break;

  case 25:
#line 223 "src/parser.y"
          { if(!prviProlaz) code.dodajByte(0x00); }
#line 1683 "src/bison.cpp"
    break;

  case 26:
#line 224 "src/parser.y"
          { if(!prviProlaz) code.dodajByte(0x20); }
#line 1689 "src/bison.cpp"
    break;

  case 27:
#line 225 "src/parser.y"
          { if(!prviProlaz) code.dodajByte(0x40); }
#line 1695 "src/bison.cpp"
    break;

  case 28:
#line 228 "src/parser.y"
          { if(!prviProlaz)code.dodajByte(0x30); }
#line 1701 "src/bison.cpp"
    break;

  case 29:
#line 229 "src/parser.y"
          { if(!prviProlaz)code.dodajByte(0x50); }
#line 1707 "src/bison.cpp"
    break;

  case 30:
#line 230 "src/parser.y"
          { if(!prviProlaz)code.dodajByte(0x51); }
#line 1713 "src/bison.cpp"
    break;

  case 31:
#line 231 "src/parser.y"
          { if(!prviProlaz)code.dodajByte(0x52); }
#line 1719 "src/bison.cpp"
    break;

  case 32:
#line 232 "src/parser.y"
          { if(!prviProlaz)code.dodajByte(0x53); }
#line 1725 "src/bison.cpp"
    break;

  case 33:
#line 235 "src/parser.y"
            { if(!prviProlaz) code.dodajByte(0x10); }
#line 1731 "src/bison.cpp"
    break;

  case 34:
#line 236 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x80); }
#line 1737 "src/bison.cpp"
    break;

  case 35:
#line 239 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x60); }
#line 1743 "src/bison.cpp"
    break;

  case 36:
#line 240 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x70); }
#line 1749 "src/bison.cpp"
    break;

  case 37:
#line 241 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x71); }
#line 1755 "src/bison.cpp"
    break;

  case 38:
#line 242 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x72); }
#line 1761 "src/bison.cpp"
    break;

  case 39:
#line 243 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x73); }
#line 1767 "src/bison.cpp"
    break;

  case 40:
#line 244 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x74); }
#line 1773 "src/bison.cpp"
    break;

  case 41:
#line 245 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x81); }
#line 1779 "src/bison.cpp"
    break;

  case 42:
#line 246 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x82); }
#line 1785 "src/bison.cpp"
    break;

  case 43:
#line 247 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x83); }
#line 1791 "src/bison.cpp"
    break;

  case 44:
#line 248 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x84); }
#line 1797 "src/bison.cpp"
    break;

  case 45:
#line 249 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x90); }
#line 1803 "src/bison.cpp"
    break;

  case 46:
#line 250 "src/parser.y"
              { if(!prviProlaz) code.dodajByte(0x91); }
#line 1809 "src/bison.cpp"
    break;

  case 47:
#line 253 "src/parser.y"
        { if(!prviProlaz) code.dodajByte(0xA0); }
#line 1815 "src/bison.cpp"
    break;

  case 48:
#line 254 "src/parser.y"
        { if(!prviProlaz) code.dodajByte(0xB0); }
#line 1821 "src/bison.cpp"
    break;

  case 49:
#line 257 "src/parser.y"
         { if(!prviProlaz) {code.dodajByte(0xB0); trenOp.up=0x1;} }
#line 1827 "src/bison.cpp"
    break;

  case 50:
#line 258 "src/parser.y"
         { if(!prviProlaz) {code.dodajByte(0xA0); trenOp.up=0x4;} }
#line 1833 "src/bison.cpp"
    break;

  case 51:
#line 261 "src/parser.y"
         { trenOp.adresiranje=NEPOSR; trenOp.vrednost=(yyvsp[0].ival); trenOp.reg=0xF; trenOp.jesteSimbol=false; }
#line 1839 "src/bison.cpp"
    break;

  case 52:
#line 262 "src/parser.y"
           { trenOp.adresiranje=NEPOSR; trenOp.reg=0xF; trenOp.jesteSimbol=true; trenOp.simbol=(yyvsp[0].sval); trenOp.tipRel=0; }
#line 1845 "src/bison.cpp"
    break;

  case 53:
#line 263 "src/parser.y"
                   { trenOp.adresiranje=REGDIRPOM; trenOp.reg=7; trenOp.simbol=(yyvsp[0].sval); trenOp.jesteSimbol=true; trenOp.tipRel=1; }
#line 1851 "src/bison.cpp"
    break;

  case 54:
#line 264 "src/parser.y"
                  { trenOp.adresiranje=MEM; trenOp.vrednost=(yyvsp[0].ival); trenOp.reg=0xF; trenOp.jesteSimbol=false; }
#line 1857 "src/bison.cpp"
    break;

  case 55:
#line 265 "src/parser.y"
                  { trenOp.adresiranje=MEM; trenOp.reg=0xF; trenOp.simbol=(yyvsp[0].sval); trenOp.jesteSimbol=true; trenOp.tipRel=0; }
#line 1863 "src/bison.cpp"
    break;

  case 56:
#line 266 "src/parser.y"
               { trenOp.adresiranje=REGDIR; trenOp.reg=(yyvsp[0].ival); trenOp.vrednost=0xFF; trenOp.jesteSimbol=false; }
#line 1869 "src/bison.cpp"
    break;

  case 57:
#line 267 "src/parser.y"
                                       { trenOp.adresiranje=REGIND; trenOp.reg=(yyvsp[-1].ival); trenOp.vrednost=0xFF; trenOp.up=0; trenOp.jesteSimbol=false; }
#line 1875 "src/bison.cpp"
    break;

  case 58:
#line 268 "src/parser.y"
                                                   { trenOp.adresiranje=REGINDPOM; trenOp.reg=(yyvsp[-3].ival); trenOp.vrednost=(yyvsp[-1].ival); trenOp.up=0; trenOp.jesteSimbol=false; }
#line 1881 "src/bison.cpp"
    break;

  case 59:
#line 269 "src/parser.y"
                                                   { trenOp.adresiranje=REGINDPOM; trenOp.reg=(yyvsp[-3].ival); trenOp.jesteSimbol=true; trenOp.up=0; trenOp.simbol=(yyvsp[-1].sval); trenOp.tipRel=0; }
#line 1887 "src/bison.cpp"
    break;

  case 60:
#line 272 "src/parser.y"
                { trenOp.adresiranje=NEPOSR; trenOp.simbol=(yyvsp[0].ival); trenOp.reg=0xF; trenOp.up=0; trenOp.jesteSimbol=false; }
#line 1893 "src/bison.cpp"
    break;

  case 61:
#line 273 "src/parser.y"
                  { trenOp.adresiranje=NEPOSR; trenOp.simbol=(yyvsp[0].sval); trenOp.tipRel=0; trenOp.reg=0xF; trenOp.jesteSimbol=false; }
#line 1899 "src/bison.cpp"
    break;

  case 62:
#line 274 "src/parser.y"
           { trenOp.adresiranje=MEM; trenOp.vrednost=(yyvsp[0].ival); trenOp.reg=0xF; trenOp.jesteSimbol=false; }
#line 1905 "src/bison.cpp"
    break;

  case 63:
#line 275 "src/parser.y"
           { trenOp.adresiranje=MEM; trenOp.reg=0x0F; trenOp.jesteSimbol=true; trenOp.simbol=(yyvsp[0].sval); trenOp.tipRel=0; }
#line 1911 "src/bison.cpp"
    break;

  case 64:
#line 276 "src/parser.y"
                   { trenOp.adresiranje=REGINDPOM; trenOp.reg=7; trenOp.up=0; trenOp.tipRel=1; trenOp.simbol=(yyvsp[0].sval); trenOp.jesteSimbol=true; }
#line 1917 "src/bison.cpp"
    break;

  case 65:
#line 277 "src/parser.y"
        { trenOp.adresiranje=REGDIR; trenOp.reg=(yyvsp[0].ival); trenOp.jesteSimbol=false; }
#line 1923 "src/bison.cpp"
    break;

  case 66:
#line 278 "src/parser.y"
                                { trenOp.adresiranje=REGIND; trenOp.reg=(yyvsp[-1].ival); trenOp.up=0; trenOp.jesteSimbol=false; }
#line 1929 "src/bison.cpp"
    break;

  case 67:
#line 279 "src/parser.y"
                                             { trenOp.adresiranje=REGINDPOM; trenOp.up=0; trenOp.reg=(yyvsp[-3].ival); trenOp. vrednost=(yyvsp[-1].ival); trenOp.jesteSimbol=false; }
#line 1935 "src/bison.cpp"
    break;

  case 68:
#line 280 "src/parser.y"
                                            { trenOp.adresiranje=REGINDPOM; trenOp.up=0; trenOp.reg=(yyvsp[-3].ival); trenOp.jesteSimbol=true; trenOp.simbol=(yyvsp[-1].sval); trenOp.tipRel=0; }
#line 1941 "src/bison.cpp"
    break;

  case 69:
#line 283 "src/parser.y"
         { symList.clear(); symList.push_back(string((yyvsp[0].sval))); }
#line 1947 "src/bison.cpp"
    break;

  case 70:
#line 284 "src/parser.y"
                          { symList.push_back(string((yyvsp[0].sval))); }
#line 1953 "src/bison.cpp"
    break;

  case 71:
#line 287 "src/parser.y"
           { (yyval.ival)=(yyvsp[0].ival); }
#line 1959 "src/bison.cpp"
    break;

  case 72:
#line 288 "src/parser.y"
                  { (yyval.ival)=(yyvsp[0].ival); }
#line 1965 "src/bison.cpp"
    break;

  case 73:
#line 289 "src/parser.y"
                   { (yyval.ival)=-1*(yyvsp[0].ival); }
#line 1971 "src/bison.cpp"
    break;

  case 74:
#line 292 "src/parser.y"
        {
      sym_lit sym={true,(yyvsp[0].sval)};
      symLitList.clear();
      symLitList.push_back(sym);
  }
#line 1981 "src/bison.cpp"
    break;

  case 75:
#line 297 "src/parser.y"
           {
      sym_lit lit={false, "", (yyvsp[0].ival)};
      lit.vrednost=(yyvsp[0].ival);
      symLitList.clear();
      symLitList.push_back(lit);
  }
#line 1992 "src/bison.cpp"
    break;

  case 76:
#line 303 "src/parser.y"
                             {
      sym_lit sym={true, (yyvsp[0].sval), 0};
      symLitList.push_back(sym);
  }
#line 2001 "src/bison.cpp"
    break;

  case 77:
#line 307 "src/parser.y"
                              {
      sym_lit lit={false, "", (yyvsp[0].ival)};
      lit.vrednost=(yyvsp[0].ival);
      symLitList.push_back(lit);
  }
#line 2011 "src/bison.cpp"
    break;


#line 2015 "src/bison.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 314 "src/parser.y"


void yyerror(const char* s){
    cout << "Parse error on line " << red << ":" << s << endl;
    exit(-1);
}
