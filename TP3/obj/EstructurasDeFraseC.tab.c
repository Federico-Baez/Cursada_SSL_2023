
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "src/EstructurasDeFraseC.y"


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

/* Declaraciones de variables globales */
int flag_error=0;
extern FILE *yyout;
extern FILE *yyin;
extern int yylineno;

int lineaSentencia;
int lineaError;

/* Declaraciones de estructuras de datos globales */ 
struct nodoDeclaracion* ListaDeclaraciones = NULL;
struct nodoFuncion* ListaFunciones = NULL;
struct nodoSentencia* ListaSentencias = NULL;



/* Line 189 of yacc.c  */
#line 99 "obj/EstructurasDeFraseC.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONSTANTES = 258,
     LITERAL_CADENA = 259,
     IDENTIFICADOR = 260,
     TIPOS_DE_DATOS = 261,
     PRESERVADA = 262,
     MODALIDAD = 263,
     AND = 264,
     PUNTUACION = 265,
     INCREMENTO = 266,
     DECREMENTO = 267,
     SUMADIRECTA = 268,
     RESTADIRECTA = 269,
     OR = 270,
     VOID = 271,
     MAYORIGUAL = 272,
     MENORIGUAL = 273,
     PERTENECE = 274,
     DESIGUALDAD = 275,
     IGUALDAD = 276,
     RETURN = 277,
     IF = 278,
     DO = 279,
     WHILE = 280,
     ELSE = 281,
     FOR = 282,
     TYPEDEF = 283,
     SIZEOF = 284,
     SWITCH = 285,
     CASE = 286,
     BREAK = 287,
     CONTINUE = 288,
     CONTROLOTRA = 289,
     OPERADOR = 290,
     CONDICION = 291,
     DEFAULT = 292,
     NEG = 293,
     POS = 294,
     PUNT = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "src/EstructurasDeFraseC.y"

  char string[50];
  char tipo[10];



