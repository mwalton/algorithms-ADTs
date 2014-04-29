
/* Michael Walton
 * mwwalton@ucsc.edu
 * heap.h
 * Header for heap ADT
 */

#include <stddef.h>
#include <strings.h>
#include "util.h"

typedef struct HeapStruct* heapHndl;

/** CONSTRUCTORS & DESTRUCTORS **/
heapHndl newHeap(int maxSize);
heapHndl buildHeap (int maxSize, int *data, int numData);
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

/* UTILITY FUNCTION PROTOTYPES */
void printHeap(FILE* out, heapHndl H);
