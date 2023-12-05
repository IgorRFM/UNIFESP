/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y"

#define YYSTYPE TreeNode *
#include <stdio.h>
#include <stdlib.h>

#define YYPARSER 
int yyerror(char * message);
#include "lex.h"
#include "util.h"
static int yylex(void);
static int yywrap(void);

TokenType toktok = ERROR;
extern char tokenString_atual[100];
static int savedNumber;
static TreeNode* aas;

// #include "defit_NEQs.h"


#line 92 "bison.tab.c"

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

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_t_IF = 3,                       /* t_IF  */
  YYSYMBOL_t_ELSE = 4,                     /* t_ELSE  */
  YYSYMBOL_t_INT = 5,                      /* t_INT  */
  YYSYMBOL_t_RETURN = 6,                   /* t_RETURN  */
  YYSYMBOL_t_VOID = 7,                     /* t_VOID  */
  YYSYMBOL_t_WHILE = 8,                    /* t_WHILE  */
  YYSYMBOL_t_ID = 9,                       /* t_ID  */
  YYSYMBOL_t_NUM = 10,                     /* t_NUM  */
  YYSYMBOL_t_LT = 11,                      /* t_LT  */
  YYSYMBOL_t_LTE = 12,                     /* t_LTE  */
  YYSYMBOL_t_GT = 13,                      /* t_GT  */
  YYSYMBOL_t_GTE = 14,                     /* t_GTE  */
  YYSYMBOL_t_EQ = 15,                      /* t_EQ  */
  YYSYMBOL_t_NEQ = 16,                     /* t_NEQ  */
  YYSYMBOL_17_ = 17,                       /* ';'  */
  YYSYMBOL_18_ = 18,                       /* '['  */
  YYSYMBOL_19_ = 19,                       /* ']'  */
  YYSYMBOL_20_ = 20,                       /* '('  */
  YYSYMBOL_21_ = 21,                       /* ')'  */
  YYSYMBOL_22_ = 22,                       /* ','  */
  YYSYMBOL_23_ = 23,                       /* '='  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_t_programa = 29,                /* t_programa  */
  YYSYMBOL_t_declList = 30,                /* t_declList  */
  YYSYMBOL_t_decl = 31,                    /* t_decl  */
  YYSYMBOL_t_vardecl = 32,                 /* t_vardecl  */
  YYSYMBOL_t_tipoEspec = 33,               /* t_tipoEspec  */
  YYSYMBOL_t_funDecl = 34,                 /* t_funDecl  */
  YYSYMBOL_t_params = 35,                  /* t_params  */
  YYSYMBOL_t_paramList = 36,               /* t_paramList  */
  YYSYMBOL_t_param = 37,                   /* t_param  */
  YYSYMBOL_t_compdecl = 38,                /* t_compdecl  */
  YYSYMBOL_t_localdecl = 39,               /* t_localdecl  */
  YYSYMBOL_t_stmtlista = 40,               /* t_stmtlista  */
  YYSYMBOL_t_stmt = 41,                    /* t_stmt  */
  YYSYMBOL_t_expdecl = 42,                 /* t_expdecl  */
  YYSYMBOL_t_selecdecl = 43,               /* t_selecdecl  */
  YYSYMBOL_t_iterdecl = 44,                /* t_iterdecl  */
  YYSYMBOL_t_retornodecl = 45,             /* t_retornodecl  */
  YYSYMBOL_t_exp = 46,                     /* t_exp  */
  YYSYMBOL_t_VAR = 47,                     /* t_VAR  */
  YYSYMBOL_48_1 = 48,                      /* @1  */
  YYSYMBOL_t_simpleexp = 49,               /* t_simpleexp  */
  YYSYMBOL_t_comp = 50,                    /* t_comp  */
  YYSYMBOL_t_somaexp = 51,                 /* t_somaexp  */
  YYSYMBOL_t_soma = 52,                    /* t_soma  */
  YYSYMBOL_t_termo = 53,                   /* t_termo  */
  YYSYMBOL_t_mult = 54,                    /* t_mult  */
  YYSYMBOL_t_fator = 55,                   /* t_fator  */
  YYSYMBOL_t_ativ = 56,                    /* t_ativ  */
  YYSYMBOL_57_2 = 57,                      /* @2  */
  YYSYMBOL_t_args = 58,                    /* t_args  */
  YYSYMBOL_t_arglista = 59                 /* t_arglista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   101

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,    21,    26,    24,    22,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    17,
       2,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,     2,    19,     2,     2,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    33,    33,    39,    52,    55,    57,    60,    67,    77,
      80,    86,    97,    99,   108,   111,   117,   124,   133,   145,
     148,   160,   163,   164,   165,   166,   167,   170,   171,   174,
     181,   190,   200,   206,   214,   221,   226,   232,   232,   244,
     252,   257,   263,   269,   275,   281,   286,   294,   302,   307,
     313,   321,   329,   332,   338,   346,   347,   348,   349,   356,
     356,   366,   367,   370,   382
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "t_IF", "t_ELSE",
  "t_INT", "t_RETURN", "t_VOID", "t_WHILE", "t_ID", "t_NUM", "t_LT",
  "t_LTE", "t_GT", "t_GTE", "t_EQ", "t_NEQ", "';'", "'['", "']'", "'('",
  "')'", "','", "'='", "'+'", "'-'", "'*'", "'/'", "$accept", "t_programa",
  "t_declList", "t_decl", "t_vardecl", "t_tipoEspec", "t_funDecl",
  "t_params", "t_paramList", "t_param", "t_compdecl", "t_localdecl",
  "t_stmtlista", "t_stmt", "t_expdecl", "t_selecdecl", "t_iterdecl",
  "t_retornodecl", "t_exp", "t_VAR", "@1", "t_simpleexp", "t_comp",
  "t_somaexp", "t_soma", "t_termo", "t_mult", "t_fator", "t_ativ", "@2",
  "t_args", "t_arglista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,   -69,   -69,    11,     9,   -69,   -69,    13,   -69,   -69,
     -69,    40,   -69,    17,     9,    19,    33,    34,    44,   -69,
      42,    53,    54,     9,   -69,    55,   -69,   -69,   -69,   -69,
       9,   -69,    64,     0,   -16,    43,    -5,    56,    57,   -69,
     -69,    66,   -69,    36,   -69,   -69,   -69,   -69,   -69,   -69,
      61,    58,   -69,    37,    41,   -69,   -69,    36,   -69,    66,
      62,    36,    60,    63,    65,   -69,    36,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,    36,    36,   -69,   -69,    36,
      67,   -69,    68,    36,   -69,   -69,   -69,   -69,    45,    41,
     -69,    23,    23,   -69,    69,    70,    73,    79,   -69,   -69,
      36,    36,    23,   -69,    74,   -69,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     7,     0,     0,     0,     0,     0,    12,    14,
       0,    15,     0,     0,     8,     0,    19,    11,    13,    16,
      21,    18,     0,     0,     0,     0,     0,     0,    36,    58,
      28,    19,    17,     0,    23,    20,    22,    24,    25,    26,
       0,    56,    35,    40,    48,    52,    57,     0,    32,     0,
       0,     0,     0,     0,     0,    27,     0,    41,    42,    43,
      44,    45,    46,    49,    50,     0,     0,    53,    54,     0,
       0,    33,     0,    62,    37,    55,    34,    56,    39,    47,
      51,     0,     0,    64,     0,    61,     0,    29,    31,    60,
       0,     0,     0,    63,     0,    30,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,    80,    71,    14,   -69,   -69,   -69,    72,
      75,   -69,   -69,   -68,   -69,   -69,   -69,   -69,   -36,   -40,
     -69,   -69,   -69,    10,   -69,    18,   -69,     8,   -69,   -69,
     -69,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      44,    30,    33,    45,    46,    47,    48,    49,    50,    51,
      96,    52,    75,    53,    76,    54,    79,    55,    56,    62,
      94,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    12,    13,    35,    38,    39,    36,    64,    37,    38,
      39,     9,    58,    59,     1,    43,     2,    40,    41,    42,
      43,    80,    11,    97,    98,    82,    35,    15,    16,    36,
      86,    37,    38,    39,   105,    87,    87,    16,    20,    87,
      40,    41,    21,    43,    32,    38,    39,    93,    67,    68,
      69,    70,    71,    72,    59,    22,    43,    12,    13,    24,
      14,    73,    74,    57,   103,   104,    23,    77,    78,    73,
      74,    25,    26,    34,    29,    63,    61,   -59,    65,    81,
      83,    66,    84,   102,    10,    88,    85,    90,    91,    92,
      99,   101,   100,   106,    89,    28,     0,    27,     0,     0,
       0,    31
};

static const yytype_int8 yycheck[] =
{
      36,    17,    18,     3,     9,    10,     6,    43,     8,     9,
      10,     0,    17,    18,     5,    20,     7,    17,    18,    19,
      20,    57,     9,    91,    92,    61,     3,    10,    14,     6,
      66,     8,     9,    10,   102,    75,    76,    23,    19,    79,
      17,    18,     9,    20,    30,     9,    10,    83,    11,    12,
      13,    14,    15,    16,    18,    21,    20,    17,    18,    17,
      20,    24,    25,    20,   100,   101,    22,    26,    27,    24,
      25,    18,    18,     9,    19,     9,    20,    20,    17,    17,
      20,    23,    19,     4,     4,    75,    21,    79,    21,    21,
      21,    18,    22,    19,    76,    23,    -1,    22,    -1,    -1,
      -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    29,    30,    31,    32,    33,    34,     0,
      31,     9,    17,    18,    20,    10,    33,    35,    36,    37,
      19,     9,    21,    22,    17,    18,    18,    38,    37,    19,
      39,    32,    33,    40,     9,     3,     6,     8,     9,    10,
      17,    18,    19,    20,    38,    41,    42,    43,    44,    45,
      46,    47,    49,    51,    53,    55,    56,    20,    17,    18,
      46,    20,    57,     9,    46,    17,    23,    11,    12,    13,
      14,    15,    16,    24,    25,    50,    52,    26,    27,    54,
      46,    17,    46,    20,    19,    21,    46,    47,    51,    53,
      55,    21,    21,    46,    58,    59,    48,    41,    41,    21,
      22,    18,     4,    46,    46,    41,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    31,    32,    32,    33,
      33,    34,    35,    36,    36,    37,    37,    38,    39,    39,
      40,    40,    41,    41,    41,    41,    41,    42,    42,    43,
      43,    44,    45,    45,    46,    46,    47,    48,    47,    49,
      49,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    55,    55,    57,
      56,    58,    58,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     3,     1,     2,     4,     4,     2,     0,
       2,     0,     1,     1,     1,     1,     1,     2,     1,     5,
       7,     5,     2,     3,     3,     1,     1,     0,     7,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     0,
       5,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* t_programa: t_declList  */
