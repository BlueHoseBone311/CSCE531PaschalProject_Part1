/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 47 "gram.y" /* yacc.c:339  */


/* Cause the `yydebug' variable to be defined.  */
#define YYDEBUG 1

#include "types.h"
#include "tree.h"

void set_yydebug(int);
void yyerror(const char *);

/* Like YYERROR but do call yyerror */
#define YYERROR1 { yyerror ("syntax error"); YYERROR; }

#line 81 "y.tab.c" /* yacc.c:339  */

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
    LEX_ID = 258,
    LEX_ARRAY = 259,
    LEX_BEGIN = 260,
    LEX_CASE = 261,
    LEX_CONST = 262,
    LEX_DO = 263,
    LEX_DOWNTO = 264,
    LEX_END = 265,
    LEX_FILE = 266,
    LEX_FOR = 267,
    LEX_FUNCTION = 268,
    LEX_GOTO = 269,
    LEX_IF = 270,
    LEX_LABEL = 271,
    LEX_NIL = 272,
    LEX_OF = 273,
    LEX_PACKED = 274,
    LEX_PROCEDURE = 275,
    LEX_PROGRAM = 276,
    LEX_RECORD = 277,
    LEX_REPEAT = 278,
    LEX_SET = 279,
    LEX_THEN = 280,
    LEX_TO = 281,
    LEX_TYPE = 282,
    LEX_UNTIL = 283,
    LEX_VAR = 284,
    LEX_WHILE = 285,
    LEX_WITH = 286,
    LEX_FORWARD = 287,
    pp_SIN = 288,
    pp_COS = 289,
    pp_EXP = 290,
    pp_LN = 291,
    pp_SQRT = 292,
    pp_ARCTAN = 293,
    rr_POW = 294,
    rr_EXPON = 295,
    r_WRITE = 296,
    r_READ = 297,
    r_INITFDR = 298,
    r_LAZYTRYGET = 299,
    r_LAZYGET = 300,
    r_LAZYUNGET = 301,
    r_POW = 302,
    r_EXPON = 303,
    z_ABS = 304,
    z_ARCTAN = 305,
    z_COS = 306,
    z_EXP = 307,
    z_LN = 308,
    z_SIN = 309,
    z_SQRT = 310,
    z_POW = 311,
    z_EXPON = 312,
    set_card = 313,
    set_isempty = 314,
    set_equal = 315,
    set_le = 316,
    set_less = 317,
    set_in = 318,
    set_clear = 319,
    set_include = 320,
    set_exclude = 321,
    set_include_range = 322,
    set_copy = 323,
    set_intersection = 324,
    set_union = 325,
    set_diff = 326,
    set_symdiff = 327,
    p_DONEFDR = 328,
    gpc_IOCHECK = 329,
    gpc_RUNTIME_ERROR = 330,
    p_INPUT = 331,
    p_OUTPUT = 332,
    p_REWRITE = 333,
    p_RESET = 334,
    p_PUT = 335,
    p_GET = 336,
    p_WRITE = 337,
    p_READ = 338,
    p_WRITELN = 339,
    p_READLN = 340,
    p_PAGE = 341,
    p_NEW = 342,
    p_DISPOSE = 343,
    p_ABS = 344,
    p_SQR = 345,
    p_SIN = 346,
    p_COS = 347,
    p_EXP = 348,
    p_LN = 349,
    p_SQRT = 350,
    p_ARCTAN = 351,
    p_TRUNC = 352,
    p_ROUND = 353,
    p_PACK = 354,
    p_UNPACK = 355,
    p_ORD = 356,
    p_CHR = 357,
    p_SUCC = 358,
    p_PRED = 359,
    p_ODD = 360,
    p_EOF = 361,
    p_EOLN = 362,
    p_MAXINT = 363,
    p_TRUE = 364,
    p_FALSE = 365,
    bp_RANDOM = 366,
    bp_RANDOMIZE = 367,
    BREAK = 368,
    CONTINUE = 369,
    RETURN_ = 370,
    RESULT = 371,
    EXIT = 372,
    FAIL = 373,
    p_CLOSE = 374,
    CONJUGATE = 375,
    p_DEFINESIZE = 376,
    SIZEOF = 377,
    BITSIZEOF = 378,
    ALIGNOF = 379,
    TYPEOF = 380,
    gpc_RETURNADDRESS = 381,
    gpc_FRAMEADDRESS = 382,
    LEX_LABEL_ADDR = 383,
    LEX_INTCONST = 384,
    LEX_STRCONST = 385,
    LEX_REALCONST = 386,
    LEX_RANGE = 387,
    LEX_ELLIPSIS = 388,
    LEX_ASSIGN = 389,
    LEX_IN = 390,
    LEX_NE = 391,
    LEX_GE = 392,
    LEX_LE = 393,
    LEX_OR = 394,
    LEX_OR_ELSE = 395,
    LEX_CEIL_PLUS = 396,
    LEX_CEIL_MINUS = 397,
    LEX_FLOOR_PLUS = 398,
    LEX_FLOOR_MINUS = 399,
    LEX_DIV = 400,
    LEX_MOD = 401,
    LEX_AND = 402,
    LEX_AND_THEN = 403,
    LEX_SHL = 404,
    LEX_SHR = 405,
    LEX_XOR = 406,
    LEX_CEIL_MULT = 407,
    LEX_CEIL_DIV = 408,
    LEX_FLOOR_MULT = 409,
    LEX_FLOOR_DIV = 410,
    LEX_POW = 411,
    LEX_POWER = 412,
    LEX_IS = 413,
    LEX_AS = 414,
    LEX_NOT = 415,
    LEX_EXTERNAL = 416,
    p_MARK = 417,
    p_RELEASE = 418,
    p_UPDATE = 419,
    p_GETTIMESTAMP = 420,
    p_UNBIND = 421,
    p_EXTEND = 422,
    bp_APPEND = 423,
    p_BIND = 424,
    p_SEEKREAD = 425,
    p_SEEKWRITE = 426,
    p_SEEKUPDATE = 427,
    LEX_SYMDIFF = 428,
    p_ARG = 429,
    p_CARD = 430,
    p_EMPTY = 431,
    p_POSITION = 432,
    p_LASTPOSITION = 433,
    p_LENGTH = 434,
    p_TRIM = 435,
    p_BINDING = 436,
    p_DATE = 437,
    p_TIME = 438,
    LEX_RENAME = 439,
    LEX_IMPORT = 440,
    LEX_USES = 441,
    LEX_QUALIFIED = 442,
    LEX_ONLY = 443,
    prec_if = 444,
    LEX_ELSE = 445,
    lower_than_error = 446
  };