/* Line 214 of yacc.c  */
#line 182 "obj/EstructurasDeFraseC.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 207 "obj/EstructurasDeFraseC.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,     2,    43,     2,
      52,    53,    38,    40,    42,    41,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    55,
      57,    47,    56,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    14,    16,    19,
      21,    23,    27,    29,    31,    33,    35,    41,    43,    47,
      49,    53,    55,    59,    62,    64,    68,    70,    72,    74,
      76,    78,    82,    86,    88,    92,    96,    98,   101,   104,
     107,   110,   113,   116,   118,   120,   122,   127,   132,   134,
     138,   140,   142,   144,   146,   149,   152,   155,   161,   167,
     174,   181,   182,   184,   188,   191,   194,   197,   199,   203,
     205,   209,   211,   215,   219,   220,   223,   225,   227,   229,
     231,   233,   235,   237,   239,   242,   243,   252,   253,   260,
     261,   268,   269,   278,   279,   290,   294,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    -1,    62,    63,    -1,    54,    -1,    95,
      -1,    95,    54,    -1,     1,    -1,     1,    55,    -1,    65,
      -1,    67,    -1,    76,    66,    65,    -1,    47,    -1,    13,
      -1,    14,    -1,    68,    -1,    68,    46,    64,    45,    64,
      -1,    69,    -1,    68,    15,    69,    -1,    70,    -1,    69,
       9,    70,    -1,    72,    -1,    70,    71,    72,    -1,    21,
      20,    -1,    74,    -1,    72,    73,    74,    -1,    56,    -1,
      57,    -1,    18,    -1,    17,    -1,    75,    -1,    74,    40,
      75,    -1,    74,    41,    75,    -1,    76,    -1,    75,    38,
      76,    -1,    75,    39,    76,    -1,    78,    -1,    76,    11,
      -1,    76,    12,    -1,    77,    76,    -1,    41,    76,    -1,
      40,    76,    -1,    38,    76,    -1,    43,    -1,    44,    -1,
      81,    -1,    78,    50,    64,    51,    -1,    78,    52,    79,
      53,    -1,    80,    -1,    79,    42,    80,    -1,    64,    -1,
       3,    -1,     5,    -1,     4,    -1,    87,    55,    -1,    88,
      55,    -1,    83,    55,    -1,     6,     5,    52,    85,    53,
      -1,    16,     5,    52,    85,    53,    -1,     6,     5,    52,
      85,    53,    93,    -1,    16,     5,    52,    85,    53,    93,
      -1,    -1,    86,    -1,    85,    42,    86,    -1,     6,     5,
      -1,     6,    89,    -1,     6,    90,    -1,    91,    -1,    91,
      42,    89,    -1,    92,    -1,    92,    42,    90,    -1,     5,
      -1,     5,    47,    65,    -1,    48,    94,    49,    -1,    -1,
      63,    94,    -1,    93,    -1,    96,    -1,    97,    -1,   100,
      -1,   104,    -1,    82,    -1,    84,    -1,    55,    -1,    64,
      55,    -1,    -1,    98,    23,    52,    64,    53,    95,    26,
      95,    -1,    -1,    99,    23,    52,    64,    53,    95,    -1,
      -1,   101,    25,    52,    64,    53,    95,    -1,    -1,   102,
      24,    95,    25,    52,    64,    53,    55,    -1,    -1,   103,
      27,    52,   105,    55,   105,    55,   105,    53,    93,    -1,
      22,    64,    55,    -1,    -1,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    61,    65,    66,    67,    68,    69,    75,
      79,    80,    84,    85,    86,    90,    91,    95,    96,   100,
     101,   105,   106,   110,   114,   115,   119,   120,   121,   122,
     126,   127,   128,   132,   133,   134,   138,   139,   140,   141,
     142,   143,   144,   148,   149,   153,   154,   155,   159,   160,
     164,   168,   169,   170,   176,   177,   178,   183,   184,   188,
     189,   192,   194,   195,   199,   203,   207,   212,   213,   217,
     218,   222,   226,   232,   235,   237,   241,   243,   245,   247,
     249,   251,   253,   257,   258,   263,   263,   264,   264,   268,
     268,   269,   269,   270,   270,   274,   277,   279
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANTES", "LITERAL_CADENA",
  "IDENTIFICADOR", "TIPOS_DE_DATOS", "PRESERVADA", "MODALIDAD", "AND",
  "PUNTUACION", "INCREMENTO", "DECREMENTO", "SUMADIRECTA", "RESTADIRECTA",
  "OR", "VOID", "MAYORIGUAL", "MENORIGUAL", "PERTENECE", "DESIGUALDAD",
  "IGUALDAD", "RETURN", "IF", "DO", "WHILE", "ELSE", "FOR", "TYPEDEF",
  "SIZEOF", "SWITCH", "CASE", "BREAK", "CONTINUE", "CONTROLOTRA",
  "OPERADOR", "CONDICION", "DEFAULT", "'*'", "'/'", "'+'", "'-'", "','",
  "'&'", "'!'", "':'", "'?'", "'='", "'{'", "'}'", "'['", "']'", "'('",
  "')'", "'\\n'", "';'", "'>'", "'<'", "NEG", "POS", "PUNT", "$accept",
  "input", "line", "expresion", "expresionAsignacion",
  "operacionAsignacion", "expresionCondicional", "expresionOr",
  "expresionAnd", "expresionIgualdad", "operadorComparacion",
  "expresionRelacional", "operadorRelacional", "expresionAditiva",
  "expresionMultiplicativa", "expresionUnaria", "operadorUnario",
  "expresionPostfijo", "listaDeArgumentos", "argumento",
  "expresionPrimaria", "declaracion", "declaracionFuncion",
  "definicionFuncion", "listaDeParametros", "parametro",
  "declaracionVariable", "declaracionAsignacion", "listaDeVariables",
  "listaDeVariablesAsignacion", "variable", "variableAsignacion",
  "sentenciaCompuesta", "listaCompuesta", "sentencia",
  "sentenciaExpresion", "sentenciaSeleccion", "$@1", "$@2",
  "sentenciaIteracion", "$@3", "$@4", "$@5", "sentenciaSalto",
  "expresionOP", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    42,    47,
      43,    45,    44,    38,    33,    58,    63,    61,   123,   125,
      91,    93,    40,    41,    10,    59,    62,    60,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    78,    79,    79,
      80,    81,    81,    81,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    86,    87,    88,    89,    89,    90,
      90,    91,    92,    93,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    98,    97,    99,    97,   101,
     100,   102,   100,   103,   100,   104,   105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     2,     1,     2,     1,
       1,     3,     1,     1,     1,     1,     5,     1,     3,     1,
       3,     1,     3,     2,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     4,     4,     1,     3,
       1,     1,     1,     1,     2,     2,     2,     5,     5,     6,
       6,     0,     1,     3,     2,     2,     2,     1,     3,     1,
       3,     1,     3,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     8,     0,     6,     0,
       6,     0,     8,     0,    10,     3,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,    51,    53,    52,     0,     0,     0,
       0,     0,     0,    43,    44,     0,     4,    83,     3,     0,
       9,    10,    15,    17,    19,    21,    24,    30,    33,     0,
      36,    45,    81,     0,    82,     0,     0,    76,     5,    77,
      78,     0,     0,    79,     0,     0,     0,    80,     8,    71,
      65,    66,    67,    69,     0,     0,    42,    41,    40,     0,
       0,    84,     0,     0,     0,     0,     0,    29,    28,    26,
      27,     0,     0,     0,     0,     0,    37,    38,    13,    14,
      12,     0,    39,     0,     0,    56,    54,    55,     6,     0,
       0,     0,    85,     0,     0,    61,     0,     0,    61,    95,
      75,    73,    18,    33,     0,    20,    23,    22,    25,    31,
      32,    34,    35,    11,     0,    50,     0,    48,     0,     0,
       0,     0,    96,    72,     0,     0,    62,    71,    68,     0,
      70,     0,     0,    46,     0,    47,     0,     0,     0,     0,
      97,     0,    64,     0,    57,    58,    16,    49,    85,    85,
      85,     0,    96,    63,    59,    60,     0,    88,    90,     0,
       0,    85,     0,    96,    86,    92,     0,     0,    94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    59,    19,    20,    81,    21,    22,    23,    24,
      66,    25,    71,    26,    27,    28,    29,    30,   116,   117,
      31,    32,    33,    34,   125,   126,    35,    36,    50,    51,
      52,    53,    37,    60,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   141
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -127
static const yytype_int16 yypact[] =
{
    -127,     8,  -127,   -34,  -127,  -127,  -127,    24,    45,    -1,
      -1,    -1,    -1,  -127,  -127,    92,  -127,  -127,  -127,    10,
    -127,  -127,    -8,    51,    69,   -12,    41,    46,    14,    -1,
     -30,  -127,  -127,    36,  -127,    37,    39,  -127,    47,  -127,
    -127,    76,    77,  -127,    78,    80,    79,  -127,  -127,    21,
    -127,  -127,    60,    63,    55,    57,    75,    75,    75,    92,
      71,  -127,    -1,    -1,    -1,    98,    -1,  -127,  -127,  -127,
    -127,    -1,    -1,    -1,    -1,    -1,  -127,  -127,  -127,  -127,
    -127,    -1,    75,    -1,    -1,  -127,  -127,  -127,  -127,    70,
      72,    74,   145,    82,    -1,   115,   122,   123,   115,  -127,
    -127,  -127,    51,    75,    84,    69,  -127,   -12,    41,    46,
      46,    75,    75,  -127,    86,  -127,    -6,  -127,    -1,    -1,
      -1,   106,    -1,  -127,   133,    11,  -127,  -127,  -127,    97,
    -127,    13,    -1,  -127,    -1,  -127,    99,   100,   102,    87,
    -127,    90,  -127,   115,   108,   108,  -127,  -127,   145,   145,
     145,    -1,    -1,  -127,  -127,  -127,   131,  -127,  -127,   105,
     104,   145,   107,    -1,  -127,  -127,   110,   108,  -127
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,   159,    -9,   -71,  -127,  -127,  -127,   103,   109,
    -127,   111,  -127,    93,    16,     5,  -127,  -127,  -127,    32,
    -127,  -127,  -127,  -127,    73,    25,  -127,  -127,    83,    81,
    -127,  -127,  -126,   116,   -91,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -94
static const yytype_int16 yytable[] =
{
      55,   121,     4,     5,     6,    67,    68,    62,     2,     3,
     113,     4,     5,     6,     7,    56,    57,    58,   154,   155,
      83,    48,    84,   123,     8,    76,    77,    78,    79,    49,
       9,   -85,   -91,   -89,    82,   -93,   134,    10,    63,    11,
      12,   168,    13,    14,    69,    70,    10,   135,    11,    12,
      54,    13,    14,   143,   104,   143,    15,   156,   157,   158,
      64,    80,    16,    17,   144,    61,   145,   103,    94,   103,
     164,   103,   160,    95,   114,   115,   103,   103,   103,   111,
     112,    72,    73,   166,    74,    75,    76,    77,   109,   110,
      65,    85,    86,     3,    87,     4,     5,     6,     7,    89,
      90,    88,    96,    91,    92,    97,    93,    98,     8,   136,
     137,   138,    99,   140,     9,   -85,   -91,   -89,   106,   -93,
     101,   124,   118,   146,   119,   115,   120,   127,   129,   132,
      10,   139,    11,    12,   122,    13,    14,   133,   142,   151,
      15,   -74,   159,   140,    94,   152,    16,    17,     4,     5,
       6,     7,   148,   149,   140,   150,    15,   161,   162,   163,
      18,     8,   165,   167,   108,   102,   147,     9,   153,   -91,
     -89,   131,   -93,   105,     0,   100,     0,   107,   130,   128,
       0,     0,     0,    10,     0,    11,    12,     0,    13,    14,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
      17
};

static const yytype_int16 yycheck[] =
{
       9,    92,     3,     4,     5,    17,    18,    15,     0,     1,
      81,     3,     4,     5,     6,    10,    11,    12,   144,   145,
      50,    55,    52,    94,    16,    11,    12,    13,    14,     5,
      22,    23,    24,    25,    29,    27,    42,    38,    46,    40,
      41,   167,    43,    44,    56,    57,    38,    53,    40,    41,
       5,    43,    44,    42,    63,    42,    48,   148,   149,   150,
       9,    47,    54,    55,    53,    55,    53,    62,    47,    64,
     161,    66,   152,    52,    83,    84,    71,    72,    73,    74,
      75,    40,    41,   163,    38,    39,    11,    12,    72,    73,
      21,    55,    55,     1,    55,     3,     4,     5,     6,    23,
      23,    54,    42,    25,    24,    42,    27,    52,    16,   118,
     119,   120,    55,   122,    22,    23,    24,    25,    20,    27,
      49,     6,    52,   132,    52,   134,    52,     5,     5,    45,
      38,    25,    40,    41,    52,    43,    44,    51,     5,    52,
      48,    49,   151,   152,    47,    55,    54,    55,     3,     4,
       5,     6,    53,    53,   163,    53,    48,    26,    53,    55,
       1,    16,    55,    53,    71,    62,   134,    22,   143,    24,
      25,    98,    27,    64,    -1,    59,    -1,    66,    97,    96,
      -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    62,     0,     1,     3,     4,     5,     6,    16,    22,
      38,    40,    41,    43,    44,    48,    54,    55,    63,    64,
      65,    67,    68,    69,    70,    72,    74,    75,    76,    77,
      78,    81,    82,    83,    84,    87,    88,    93,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    55,     5,
      89,    90,    91,    92,     5,    64,    76,    76,    76,    63,
      94,    55,    15,    46,     9,    21,    71,    17,    18,    56,
      57,    73,    40,    41,    38,    39,    11,    12,    13,    14,
      47,    66,    76,    50,    52,    55,    55,    55,    54,    23,
      23,    25,    24,    27,    47,    52,    42,    42,    52,    55,
      94,    49,    69,    76,    64,    70,    20,    72,    74,    75,
      75,    76,    76,    65,    64,    64,    79,    80,    52,    52,
      52,    95,    52,    65,     6,    85,    86,     5,    89,     5,
      90,    85,    45,    51,    42,    53,    64,    64,    64,    25,
      64,   105,     5,    42,    53,    53,    64,    80,    53,    53,
      53,    52,    55,    86,    93,    93,    95,    95,    95,    64,
     105,    26,    53,    55,    95,    55,   105,    53,    93
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;
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
     `$$ = $1'.

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
        case 7:

/* Line 1455 of yacc.c  */
#line 68 "src/EstructurasDeFraseC.y"
    { printf("\nError sintactico en la linea: %d \n", yylineno-1); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 69 "src/EstructurasDeFraseC.y"
    { printf("\nError sintactico en la linea: %d \n", yylineno-1); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 176 "src/EstructurasDeFraseC.y"
    { ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 177 "src/EstructurasDeFraseC.y"
    { ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 178 "src/EstructurasDeFraseC.y"
    { strcpy((yyval.tipo), (yyvsp[(1) - (2)].tipo)); 
                                    strcpy((yyval.string), (yyvsp[(1) - (2)].string)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 183 "src/EstructurasDeFraseC.y"
    { ListaFunciones = agregarFuncion(ListaFunciones, (yyvsp[(2) - (5)].string), (yyvsp[(1) - (5)].string), yylineno); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 184 "src/EstructurasDeFraseC.y"
    { ListaFunciones = agregarFuncion(ListaFunciones, (yyvsp[(2) - (5)].string), (yyvsp[(1) - (5)].string), yylineno); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 188 "src/EstructurasDeFraseC.y"
    { ListaFunciones = agregarFuncion(ListaFunciones, (yyvsp[(2) - (6)].string), (yyvsp[(1) - (6)].string), yylineno); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 189 "src/EstructurasDeFraseC.y"
    { ListaFunciones = agregarFuncion(ListaFunciones, (yyvsp[(2) - (6)].string), (yyvsp[(1) - (6)].string), yylineno); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 203 "src/EstructurasDeFraseC.y"
    { ListaDeclaraciones = agregarDeclaracion(ListaDeclaraciones, (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string), yylineno); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 207 "src/EstructurasDeFraseC.y"
    { ListaDeclaraciones = agregarDeclaracion(ListaDeclaraciones, (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string), yylineno); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 241 "src/EstructurasDeFraseC.y"
    { strcpy((yyval.tipo), (yyvsp[(1) - (1)].tipo)); 
                          strcpy((yyval.string), (yyvsp[(1) - (1)].string)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 243 "src/EstructurasDeFraseC.y"
    { strcpy((yyval.tipo), (yyvsp[(1) - (1)].tipo)); 
                          strcpy((yyval.string), (yyvsp[(1) - (1)].string)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 245 "src/EstructurasDeFraseC.y"
    { strcpy((yyval.tipo), (yyvsp[(1) - (1)].tipo)); 
                          strcpy((yyval.string), (yyvsp[(1) - (1)].string)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 247 "src/EstructurasDeFraseC.y"
    { strcpy((yyval.tipo), (yyvsp[(1) - (1)].tipo)); 
                          strcpy((yyval.string),(yyvsp[(1) - (1)].string)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 249 "src/EstructurasDeFraseC.y"
    { strcpy((yyval.tipo), (yyvsp[(1) - (1)].tipo)); 
                          strcpy((yyval.string), (yyvsp[(1) - (1)].string)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 251 "src/EstructurasDeFraseC.y"
    { strcpy((yyval.tipo), (yyvsp[(1) - (1)].tipo)); 
                          strcpy((yyval.string), (yyvsp[(1) - (1)].string)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 258 "src/EstructurasDeFraseC.y"
    { strcpy((yyval.tipo), (yyvsp[(1) - (2)].tipo)); 
                    strcpy((yyval.string), (yyvsp[(1) - (2)].string)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 263 "src/EstructurasDeFraseC.y"
    { lineaSentencia = yylineno ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 263 "src/EstructurasDeFraseC.y"
    { ListaSentencias = agregarSentencia(ListaSentencias, (yyvsp[(2) - (8)].string), lineaSentencia);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 264 "src/EstructurasDeFraseC.y"
    { lineaSentencia = yylineno ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 264 "src/EstructurasDeFraseC.y"
    { ListaSentencias = agregarSentencia(ListaSentencias, (yyvsp[(2) - (6)].string), lineaSentencia);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 268 "src/EstructurasDeFraseC.y"
    { lineaSentencia = yylineno ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 268 "src/EstructurasDeFraseC.y"
    { ListaSentencias = agregarSentencia(ListaSentencias, (yyvsp[(2) - (6)].string), lineaSentencia);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 269 "src/EstructurasDeFraseC.y"
    { lineaSentencia = yylineno ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 269 "src/EstructurasDeFraseC.y"
    { ListaSentencias = agregarSentencia(ListaSentencias, (yyvsp[(2) - (8)].string), lineaSentencia);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 270 "src/EstructurasDeFraseC.y"
    { lineaSentencia = yylineno ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 270 "src/EstructurasDeFraseC.y"
    { ListaSentencias = agregarSentencia(ListaSentencias, (yyvsp[(2) - (10)].string), lineaSentencia);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 274 "src/EstructurasDeFraseC.y"
    { ListaSentencias = agregarSentencia(ListaSentencias, (yyvsp[(1) - (3)].string), yylineno); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1824 "obj/EstructurasDeFraseC.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 1675 of yacc.c  */
#line 282 "src/EstructurasDeFraseC.y"


int main(){

  yyin = fopen("./codigoTest.c", "r");
  #if YYDEBUG
          yydebug = 1;
  #endif

	if(yyin == NULL){
		printf("\nError: No se pudo abrir el archivo \n"); 
	}
  else{
		printf("\nEl archivo se abrio correctamente \n");
    printf("\nAnalisis sintactico del archivo: \n");


    printf("\n\n-----------------------------------------------------------------------------\n");
    printf("Errores lexicos y sintacticos: \n");
    printf("-----------------------------------------------------------------------------\n");

		yyparse();
	}

	fclose(yyin);

  mostrarListaDeclaraciones(ListaDeclaraciones);
  mostrarListaFuncion(ListaFunciones);
  mostrarListaSentencias(ListaSentencias);

  return 0;
}