#line 33 "bison.y"
                       {
                printTree(aas);
                aas=yyvsp[0];
                printf("Programa\n");
                }
#line 1212 "bison.tab.c"
    break;

  case 3: /* t_declList: t_declList t_decl  */
#line 40 "bison.y"
            { printf("decl list\n");
              TreeNode * t = yyvsp[-1];
              if( t == NULL){
                yyval = yyvsp[0];
            }else{
              while(t->sibling != NULL){ // percorre ate o ut_LTimo irmao
                t = t->sibling;
              }
              t->sibling = yyvsp[0];
              yyval = yyvsp[-1];
            }
            }
#line 1229 "bison.tab.c"
    break;

  case 4: /* t_declList: t_decl  */
#line 52 "bison.y"
                  {yyval = yyvsp[0]; printf("decl\n");}
#line 1235 "bison.tab.c"
    break;

  case 5: /* t_decl: t_vardecl  */
#line 55 "bison.y"
                   {yyval = yyvsp[0];
printf("decl\n");}
#line 1242 "bison.tab.c"
    break;

  case 6: /* t_decl: t_funDecl  */
#line 57 "bison.y"
                 {yyval = yyvsp[0];printf("decl\n");}
#line 1248 "bison.tab.c"
    break;

  case 7: /* t_vardecl: t_tipoEspec t_ID ';'  */
