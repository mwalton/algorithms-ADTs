/*
 * util.h
 *
 *		Michael Walton
 * 		mwwalton@ucsc.edu
 *
 */

#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>   /* this includes malloc, free, rand, etc. */
#include <stdarg.h>

#define EQ ==
#define NEQ !=
#define LEQ <=
#define GEQ >=
/* I try to use these in boolean expressions.  One of the problems with C */
/* is that "(x = y)" when you mean "(x == y)" is almost always is true    */
/* AND also assigns the value of y to x.  Since this is almost impossible */
/* to debug, I try to use the above abbreviations for comparison operators. */

#define AND &&
#define OR ||

#define streq(s, t) (! strcmp(s, t))
#define strneq(s, t) (strcmp(s, t))

typedef int bool;
#define true 1
#define false 0
/* these three things give me a "poor man's" boolean type */
/* with constants TRUE and FALSE */
typedef char *  String;
typedef FILE *  FilePtr;
/* these are two other commonly used types. */

//Define type values to emulate typesafe void*
#define TYP_INT 0
#define TYP_CHAR 1
#define TYP_DBL 2
#define TYP_STR 3

/* define some colors so we can make pretty output */
#define KNRM  "\x1B[0m"  /* normal */
#define KRED  "\x1B[31m" /* red */
#define KGRN  "\x1B[32m" /* green */
#define KYEL  "\x1B[33m" /* yellow */
#define KBLU  "\x1B[34m" /* blue */
#define KMAG  "\x1B[35m" /* magenta */
#define KCYN  "\x1B[36m" /* cyan */
#define KWHT  "\x1B[37m" /* white */

/* functs for  driver testing and printing results */
void accessorTest(String fname, int expected, int actual);
void mutatorTest(String format, ... );
void arrayTest(int *a, int *b, int size, String labelA, String labelB, int lnW);
void printHeading(String h, char pad, int width);

#endif

