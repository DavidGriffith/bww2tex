
/*  A Bison parser, made from grammar.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TXT	257
#define	ANTXT	258
#define	NUMBER	259
#define	TITLE	260
#define	CLEFT	261
#define	BEAT	262
#define	BAR	263
#define	EOL	264
#define	METERFRAC	265
#define	METER	266
#define	SIGNATURE	267
#define	COMMENT	268
#define	FORMAT	269
#define	STARTFS	270
#define	ENDFS	271
#define	EMB	272
#define	EMBP	273
#define	REST	274
#define	REP	275
#define	TREMB	276
#define	TREMBP	277
#define	BEAM	278
#define	THEME	279
#define	TIME	280
#define	DOT	281
#define	DDOT	282
#define	TUNETYPE	283
#define	COMPOSER	284
#define	TRIPLET	285
#define	ETIE	286
#define	ENDFILE	287
#define	TIE	288
#define	TIEBEAT	289
#define	TIEALA	290
#define	TIEDBL	291
#define	TIECLEFT	292
#define	TIEXBAR	293
#define	TIELRBAR	294
#define	TIEDBAR	295

#line 5 "grammar.y"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tokensDat.h"
#define YYMAXDEPTH 1000
#define MAXLEN 2047
#define YYSTYPE char *

/* uncomment the following line for use with DropUNIX on the MAC */
/* #define MAC */

#ifdef MAC
#define alloca malloc
#endif

/* _WIN32 definition added for use with MS VC++ compiler. */
#ifdef _WIN32
#include <malloc.h>
#endif


int firstline=1, ntext=0, page, tiepend=0, tiearmed=0, lbhead;
size_t prelen, nn;
char num[2],den[2];
char *insert(char *, char *);
char *inserts(char*, char *, char *);
char *insertt(char*, char *, char *);
char *inserttie(char*, char *);
char *inserttrip(char*, char*);
char *insertthtrip(char*, char*);
char *insertetn(char *);
char *shorten( char *);
char *sdpnt;

/* FILE *yyout = stderr; */  /* directs unrecognized input to stderr.
                                some loaders don't like this. */
int  i;

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		146
#define	YYFLAG		-32768
#define	YYNTBASE	42

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 61)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     7,    11,    15,    20,    22,    25,    28,
    30,    34,    37,    40,    43,    46,    50,    53,    56,    58,
    61,    64,    67,    70,    74,    77,    80,    84,    88,    92,
    96,   101,   105,   108,   112,   115,   119,   123,   127,   131,
   136,   140,   143,   147,   150,   153,   156,   160,   164,   168,
   172,   177,   181,   183,   186,   190,   192,   194,   196,   200,
   203,   207,   211,   215,   218,   221,   224,   229,   234,   238,
   244,   250,   255,   262,   269,   275,   282,   289,   295,   298,
   301,   303,   306,   309,   311,   313,   315,   317,   319,   321,
   323,   326,   329,   332,   334,   337,   340,   343,   346,   348,
   351,   354,   357,   359,   361,   363,   365,   367,   370,   374,
   376,   378,   382,   385,   388,   391,   393,   395,   397
};

static const short yyrhs[] = {    -1,
    42,    43,     0,    44,    46,     0,    44,    46,    33,     0,
    44,    46,    46,     0,    44,    46,    46,    33,     0,    57,
     0,     1,    10,     0,    44,    47,     0,    45,     0,    44,
    46,    47,     0,    44,    56,     0,    44,    34,     0,    44,
    55,     0,    44,    48,     0,    44,    46,    48,     0,    44,
    17,     0,    44,     8,     0,     7,     0,    45,    13,     0,
    45,    12,     0,    45,    11,     0,    49,    53,     0,    49,
    34,    53,     0,    49,    36,     0,    49,    37,     0,    49,
     8,    53,     0,    49,    55,    53,     0,    49,     8,    46,
     0,    49,    55,    46,     0,    49,    52,    54,    53,     0,
    52,    54,    53,     0,    49,     7,     0,    49,    34,     7,
     0,    49,    38,     0,    49,     8,     7,     0,    49,    55,
     7,     0,    49,     8,    47,     0,    49,    55,    47,     0,
    49,    52,    54,     7,     0,    52,    54,     7,     0,    49,
    56,     0,    49,    34,    56,     0,    49,    39,     0,    49,
    41,     0,    49,    40,     0,    49,     8,    56,     0,    49,
    55,    56,     0,    49,     8,    48,     0,    49,    55,    48,
     0,    49,    52,    54,    56,     0,    52,    54,    56,     0,
    50,     0,    49,    50,     0,    49,    34,    50,     0,    51,
     0,    52,     0,    54,     0,    52,    54,     8,     0,    52,
    51,     0,    52,    54,    51,     0,    25,    26,    28,     0,
    25,    26,    27,     0,    25,    26,     0,    51,    31,     0,
    51,    32,     0,    25,    24,    26,    28,     0,    25,    24,
    26,    27,     0,    25,    24,    26,     0,    52,    25,    24,
    26,    28,     0,    52,    25,    24,    26,    27,     0,    52,
    25,    24,    26,     0,    52,    54,    25,    24,    26,    28,
     0,    52,    54,    25,    24,    26,    27,     0,    52,    54,
    25,    24,    26,     0,    52,    34,    25,    24,    26,    28,
     0,    52,    34,    25,    24,    26,    27,     0,    52,    34,
    25,    24,    26,     0,    52,    31,     0,    52,    32,     0,
    10,     0,    53,    21,     0,    53,    17,     0,    19,     0,
    18,     0,    20,     0,    17,     0,    16,     0,    12,     0,
    11,     0,    54,    18,     0,    54,    19,     0,    54,    54,
     0,    35,     0,    34,     8,     0,     8,    34,     0,    55,
     8,     0,     8,    55,     0,     9,     0,     8,    56,     0,
    56,     8,     0,    56,    17,     0,    14,     0,    15,     0,
    58,     0,    59,     0,    60,     0,    58,    58,     0,    58,
    58,    58,     0,     3,     0,     4,     0,     6,    29,    30,
     0,     6,    29,     0,     6,    30,     0,    29,    30,     0,
     6,     0,    29,     0,    30,     0,     5,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    57,    58,    61,    67,    78,    85,    99,   100,   102,   108,
   110,   118,   171,   173,   175,   180,   187,   188,   191,   197,
   201,   205,   216,   218,   222,   226,   230,   233,   238,   240,
   244,   248,   254,   257,   262,   267,   270,   276,   278,   282,
   287,   294,   296,   300,   304,   309,   313,   315,   319,   321,
   325,   329,   336,   337,   338,   343,   344,   345,   346,   347,
   348,   351,   354,   357,   360,   362,   367,   370,   373,   376,
   381,   386,   391,   396,   401,   406,   411,   416,   511,   513,
   517,   518,   520,   523,   524,   525,   526,   527,   545,   548,
   556,   557,   558,   560,   561,   562,   563,   564,   566,   567,
   568,   569,   605,   608,   609,   616,   619,   633,   641,   656,
   659,   660,   663,   665,   667,   669,   670,   671,   674
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","TXT","ANTXT",
"NUMBER","TITLE","CLEFT","BEAT","BAR","EOL","METERFRAC","METER","SIGNATURE",
"COMMENT","FORMAT","STARTFS","ENDFS","EMB","EMBP","REST","REP","TREMB","TREMBP",
"BEAM","THEME","TIME","DOT","DDOT","TUNETYPE","COMPOSER","TRIPLET","ETIE","ENDFILE",
"TIE","TIEBEAT","TIEALA","TIEDBL","TIECLEFT","TIEXBAR","TIELRBAR","TIEDBAR",
"input","line","bline","bbline","ebar","ebarc","mbar","bcont","element","theme",
"btheme","eol","emb","tiebeat","bar","tline","text","antext","number", NULL
};
#endif

