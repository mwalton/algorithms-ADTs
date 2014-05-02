/* Michael Walton
 * mwwalton@ucsc.edu
 * sortPrint.c
 * HeapSort & insertionSort testing program
 */

#include "heap.h"
#include "util.h"
#include "insertionSort.h"
#include "heapSort.h"

int main(int argc, char **argv) {
    FILE *fp;
    char str[60];

    int numCount;
    int *inssArr;
    int *heapArr;
    int i;

    if (argc < 1) {
        printf("Please specify an input file\n");
        return (-1);
    }
    
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Could not open file");
        return (-1);
    }

    fgets(str, 60, fp);
    strtok(str, "\n");
    numCount = atoi( str );

    inssArr = calloc(numCount, sizeof(int));
    heapArr = calloc(numCount, sizeof(int));

    for ( i = 0; i < numCount; ++i ) {
        fgets (str, 60, fp);
        strtok(str, "\n");
        inssArr[i] = atoi( str );
        heapArr[i] = atoi( str );
    }

    fclose (fp);

    insertionSort(inssArr, numCount);
    heapSort(heapArr, numCount);
    
    printHeading("RESULT OF INSERTION SORT", '-', 75);

    for( i = 0; i < numCount; ++i) {
        printf("%d\n", inssArr[i]);
    }

    printHeading("RESULT OF HEAP SORT", '-', 75);

    for( i = 0; i < numCount; ++i) {
        printf("%d\n", heapArr[i]);
    }

    printHeading("SORTING VALIDATION", '-', 75);
    arrayTest(heapArr, inssArr, numCount, "heapsort", "insertion Sort", 75);
    printf("n = %d\n", numCount);

    free(inssArr);
    free(heapArr);

    return (0);
}
