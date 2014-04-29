/* Michael Walton
 * mwwalton@ucsc.edu
 * heapDriver.c
 * Heap ADT testing program
 */

#include "heap.h"
#include "util.h"

int main() {
    heapHndl testHeap;
    int i;
    int heapSize;

    int testSet[] = {18, 69, 37, 6, 9, 80, 90, 95, 74, 29};
    
    /*
    int testSetErr[] = {18, 12, 37, 6, 9, 7, 90, 95, 15, 29};
    int testSet100[] = {32, 74, 98, 7, 16, 85, 35, 38, 66, 77, 14, 10, 95, 92, 62, 36, 26, 90, 
    44, 61, 88, 60, 8, 53, 51, 70, 65, 86, 54, 13, 6, 91, 78, 17, 56, 12, 93, 23, 73, 68, 39, 
    5, 22, 18, 9, 71, 79, 50, 100, 76, 45, 41, 97, 67, 80, 3, 59, 37, 46, 87, 11, 64, 4, 40, 55, 
    83, 1, 34, 19, 25, 30, 72, 75, 82, 27, 96, 49, 33, 15, 42, 21, 48, 99, 57, 43, 81, 89, 24, 52, 
    29, 94, 63, 28, 31, 58, 20, 47, 2, 69, 84};
    */

    heapSize = 10;
    testHeap = newHeap(heapSize);

    accessorTest("isEmpty", 1, isEmpty( testHeap ));

    for (i = 0; i < heapSize; ++i) {
        mutatorTest("%s : priority = %d", "insert", testSet[i]);
        insert( testHeap, testSet[i] );
    }

    accessorTest("isFull", 1, isFull( testHeap ));

    arrayTest(testSet, getHeap( testHeap ), heapSize, 1, "heap", "testSet");
    
    printf("[HEAP] : ");
    printHeap(stdout, testHeap);

    freeHeap( &testHeap );

    return 0;
}