static const short yyr1[] = {     0,
    42,    42,    43,    43,    43,    43,    43,    43,    44,    44,
    44,    44,    44,    44,    44,    44,    44,    44,    45,    45,
    45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    47,    47,    47,    47,    47,    47,    47,    47,
    47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    48,    48,    49,    49,    49,    50,    50,    50,    50,    50,
    50,    51,    51,    51,    51,    51,    52,    52,    52,    52,
    52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
    53,    53,    53,    54,    54,    54,    54,    54,    54,    54,
    54,    54,    54,    55,    55,    55,    55,    55,    56,    56,
    56,    56,    57,    57,    57,    57,    57,    57,    57,    58,
    59,    59,    59,    59,    59,    59,    59,    59,    60
};

static const short yyr2[] = {     0,
     0,     2,     2,     3,     3,     4,     1,     2,     2,     1,
     3,     2,     2,     2,     2,     3,     2,     2,     1,     2,
     2,     2,     2,     3,     2,     2,     3,     3,     3,     3,
     4,     3,     2,     3,     2,     3,     3,     3,     3,     4,
     3,     2,     3,     2,     2,     2,     3,     3,     3,     3,
     4,     3,     1,     2,     3,     1,     1,     1,     3,     2,
     3,     3,     3,     2,     2,     2,     4,     4,     3,     5,
     5,     4,     6,     6,     5,     6,     6,     5,     2,     2,
     1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
     2,     2,     2,     1,     2,     2,     2,     2,     1,     2,
     2,     2,     1,     1,     1,     1,     1,     2,     3,     1,
     1,     3,     2,     2,     2,     1,     1,     1,     1
};

static const short yydefact[] = {     1,
     0,     0,   110,   111,   119,   116,    19,   103,   104,   117,
   118,     2,     0,    10,     7,   105,   106,   107,     8,   113,
   114,   115,    18,    99,    90,    89,    88,    17,    85,    84,
    86,     0,    13,    94,     3,     9,    15,     0,    53,    56,
    57,    58,    14,    12,    22,    21,    20,   108,   112,     0,
    96,    98,   100,     0,    64,    95,    87,     4,     5,    11,
    16,    33,     0,    81,     0,    25,    26,    35,    44,    46,
    45,    54,    57,    23,     0,    42,    65,    66,     0,    79,
    80,     0,    60,     0,    85,    84,    93,    97,   101,   102,
   109,    69,    63,    62,     6,    36,    29,    38,    49,    27,
    47,    34,    95,    55,    57,    24,    43,     0,    83,    82,
    37,    97,    30,    39,    50,    28,    48,     0,     0,    41,
    59,     0,    61,    32,    52,    68,    67,     0,     0,    40,
    31,    51,    72,     0,     0,    59,    71,    70,    78,    75,
    77,    76,    74,    73,     0,     0
};

static const short yydefgoto[] = {     1,
    12,    13,    14,    35,    36,    37,    38,    39,    40,    41,
    74,    42,    52,    53,    15,    16,    17,    18
};

static const short yypact[] = {-32768,
   107,     0,-32768,-32768,-32768,     9,-32768,-32768,-32768,    -6,
-32768,-32768,   136,    10,-32768,    28,-32768,-32768,-32768,    13,
-32768,-32768,   123,-32768,-32768,-32768,-32768,    19,-32768,-32768,
-32768,    -7,    40,-32768,   172,-32768,-32768,    65,-32768,    47,
   148,   273,    56,     3,-32768,-32768,-32768,    28,-32768,   123,
    40,    56,     3,    43,    59,-32768,-32768,-32768,    12,-32768,
-32768,-32768,   108,-32768,   191,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   148,    -5,   210,     3,-32768,-32768,     4,-32768,
-32768,    41,    47,   229,-32768,-32768,   273,-32768,-32768,-32768,
-32768,    66,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    -5,
     3,-32768,    88,-32768,   148,    -5,     3,   248,-32768,-32768,
-32768,    88,-32768,-32768,-32768,    -5,     3,    54,    64,-32768,
    88,    37,    47,    -5,     3,-32768,-32768,    88,   263,-32768,
    -5,     3,   102,    72,    83,-32768,-32768,-32768,   111,   113,
-32768,-32768,-32768,-32768,    92,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,   -26,   -22,   -21,-32768,   -33,   -38,   -31,
   -57,   -40,     2,   -13,-32768,   -12,-32768,-32768
};


#define	YYLAST		293


static const short yytable[] = {    44,
    84,    87,    83,    48,    72,   100,    73,   106,    59,    19,
    89,   109,    60,    61,    43,   110,    54,   116,    55,    90,
    45,    46,    47,    22,    76,   -87,   124,   118,   -87,    55,
     3,   104,   108,   105,    83,    91,    97,    20,    21,    75,
    98,    99,    49,    87,    95,   123,    87,    56,   113,   101,
   131,   107,   114,   115,   -87,   -87,   -87,   -87,   -87,   -87,
   135,   117,    55,    88,   129,   119,    83,    87,    92,   123,
   125,    62,    63,    24,    64,    25,    26,    77,    78,   133,
    27,    57,    29,    30,    31,    93,    94,   134,    87,    32,
   123,   146,   126,   127,   132,   128,    24,   139,    65,    34,
    66,    67,    68,    69,    70,    71,   145,     2,   140,     3,
     4,     5,     6,     7,    96,    50,    24,    64,    25,    26,
     8,     9,     0,    27,    57,    29,    30,    31,   137,   138,
    50,    24,    32,     0,     0,    10,    11,   141,   142,   143,
   144,    51,    34,    23,    24,     0,    25,    26,     0,     0,
     0,    27,    28,    29,    30,    31,    51,    34,    25,    26,
    32,     0,     0,    27,    57,    29,    30,    31,     0,    33,
    34,     0,    79,     0,     0,     0,     0,     0,    80,    81,
     0,    82,    25,    26,     0,     0,     0,    27,    57,    29,
    30,    31,     0,     0,     0,     0,    32,   102,   103,    24,
    64,    25,    26,     0,    58,     0,    27,    57,    29,    30,
    31,     0,     0,     0,     0,    32,   111,   112,    24,    64,
    25,    26,     0,     0,     0,    27,    57,    29,    30,    31,
     0,     0,     0,     0,    32,   120,   121,    24,    64,    25,
    26,     0,     0,     0,    27,    57,    85,    86,    31,     0,
     0,     0,     0,   122,   130,   121,    24,    64,    25,    26,
     0,     0,     0,    27,    57,    85,    86,    31,     0,     0,
   136,     0,   122,    25,    26,     0,     0,     0,    27,    57,
    85,    86,    31,    25,    26,     0,     0,   122,    27,    57,
    85,    86,    31
};