#line 60 "bison.y"
                                 {
  printf("var decl\n");
  yyval = newDeclNode(VarK);
                                  yyval->child[0] = yyvsp[-2];
                                  yyval->attr.name = buffer->buf;
                                  yyval->lineno = buffer->linha;
                                  }
#line 1260 "bison.tab.c"
    break;

  case 8: /* t_vardecl: t_tipoEspec t_ID '[' t_NUM ']' ';'  */
#line 67 "bison.y"
                                             {
          printf("[var decl]\n");
               yyval = newDeclNode(ArrVarK);
                    yyval->child[0] = yyvsp[-5];
                    yyval->lineno = buffer->linha;
                    yyval->type = IntegerArray;
                    yyval->attr.name = buffer->buf;
                    yyval->attr.val = savedNumber;}
#line 1273 "bison.tab.c"
    break;

  case 9: /* t_tipoEspec: t_INT  */
#line 77 "bison.y"
                    {yyval = newExpNode(TypeK);
                    yyval->type = Integer;
                    printf("Tipo espec. INT\n");}
#line 1281 "bison.tab.c"
    break;

  case 10: /* t_tipoEspec: t_VOID  */
#line 80 "bison.y"
                  {
            printf("Tipo espec. VOID\n");
            yyval = newExpNode(TypeK);
                    yyval->type = Void;}
