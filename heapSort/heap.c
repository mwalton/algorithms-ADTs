/* Michael Walton
 * mwwalton@ucsc.edu
 * heap.c
 * Heap ADT implementation
 */

#include "heap.h"
#include <assert.h>

typedef struct HeapStruct {
  int maxSize;
  int size;
  int *heap;
} HeapStruct;


/* CONSTRUCTORS & DESTRUCTORS */
heapHndl newHeap(int maxSize) {
   heapHndl tmpHeap;
   int heapSize;
   tmpHeap = malloc(sizeof(HeapStruct));
   
   /*to maintain the heap property, we want
    * to start our heaps at i = 1, so
    * we need to alloc one more element than
    * the max size.  Hence:
    */
   heapSize = maxSize + 1;

   tmpHeap -> size = 0;
   tmpHeap -> maxSize = maxSize;
   tmpHeap -> heap = calloc(heapSize, sizeof(int));

   return( tmpHeap );
}

heapHndl buildHeap (int maxSize, int *data, int numData) {
    heapHndl tmpHeap;
    tmpHeap = malloc(sizeof(HeapStruct));

    tmpHeap -> size = numData;
    tmpHeap -> maxSize = maxSize;
    tmpHeap -> heap = data;
    return( tmpHeap );
}


void freeHeap(heapHndl *H) {
    assert( (*H) != NULL);
    free ((*H) -> heap);
    free(*H);
    H = NULL;
}

/* ACCESS FUNCTIONS */
bool isFull(heapHndl H) {
    return (H -> size == H -> maxSize);
}

bool isEmpty(heapHndl H) {
    return (H -> size == 0);
}

int *getHeap(heapHndl H) {
    return (H -> heap);
}

/* MANIPULATION PROCEDURES */
void insert(heapHndl H, int priority) {
    H -> heap[ H -> size + 1 ] = priority;
    H -> size++;
}

/* UTILITY FUNCTIONS */
void printHeap(FILE* out, heapHndl H) {
    int i;
    if ( isEmpty(H) ) { fprintf(out, "HEAP IS EMPTY"); }
    else {
        for (i = 1; i <= H -> size; ++i) {
            fprintf( out, "%d ", H -> heap[i]);
        }
    }
    fprintf(out, "\n");
}