static const short yycheck[] = {    13,
    41,    42,    41,    16,    38,    63,    38,    65,    35,    10,
     8,    17,    35,    35,    13,    21,    24,    75,    26,    17,
    11,    12,    13,    30,    38,     7,    84,    24,    10,    26,
     3,    65,    73,    65,    73,    48,    63,    29,    30,    38,
    63,    63,    30,    84,    33,    84,    87,     8,    75,    63,
   108,    65,    75,    75,    36,    37,    38,    39,    40,    41,
    24,    75,    26,     8,   105,    25,   105,   108,    26,   108,
    84,     7,     8,     9,    10,    11,    12,    31,    32,    26,
    16,    17,    18,    19,    20,    27,    28,    24,   129,    25,
   129,     0,    27,    28,   108,     8,     9,    26,    34,    35,
    36,    37,    38,    39,    40,    41,     0,     1,    26,     3,
     4,     5,     6,     7,     7,     8,     9,    10,    11,    12,
    14,    15,    -1,    16,    17,    18,    19,    20,    27,    28,
     8,     9,    25,    -1,    -1,    29,    30,    27,    28,    27,
    28,    34,    35,     8,     9,    -1,    11,    12,    -1,    -1,
    -1,    16,    17,    18,    19,    20,    34,    35,    11,    12,
    25,    -1,    -1,    16,    17,    18,    19,    20,    -1,    34,
    35,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,
    -1,    34,    11,    12,    -1,    -1,    -1,    16,    17,    18,
    19,    20,    -1,    -1,    -1,    -1,    25,     7,     8,     9,
    10,    11,    12,    -1,    33,    -1,    16,    17,    18,    19,
    20,    -1,    -1,    -1,    -1,    25,     7,     8,     9,    10,
    11,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,
    -1,    -1,    -1,    -1,    25,     7,     8,     9,    10,    11,
    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,    -1,
    -1,    -1,    -1,    25,     7,     8,     9,    10,    11,    12,
    -1,    -1,    -1,    16,    17,    18,    19,    20,    -1,    -1,
     8,    -1,    25,    11,    12,    -1,    -1,    -1,    16,    17,
    18,    19,    20,    11,    12,    -1,    -1,    25,    16,    17,
    18,    19,    20
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/afs/slac.stanford.edu/package/gnu2/bison/1.28/i386_linux22/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/afs/slac.stanford.edu/package/gnu2/bison/1.28/i386_linux22/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
#line 61 "grammar.y"
{ strcat(yyvsp[-1],"\\notes");
                         if(tiearmed) { tiearmed=0; strcat(yyvsp[-1],"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                           printf("%s", strcat(strcat(yyvsp[-1],yyvsp[0]),suspmorceau));
                           free(yyvsp[-1]); free(yyvsp[0]);
                        ;
    break;}
case 4:
#line 67 "grammar.y"
{ strcat(yyvsp[-2],"\\notes");
                         if(tiearmed) { tiearmed=0; strcat(yyvsp[-2],"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                         sdpnt = strrchr(yyvsp[-1],'\\');
                         if (sdpnt !="" && strcmp(sdpnt,"\\setrightrepeat") == 0){
                              printf("%s", strcat(strcat(yyvsp[-2],yyvsp[-1]),"\\suspmorceau"));
                              free(yyvsp[-2]); free(yyvsp[-1]); return 1; }
                         else {
                           printf("%s", strcat(strcat(yyvsp[-2],yyvsp[-1]),"\\finmorceau"));
                           free(yyvsp[-2]); free(yyvsp[-1]); return 1; }
                        ;
    break;}
case 5:
#line 78 "grammar.y"
{ strcat(yyvsp[-2],"\\notes");
                         if(tiearmed) { tiearmed=0; strcat(yyvsp[-2],"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                           printf("%s",strcat(strcat(strcat(strcat(strcat
                                (yyvsp[-2],yyvsp[-1]),xbarre),"\\notes"),yyvsp[0]),suspmorceau));
                           free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                        ;
    break;}
case 6:
#line 85 "grammar.y"
{ strcat(yyvsp[-3],"\\notes");
                         if(tiearmed) { tiearmed=0; strcat(yyvsp[-3],"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                          sdpnt = strrchr(yyvsp[-1],'\\');
                         if (sdpnt !="" && strcmp(sdpnt,"\\setrightrepeat") == 0){
                            printf("%s",strcat(strcat(strcat(strcat(strcat
                                (yyvsp[-3],yyvsp[-2]),xbarre),"\\notes"),yyvsp[-1]),"\\suspmorceau"));
                              free(yyvsp[-3]); free(yyvsp[-2]); free(yyvsp[-1]); return 1; }
                         else {
                          printf("%s",strcat(strcat(strcat(strcat(strcat
                                (yyvsp[-3],yyvsp[-2]),xbarre),"\\notes"),yyvsp[-1]),"\\finmorceau"));
                           free(yyvsp[-3]); free(yyvsp[-2]); free(yyvsp[-1]); return 1;
                              }
                        ;
    break;}
case 7:
#line 99 "grammar.y"
{ printf("%s%%\n",yyvsp[0]); free(yyvsp[0]);;
    break;}
case 8:
#line 100 "grammar.y"
{ printf("%s\n",yyvsp[-1]); ;
    break;}
case 9:
#line 102 "grammar.y"
{ strcat(yyvsp[-1],"\\notes");
                     if(tiearmed) { tiearmed=0; strcat(yyvsp[-1],"\\tten0"); }
                     if(tiepend) { tiepend=0; tiearmed=1; }
                     printf("%s", strcat(yyvsp[-1],yyvsp[0])); free(yyvsp[-1]); free(yyvsp[0]);
                     yyval=malloc(MAXLEN); strcpy(yyval,reprmorceau);
                   ;
    break;}
case 10:
#line 108 "grammar.y"
{  yyval = yyvsp[0]
                   ;
    break;}
case 11:
#line 110 "grammar.y"
{ strcat(yyvsp[-2],"\\notes");
                     if(tiearmed) { tiearmed=0; strcat(yyvsp[-2],"\\tten0"); }
                     if(tiepend) { tiepend=0; tiearmed=1; }
                     printf("%s", strcat(strcat(strcat(strcat
                     (yyvsp[-2],yyvsp[-1]),xbarre),"\\notes"),yyvsp[0]));
                     free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                     yyval=malloc(MAXLEN); strcpy(yyval,reprmorceau);
                        ;
    break;}
case 12:
#line 118 "grammar.y"
{ yyval = strcat(yyvsp[-1],yyvsp[0]); free(yyvsp[0]);
                     ;
    break;}
case 13:
#line 171 "grammar.y"
{ yyval = yyvsp[-1]; free(yyvsp[0]);
                     ;
    break;}
case 14:
#line 173 "grammar.y"
{ yyval = insertetn(yyvsp[-1]); free(yyvsp[0]);
                     ;
    break;}
case 15:
#line 175 "grammar.y"
{ yyval = strcat(yyvsp[-1],"\\notes");
                         if(tiearmed) { tiearmed=0; strcat(yyval,"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                         strcat(yyval,yyvsp[0]); free(yyvsp[0]);
                        ;
    break;}
case 16:
#line 180 "grammar.y"
{ yyval = strcat(yyvsp[-2],"\\notes");
                         if(tiearmed) { tiearmed=0; strcat(yyval,"\\tten0"); }
                         if(tiepend) { tiepend=0; tiearmed=1; }
                         strcat(yyval,yyvsp[-1]); strcat(yyval,xbarre);
                         strcat(yyval,"\\notes"); strcat(yyval,yyvsp[0]);
                         free(yyvsp[-1]); free(yyvsp[0]);
                        ;
    break;}
case 17:
#line 187 "grammar.y"
{ yyval=strcat(yyvsp[-1],"\\notes\\Uptext{$\\vert$}\\enotes"); ;
    break;}
case 18:
#line 188 "grammar.y"
{ yyval=yyvsp[-1]; ;
    break;}
case 19:
#line 191 "grammar.y"
{yyval=malloc(MAXLEN);
              if (firstline) { firstline=0;
                               strcpy(yyval,"\\debutmorceau\n\\setelemq{1.2}%\n");
                             }
              else             strcpy(yyval,yyvsp[0]);
             ;
    break;}
case 20:
#line 197 "grammar.y"
{ yyval = malloc(MAXLEN);
                         strcat(strcat(strcat(strcpy(yyval,"\\generalsignature{"),
                         yyvsp[0]),"}\n"),yyvsp[-1]); free(yyvsp[-1]);
                       ;
    break;}
case 21:
#line 201 "grammar.y"
{ yyval = malloc(MAXLEN);
                          strcpy(yyval,"\\generalmeter{");
                          strcat(strcat(yyval,yyvsp[0]),"}\n"); strcat(yyval,yyvsp[-1]); free(yyvsp[-1]);
                   ;
    break;}
case 22:
#line 205 "grammar.y"
{ prelen=strcspn(yyvsp[0],"_") ;
                         strncpy(num,yyvsp[0],prelen) ; strcpy(num+prelen,"");
                         strcpy(den,yyvsp[0]+prelen+1) ;
                         yyval=malloc(MAXLEN);
                         strcat(strcat(strcat(strcat(strcat(strcpy(
                              yyval,"\\generalmeter{\\meterfrac{"),
                                   num),"}{"),den),"}}\n"),yyvsp[-1]);
                         free(yyvsp[-1]); free(yyvsp[0]);
                       ;
    break;}
case 23:
#line 216 "grammar.y"
{yyval = strcat(strcat(yyvsp[-1],"\\enotes"),yyvsp[0]); free(yyvsp[0]);
                ;
    break;}
case 24:
#line 218 "grammar.y"
{ yyval = inserttie(yyvsp[-2],yyvsp[-1]);
                      strcat(strcat(yyval,"\\enotes"),yyvsp[0]);
                      tiepend=1; free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                    ;
    break;}
case 25:
#line 222 "grammar.y"
{ yyval = inserttie(yyvsp[-1],yyvsp[0]);
                      strcat(strcat(yyval,"\\enotes"),alaligne);
                      tiepend=1; free(yyvsp[-1]); free(yyvsp[0]);
                    ;
    break;}
case 26:
#line 226 "grammar.y"
{ yyval = inserttie(yyvsp[-1],yyvsp[0]);
                      strcat(strcat(yyval,"\\enotes"),setdoublebar);
                      tiepend=1; free(yyvsp[-1]); free(yyvsp[0]);
                    ;
    break;}
case 27:
#line 230 "grammar.y"
{ yyval = strcat(strcat(yyvsp[-2],"\\enotes"),yyvsp[0]);
                                                       free(yyvsp[0]);
                     ;
    break;}
case 28:
#line 233 "grammar.y"
{
                         yyval = inserttie(yyvsp[-2],yyvsp[-1]);
                         strcat(strcat(yyval,"\\enotes"),yyvsp[0]);
                         tiepend=1; free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                        ;
    break;}
case 29:
#line 238 "grammar.y"
{yyval = insertetn(yyvsp[-2]); strcat(yyval,yyvsp[0]); free(yyvsp[0]);
                      ;
    break;}
case 30:
#line 240 "grammar.y"
{yyval = inserttie(yyvsp[-2],yyvsp[-1]); insertetn(yyval);
                          strcat(yyval,"\\tten0"); strcat(yyval,yyvsp[0]);
                          free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                         ;
    break;}
case 31:
#line 244 "grammar.y"
{yyval = strcat(yyvsp[-3],yyvsp[-2]); strcat (yyval,yyvsp[-1]);
                            strcat(yyval,"\\enotes"); strcat(yyval,yyvsp[0]);
                            free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                           ;
    break;}
case 32:
#line 248 "grammar.y"
{yyval = strcat(yyvsp[-2],yyvsp[-1]);
                             strcat(yyval,"\\enotes"); strcat(yyval,yyvsp[0]);
                             free(yyvsp[-1]); free(yyvsp[0]);
                      ;
    break;}
case 33:
#line 254 "grammar.y"
{yyval = strcat(strcat(yyvsp[-1],"\\enotes"),alaligne);
                    strcat(yyval,suspmorceau);
                   ;
    break;}
case 34:
#line 257 "grammar.y"
{ yyval = inserttie(yyvsp[-2],yyvsp[-1]);
                       strcat(strcat(yyval,"\\enotes"),alaligne);
                       strcat(yyval,suspmorceau);
                       tiepend=1; free(yyvsp[-2]); free(yyvsp[-1]);
                      ;
    break;}
case 35:
#line 262 "grammar.y"
{ yyval = inserttie(yyvsp[-1],yyvsp[0]);
                      strcat(strcat(yyval,"\\enotes"),alaligne);
                      strcat(yyval,suspmorceau);
                      tiepend=1; free(yyvsp[-1]); free(yyvsp[0]);
                     ;
    break;}
case 36:
#line 267 "grammar.y"
{ yyval = strcat(strcat(yyvsp[-2],"\\enotes"),alaligne);
                         strcat(yyval,suspmorceau);
                       ;
    break;}
case 37:
#line 270 "grammar.y"
{
                           yyval = inserttie(yyvsp[-2],yyvsp[-1]);
                           strcat(strcat(yyval,"\\enotes"),alaligne);
                           strcat(yyval,suspmorceau);
                           tiepend=1; free(yyvsp[-2]); free(yyvsp[-1]);
                          ;
    break;}
case 38:
#line 276 "grammar.y"
{yyval = insertetn(yyvsp[-2]); strcat(yyval,yyvsp[0]); free(yyvsp[0]);
                       ;
    break;}
case 39:
#line 278 "grammar.y"
{yyval = inserttie(yyvsp[-2],yyvsp[-1]); insertetn(yyval);
                           strcat(yyval,"\\tten0"); strcat(yyval,yyvsp[0]);
                           free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                          ;
    break;}
case 40:
#line 282 "grammar.y"
{yyval = strcat(yyvsp[-3],yyvsp[-2]); strcat (yyval,yyvsp[-1]);
                              strcat(yyval,"\\enotes"); strcat(yyval,alaligne);
                              strcat(yyval,suspmorceau);
                              free(yyvsp[-2]); free(yyvsp[-1]);
                             ;
    break;}
case 41:
#line 287 "grammar.y"
{yyval = strcat(yyvsp[-2],yyvsp[-1]);
                         strcat(yyval,"\\enotes"); strcat(yyval,alaligne);
                         strcat(yyval,suspmorceau);
                         free(yyvsp[-1]);
                        ;
    break;}
case 42:
#line 294 "grammar.y"
{yyval = yyvsp[-1]; strcat(strcat(yyval,"\\enotes"),yyvsp[0]); free(yyvsp[0]);
                 ;
    break;}
case 43:
#line 296 "grammar.y"
{yyval = inserttie(yyvsp[-2],yyvsp[-1]);
                     strcat(strcat(yyval,"\\enotes"),yyvsp[0]);
                     tiepend=1; free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                    ;
    break;}
case 44:
#line 300 "grammar.y"
{yyval = inserttie(yyvsp[-1],yyvsp[0]);
                     strcat(strcat(yyval,"\\enotes"),xbarre);
                     tiepend=1; free(yyvsp[-1]); free(yyvsp[0]);
                    ;
    break;}
case 45:
#line 304 "grammar.y"
{yyval = inserttie(yyvsp[-1],yyvsp[0]);
                     strcat(strcat(yyval,"\\enotes"),setdoublebar);
                     strcat(yyval,xbarre);
                     tiepend=1; free(yyvsp[-1]); free(yyvsp[0]);
                    ;
    break;}
case 46:
#line 309 "grammar.y"
{yyval = inserttie(yyvsp[-1],yyvsp[0]);
                     strcat(strcat(yyval,"\\enotes"),leftrepeatsymbol);
                     tiepend=1; free(yyvsp[-1]); free(yyvsp[0]);
                    ;
    break;}
case 47:
#line 313 "grammar.y"
{yyval = yyvsp[-2]; strcat(strcat(yyval,"\\enotes"),yyvsp[0]); free(yyvsp[0]);
                     ;
    break;}
case 48:
#line 315 "grammar.y"
{yyval = inserttie(yyvsp[-2],yyvsp[-1]);
                         strcat(strcat(yyval,"\\enotes"),yyvsp[0]);
                         tiepend=1; free(yyvsp[-2]); free(yyvsp[-1]);
                        ;
    break;}
case 49:
#line 319 "grammar.y"
{yyval = strcat(insertetn(yyvsp[-2]),yyvsp[0]); free(yyvsp[0]);
                      ;
    break;}
case 50:
#line 321 "grammar.y"
{yyval = inserttie(yyvsp[-2],yyvsp[-1]);
                          strcat(strcat(insertetn(yyval),"\\tten0"),yyvsp[0]);
                          free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                         ;
    break;}
case 51:
#line 325 "grammar.y"
{yyval = strcat(yyvsp[-3],yyvsp[-2]); strcat (yyval,yyvsp[-1]);
                             strcat(yyval,"\\enotes"); strcat(yyval,yyvsp[0]);
                             free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                           ;
    break;}
case 52:
#line 329 "grammar.y"
{yyval = strcat(yyvsp[-2],yyvsp[-1]);
                             strcat(yyval,"\\enotes"); strcat(yyval,yyvsp[0]);
                             free(yyvsp[-1]); free(yyvsp[0]);
                     ;
    break;}
case 53:
#line 336 "grammar.y"
{ yyval=yyvsp[0]; ;
    break;}
case 54:
#line 337 "grammar.y"
{ yyval = strcat(yyvsp[-1],yyvsp[0]); free(yyvsp[0]); ;
    break;}
case 55:
#line 338 "grammar.y"
{ yyval=inserttie(yyvsp[-2],yyvsp[-1]); strcat(yyval,"\\tten0");
                           strcat(yyval,yyvsp[0]); free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
                         ;
    break;}
case 56:
#line 343 "grammar.y"
{ yyval=yyvsp[0]; ;
    break;}
case 57:
#line 344 "grammar.y"
{ yyval=yyvsp[0]; ;
    break;}
case 58:
#line 345 "grammar.y"
{ yyval=yyvsp[0]; ;
    break;}
case 59:
#line 346 "grammar.y"
{ yyval = insertetn(strcat(yyvsp[-2],yyvsp[-1])); free(yyvsp[-1]); ;
    break;}
case 60:
#line 347 "grammar.y"
{ yyval = strcat(yyvsp[-1],yyvsp[0]); free(yyvsp[0]); ;
    break;}
case 61:
#line 348 "grammar.y"
{ yyval = strcat(strcat(yyvsp[-2],yyvsp[-1]),yyvsp[0]); free(yyvsp[-1]); free(yyvsp[0]); ;
    break;}
case 62:
#line 351 "grammar.y"
{ yyval =  malloc(MAXLEN); strcpy(yyval,"\\");
                              strcat(strcat(strcat(yyval,yyvsp[-1]),"pp "),yyvsp[-2]);
                       ;
    break;}
case 63:
#line 354 "grammar.y"
{ yyval =  malloc(MAXLEN); strcpy(yyval,"\\");
                              strcat(strcat(strcat(yyval,yyvsp[-1]),"p "),yyvsp[-2]);
                      ;
    break;}
case 64:
#line 357 "grammar.y"
{ yyval =  malloc(MAXLEN); strcpy(yyval,"\\");
                          strcat(strcat(yyval,yyvsp[0]),yyvsp[-1]);
                  ;
    break;}
case 65:
#line 360 "grammar.y"
{ yyval=insertthtrip(yyvsp[-1],yyvsp[0]); free(yyvsp[-1]);
                     ;
    break;}
case 66:
#line 362 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,yyvsp[0]);
                            strcat(yyval,yyvsp[-1]); free(yyvsp[-1]);
                     ;
    break;}
case 67:
#line 367 "grammar.y"
{ yyval =  malloc(MAXLEN); strcpy(yyval,"\\b");
         strcat(strcat(strcat(strcat(strcat(yyval,yyvsp[-1])," bb3"),"\\b"),yyvsp[-3]),"pp");
                            ;
    break;}
case 68:
#line 370 "grammar.y"
{ yyval =  malloc(MAXLEN); strcpy(yyval,"\\b");
         strcat(strcat(strcat(strcat(strcat(yyval,yyvsp[-1])," bb3"),"\\b"),yyvsp[-3]),"p");
                            ;
    break;}
case 69:
#line 373 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,"\\b");
         strcat(strcat(strcat(strcat(yyval,yyvsp[0])," bb3"),"\\b"),yyvsp[-2]);
                            ;
    break;}
case 70:
#line 376 "grammar.y"
{ yyval = yyvsp[-4];
            strcat(strcat(strcat(insert(yyval,yyvsp[-1]),"\\b"),yyvsp[-3]),"pp");
            lbhead = strchr(yyval,' ')-yyval;
            if( lbhead > 6) yyval = shorten(yyval);
                                   ;
    break;}
case 71:
#line 381 "grammar.y"
{ yyval = yyvsp[-4];
            strcat(strcat(strcat(insert(yyval,yyvsp[-1]),"\\b"),yyvsp[-3]),"p");
            lbhead = strchr(yyval,' ')-yyval;
            if( lbhead > 6) yyval = shorten(yyval);
                                   ;
    break;}
case 72:
#line 386 "grammar.y"
{ yyval = yyvsp[-3];
            strcat(strcat(insert(yyval,yyvsp[0]),"\\b"),yyvsp[-2]);
            lbhead = strchr(yyval,' ')-yyval;
            if( lbhead > 6) yyval = shorten(yyval);
                               ;
    break;}
case 73:
#line 391 "grammar.y"
{yyval = yyvsp[-5];
              strcat(strcat(strcat(inserts(yyvsp[-5],yyvsp[-1],yyvsp[-4]),"\\b"),yyvsp[-3]),"pp");
              lbhead = strchr(yyval,' ')-yyval;
              if( lbhead > 6) yyval = shorten(yyval); free(yyvsp[-4]);
                                       ;
    break;}
case 74:
#line 396 "grammar.y"
{yyval = yyvsp[-5];
              strcat(strcat(strcat(inserts(yyvsp[-5],yyvsp[-1],yyvsp[-4]),"\\b"),yyvsp[-3]),"p");
              lbhead = strchr(yyval,' ')-yyval;
              if( lbhead > 6) yyval = shorten(yyval); free(yyvsp[-4]);
                                       ;
    break;}
case 75:
#line 401 "grammar.y"
{yyval = yyvsp[-4];
              strcat(strcat(inserts(yyvsp[-4],yyvsp[0],yyvsp[-3]),"\\b"),yyvsp[-2]);
              lbhead = strchr(yyval,' ')-yyval;
              if( lbhead > 6) yyval = shorten(yyval); free(yyvsp[-3]);
                                   ;
    break;}
case 76:
#line 406 "grammar.y"
{yyval = yyvsp[-5];
              strcat(strcat(strcat(insertt(yyvsp[-5],yyvsp[-1],yyvsp[-4]),"\\b"),yyvsp[-3]),"pp");
              lbhead = strchr(yyval,' ')-yyval;
              if( lbhead > 6) yyval = shorten(yyval); free(yyvsp[-4]);
                                       ;
    break;}
case 77:
#line 411 "grammar.y"
{yyval = yyvsp[-5];
              strcat(strcat(strcat(insertt(yyvsp[-5],yyvsp[-1],yyvsp[-4]),"\\b"),yyvsp[-3]),"p");
              lbhead = strchr(yyval,' ')-yyval;
              if( lbhead > 6) yyval = shorten(yyval); free(yyvsp[-4]);
                                       ;
    break;}
case 78:
#line 416 "grammar.y"
{yyval = yyvsp[-4];
              strcat(strcat(insertt(yyvsp[-4],yyvsp[0],yyvsp[-3]),"\\b"),yyvsp[-2]);
              lbhead = strchr(yyval,' ')-yyval;
              if( lbhead > 6) yyval = shorten(yyval);free(yyvsp[-3]);
                                   ;
    break;}
case 79:
#line 511 "grammar.y"
{ yyval=inserttrip(yyvsp[-1],yyvsp[0]); free(yyvsp[-1]);
                       ;
    break;}
case 80:
#line 513 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,yyvsp[0]);
                            strcat(yyval,yyvsp[-1]); free(yyvsp[-1]);
                       ;
    break;}
case 81:
#line 517 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,yyvsp[0]); ;
    break;}
case 82:
#line 518 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,yyvsp[0]);
                                        strcat(yyval,yyvsp[-1]); free(yyvsp[-1]); ;
    break;}
case 83:
#line 520 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,"\\notes"); strcat(yyval,yyvsp[0]);
                                        strcat(strcat(yyval,"\\enotes"),yyvsp[-1]); free(yyvsp[-1]); ;
    break;}