#endif
/* Tokens.  */
#define LEX_ID 258
#define LEX_ARRAY 259
#define LEX_BEGIN 260
#define LEX_CASE 261
#define LEX_CONST 262
#define LEX_DO 263
#define LEX_DOWNTO 264
#define LEX_END 265
#define LEX_FILE 266
#define LEX_FOR 267
#define LEX_FUNCTION 268
#define LEX_GOTO 269
#define LEX_IF 270
#define LEX_LABEL 271
#define LEX_NIL 272
#define LEX_OF 273
#define LEX_PACKED 274
#define LEX_PROCEDURE 275
#define LEX_PROGRAM 276
#define LEX_RECORD 277
#define LEX_REPEAT 278
#define LEX_SET 279
#define LEX_THEN 280
#define LEX_TO 281
#define LEX_TYPE 282
#define LEX_UNTIL 283
#define LEX_VAR 284
#define LEX_WHILE 285
#define LEX_WITH 286
#define LEX_FORWARD 287
#define pp_SIN 288
#define pp_COS 289
#define pp_EXP 290
#define pp_LN 291
#define pp_SQRT 292
#define pp_ARCTAN 293
#define rr_POW 294
#define rr_EXPON 295
#define r_WRITE 296
#define r_READ 297
#define r_INITFDR 298
#define r_LAZYTRYGET 299
#define r_LAZYGET 300
#define r_LAZYUNGET 301
#define r_POW 302
#define r_EXPON 303
#define z_ABS 304
#define z_ARCTAN 305
#define z_COS 306
#define z_EXP 307
#define z_LN 308
#define z_SIN 309
#define z_SQRT 310
#define z_POW 311
#define z_EXPON 312
#define set_card 313
#define set_isempty 314
#define set_equal 315
#define set_le 316
#define set_less 317
#define set_in 318
#define set_clear 319
#define set_include 320
#define set_exclude 321
#define set_include_range 322
#define set_copy 323
#define set_intersection 324
#define set_union 325
#define set_diff 326
#define set_symdiff 327
#define p_DONEFDR 328
#define gpc_IOCHECK 329
#define gpc_RUNTIME_ERROR 330
#define p_INPUT 331
#define p_OUTPUT 332
#define p_REWRITE 333
#define p_RESET 334
#define p_PUT 335
#define p_GET 336
#define p_WRITE 337
#define p_READ 338
#define p_WRITELN 339
#define p_READLN 340
#define p_PAGE 341
#define p_NEW 342
#define p_DISPOSE 343
#define p_ABS 344
#define p_SQR 345
#define p_SIN 346
#define p_COS 347
#define p_EXP 348
#define p_LN 349
#define p_SQRT 350
#define p_ARCTAN 351
#define p_TRUNC 352
#define p_ROUND 353
#define p_PACK 354
#define p_UNPACK 355
#define p_ORD 356
#define p_CHR 357
#define p_SUCC 358
#define p_PRED 359
#define p_ODD 360
#define p_EOF 361
#define p_EOLN 362
#define p_MAXINT 363
#define p_TRUE 364
#define p_FALSE 365
#define bp_RANDOM 366
#define bp_RANDOMIZE 367
#define BREAK 368
#define CONTINUE 369
#define RETURN_ 370
#define RESULT 371
#define EXIT 372
#define FAIL 373
#define p_CLOSE 374
#define CONJUGATE 375
#define p_DEFINESIZE 376
#define SIZEOF 377
#define BITSIZEOF 378
#define ALIGNOF 379
#define TYPEOF 380
#define gpc_RETURNADDRESS 381
#define gpc_FRAMEADDRESS 382
#define LEX_LABEL_ADDR 383
#define LEX_INTCONST 384
#define LEX_STRCONST 385
#define LEX_REALCONST 386
#define LEX_RANGE 387
#define LEX_ELLIPSIS 388
#define LEX_ASSIGN 389
#define LEX_IN 390
#define LEX_NE 391
#define LEX_GE 392
#define LEX_LE 393
#define LEX_OR 394
#define LEX_OR_ELSE 395
#define LEX_CEIL_PLUS 396
#define LEX_CEIL_MINUS 397
#define LEX_FLOOR_PLUS 398
#define LEX_FLOOR_MINUS 399
#define LEX_DIV 400
#define LEX_MOD 401
#define LEX_AND 402
#define LEX_AND_THEN 403
#define LEX_SHL 404
#define LEX_SHR 405
#define LEX_XOR 406
#define LEX_CEIL_MULT 407
#define LEX_CEIL_DIV 408
#define LEX_FLOOR_MULT 409
#define LEX_FLOOR_DIV 410
#define LEX_POW 411
#define LEX_POWER 412
#define LEX_IS 413
#define LEX_AS 414
#define LEX_NOT 415
#define LEX_EXTERNAL 416
#define p_MARK 417
#define p_RELEASE 418
#define p_UPDATE 419
#define p_GETTIMESTAMP 420
#define p_UNBIND 421
#define p_EXTEND 422
#define bp_APPEND 423
#define p_BIND 424
#define p_SEEKREAD 425
#define p_SEEKWRITE 426
#define p_SEEKUPDATE 427
#define LEX_SYMDIFF 428
#define p_ARG 429
#define p_CARD 430
#define p_EMPTY 431
#define p_POSITION 432
#define p_LASTPOSITION 433
#define p_LENGTH 434
#define p_TRIM 435
#define p_BINDING 436
#define p_DATE 437
#define p_TIME 438
#define LEX_RENAME 439
#define LEX_IMPORT 440
#define LEX_USES 441
#define LEX_QUALIFIED 442
#define LEX_ONLY 443
#define prec_if 444
#define LEX_ELSE 445
#define lower_than_error 446

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 67 "gram.y" /* yacc.c:355  */

    char *        y_string;
    int	          y_cint;
    long          y_int;
    double        y_real;
    VAR_ID_LIST   y_varidlist;
    ST_ID         y_stid; 
    INDEX_LIST	  y_indexlist;
    PARAM_LIST    y_paramlist;  
    TYPE          y_type; 

