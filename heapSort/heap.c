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

/* HEAP MAINTENANCE FUNCTIONS */
void siftUp( int *A, int i);

/* CONSTRUCTORS & DESTRUCTORS */
heapHndl newHeap(int maxSize) {
   heapHndl tmpHeap;
   tmpHeap = malloc(sizeof(HeapStruct));
   
   /*to maintain the heap property, we want
    * to start our heaps at i = 1, so
    * we need to alloc one more element than
    * the max size.  Hence:
    */

   tmpHeap -> size = 0;
   tmpHeap -> maxSize = maxSize;
   tmpHeap -> heap = calloc(maxSize, sizeof(int));

   return( tmpHeap );
}

heapHndl buildHeap (int maxSize, int data[], int numData) {
    heapHndl tmpHeap;
    int i;
    tmpHeap = newHeap( maxSize );

    for (i = 0; i < numData; ++i) {
        insert(tmpHeap, data[i]);
    }
    

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

int maxValue(heapHndl H) {
    assert( !isEmpty(H) );
    return ( H -> heap[0] );
}

/* MANIPULATION PROCEDURES */
void insert(heapHndl H, int priority) {
    assert( !isFull(H) );
    H -> size++;
    H -> heap[ H -> size - 1 ] = priority;
    siftUp(H -> heap, H -> size -1);
}

void deleteMax(heapHndl H) {
    int last;

    assert( !isEmpty(H) );

    last = H -> heap[H -> size -1];

    H -> heap[0] = last;
    H -> size = H -> size -1;
    printf(" [ %d ] ", H -> size);

    heapify(H, 0);
}

void decSize(heapHndl H) {
    H -> size = H -> size -1;
}

/* HEAP MAINTENANCE FUNCTIONS */
void siftUp( int *A, int i) {
    int parent;
    
    if (i == 0) { return; }

    parent = parent(i);
    if (A[parent] < A[i]) {
        swap(&A[parent], &A[i]);
        siftUp(A, parent);
    }
}

void heapify( heapHndl H, int i ) {
    int heapSize;
    int left;
    int right;
    int *A;
    int largest;

    heapSize = H -> size;
    A = H -> heap;

    left = left(i);
    right = right(i);

    if (left < heapSize && A[left] > A[i]) {
        largest = left;
    } else {
        largest = i;
    }

    if (right < heapSize && A[right] > A[largest]) {
        largest = right;
    }

    if ( largest != i) {
        swap( &A[i], &A[largest] );
        heapify( H, largest );
    }
}

/* UTILITY FUNCTIONS */
void printHeap(FILE* out, heapHndl H) {
    int i;
    if ( isEmpty(H) ) { fprintf(out, "HEAP IS EMPTY"); }
    else {
        for (i = 0; i < H -> size; ++i) {
            fprintf( out, "%d ", H -> heap[i]);
        }
    }
    fprintf(out, "\n");
}

void printRaw(int a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