case 84:
#line 523 "grammar.y"
{ yyval = yyvsp[0]; ;
    break;}
case 85:
#line 524 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,yyvsp[0]); ;
    break;}
case 86:
#line 525 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,yyvsp[0]); ;
    break;}
case 87:
#line 526 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,yyvsp[0]); ;
    break;}
case 88:
#line 527 "grammar.y"
{ yyval = malloc(MAXLEN);
                  if      ( yyvsp[0]==first )  strcpy(yyval,"\\Uptext{$\\vert$ 1.}");
                  else if ( yyvsp[0]==second ) strcpy(yyval,"\\Uptext{$\\vert$ 2.}");
                  else  {   nn=strlen(yyvsp[0]);
                    if(nn==1) { strcpy(yyval,"\\Uptext{repeat ");
                                strcat(yyval,yyvsp[0]); strcat(yyval,"}");
                              }
                    else      { strcpy(yyval,"\\Uptext{$\\vert$ time ");
                                strncat(yyval,yyvsp[0],1);
                                strcat(yyval," on part(s) "); strncat(yyval,yyvsp[0]+1,1);
                                for(i=3; i <= (int) nn; i++)
                                   {strcat(yyval,", and ");strncat(yyval,yyvsp[0]+i-1,1);
                                   }
                                strcat(yyval,"}");
                              }
                    free(yyvsp[0]);
                         }
                  ;
    break;}