#line 515 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 530 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1651

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  136
/* YYNRULES -- Number of rules.  */
#define YYNRULES  367
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  549

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   446

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
     200,   201,   151,   143,   202,   142,   199,   150,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   205,   208,
     135,   136,   137,     2,   204,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   206,     2,   207,   203,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     138,   139,   140,   141,   144,   145,   146,   147,   148,   149,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   174,   178,   181,   183,   187,   188,   192,
     196,   200,   204,   206,   207,   208,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   224,
     225,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   238,   239,   241,   242,   243,   244,   245,   247,   248,
     249,   250,   251,   252,   253,   254,   257,   259,   262,   264,
     268,   269,   273,   274,   275,   281,   285,   286,   290,   294,
     295,   296,   297,   301,   302,   306,   307,   311,   312,   316,
     317,   321,   322,   323,   327,   328,   332,   336,   337,   342,
     346,   347,   348,   349,   350,   354,   355,   359,   363,   364,
     368,   372,   376,   380,   381,   385,   386,   390,   391,   395,
     396,   400,   401,   405,   406,   407,   408,   412,   413,   414,
     420,   424,   425,   430,   431,   437,   441,   444,   446,   447,
     448,   452,   453,   457,   461,   465,   466,   470,   471,   475,
     476,   480,   481,   485,   489,   490,   494,   495,   503,   507,
     508,   512,   516,   517,   521,   522,   526,   527,   531,   532,
     536,   537,   542,   544,   548,   549,   553,   554,   561,   565,
     569,   570,   574,   575,   579,   580,   581,   582,   586,   590,
     591,   595,   599,   600,   604,   608,   609,   613,   617,   618,
     622,   623,   627,   631,   632,   636,   637,   638,   642,   646,
     650,   654,   655,   659,   660,   661,   662,   666,   671,   673,
     677,   678,   682,   688,   692,   693,   694,   697,   699,   703,
     704,   705,   706,   707,   708,   709,   710,   711,   714,   716,
     720,   721,   725,   726,   727,   732,   733,   734,   735,   736,
     737,   738,   739,   743,   744,   745,   746,   747,   748,   749,
     750,   751,   752,   753,   754,   755,   756,   757,   758,   759,
     763,   764,   765,   769,   770,   771,   772,   776,   780,   784,
     785,   789,   790,   794,   795,   801,   805,   809,   810,   811,
     815,   816,   817,   818,   819,   823,   824,   825,   829,   830,
     834,   835,   836,   837,   841,   842,   846,   847,   848,   849,
     850,   851,   855,   859,   860,   864,   865,   869,   870,   871,
     872,   873,   874,   875,   876,   880,   881,   885,   886,   890,
     891,   895,   896,   897,   900,   902,   906,   907,   911,   912,
     913,   914,   915,   916,   917,   918,   919,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,   930,   931,   932,
     933,   937,   938,   942,   943,   944,   945,   946,   947,   951,
     952,   953,   954,   958,   959,   963,   966,   968
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEX_ID", "LEX_ARRAY", "LEX_BEGIN",
  "LEX_CASE", "LEX_CONST", "LEX_DO", "LEX_DOWNTO", "LEX_END", "LEX_FILE",
  "LEX_FOR", "LEX_FUNCTION", "LEX_GOTO", "LEX_IF", "LEX_LABEL", "LEX_NIL",
  "LEX_OF", "LEX_PACKED", "LEX_PROCEDURE", "LEX_PROGRAM", "LEX_RECORD",
  "LEX_REPEAT", "LEX_SET", "LEX_THEN", "LEX_TO", "LEX_TYPE", "LEX_UNTIL",
  "LEX_VAR", "LEX_WHILE", "LEX_WITH", "LEX_FORWARD", "pp_SIN", "pp_COS",
  "pp_EXP", "pp_LN", "pp_SQRT", "pp_ARCTAN", "rr_POW", "rr_EXPON",
  "r_WRITE", "r_READ", "r_INITFDR", "r_LAZYTRYGET", "r_LAZYGET",
  "r_LAZYUNGET", "r_POW", "r_EXPON", "z_ABS", "z_ARCTAN", "z_COS", "z_EXP",
  "z_LN", "z_SIN", "z_SQRT", "z_POW", "z_EXPON", "set_card", "set_isempty",
  "set_equal", "set_le", "set_less", "set_in", "set_clear", "set_include",
  "set_exclude", "set_include_range", "set_copy", "set_intersection",
  "set_union", "set_diff", "set_symdiff", "p_DONEFDR", "gpc_IOCHECK",
  "gpc_RUNTIME_ERROR", "p_INPUT", "p_OUTPUT", "p_REWRITE", "p_RESET",
  "p_PUT", "p_GET", "p_WRITE", "p_READ", "p_WRITELN", "p_READLN", "p_PAGE",
  "p_NEW", "p_DISPOSE", "p_ABS", "p_SQR", "p_SIN", "p_COS", "p_EXP",
  "p_LN", "p_SQRT", "p_ARCTAN", "p_TRUNC", "p_ROUND", "p_PACK", "p_UNPACK",
  "p_ORD", "p_CHR", "p_SUCC", "p_PRED", "p_ODD", "p_EOF", "p_EOLN",
  "p_MAXINT", "p_TRUE", "p_FALSE", "bp_RANDOM", "bp_RANDOMIZE", "BREAK",
  "CONTINUE", "RETURN_", "RESULT", "EXIT", "FAIL", "p_CLOSE", "CONJUGATE",
  "p_DEFINESIZE", "SIZEOF", "BITSIZEOF", "ALIGNOF", "TYPEOF",
  "gpc_RETURNADDRESS", "gpc_FRAMEADDRESS", "LEX_LABEL_ADDR",
  "LEX_INTCONST", "LEX_STRCONST", "LEX_REALCONST", "LEX_RANGE",
  "LEX_ELLIPSIS", "LEX_ASSIGN", "'<'", "'='", "'>'", "LEX_IN", "LEX_NE",
  "LEX_GE", "LEX_LE", "'-'", "'+'", "LEX_OR", "LEX_OR_ELSE",
  "LEX_CEIL_PLUS", "LEX_CEIL_MINUS", "LEX_FLOOR_PLUS", "LEX_FLOOR_MINUS",
  "'/'", "'*'", "LEX_DIV", "LEX_MOD", "LEX_AND", "LEX_AND_THEN", "LEX_SHL",
  "LEX_SHR", "LEX_XOR", "LEX_CEIL_MULT", "LEX_CEIL_DIV", "LEX_FLOOR_MULT",
  "LEX_FLOOR_DIV", "LEX_POW", "LEX_POWER", "LEX_IS", "LEX_AS", "LEX_NOT",
  "LEX_EXTERNAL", "p_MARK", "p_RELEASE", "p_UPDATE", "p_GETTIMESTAMP",
  "p_UNBIND", "p_EXTEND", "bp_APPEND", "p_BIND", "p_SEEKREAD",
  "p_SEEKWRITE", "p_SEEKUPDATE", "LEX_SYMDIFF", "p_ARG", "p_CARD",
  "p_EMPTY", "p_POSITION", "p_LASTPOSITION", "p_LENGTH", "p_TRIM",
  "p_BINDING", "p_DATE", "p_TIME", "LEX_RENAME", "LEX_IMPORT", "LEX_USES",
  "LEX_QUALIFIED", "LEX_ONLY", "prec_if", "LEX_ELSE", "lower_than_error",
  "'.'", "'('", "')'", "','", "'^'", "'@'", "':'", "'['", "']'", "';'",
  "$accept", "pascal_program", "main_program_declaration",
  "program_heading", "optional_par_id_list", "id_list", "typename",
  "identifier", "new_identifier", "new_identifier_1",
  "any_global_declaration_part", "any_declaration_part", "any_decl",
  "simple_decl", "constant_definition_part", "constant_definition_list",
  "constant_definition", "constant", "number", "unsigned_number", "sign",
  "constant_literal", "predefined_literal", "string",
  "type_definition_part", "type_definition_list", "type_definition",
  "type_denoter", "new_ordinal_type", "enumerated_type", "enum_list",
  "enumerator", "subrange_type", "new_pointer_type", "pointer_char",
  "pointer_domain_type", "new_procedural_type",
  "optional_procedural_type_formal_parameter_list",
  "procedural_type_formal_parameter_list",
  "procedural_type_formal_parameter", "new_structured_type", "array_type",
  "array_index_list", "ordinal_index_type", "set_type", "record_type",
  "record_field_list", "fixed_part", "record_section", "variant_part",
  "rest_of_variant", "variant_selector", "variant_type", "variant_list",
  "variant", "case_constant_list", "one_case_constant",
  "variable_declaration_part", "variable_declaration_list",
  "variable_declaration", "function_declaration", "function_heading",
  "directive_list", "directive", "functiontype",
  "optional_par_formal_parameter_list", "formal_parameter_list",
  "formal_parameter", "statement_part", "compound_statement",
  "statement_sequence", "statement", "structured_statement",
  "with_statement", "structured_variable_list", "structured_variable",
  "conditional_statement", "simple_if", "if_statement", "case_statement",
  "optional_semicolon_or_else_branch", "case_element_list", "case_element",
  "case_default", "repetitive_statement", "repeat_statement",
  "while_statement", "for_statement", "for_direction", "simple_statement",
  "empty_statement", "optional_par_actual_parameter_list",
  "actual_parameter_list", "actual_parameter",
  "assignment_or_call_statement",
  "variable_or_function_access_maybe_assignment", "rest_of_statement",
  "standard_procedure_statement", "optional_par_write_parameter_list",
  "write_actual_parameter_list", "write_actual_parameter",
  "rts_proc_onepar", "rts_proc_parlist", "statement_extensions",
  "return_statement", "break_statement", "continue_statement",
  "variable_access_or_typename", "index_expression_list",
  "index_expression_item", "static_expression", "boolean_expression",
  "expression", "simple_expression", "term", "signed_primary", "primary",
  "signed_factor", "factor", "address_operator",
  "variable_or_function_access",
  "variable_or_function_access_no_standard_function",
  "variable_or_function_access_no_id", "set_constructor",
  "set_constructor_element_list", "member_designator",
  "standard_functions", "optional_par_actual_parameter", "rts_fun_optpar",
  "rts_fun_onepar", "rts_fun_parlist", "relational_operator",
  "multiplying_operator", "adding_operator", "semi", "optional_semicolon", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,    60,    61,    62,   390,   391,
     392,   393,    45,    43,   394,   395,   396,   397,   398,   399,
      47,    42,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,    46,
      40,    41,    44,    94,    64,    58,    91,    93,    59
};
# endif

