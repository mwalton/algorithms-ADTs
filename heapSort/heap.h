
/* Michael Walton
 * mwwalton@ucsc.edu
 * heap.h
 * Header for heap ADT
 */

#include <stddef.h>
#include <strings.h>
#include "util.h"

/* Define some useful macros for mapping the heap ADT
 * onto the array
 */

#define parent(i) ((i - 1) >> 1)
#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)

typedef struct HeapStruct* heapHndl;

/** CONSTRUCTORS & DESTRUCTORS **/
heapHndl newHeap(int maxSize);
heapHndl buildHeap (int maxSize, int data[], int numData);
void freeHeap(heapHndl *H);  /* H has been alloc'd w/ newHeap */

/*
 * All access & manipulation fnctns assume
 * H has been init w/ newHeap
 */

/** ACCESS FUNCTIONS **/
bool isFull(heapHndl H);

bool isEmpty(heapHndl H);

int maxValue(heapHndl H); /* assert !isEmpty */

int *getHeap(heapHndl H);

/** MANIPULATION PROCEDURES **/
void deleteMax(heapHndl H); /* assert !isEmpty */

void insert(heapHndl H, int priority);

void decSize(heapHndl H);

/* UTILITY FUNCTION PROTOTYPES */
void heapify( heapHndl H, int i);
void printHeap(FILE* out, heapHndl H);
void printRaw(int a[], int size);