case 89:
#line 545 "grammar.y"
{ yyval = malloc(MAXLEN);
                          strcpy(yyval,yyvsp[0]);
                   ;
    break;}
case 90:
#line 548 "grammar.y"
{ prelen=strcspn(yyvsp[0],"_");
                   strncpy(num,yyvsp[0],prelen) ; strcpy(num+prelen,"");
                   strcpy(den,yyvsp[0]+prelen+1) ;
                   yyval=malloc(MAXLEN);
                   strcat(strcat(strcat(strcat(strcpy(yyval,"\\meterfrac{"),
                                   num),"}{"),den),"}");
                         free(yyvsp[0]);
                       ;
    break;}
case 91:
#line 556 "grammar.y"
{ yyval = strcat(yyvsp[-1],yyvsp[0]);          ;
    break;}
case 92:
#line 557 "grammar.y"
{ yyval = strcat(yyvsp[-1],yyvsp[0]); free(yyvsp[0]);;
    break;}
case 93:
#line 558 "grammar.y"
{ yyval = strcat(yyvsp[-1],yyvsp[0]); free(yyvsp[0]);;
    break;}
case 94:
#line 560 "grammar.y"
{ yyval = yyvsp[0]; ;
    break;}
case 95:
#line 561 "grammar.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 96:
#line 562 "grammar.y"
{ yyval = yyvsp[0]; ;
    break;}