#define YYPACT_NINF -488

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-488)))

#define YYTABLE_NINF -368

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      34,  1528,    65,  -128,  -118,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -104,
    -488,  -488,  -488,  -488,  -488,  1528,  -488,    86,   -44,  -488,
     840,  1528,  1528,  1528,  1528,  1528,  -488,  -488,  -488,  -488,
    -488,  -488,  -118,  -488,  -488,  -488,  1528,  -488,   638,  1028,
     638,   840,   638,  1028,  -488,  -488,  -488,  -488,  -488,  -488,
     -84,   -68,   -84,   -68,   -68,   -54,   -52,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,   638,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
     638,  -488,  -102,  -488,    -1,  -488,  -488,  -488,  -488,  -117,
    -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,     8,
    -488,   -47,   -30,  -488,  -488,  -488,  -488,  1028,   123,   -26,
     108,  -488,   -18,   -15,     3,    72,  1528,  -488,    44,    44,
     112,  -118,  -488,  -120,  1528,  -488,   -19,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,  -488,  -488,   638,   439,  -488,  -488,
     638,  -488,  -488,   126,   209,   137,   243,  -488,   -56,  -488,
     706,   123,  -488,  -488,    99,   246,   415,   -20,   260,    -2,
    -488,   123,   638,  -488,   638,  -488,  -488,  -488,  -488,  1085,
     638,   415,   308,  -488,   840,   840,   638,  -488,   638,   638,
     123,  1528,  -488,  -488,   638,  -488,   638,   638,  -488,   638,
     638,   638,  -488,  1324,    69,  -488,   448,  1528,   448,  -488,
    -488,  -488,    86,  -118,  -488,   638,  -488,  -488,  -488,   362,
    -168,  -488,  -488,  -488,   638,  -488,  -488,  -488,   638,  -488,
    -488,  -488,   638,  -488,  -488,   638,   638,   638,   638,  -488,
    -488,  -488,  -488,   638,   638,   706,   706,   273,  -488,   638,
     840,   638,   840,   840,  1028,    84,    -9,  -488,   415,    -7,
    -488,    83,    85,    92,    51,  -488,  -488,  -488,   415,   105,
      81,  -488,  -158,  -488,   382,    95,   114,   122,   119,  -118,
     415,  1528,  -116,  -148,  -488,   273,  -488,   177,   128,   132,
     132,  1372,   320,  1528,  -488,  -488,   208,  -488,  -488,    42,
    -488,  -488,  -488,  -488,  -488,  -488,  1216,  -488,  -488,  -488,
    -488,  -488,  -488,  -118,  -488,  -118,   -19,  -488,   638,   638,
    -488,   -78,  -488,  -157,  -488,   210,   137,   137,   243,   243,
     243,   243,  -488,  -488,  -488,  -488,  -488,  -488,    79,  -488,
    -488,  -488,  -488,  -488,   638,  -488,   638,  -488,   638,  -488,
    -488,   638,  -488,  -488,   638,  -488,   638,  -488,  -488,  -488,
    -488,  -488,   -77,   273,  -488,  1324,  -488,    21,  1480,    69,
    -488,   969,   -66,   331,   143,  -488,  -488,   448,  -488,   129,
    -488,    25,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,
     415,  -488,   638,   840,  -488,     1,   333,   840,   507,  -488,
     638,  -488,  -488,   638,   222,  -488,  -488,   135,  -488,   415,
     273,  -488,  -488,  -488,  -488,  -150,  -488,  1528,   -58,  -135,
    -488,  -488,  -105,   220,   224,  -488,   159,  -488,   347,  -488,
     448,  -488,  1372,  -488,  -488,  -488,  1528,  -488,  -488,  -488,
    -488,  -118,  -488,  -488,  -488,    40,   638,  -488,  -488,    21,
     349,   -43,   273,  -488,  1480,    21,   638,  -488,  -488,  -488,
    -488,   840,   415,  -488,   448,   273,  -488,  -488,  -488,  -157,
    -488,   -36,  -488,  -488,  -488,  -488,   168,   507,  -488,   170,
    1372,  -488,  1372,   172,   174,   173,  -488,  -488,  -488
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,    12,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    27,    28,    13,    15,
      14,    48,    49,    50,    51,    52,    53,    54,    55,     5,
      11,     1,     2,   365,    56,     0,     4,     0,     0,     7,
     207,     0,     0,     0,     0,     0,    57,    60,    62,    63,
      64,    61,     0,     3,   168,     6,     0,    10,     0,     0,
       0,   207,     0,     0,   308,   307,   243,   244,   235,   236,
     228,   208,   228,   208,   208,     0,     0,   328,   329,   330,
     331,   332,   333,   334,   335,   337,   338,   247,   248,   340,
     341,   351,   352,   342,   326,   327,   267,   268,   263,   265,
     266,   239,   253,   255,   254,   258,   259,   257,   256,   237,
     238,   240,   241,   242,   245,   246,   249,   250,   251,   252,
     336,   339,   343,   344,   345,   346,   347,   348,   349,   350,
       0,   302,   214,   174,     0,   170,   172,   175,   176,   186,
     182,   183,   177,   195,   196,   197,   173,   203,   204,   217,
     205,     0,     0,   206,   260,   262,   261,     0,     0,   303,
     216,   304,   324,     0,     0,     0,    65,    66,   162,   162,
       0,     0,    87,     0,   148,   149,    58,     8,    81,    83,
      82,    75,    84,    76,    78,    77,     0,     0,   305,   298,
       0,   297,    80,    79,     0,   279,   280,   285,   288,   290,
       0,   296,   306,   299,     0,     0,   276,     0,     0,     0,
     179,   181,     0,   221,     0,   223,   222,   224,   225,     0,
       0,   264,     0,   169,   207,   207,     0,   213,     0,     0,
     215,     0,   103,   104,     0,   311,     0,     0,   322,     0,
       0,     0,    67,     0,   160,   154,     0,    86,     0,   150,
     158,   159,     0,     0,   156,     0,   300,   294,   315,   319,
       0,   317,   289,    85,     0,   357,   356,   358,     0,   353,
     355,   354,     0,   363,   364,     0,     0,     0,     0,   361,
     362,   359,   360,     0,     0,     0,     0,     0,   301,     0,
     207,     0,   207,   207,     0,   232,     0,   230,   212,     0,
     210,    10,     0,   306,     0,   310,   171,   185,   218,     0,
       0,   309,     0,   271,   273,     0,     0,     0,     0,     0,
     275,     0,     0,     0,   164,     0,   155,     9,     0,   109,
     109,   127,     0,     0,    90,    69,     0,    71,    74,     0,
      72,    89,    91,    95,    96,    92,     0,    93,    94,   117,
     118,   119,    88,     0,    59,     0,   152,   295,     0,     0,
     316,     0,   144,   366,   190,   146,   278,   277,   283,   284,
     282,   281,   287,   286,   291,   292,     9,   293,     0,   184,
     198,   199,   178,   180,     0,   229,     0,   209,     0,   314,
     226,     0,   219,   220,     0,   312,     0,   313,   325,   321,
     323,    68,     0,     0,   163,     0,   161,     0,     0,   160,
     107,     0,     0,     0,   366,   131,   130,     0,   100,     0,
      98,     0,    70,    73,   105,   102,   106,   151,   153,   157,
     320,   318,     0,   207,   193,   365,     0,   207,     0,   188,
       0,   202,   201,     0,   233,   231,   211,     0,   272,   274,
       0,   166,   165,   124,   123,     0,   121,     0,   113,     0,
     111,   108,     9,    15,    14,   139,     0,   140,     0,   138,
       0,   126,     0,   128,   125,    97,     0,   101,   145,   192,
     187,   189,   194,   191,   147,     0,     0,   227,   167,     0,
       0,   116,     0,   110,     0,     0,     0,   133,   132,   129,
      99,   207,   234,   122,     0,     0,   114,   112,   137,   366,
     141,     0,   200,   120,   115,   134,     0,     0,   135,     0,
     127,   142,   127,     0,     0,   366,   143,   367,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -488,  -488,  -488,  -488,  -488,   -51,  -286,   -55,     0,  -488,
    -488,  -488,   111,  -488,  -488,  -488,   198,   -53,  -488,  -199,
    -196,  -191,  -488,  -488,  -488,  -488,   118,  -265,  -266,  -488,
    -488,  -109,  -488,  -488,  -236,  -488,    23,    41,  -488,  -115,
    -488,  -488,  -488,  -108,  -488,  -488,  -402,  -488,   -92,   -89,
    -488,  -488,  -111,  -488,  -131,  -487,   -45,  -488,  -488,   214,
    -488,  -488,  -488,    35,   -17,   221,  -488,   -11,   144,   -38,
     -79,  -229,  -488,  -488,  -488,   101,  -488,  -488,  -488,  -488,
    -488,  -488,   -39,  -106,  -488,  -488,  -488,  -488,  -488,  -488,
    -488,   207,  -213,  -145,  -488,  -488,  -488,  -488,   328,  -488,
      15,  -488,  -488,  -488,  -488,  -488,  -488,  -488,  -488,    10,
    -254,   -64,   -24,  -214,  -177,  -193,  -488,   150,  -183,   -35,
     -48,  -488,   -40,  -488,  -488,    50,  -488,  -488,  -488,  -488,
    -488,  -488,  -488,  -488,    -4,  -412
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    56,   432,   354,   208,    59,    50,
      57,   272,    66,    67,    68,   186,   187,   356,   357,   209,
     210,   211,   212,   213,    69,   191,   192,   361,   362,   363,
     439,   440,   364,   365,   255,   445,   367,   429,   479,   480,
     368,   369,   475,   476,   370,   371,   433,   434,   435,   436,
     535,   488,   489,   529,   530,   381,   382,    70,   194,   195,
      71,    72,   273,   274,   346,   264,   343,   344,    73,   153,
     154,   155,   156,   157,   229,   230,   158,   159,   160,   161,
     456,   383,   384,   457,   162,   163,   164,   165,   463,   166,
     167,   235,   319,   320,   168,   169,   247,   170,   233,   316,
     317,   171,   172,   173,   174,   175,   176,   322,   332,   333,
     385,   225,   318,   215,   216,   217,   218,   276,   219,   220,
     221,   179,   222,   223,   280,   281,   181,   258,   182,   183,
     184,   292,   304,   298,   244,   459
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    49,   227,   373,    58,   152,   313,   339,   311,   243,
     275,  -367,   178,   270,   193,   326,   327,   282,   228,    74,
     180,   397,   493,   277,   347,   177,   152,   -10,    77,   531,
     366,   224,   366,   178,   379,   231,   330,   308,   198,   380,
     454,   180,   198,   335,   414,    77,   177,   338,   521,   415,
     531,   455,   509,   424,   214,     1,   226,   510,   226,   426,
      53,   185,   188,   189,   190,    51,   513,   358,   196,   358,
     359,    52,   359,    53,   386,   360,   197,   360,   387,   275,
     245,   399,    76,   401,   402,   268,    76,   315,   461,   423,
      53,    60,   277,    61,   241,   324,    55,  -305,  -305,    62,
     -12,  -305,  -305,   329,  -305,   462,    63,   305,   306,   307,
     392,   393,   336,    64,   337,    65,   232,   538,   388,   389,
     390,   391,   394,   395,   452,    76,   242,   453,   470,   250,
     199,   200,   234,   548,   199,   200,    76,   471,   543,   490,
     544,   473,   246,   193,    76,   485,   239,   512,   240,   271,
     201,   202,   203,   248,   201,   202,   203,    75,    76,    76,
     443,   474,   525,   204,   205,   487,   452,   204,   205,   539,
     249,   201,   494,   203,   256,   285,   286,   287,   288,   289,
     290,   291,   257,   279,   508,   259,   185,   267,    53,   152,
     152,   178,   405,   406,   407,   408,   178,   178,   467,   323,
     314,   366,  -367,   260,   180,   180,   504,    53,   261,   177,
     177,   355,   342,   355,   285,   286,   287,   288,   289,   290,
     291,   353,   328,   473,   499,   517,   526,   284,   358,   485,
     334,   359,   358,   309,    74,   359,   360,   340,   358,   534,
     360,   359,   358,   474,   263,   359,   360,   400,   266,   487,
     360,   331,   410,   411,   366,   152,   283,   152,   152,   533,
     340,   315,   178,   466,   178,   178,   231,   190,   312,   376,
     180,   310,   180,   180,   345,   177,   396,   177,   177,   293,
     294,   295,   413,   408,  -270,   398,   409,   226,   366,   404,
     422,   358,   532,  -269,   359,   296,   417,   408,   251,   360,
     237,   238,   252,   253,   442,   254,   412,  -306,  -306,   -10,
     358,  -306,  -306,   359,  -306,   418,   358,   297,   360,   359,
     420,   408,   251,   419,   360,   358,   252,   253,   359,   254,
     495,   496,   428,   360,   427,   421,   507,   408,   437,   425,
     441,   491,   460,   500,   285,   286,   287,   288,   289,   290,
     291,   455,   -83,   438,   450,   279,   -82,   285,   286,   287,
     288,   289,   290,   291,   515,   516,   444,   524,   540,   447,
     542,   448,   355,   545,   342,   546,   355,   478,   501,   458,
     464,   547,   355,   374,   262,   372,   355,   520,   497,   446,
     334,   430,   469,   299,   300,   301,   302,   303,   152,   527,
     518,   523,   152,   519,   528,   178,   541,   498,   269,   178,
     265,   449,   481,   180,   472,   403,   375,   180,   177,   503,
     236,   465,   177,   536,   468,   377,   511,   506,   340,   451,
     492,   486,     0,     0,   340,   355,   340,     0,     0,   505,
       0,     0,    77,   285,   286,   287,   288,   289,   290,   291,
       0,   347,   348,     0,   355,     0,   198,     0,     0,     0,
     355,   349,     0,   478,     0,   198,   152,     0,   350,   355,
     351,     0,   352,   178,     0,   514,     0,     0,     0,     0,
       0,   180,   522,     0,     0,     0,   177,     0,     0,     0,
       0,     0,   340,     0,   378,     0,   438,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   325,
      77,     0,     0,   340,   416,    84,    85,   285,   286,   287,
     288,   289,   290,   291,   198,   537,    95,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
     109,   110,   111,   112,   113,   114,   115,     0,   199,   200,
     285,   286,   287,   288,   289,   290,   291,   199,   200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   202,
     203,     0,     0,     0,     0,     0,     0,   201,   202,   203,
       0,   204,   205,    84,    85,     0,     0,     0,     0,     0,
     204,   205,     0,     0,    95,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   206,     0,   109,   110,
     111,   112,   113,   114,   115,     0,   199,   200,     0,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,     0,     0,   201,   202,   203,   150,
       0,    77,     0,   151,     0,   207,   278,     0,   353,   204,
     205,   252,   253,     0,     0,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   206,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,     0,     0,   502,     0,     0,   150,     0,    77,
       0,   151,     0,   207,    84,    85,     0,     0,     0,     0,
       0,     0,     0,   198,     0,    95,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,   109,
     110,   111,   112,   113,   114,   115,     0,   199,   200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,   205,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   206,     0,   109,   110,   111,
     112,   113,   114,   115,     0,   199,   200,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,     0,     0,     0,     0,   201,   202,   203,   150,     0,
       0,     0,   151,    77,   207,    60,    78,     0,     0,     0,
       0,     0,    79,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,     0,
      82,    83,     0,   206,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,     0,     0,     0,
     151,     0,   207,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,   116,   117,   118,     0,   119,   120,   121,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,   198,     0,     0,     0,
       0,     0,     0,     0,   124,     0,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    77,     0,     0,     0,     0,     0,     0,     0,     0,
     150,     0,     0,     0,   151,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,   483,   484,
       0,     0,    41,    42,    43,    44,    45,    46,   321,     0,
       0,    47,    48,     0,     0,     0,     0,     0,   201,   202,
     203,     0,     0,     0,    84,    85,     0,     0,     0,     0,
       0,   204,   205,     0,     0,    95,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,   353,
       0,     0,    95,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     5,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   349,
       0,     0,     0,     0,     0,     0,   350,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     5,     0,    41,
      42,    43,    44,    45,    46,     0,     0,     0,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,   431,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     0,    41,    42,    43,
      44,    45,    46,     0,     0,     0,    47,    48,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     5,     0,    41,    42,    43,    44,    45,
      46,     0,     0,     0,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,     0,    41,    42,    43,    44,    45,    46,     0,
       0,     0,    47,    48,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       0,    41,    42,    43,    44,    45,    46,     0,     0,     0,
      47,    48
};

