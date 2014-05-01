/* Michael Walton
 * mwwalton@ucsc.edu
 * insertionSort.c
 * insertionSort implementation
 */
#include "insertionSort.h"

void insertionSort(int keys[], int numKeys) {
    int cursor;
    int i;

    for (i = 1; i < numKeys; ++i) {
        cursor = i;

        while ( cursor > 0 && keys[cursor] < keys[cursor - 1] ) {
            swap(&keys[cursor], &keys[cursor - 1]);
            cursor--;
        }
    }
    return;
}