case 97:
#line 563 "grammar.y"
{ yyval = yyvsp[-1] ;
    break;}
case 98:
#line 564 "grammar.y"
{ yyval = yyvsp[0] ;
    break;}
case 99:
#line 566 "grammar.y"
{ yyval = (char *) malloc(MAXLEN); strcpy(yyval,yyvsp[0]); ;
    break;}
case 100:
#line 567 "grammar.y"
{ yyval = yyvsp[0]; ;
    break;}
case 101:
#line 568 "grammar.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 102:
#line 569 "grammar.y"
{ yyval = malloc(MAXLEN); strcpy(yyval,"\\notes"); strcat(yyval,yyvsp[0]);
                                        strcat(strcat(yyval,"\\enotes"),yyvsp[-1]); free(yyvsp[-1]); ;
    break;}
case 103:
#line 605 "grammar.y"
{ yyval= (char *) malloc(MAXLEN);
                 strcat(strcpy(yyval,"%"),yyvsp[0]); free(yyvsp[0]);
               ;
    break;}
case 104:
#line 608 "grammar.y"
{ yyval = yyvsp[0] ;
    break;}
case 105:
#line 609 "grammar.y"
{ yyval = (char *) malloc(MAXLEN);
               if( ntext != 4 || strlen(yyvsp[0]) > 0)
               { if (ntext == 1) {strcat(strcat(strcpy(yyval,"\\line{\\moyen "),yyvsp[0])," \\hss}\n"); free(yyvsp[0]);}
                 else {strcat(strcat(strcpy(yyval,"\\line{"),yyvsp[0])," \\hss}\n"); free(yyvsp[0]);}
               }
               else yyval=yyvsp[0];
            ;
    break;}
case 106:
#line 616 "grammar.y"
{ yyval=malloc(MAXLEN); strcat(strcat(strcpy(yyval,"\\line{"),yyvsp[0]),"}\n");
                            free(yyvsp[0]);
              ;
    break;}