static const yytype_int16 yycheck[] =
{
       4,     1,    81,   268,    55,    60,     8,   261,    28,    10,
     206,    10,    60,    32,    65,   244,   245,   210,    82,    57,
      60,   307,   434,   206,     3,    60,    81,   132,     3,   516,
     266,    79,   268,    81,   202,    83,   249,   220,    17,   207,
     197,    81,    17,   256,   202,     3,    81,   260,     8,   207,
     537,   208,   202,   201,    78,    21,    80,   207,    82,   345,
     208,    61,    62,    63,    64,     0,   201,   266,    72,   268,
     266,   199,   268,   208,   288,   266,    76,   268,   292,   275,
     197,   310,   202,   312,   313,   205,   202,   232,     9,   205,
     208,     5,   275,     7,   118,   240,   200,   199,   200,    13,
     205,   203,   204,   248,   206,    26,    20,   163,   164,   165,
     303,   304,   257,    27,   259,    29,   200,   529,   295,   296,
     297,   298,   305,   306,   202,   202,   150,   205,   205,   177,
     109,   110,   200,   545,   109,   110,   202,   423,   540,   205,
     542,   427,   134,   194,   202,   431,   200,   205,   200,   168,
     129,   130,   131,   200,   129,   130,   131,   201,   202,   202,
     359,   427,   205,   142,   143,   431,   202,   142,   143,   205,
     200,   129,   437,   131,   200,   135,   136,   137,   138,   139,
     140,   141,   200,   207,   470,   200,   186,   191,   208,   244,
     245,   239,   201,   202,   201,   202,   244,   245,   411,   239,
     202,   437,   201,   200,   244,   245,   460,   208,   136,   244,
     245,   266,   263,   268,   135,   136,   137,   138,   139,   140,
     141,   200,   246,   509,   453,   490,   512,    18,   427,   515,
     254,   427,   431,   134,   272,   431,   427,   261,   437,   525,
     431,   437,   441,   509,   200,   441,   437,   311,   136,   515,
     441,   251,   201,   202,   490,   310,   130,   312,   313,   524,
     284,   406,   310,   408,   312,   313,   314,   267,     8,   273,
     310,    25,   312,   313,   205,   310,     3,   312,   313,   142,
     143,   144,   201,   202,   201,   309,   201,   311,   524,   205,
     341,   490,   521,   201,   490,   158,   201,   202,   199,   490,
      93,    94,   203,   204,   359,   206,   201,   199,   200,   132,
     509,   203,   204,   509,   206,   201,   515,   180,   509,   515,
     201,   202,   199,   201,   515,   524,   203,   204,   524,   206,
     201,   202,   200,   524,   206,   339,   201,   202,    18,   343,
     132,    10,   132,    10,   135,   136,   137,   138,   139,   140,
     141,   208,   132,   353,   378,   379,   132,   135,   136,   137,
     138,   139,   140,   141,   205,    18,   366,    18,   200,   373,
     200,   375,   427,   201,   425,   201,   431,   428,   457,   383,
     404,   208,   437,   272,   186,   267,   441,   496,   441,   366,
     414,   350,   416,   150,   151,   152,   153,   154,   453,   514,
     492,   509,   457,   492,   515,   453,   537,   452,   194,   457,
     189,   376,   429,   453,   425,   314,   272,   457,   453,   458,
      92,   406,   457,   529,   414,   275,   477,   205,   452,   379,
     434,   431,    -1,    -1,   458,   490,   460,    -1,    -1,   463,
      -1,    -1,     3,   135,   136,   137,   138,   139,   140,   141,
      -1,     3,     4,    -1,   509,    -1,    17,    -1,    -1,    -1,
     515,    13,    -1,   514,    -1,    17,   521,    -1,    20,   524,
      22,    -1,    24,   521,    -1,   479,    -1,    -1,    -1,    -1,
      -1,   521,   506,    -1,    -1,    -1,   521,    -1,    -1,    -1,
      -1,    -1,   516,    -1,   132,    -1,   496,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,   201,
       3,    -1,    -1,   537,   132,    76,    77,   135,   136,   137,
     138,   139,   140,   141,    17,   529,    87,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,   104,   105,   106,   107,    -1,   109,   110,
     135,   136,   137,   138,   139,   140,   141,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
      -1,   142,   143,    76,    77,    -1,    -1,    -1,    -1,    -1,
     142,   143,    -1,    -1,    87,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   167,    -1,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,   110,    -1,    -1,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   200,
      -1,     3,    -1,   204,    -1,   206,   207,    -1,   200,   142,
     143,   203,   204,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,    -1,   200,    -1,     3,
      -1,   204,    -1,   206,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   167,    -1,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,   110,    -1,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   200,    -1,
      -1,    -1,   204,     3,   206,     5,     6,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,
     204,    -1,   206,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,   204,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,   113,   114,   115,   116,   117,   118,     3,    -1,
      -1,   122,   123,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   200,
      -1,    -1,    87,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,     3,    -1,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,   123,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     3,    -1,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,   123,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
     122,   123
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   210,   211,   212,     3,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   113,   114,   115,   116,   117,   118,   122,   123,   217,
     218,     0,   199,   208,   343,   200,   213,   219,   214,   217,
       5,     7,    13,    20,    27,    29,   221,   222,   223,   233,
     266,   269,   270,   277,   278,   201,   202,     3,     6,    12,
      15,    23,    30,    31,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   113,   114,   115,   117,
     118,   119,   121,   144,   154,   156,   157,   158,   167,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     200,   204,   216,   278,   279,   280,   281,   282,   285,   286,
     287,   288,   293,   294,   295,   296,   298,   299,   303,   304,
     306,   310,   311,   312,   313,   314,   315,   328,   329,   330,
     331,   335,   337,   338,   339,   217,   224,   225,   217,   217,
     217,   234,   235,   214,   267,   268,   343,   217,    17,   109,
     110,   129,   130,   131,   142,   143,   167,   206,   216,   228,
     229,   230,   231,   232,   321,   322,   323,   324,   325,   327,
     328,   329,   331,   332,   329,   320,   321,   279,   320,   283,
     284,   329,   200,   307,   200,   300,   307,   300,   300,   200,
     200,   321,   321,    10,   343,   197,   134,   305,   200,   200,
     329,   199,   203,   204,   206,   243,   200,   200,   336,   200,
     200,   136,   225,   200,   274,   274,   136,   343,   205,   268,
      32,   168,   220,   271,   272,   229,   326,   327,   207,   321,
     333,   334,   324,   130,    18,   135,   136,   137,   138,   139,
     140,   141,   340,   142,   143,   144,   158,   180,   342,   150,
     151,   152,   153,   154,   341,   163,   164,   165,   327,   134,
      25,    28,     8,     8,   202,   302,   308,   309,   321,   301,
     302,     3,   316,   331,   302,   201,   280,   280,   321,   302,
     301,   217,   317,   318,   321,   301,   302,   302,   301,   319,
     321,    29,   214,   275,   276,   205,   273,     3,     4,    13,
      20,    22,    24,   200,   215,   216,   226,   227,   228,   229,
     230,   236,   237,   238,   241,   242,   243,   245,   249,   250,
     253,   254,   235,   236,   221,   277,   343,   326,   132,   202,
     207,   264,   265,   290,   291,   319,   322,   322,   323,   323,
     323,   323,   324,   324,   327,   327,     3,   215,   321,   280,
     320,   280,   280,   284,   205,   201,   202,   201,   202,   201,
     201,   202,   201,   201,   202,   207,   132,   201,   201,   201,
     201,   343,   214,   205,   201,   343,   215,   206,   200,   246,
     246,     6,   214,   255,   256,   257,   258,    18,   217,   239,
     240,   132,   216,   228,   217,   244,   245,   343,   343,   272,
     321,   334,   202,   205,   197,   208,   289,   292,   343,   344,
     132,     9,    26,   297,   321,   309,   302,   301,   318,   321,
     205,   215,   276,   215,   237,   251,   252,    29,   214,   247,
     248,   273,     3,   109,   110,   215,   217,   237,   260,   261,
     205,    10,   343,   344,   236,   201,   202,   226,   265,   280,
      10,   279,   197,   291,   319,   321,   205,   201,   215,   202,
     207,   214,   205,   201,   343,   205,    18,   236,   257,   258,
     240,     8,   321,   252,    18,   205,   215,   248,   261,   262,
     263,   264,   280,   236,   215,   259,   292,   343,   344,   205,
     200,   263,   200,   255,   255,   201,   201,   208,   344
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   209,   210,   211,   212,   213,   213,   214,   214,   215,
     216,   217,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   219,   219,   220,   220,
     221,   221,   222,   222,   222,   223,   224,   224,   225,   226,
     226,   226,   226,   227,   227,   228,   228,   229,   229,   230,
     230,   231,   231,   231,   232,   232,   233,   234,   234,   235,
     236,   236,   236,   236,   236,   237,   237,   238,   239,   239,
     240,   241,   242,   243,   243,   244,   244,   245,   245,   246,
     246,   247,   247,   248,   248,   248,   248,   249,   249,   249,
     250,   251,   251,   252,   252,   253,   254,   255,   255,   255,
     255,   256,   256,   257,   258,   259,   259,   260,   260,   261,
     261,   262,   262,   263,   264,   264,   265,   265,   266,   267,
     267,   268,   269,   269,   270,   270,   271,   271,   272,   272,
     273,   273,   274,   274,   275,   275,   276,   276,   277,   278,
     279,   279,   280,   280,   281,   281,   281,   281,   282,   283,
     283,   284,   285,   285,   286,   287,   287,   288,   289,   289,
     290,   290,   291,   292,   292,   293,   293,   293,   294,   295,
     296,   297,   297,   298,   298,   298,   298,   299,   300,   300,
     301,   301,   302,   303,   304,   304,   304,   305,   305,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   307,   307,
     308,   308,   309,   309,   309,   310,   310,   310,   310,   310,
     310,   310,   310,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     312,   312,   312,   313,   313,   313,   313,   314,   315,   316,
     316,   317,   317,   318,   318,   319,   320,   321,   321,   321,
     322,   322,   322,   322,   322,   323,   323,   323,   324,   324,
     325,   325,   325,   325,   326,   326,   327,   327,   327,   327,
     327,   327,   328,   329,   329,   330,   330,   331,   331,   331,
     331,   331,   331,   331,   331,   332,   332,   333,   333,   334,
     334,   335,   335,   335,   336,   336,   337,   337,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   339,   339,   340,   340,   340,   340,   340,   340,   341,
     341,   341,   341,   342,   342,   343,   344,   344
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     0,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     0,     2,
       1,     1,     1,     1,     1,     2,     1,     2,     4,     1,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     2,     1,     1,     1,     1,     2,     3,     0,
       3,     1,     3,     1,     3,     4,     2,     1,     1,     1,
       6,     1,     3,     1,     1,     3,     3,     0,     2,     3,
       1,     1,     3,     3,     5,     1,     5,     3,     1,     1,
       1,     1,     3,     5,     1,     3,     1,     3,     2,     1,
       2,     4,     4,     5,     3,     4,     1,     3,     1,     1,
       0,     2,     0,     3,     1,     3,     3,     4,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     1,     1,     1,     4,     3,     1,     6,     1,     2,
       1,     3,     3,     1,     2,     1,     1,     1,     4,     4,
       8,     1,     1,     1,     1,     1,     1,     0,     0,     3,
       1,     3,     1,     2,     1,     2,     1,     0,     2,     4,
       4,     2,     2,     2,     2,     2,     4,     6,     0,     3,
       1,     3,     1,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     3,     3,     1,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     2,
       1,     3,     3,     3,     1,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2,     4,     4,     4,     2,     3,     1,     3,     1,
       3,     4,     2,     4,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1
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
        case 7:
#line 187 "gram.y" /* yacc.c:1646  */
    {(yyval.y_varidlist)  = build_var_id_list(NULL, (yyvsp[0].y_stid));}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 188 "gram.y" /* yacc.c:1646  */
    {(yyval.y_varidlist) = build_var_id_list((yyvsp[-2].y_varidlist), (yyvsp[0].y_stid));}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 192 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = check_typename(st_enter_id((yyvsp[0].y_string)));}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 196 "gram.y" /* yacc.c:1646  */
    {(yyval.y_stid) = st_enter_id((yyvsp[0].y_string));}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 204 "gram.y" /* yacc.c:1646  */
    {(yyval.y_stid) = st_enter_id((yyvsp[0].y_string));}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 206 "gram.y" /* yacc.c:1646  */
    {}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 207 "gram.y" /* yacc.c:1646  */
    {}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 208 "gram.y" /* yacc.c:1646  */
    {}
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 210 "gram.y" /* yacc.c:1646  */
    {}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 211 "gram.y" /* yacc.c:1646  */
    {}
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 212 "gram.y" /* yacc.c:1646  */
    {}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 213 "gram.y" /* yacc.c:1646  */
    {}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 214 "gram.y" /* yacc.c:1646  */
    {}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 215 "gram.y" /* yacc.c:1646  */
    {}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 216 "gram.y" /* yacc.c:1646  */
    {}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 217 "gram.y" /* yacc.c:1646  */
    {}
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 218 "gram.y" /* yacc.c:1646  */
    {}
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 219 "gram.y" /* yacc.c:1646  */
    {}
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 220 "gram.y" /* yacc.c:1646  */
    {}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 221 "gram.y" /* yacc.c:1646  */
    {}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 222 "gram.y" /* yacc.c:1646  */
    {}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "gram.y" /* yacc.c:1646  */
    {}
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 225 "gram.y" /* yacc.c:1646  */
    {}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 227 "gram.y" /* yacc.c:1646  */
    {}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 228 "gram.y" /* yacc.c:1646  */
    {}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 229 "gram.y" /* yacc.c:1646  */
    {}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 230 "gram.y" /* yacc.c:1646  */
    {}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "gram.y" /* yacc.c:1646  */
    {}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 232 "gram.y" /* yacc.c:1646  */
    {}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 233 "gram.y" /* yacc.c:1646  */
    {}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 234 "gram.y" /* yacc.c:1646  */
    {}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 235 "gram.y" /* yacc.c:1646  */
    {}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 236 "gram.y" /* yacc.c:1646  */
    {}
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 238 "gram.y" /* yacc.c:1646  */
    {}
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 239 "gram.y" /* yacc.c:1646  */
    {}
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 241 "gram.y" /* yacc.c:1646  */
    {}
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 242 "gram.y" /* yacc.c:1646  */
    {}
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 243 "gram.y" /* yacc.c:1646  */
    {}
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 244 "gram.y" /* yacc.c:1646  */
    {}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 245 "gram.y" /* yacc.c:1646  */
    {}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 247 "gram.y" /* yacc.c:1646  */
    {}
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 248 "gram.y" /* yacc.c:1646  */
    {}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 249 "gram.y" /* yacc.c:1646  */
    {}
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 250 "gram.y" /* yacc.c:1646  */
    {}
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 251 "gram.y" /* yacc.c:1646  */
    {}
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 252 "gram.y" /* yacc.c:1646  */
    {}
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 253 "gram.y" /* yacc.c:1646  */
    {}
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 254 "gram.y" /* yacc.c:1646  */
    {}
