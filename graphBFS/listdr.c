/*
 * listdr.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#include "list.h"

int main() {
    ListHndl intList;
    intList = newList();

    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
/*
 * Integer list testing
 *
 */

    printHeading(" INTEGER LIST ", '#', 80);
    printList(stdout, intList);
    accessorTest("isEmpty", 1, isEmpty(intList));
    
    for(int i = 0; i < 10; i++) {
        insertAtFront(intList, data[i]);
        mutatorTest("%s : data = %d", "insertAtFront", data[i]);
    }

    moveFirst(intList);

    for(int i = 0; i < 5; i++) {
        printList(stdout, intList);
        insertBeforeCurrent(intList, data[i]);
        mutatorTest("insertBeforeCurrent : data = %d", data[i]);
        moveNext(intList);
    }

    accessorTest("isEmpty", 0, isEmpty(intList));
    printList(stdout, intList);

    moveFirst(intList);
    while( !offEnd(intList) ) {
        printList(stdout, intList);
        moveNext(intList);
    }

    moveLast(intList);
    while( !offEnd(intList) ) {
        printList(stdout, intList);
        movePrev(intList);
    }

    makeEmpty(intList);
    mutatorTest("makeEmpty( intList)");

    printList(stdout, intList);
    accessorTest("isEmpty", 1, isEmpty(intList));

    freeList(intList);
    return 0;
}