case 107:
#line 619 "grammar.y"
{ yyval=malloc(MAXLEN);
           if(ntext > 4){strcat(strcat(strcpy(yyval,"\\line{"),yyvsp[0])," \\hss}\n");
                            free(yyvsp[0]);
                        }
           else if(ntext == 4){ if(strlen(yyvsp[0]) > 0)
                                     {strcpy(yyval,"\\pagenumbers\\pageno=");
                                      strcat(strcat(yyval,yyvsp[0]),"\n"); free(yyvsp[0]);
                                     }
                                else { strcpy(yyval,"%\n"); free(yyvsp[0]);
                                     }
                              }
           else               {strcat(strcat(strcpy(yyval,"%"),yyvsp[0]),"\n"); free(yyvsp[0]);
                              }
               ;
    break;}
case 108:
#line 633 "grammar.y"
{ yyval=malloc(MAXLEN);
                      if(ntext == 2)
                         {strcat(strcat(strcpy(yyval,"\\line{\\moyen "),yyvsp[-1])," \\hss}\n"); free(yyvsp[-1]);}
                      else
                         {strcat(strcat(strcpy(yyval,"\\line{"),yyvsp[-1])," \\hss}\n"); free(yyvsp[-1]);}
                      strcat(strcat(strcat(yyval,"\\line{"),yyvsp[0])," \\hss}\n"); free(yyvsp[0]);
                 ;
    break;}
case 109:
#line 641 "grammar.y"
{ yyval=malloc(MAXLEN);
                       if(ntext == 3)
                         {strcat(strcpy(yyval,"\\line{\\moyen "),yyvsp[-2]);
                         strcat(strcat(strcat(strcat(strcat
                         (yyval," \\hss\n\\rm "),yyvsp[-1])," \\hss "),yyvsp[0]),"}\n\\bigskip\n");
                         }
                       else
                         {strcat(strcat(strcpy(yyval,"\\line{"),yyvsp[-2])," \\hss}\n");
                          strcat(strcat(strcat(yyval,"\\line{"),yyvsp[-1])," \\hss}\n");
                          strcat(strcat(strcat(yyval,"\\line{"),yyvsp[0])," \\hss}\n");
                          }
                       free(yyvsp[-2]); free(yyvsp[-1]); free(yyvsp[0]);
              ;
    break;}
case 110:
#line 656 "grammar.y"
{yyval=yyvsp[0]; ntext++; ;
    break;}
case 111:
#line 659 "grammar.y"
{ yyval=yyvsp[0]; ntext++; ;
    break;}
case 112:
#line 660 "grammar.y"
{ yyval=strcat(strcat(yyvsp[-2],yyvsp[-1]),yyvsp[0]); free(yyvsp[-1]);
                                   free(yyvsp[0]); ntext=ntext+3;
                                ;
    break;}
case 113:
#line 663 "grammar.y"
{ yyval=strcat(yyvsp[-1],yyvsp[0]); free(yyvsp[0]); ntext=ntext+2;
                                ;
    break;}
case 114:
#line 665 "grammar.y"
{ yyval=strcat(yyvsp[-1],yyvsp[0]); free(yyvsp[0]); ntext=ntext+2;
                                ;
    break;}
case 115:
#line 667 "grammar.y"
{ yyval=strcat(yyvsp[-1],yyvsp[0]); free(yyvsp[0]); ntext=ntext+2;
                                ;
    break;}
case 116:
#line 669 "grammar.y"
{ yyval = yyvsp[0]; ntext++; ;
    break;}
case 117:
#line 670 "grammar.y"
{ yyval = yyvsp[0]; ntext++; ;
    break;}
case 118:
#line 671 "grammar.y"
{ yyval = yyvsp[0]; ntext++; ;
    break;}