#line 2624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 273 "gram.y" /* yacc.c:1646  */
    {}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 274 "gram.y" /* yacc.c:1646  */
    {}
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 275 "gram.y" /* yacc.c:1646  */
    {}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 294 "gram.y" /* yacc.c:1646  */
    {}
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 295 "gram.y" /* yacc.c:1646  */
    {}
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 297 "gram.y" /* yacc.c:1646  */
    {}
#line 2660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 301 "gram.y" /* yacc.c:1646  */
    {(yyval.y_cint) = (yyvsp[0].y_cint);}
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 302 "gram.y" /* yacc.c:1646  */
    {(yyval.y_cint) = (yyvsp[0].y_cint);}
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 311 "gram.y" /* yacc.c:1646  */
    {}
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 312 "gram.y" /* yacc.c:1646  */
    {}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 332 "gram.y" /* yacc.c:1646  */
    {resolve_all_ptr();}
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 342 "gram.y" /* yacc.c:1646  */
    {create_typename((yyvsp[-2].y_stid), (yyvsp[0].y_type));}
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 347 "gram.y" /* yacc.c:1646  */
    {}
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 354 "gram.y" /* yacc.c:1646  */
    {}
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 372 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = check_subrange((yyvsp[-2].y_cint), (yyvsp[0].y_cint));}
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 376 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = (yyvsp[0].y_type);}
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 385 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = ty_build_ptr((yyvsp[0].y_stid));}
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 386 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = ty_build_ptr((yyvsp[0].y_type));}
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 390 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = ty_build_func(ty_build_basic(TYVOID), (yyvsp[0].y_paramlist), TRUE);}
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 391 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = ty_build_func((yyvsp[0].y_type), (yyvsp[-1].y_paramlist), TRUE);}
#line 2744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 395 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist) = NULL;}
#line 2750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 396 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist) = check_param((yyvsp[-1].y_paramlist));}
#line 2756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 401 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist) = concat_param_list((yyvsp[-2].y_paramlist), (yyvsp[0].y_paramlist));}
#line 2762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 405 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist)=build_param_list((yyvsp[0].y_varidlist),ty_build_basic(TYERROR),FALSE);}
#line 2768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 406 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist) = build_param_list((yyvsp[-2].y_varidlist), (yyvsp[0].y_type), FALSE);}
#line 2774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 407 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist) = build_param_list((yyvsp[-2].y_varidlist), (yyvsp[0].y_type), TRUE);}
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 408 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist)=build_param_list((yyvsp[0].y_varidlist),ty_build_basic(TYERROR),TRUE);}
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 413 "gram.y" /* yacc.c:1646  */
    {}
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 414 "gram.y" /* yacc.c:1646  */
    {}
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 420 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = check_array((yyvsp[0].y_type), (yyvsp[-3].y_indexlist));}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 424 "gram.y" /* yacc.c:1646  */
    {(yyval.y_indexlist) = create_list_from_type((yyvsp[0].y_type));}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 425 "gram.y" /* yacc.c:1646  */
    {(yyval.y_indexlist) = concat_index_list((yyvsp[-2].y_indexlist),(yyvsp[0].y_type));}
#line 2816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 430 "gram.y" /* yacc.c:1646  */
    {}
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 512 "gram.y" /* yacc.c:1646  */
    {create_gdecl((yyvsp[-3].y_varidlist), (yyvsp[-1].y_type)); encode_declaration ((yyvsp[-1].y_type), (yyvsp[-3].y_varidlist));}
#line 2828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 536 "gram.y" /* yacc.c:1646  */
    {}
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 537 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = check_function_type((yyvsp[0].y_type));}
#line 2840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 947 "gram.y" /* yacc.c:1646  */
    {}
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2850 "y.tab.c" /* yacc.c:1646  */
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
#line 971 "gram.y" /* yacc.c:1906  */


void yyerror(const char *msg)
{
    error(msg);
}

/* Sets the value of the 'yydebug' variable to VALUE.
   This is a function so we don't have to have YYDEBUG defined
   in order to build the compiler.  */
void
set_yydebug (int value)
{
#if YYDEBUG != 0
  yydebug = value;
#else
  warning ("YYDEBUG not defined.");
#endif
}
