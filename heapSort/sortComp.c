/* Michael Walton
 * mwwalton@ucsc.edu
 * sortComp.c
 * HeapSort & insertionSort testing program
 */

#include "heap.h"
#include "util.h"
#include "insertionSort.h"
#include "heapSort.h"
#include <time.h>

int main(int argc, char **argv) {
    FILE *fp;
    char str[60];

    int numCount;
    int *inssArr;
    int *heapArr;
    int i;

    clock_t startTime, insDuration, heapDuration;
    
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

    startTime = clock();
    insertionSort(inssArr, numCount);
    insDuration = clock() - startTime;

    startTime = clock();
    heapSort(heapArr, numCount);
    heapDuration = clock() - startTime;

    printHeading("SORTING RUNTIMES IN SECONDS", '-', 75);
    printf("Data set file: %s\n", argv[1]);
    printf("Size of set: %d\n\n", numCount);
    printf("Insertion Sort: %f\n", ((float) insDuration) / CLOCKS_PER_SEC);
    printf("Heap Sort: %f\n", ((float) heapDuration) / CLOCKS_PER_SEC);

    free(inssArr);
    free(heapArr);

    return (0);
}