#line 1290 "bison.tab.c"
    break;

  case 11: /* t_funDecl: t_tipoEspec t_ID '(' t_params ')' t_compdecl  */
#line 86 "bison.y"
                                                         {
  printf("fun decl\n");
              yyval = newDeclNode(FunK);
              yyval->lineno = buffer->linha;
              yyval->attr.name = buffer->buf;
              yyval->child[0] = yyvsp[-5];
              yyval->child[1] = yyvsp[-2];
              yyval->child[2] = yyvsp[0];
            }
#line 1304 "bison.tab.c"
    break;

  case 12: /* t_params: t_paramList  */
#line 97 "bison.y"
                       {yyval = yyvsp[0]; printf("params\n");}
#line 1310 "bison.tab.c"
    break;

  case 13: /* t_paramList: t_paramList ',' t_param  */
#line 99 "bison.y"
                                      {
            printf("param list\n");
            TreeNode *t = yyvsp[-2];
            while(t->sibling != NULL){ // percorre ate o ut_LTimo irmao
              t = t->sibling;
            }
            t->sibling = yyvsp[0];
            yyval = yyvsp[-2];
            }
#line 1324 "bison.tab.c"
    break;

  case 14: /* t_paramList: t_param  */
#line 108 "bison.y"
                      {yyval = yyvsp[0];}
#line 1330 "bison.tab.c"
    break;

  case 15: /* t_param: t_tipoEspec t_ID  */
#line 111 "bison.y"
                           {
        printf("param\n");
          yyval = newDeclNode(ParamK);
          yyval->child[0] = yyvsp[-1];
          yyval->attr.name = buffer->buf;
          }
#line 1341 "bison.tab.c"
    break;

  case 16: /* t_param: t_tipoEspec t_ID '[' ']'  */
#line 117 "bison.y"
                                     {
            printf("param\n");
            yyval = newDeclNode(ArrParamK);
            yyval->child[0] = yyvsp[-3];
            strcpy(yyval->attr.name, buffer->buf);
          }
#line 1352 "bison.tab.c"
    break;

  case 17: /* t_compdecl: '[' t_localdecl t_stmtlista ']'  */
#line 125 "bison.y"
                { 
                  printf("comp decl\n");
                  yyval = newStmtNode(CompoundK);
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[-1];
                }
#line 1363 "bison.tab.c"
    break;

  case 18: /* t_localdecl: t_localdecl t_vardecl  */
#line 134 "bison.y"
                     {
                      printf("local dcl\n"); 
                      TreeNode * t = yyvsp[-1];
                       if (t != NULL) {
                         while (t->sibling != NULL) { t = t->sibling; }
                         t->sibling = yyvsp[0];
                         yyval = yyvsp[-1];
                       } else {
                         yyval = yyvsp[0];
                       }
                     }
#line 1379 "bison.tab.c"
    break;

  case 19: /* t_localdecl: %empty  */
#line 145 "bison.y"
                     { yyval = NULL; }
#line 1385 "bison.tab.c"
    break;

  case 20: /* t_stmtlista: t_stmtlista t_stmt  */
