/* Michael Walton
 * mwwalton@ucsc.edu
 * heapDriver.c
 * Heap ADT testing program
 */

#include "heap.h"
#include "util.h"

int main() {
    heapHndl testHeap;
    heapHndl testHeap_build;
    int i;
    int heapSize;

    int testSet[] = {18, 69, 37, 6, 9, 80, 90, 95, 74, 29};
    int sifted[] = {95, 90, 80, 74, 29, 37, 69, 6, 18, 9};
    
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
    testHeap_build = newHeap(heapSize);

    /* INIT STATE CHECK */
    printHeading(" VERIFY INITIAL STATE ", '-', 75);
    accessorTest("isEmpty", 1, isEmpty( testHeap ));

    /* MUTATOR CHECK */
    printHeading(" INSERT HEAP KEYS ", '-', 75);
    for (i = 0; i < heapSize; ++i) {
        mutatorTest("%s : priority = %d", "insert", testSet[i]);
        insert( testHeap, testSet[i] );
    }

    /* POST CONDITION CHECK */
    printHeading(" VALIDATE HEAP ", '-', 75);
    accessorTest("isFull", 1, isFull( testHeap ));
    arrayTest( sifted, getHeap( testHeap ), heapSize, "sifted", "testHeap", 75 );
    
    printHeading(" UTILITY FUNCTIONS ", '-', 75);
    
    /* Test bitwise macros for heap -> array mapping */
    accessorTest("parent", 2, parent(5));
    accessorTest("parent", 5, parent(12));
    accessorTest("left", 25, left(12));
    accessorTest("right", 52, right(25));
    
    /* PRINT HEAP */
    printf("[HEAP] : ");
    printHeap(stdout, testHeap);

    freeHeap( &testHeap );

    /* TEST BUILDHEAP  */
    printHeading(" VALIDATE BUILD HEAP ", '-', 75);
    testHeap_build = buildHeap(heapSize, testSet, heapSize);
    arrayTest(sifted, getHeap( testHeap_build ), heapSize, "sifted", "buildHeap", 75);
    printHeap(stdout, testHeap_build);
    
    /* VERIFY MAX & DELMAX */
    printHeading(" VALIDATE maxValue & deleteMax ", '-', 75);
    accessorTest("max", 95, maxValue(testHeap_build));

    for (i = 0; i < heapSize; ++i) {
        deleteMax(testHeap_build);
        printHeap(stdout, testHeap_build);
    }

    for (i = 0; i < heapSize; ++i) {
        mutatorTest("%s : priority = %d", "insert", testSet[i]);
        insert( testHeap, testSet[i] );
    }
    
    freeHeap( &testHeap_build );


    return 0;
}