case 119:
#line 674 "grammar.y"
{yyval=yyvsp[0]; ntext++; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/afs/slac.stanford.edu/package/gnu2/bison/1.28/i386_linux22/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 677 "grammar.y"


#include <stdio.h>

int yyerror(char *s){printf("%s\n",s); return 0;}

#ifdef MAC
#include "Main.h"
#endif

int main (int argc, char **argv)

{
    int retcode;
    char *infile;
    char *outfile;
    int inopened=0;
    int outopened=0;

       firstline=1; ntext=0; tiepend=0; tiearmed=0;

    if (argc > 1)   /* if a file was named, open it for reading*/
    {
        if(! strncmp(argv[1],"help",4))
        {
            printf("%s","bmw2tex [input [output]]\n"
                "The extension .bww will be added to the input"
                " file name if .bmw or .bww is not already present\n"
                "The extension .tex will be added to the output"
                " file name if not already present\n"
                "If an output file name is not given,"
                " the input file name with .bww or .bmw replaced\n by"
                " .tex will be used.\n"
                "If no file names are given, stdin and stdout"
                " will be used.\n");
            exit(0);
              }

              infile=(char *) malloc(129); strcpy(infile,argv[1]);
              if(!(strstr(infile,".bmw") || strstr(infile,".bww")) ) strcat(infile,".bww");

        if (freopen (infile, "r", stdin) == (FILE *) NULL)
        {
            fprintf (stderr, "cannot open %s\n", infile);
            return 1;   /* terminate abnormally */
        }
              else inopened=1;
        fprintf (stderr, "processing %s...\n", infile);

        if(argc > 2) /* if a second file was named, open it for writing*/
        {
                outfile= (char *) malloc(129); strcpy(outfile,argv[2]);
                if(strcmp(outfile+strlen(outfile)-4,".tex"))
                strcat(outfile,".tex");
        }
        else
        {
                outfile= (char *) malloc(129); strcpy(outfile,"");
            strncat(outfile,infile,strlen(infile)-4);
            strcat(outfile,".tex");
        }

        if (freopen (outfile, "w", stdout) == (FILE *) NULL)
        {
            fprintf (stderr, "cannot open %s\n", outfile);
            return 1;   /* terminate abnormally */
        }
              else outopened=1;
        fprintf (stderr, "writing %s...\n", outfile);
              free(infile); free(outfile);
    }

/* standard initial text output */
printf("%s\n","%&bagpipe\n\\input bagpipe\n%");
printf("%s\n","% Converted from bmw or bww format by bww2tex version 2.00\n%");
printf("%s\n","\\def\\freqbarno{9999}");
printf("%s\n","\\maxlinesinpage=12\n%");
printf("%s\n","\\ifx\\medleyflag\\relax\\else\n"
                "  \\nopagenumbers\\pageno=1\\medtall\\medwidewidth\\fi");
printf("%s\n","\\newpitch\\newgrace\\noautoglue\n%");
printf("%s\n","\\musicsize 16\\relax");

yydebug=0; /* set to 1 to turn on parsing trace */

retcode = yyparse();

/* standard ending text */
printf("%s\n","\\byemedley");
printf("%s\n","\\bye");

if (inopened ) fclose(stdin );
if (outopened) fclose(stdout);

return retcode;

}

char *insert(char *aptr, char *bptr)
/* add a note to a beamed note group head structure */
  {
   char *rptr;
   char rchr[MAXLEN];
   size_t len;

   rptr=rchr;
   len=strcspn(aptr," ");
   strncpy(rptr,aptr,len);
   strcpy(rptr+len,bptr);
   strcat(rptr,aptr+len);
   strcpy(aptr,rptr);
   return aptr;
  }

char *inserts(char *aptr, char *bptr, char *cptr)
/* add an embellishment to a beamed note group
   plus a note to its head structure  */
  {
   char *rptr;
   char rchr[MAXLEN];
   char *sptr;
   char schr[MAXLEN];
   char *dptr;
   size_t lena,lenr,lend;

   rptr=rchr;
   sptr=schr;
   lena=strcspn(aptr," ");
   strncpy(rptr,aptr,lena);
   strcpy(rptr+lena,bptr);
   strcat(rptr,aptr+lena);
   dptr=strrchr(rptr,'\\');
   lenr=strlen(rptr);
   lend=strlen(dptr);
   strncpy(sptr,rptr,lenr-lend);
   strcat(strcat(strcat(strcpy(sptr+lenr-lend,"{"),dptr),cptr),"}");
   strcpy(aptr,sptr);
   return aptr;
  }


char *insertt(char *aptr, char *bptr, char *cptr)
/* add a tie to a beamed note group plus a note to its head structure */
  {
   char *rptr;
   char rchr[MAXLEN];
   char *sptr;
   char schr[MAXLEN];
   char *dptr;
   size_t lena,lenr,lend;

   rptr=rchr;
   sptr=schr;
   lena=strcspn(aptr," ");
   strncpy(rptr,aptr,lena);
   strcpy(rptr+lena,bptr);
   strcat(rptr,aptr+lena);
   dptr=strrchr(rptr,'\\');
   lenr=strlen(rptr);
   lend=strlen(dptr);
   strncpy(sptr,rptr,lenr-lend);
   strcat(strcat(strcpy(sptr+lenr-lend,"{"),cptr),dptr);
   if (*(sptr+strlen(sptr)-1) == 'p') strcat(sptr+lenr-lend,"\\tten0}");
   else                               strcat(sptr+lenr-lend,"\\qsk\\tten0}");
   strcpy(aptr,sptr);
   return aptr;
  }

char *inserttie(char *aptr, char* bptr)
/* add a tie between notes */
  {
   char *retptr; char* tieptr; char *rptr;
   char rchr[MAXLEN];
   int lena, lenh, lent;

   rptr=rchr;
   retptr = (char *) malloc(MAXLEN); strcpy(retptr,"");
   tieptr=strrchr(aptr,'\\');
   lena=strlen(aptr); lent=strlen(tieptr); lenh=lena-lent;
   strncat(retptr,aptr,lenh);
   if( *(tieptr+1) != 'b' )
      {
       strcat(retptr,bptr);
       strcat(retptr,aptr+lenh);
       if(*(aptr+lena-1) != 'p') strcat(retptr,"\\qsk");
      }
   else
      {
       strcat(retptr,"{");
       strcat(retptr,bptr); strcat(retptr,aptr+lenh);
       if( *(aptr+lena) != 'p' ) strcat(retptr,"\\qsk}");
       else                      strcat(retptr,"}");
      }
   return retptr;
  }

char *inserttrip( char *aptr, char* bptr)
/* insert a triplet instruction in a beamed group */
  {
   char *retptr;
   char *rptr;
   char rchr[MAXLEN];
   char *sptr;
   char schr[MAXLEN];
   char *cptr; char *dptr; char *eptr;
   char search;
   size_t lta, lha, ltr, lhr, lts, lhs;

   rptr=rchr; strcpy(rptr,"");
   sptr=schr; strcpy(sptr,"");

   retptr= (char *) malloc(MAXLEN); strcpy(retptr,"");
   cptr=strrchr(aptr,'\\'); lta=strlen(cptr); lha=strlen(aptr)-lta;
   strncat(rptr,aptr,lha);

   if(*(cptr-1)=='}')search='{';
   else search='\\';
   dptr=strrchr(rptr,search); ltr=strlen(dptr); lhr=strlen(rptr)-ltr;
   strncat(sptr,rptr,lhr);

   eptr=strrchr(sptr,'\\'); lts=strlen(eptr); lhs=strlen(sptr)-lts;
   strncat(retptr,sptr,lhs);
   if(*(eptr-1)=='{'){ strcat(retptr,bptr); strcat(retptr,eptr);
                     }
   else              { strcat(retptr,"{"); strcat(retptr,bptr);
                       strcat(strcat(retptr,eptr),"}");
                     }
   strcat(retptr,dptr); strcat(retptr,cptr);

   return retptr;
  }

char *insertthtrip( char *aptr, char* bptr)
/* insert a triplet instruction between notes */
  {
   char *retptr;
   char *cptr;
   size_t lta, lha;

   retptr= (char *) malloc(MAXLEN); strcpy(retptr,"");
   cptr=strrchr(aptr,'\\'); lta=strlen(cptr); lha=strlen(aptr)-lta;
   strncat(retptr,aptr,lha); strcat(retptr,bptr); strcat(retptr,cptr);

   return retptr;
  }

char *insertetn(char *aptr)
/* add some glue  (\etn) between beats */
  { /* char *tieptr; */
    /* tieptr=strrchr(aptr,'\\'); */
    /* if( *(tieptr+1) != 'b' ) */
   strcat(aptr,"\\etn");
   strcat(aptr,"\n");
   return aptr;
  }

char *shorten( char *aptr )
/* try to compress a beamed note group to a beam structure with
   four elements */
  {
    char *sptr; char *bptr; char *cptr; char *retptr;
    int lena, lens, lsh, lbh, i, j;

    lena=strlen(aptr);
    sptr = strchr(aptr, ' ');
    lens=strlen(sptr);
    lsh=lena-lens;
    for ( i=2; i<lsh-2; i++)
      {
         if ( *(aptr+i) == *(aptr+i+1) )
            {
             retptr= (char *) malloc(MAXLEN); strcpy(retptr,"");
             bptr=aptr+i+1;
             lbh = lena-strlen(bptr);
             strncat(retptr,aptr,lbh-1); strncat(retptr,bptr,lsh-lbh+4);
             bptr=sptr+4; cptr=bptr;
             for ( j = 2; j < i; j++)
                {
                 if ( *bptr=='{' ) bptr=strchr(bptr,'}')+1;
                 else
                    {
                     bptr=bptr+3;
                     if( *(bptr) == 'p' ) bptr++ ;
                    }
                }
             lbh=strlen(cptr)-strlen(bptr);
             if (lbh) strncat(retptr,cptr,lbh);
             cptr=bptr;
             if( *bptr=='{' )
                {
                 bptr=strchr(bptr+1,'}');
                 lbh=strlen(cptr)-strlen(bptr);
                 strncat(retptr,cptr,lbh);
                 if( *(bptr+1)=='{' ) strcat(retptr,bptr+2);
                 else
                    {
                     strncat(retptr,bptr+1,3); bptr=bptr+4;
                     if(*bptr=='p')
                        {
                         strncat(retptr,bptr,1); bptr++;
                        }
                      strcat(retptr,"}"); strcat(retptr,bptr);
                     }
                }
             else
                {
                 strcat(retptr,"{");
                 strncat(retptr,bptr,3);
                 bptr=bptr+3;
                 if( *(bptr)=='p' ) { strncat(retptr,bptr,1); bptr++; }
                 if( *bptr != '{')
                    {
                      strncat(retptr,bptr,3); bptr=bptr+3;
                      if( *bptr=='p' ){ strncat(retptr,bptr,1); bptr++ ; }
                      strcat(retptr,"}"); strcat(retptr,bptr);
                    }
                 else strcat(retptr,bptr+1);
                }
             free(aptr);
             return retptr;
            }
        }
    printf("%% can't shorten long beam macro, output file will not TeX ");
    return aptr;
  }
