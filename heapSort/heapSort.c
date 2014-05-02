/* Michael Walton
 * mwwalton@ucsc.edu
 * heapSort.c
 * heapSort implementation
 */
#include "heapSort.h"
#include "heap.h"

void heapSort(int keys[], int numKeys) {
    heapHndl heap;
    int i;
    int *A0;
    int *Ai;

    heap = buildHeap(numKeys, keys, numKeys);

    for (i = numKeys - 1; i > 0; --i) {
        A0 = &getHeap( heap ) [0];
        Ai = &getHeap( heap ) [i];

        swap(A0, Ai);
        decSize( heap );
        heapify( heap, 0);
        keys[i] = *Ai;
        keys[0] = *A0;
    }

    freeHeap( &heap );
}