#line 149 "bison.y"
                 {
                  printf("stmt lista\n "); 
                  TreeNode * t = yyvsp[-1];
                   if (t != NULL) {
                     while (t->sibling != NULL) { t = t->sibling; }
                    t->sibling = yyvsp[0];
                    yyval = yyvsp[-1];
                   } else {
                     yyval = yyvsp[0];
                   }
                 }
#line 1401 "bison.tab.c"
    break;

  case 21: /* t_stmtlista: %empty  */
#line 160 "bison.y"
                 { yyval = NULL; }
#line 1407 "bison.tab.c"
    break;

  case 22: /* t_stmt: t_expdecl  */
#line 163 "bison.y"
                   { yyval = yyvsp[0]; printf("stmt exp\n" );}
#line 1413 "bison.tab.c"
    break;

  case 23: /* t_stmt: t_compdecl  */
#line 164 "bison.y"
                       { yyval = yyvsp[0]; printf("stmt comp\n");}
#line 1419 "bison.tab.c"
    break;

  case 24: /* t_stmt: t_selecdecl  */
#line 165 "bison.y"
                        { yyval = yyvsp[0]; printf("stmt selec\n");}
#line 1425 "bison.tab.c"
    break;

  case 25: /* t_stmt: t_iterdecl  */
#line 166 "bison.y"
                       { yyval = yyvsp[0]; printf("stmt iter\n");}
#line 1431 "bison.tab.c"
    break;

  case 26: /* t_stmt: t_retornodecl  */
#line 167 "bison.y"
                          { yyval = yyvsp[0]; printf("stmt retorno\n");}
#line 1437 "bison.tab.c"
    break;

  case 27: /* t_expdecl: t_exp ';'  */
#line 170 "bison.y"
                      { yyval = yyvsp[-1]; printf(";");}
#line 1443 "bison.tab.c"
    break;

  case 28: /* t_expdecl: ';'  */
#line 171 "bison.y"
                      { yyval = NULL; printf(";");}
#line 1449 "bison.tab.c"
    break;

  case 29: /* t_selecdecl: t_IF '(' t_exp ')' t_stmt  */
#line 175 "bison.y"
                 { 
                  printf( "if(exp)algo\n");
                  yyval = newStmtNode(IfK);
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1460 "bison.tab.c"
    break;

  case 30: /* t_selecdecl: t_IF '(' t_exp ')' t_stmt t_ELSE t_stmt  */
#line 182 "bison.y"
                 { printf( "if(exp)algo else algo\n");
                  yyval = newStmtNode(IfK);
                   yyval->child[0] = yyvsp[-4];
                   yyval->child[1] = yyvsp[-2];
                   yyval->child[2] = yyvsp[0];
                 }
#line 1471 "bison.tab.c"
    break;

  case 31: /* t_iterdecl: t_WHILE '(' t_exp ')' t_stmt  */
#line 191 "bison.y"
                 { 
                    printf( "while\n");
                    
                  yyval = newStmtNode(RepeatK);
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1483 "bison.tab.c"
    break;

  case 32: /* t_retornodecl: t_RETURN ';'  */
#line 201 "bison.y"
              { 
                printf( "return\n");
                yyval = newStmtNode(ReturnK);
                yyval->type = Void;
              }
#line 1493 "bison.tab.c"
    break;

  case 33: /* t_retornodecl: t_RETURN t_exp ';'  */
#line 207 "bison.y"
              { 
                printf( "return\n");
                yyval = newStmtNode(ReturnK);
                yyval->child[0] = yyvsp[-1];
              }
#line 1503 "bison.tab.c"
    break;

  case 34: /* t_exp: t_VAR '=' t_exp  */
#line 215 "bison.y"
             { 
              printf( "exp\n");
              yyval = newStmtNode(AssignK);
               yyval->child[0] = yyvsp[-2];
               yyval->child[1] = yyvsp[0];
             }
#line 1514 "bison.tab.c"
    break;

  case 35: /* t_exp: t_simpleexp  */
#line 221 "bison.y"
                         { 
            printf( "exp_simpleexp\n");
            yyval = yyvsp[0]; }
#line 1522 "bison.tab.c"
    break;

  case 36: /* t_VAR: t_ID  */
#line 227 "bison.y"
      {
        printf( "var\n");
         yyval = newExpNode(IdK);
        yyval->attr.name = buffer->buf;
      }
#line 1532 "bison.tab.c"
    break;

  case 37: /* @1: %empty  */
#line 232 "bison.y"
                 {
      printf( "arr\n");
        yyval = newExpNode(ArrIdK);
        yyval->attr.name = buffer->buf;
      }
#line 1542 "bison.tab.c"
    break;

  case 38: /* t_VAR: '[' t_ID ']' @1 '[' t_exp ']'  */
#line 237 "bison.y"
      {
        printf("[var]\n");
        yyval = yyvsp[-5];
        yyval->child[0] = yyvsp[-3];
      }
#line 1552 "bison.tab.c"
    break;

  case 39: /* t_simpleexp: t_somaexp t_comp t_somaexp  */
#line 245 "bison.y"
                    { 
                      printf( "simpleexp\n");
                      yyval = newExpNode(CalcK);
                      yyval->child[0] = yyvsp[-2];
                      yyval->child[1] = yyvsp[-1];
                      yyval->child[2] = yyvsp[0];
                    }
#line 1564 "bison.tab.c"
    break;

  case 40: /* t_simpleexp: t_somaexp  */
#line 252 "bison.y"
                              { 
                    printf( "simpt_LTEsexp_termo\n");
                    yyval = yyvsp[0]; }
#line 1572 "bison.tab.c"
    break;

  case 41: /* t_comp: t_LT  */
#line 258 "bison.y"
        {
          printf( "lt\n");
           yyval = newExpNode(OpK);
          yyval->attr.op = t_LT;
        }
#line 1582 "bison.tab.c"
    break;

  case 42: /* t_comp: t_LTE  */
#line 264 "bison.y"
        {
          printf( "lte\n");
           yyval = newExpNode(OpK);
          yyval->attr.op = t_LTE;
        }
#line 1592 "bison.tab.c"
    break;

  case 43: /* t_comp: t_GT  */
#line 270 "bison.y"
        {
          printf( "gt\n");
           yyval = newExpNode(OpK);
          yyval->attr.op = t_GT;
        }
#line 1602 "bison.tab.c"
    break;

  case 44: /* t_comp: t_GTE  */
#line 276 "bison.y"
        {
          printf( "gte\n");
           yyval = newExpNode(OpK);
          yyval->attr.op = t_GTE;
        }
#line 1612 "bison.tab.c"
    break;

  case 45: /* t_comp: t_EQ  */
#line 282 "bison.y"
        { printf( "eq\n");
          yyval = newExpNode(OpK);
          yyval->attr.op = t_EQ;
        }
#line 1621 "bison.tab.c"
    break;

  case 46: /* t_comp: t_NEQ  */
#line 287 "bison.y"
        { 
          printf( "neq\n");
          yyval = newExpNode(OpK);
          yyval->attr.op = t_NEQ;
        }
#line 1631 "bison.tab.c"
    break;

  case 47: /* t_somaexp: t_somaexp t_soma t_termo  */
#line 295 "bison.y"
                      { 
                        printf( "somaexp\n");
                        yyval = newExpNode(CalcK);
                        yyval->child[0] = yyvsp[-2];
                        yyval->child[1] = yyvsp[-1];
                        yyval->child[2] = yyvsp[0];
                      }
#line 1643 "bison.tab.c"
    break;

  case 48: /* t_somaexp: t_termo  */
#line 302 "bison.y"
                              {
                      printf( "somaexp_termo\n");
                       yyval = yyvsp[0]; }
#line 1651 "bison.tab.c"
    break;

  case 49: /* t_soma: '+'  */
#line 308 "bison.y"
        { 
          printf("mais\n");
          yyval = newExpNode(OpK);
          yyval->attr.op = PLUS;
        }
#line 1661 "bison.tab.c"
    break;

  case 50: /* t_soma: '-'  */
#line 314 "bison.y"
        { 
          printf("menos\n");
          yyval = newExpNode(OpK);
          yyval->attr.op = MINUS;
        }
#line 1671 "bison.tab.c"
    break;

  case 51: /* t_termo: t_termo t_mult t_fator  */
#line 322 "bison.y"
       {
        printf("termo\n") ;
        yyval = newExpNode(CalcK);
         yyval->child[0] = yyvsp[-2];
         yyval->child[1] = yyvsp[-1];
         yyval->child[2] = yyvsp[0];
       }
#line 1683 "bison.tab.c"
    break;

  case 52: /* t_termo: t_fator  */
#line 329 "bison.y"
               { yyval = yyvsp[0]; }
#line 1689 "bison.tab.c"
    break;

  case 53: /* t_mult: '*'  */
#line 333 "bison.y"
        {
          printf("mult\n");
           yyval = newExpNode(OpK);
          yyval->attr.op = TIMES;
        }
#line 1699 "bison.tab.c"
    break;

  case 54: /* t_mult: '/'  */
#line 339 "bison.y"
        { 
          printf("div\n");
          yyval = newExpNode(OpK);
          yyval->attr.op = OVER;
        }
#line 1709 "bison.tab.c"
    break;

  case 55: /* t_fator: '(' t_exp ')'  */
#line 346 "bison.y"
                        { yyval = yyvsp[-1]; printf( "(fator)\n");}
#line 1715 "bison.tab.c"
    break;

  case 56: /* t_fator: t_VAR  */
#line 347 "bison.y"
               { yyval = yyvsp[0]; printf( "fator_var\n");}
#line 1721 "bison.tab.c"
    break;

  case 57: /* t_fator: t_ativ  */
#line 348 "bison.y"
                { yyval = yyvsp[0]; printf( "fator_ativ\n"); }
#line 1727 "bison.tab.c"
    break;

  case 58: /* t_fator: t_NUM  */
#line 350 "bison.y"
         { yyval = newExpNode(ConstK);
           yyval->type = Integer;
           yyval->attr.val = atoi(buffer->buf);
         }
#line 1736 "bison.tab.c"
    break;

  case 59: /* @2: %empty  */
#line 356 "bison.y"
              {
        printf("ativ\n");
         yyval = newExpNode(CallK);
         yyval->attr.name = buffer->buf;
         }
#line 1746 "bison.tab.c"
    break;

  case 60: /* t_ativ: t_ID @2 '(' t_args ')'  */
#line 360 "bison.y"
                          {
           yyval = yyvsp[-3];
           yyval->child[0] = yyvsp[-1];
       }
#line 1755 "bison.tab.c"
    break;

  case 61: /* t_args: t_arglista  */
#line 366 "bison.y"
                    { yyval = yyvsp[0]; printf("args\n"); }
#line 1761 "bison.tab.c"
    break;

  case 62: /* t_args: %empty  */
#line 367 "bison.y"
       { printf( "null\n"); yyval = NULL; }
#line 1767 "bison.tab.c"
    break;

  case 63: /* t_arglista: t_arglista ',' t_exp  */
#line 371 "bison.y"
           {
            printf("arglista\n");
            TreeNode * t = yyvsp[-2];
             if (t != NULL) {
               while (t->sibling != NULL) { t = t->sibling; }
               t->sibling = yyvsp[0];
               yyval = yyvsp[-2];
             } else {
               yyval = yyvsp[0];
             }
           }
#line 1783 "bison.tab.c"
    break;

  case 64: /* t_arglista: t_exp  */
#line 382 "bison.y"
                 { yyval = yyvsp[0]; }
#line 1789 "bison.tab.c"
    break;


#line 1793 "bison.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 407 "bison.y"


/**************************/
/* Additional C code      */
/**************************/

int yyerror(char * message) {
  printf("\033[0;31m");
  printf("Syntax error at line %d: %s\n",buffer->linha,message);
  printf("Current token: ");
  printf("%s(%d)\n",tokenString_atual, toktok);
  printf("\033[0m");
  Error = TRUE;
  exit(1);
}


static int yylex(void) { 
  toktok = ERROR;
  toktok = tabledriven(tokenString_atual, toktok, TRUE);
  int temp = toktok;
  toktok = ajusta_token(toktok);
  // yylval.f = atof(tokenString_atual);

  return toktok;
}

// TreeNode * parse(void) {
//   yyparse();
//   t_RETURN savedTree;
// }
