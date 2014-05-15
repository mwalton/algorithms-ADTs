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

    ListHndl stringList;
    stringList = newList();

    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    String strings[] = { "Don't", "stop", "me", "now", "I'm",
                        "having", "such", "a", "good", "time",
                        "I'm", "having", "a", "ball",
                        "Don't", "stop", "me", "now",
                        "If", "you", "wanna", "have", "a",
                        "good", "time", "just", "gimme", "a",
                        "call" };

/*
 * Integer list testing
 *
 */

    printHeading(" INTEGER LIST ", '#', 80);
    printList(stdout, intList, TYP_INT);
    accessorTest("isEmpty", 1, isEmpty(intList));
    
    for(int i = 0; i < 10; i++) {
        insertAtFront(intList, &data[i]);
        mutatorTest("%s : data = %d", "insertAtFront", data[i]);
    }

    moveFirst(intList);

    for(int i = 0; i < 5; i++) {
        printList(stdout, intList, TYP_INT);
        insertBeforeCurrent(intList, &data[i]);
        mutatorTest("insertBeforeCurrent : data = %d", data[i]);
        moveNext(intList);
    }

    accessorTest("isEmpty", 0, isEmpty(intList));
    printList(stdout, intList, TYP_INT);

    moveFirst(intList);
    while( !offEnd(intList) ) {
        printList(stdout, intList, TYP_INT);
        moveNext(intList);
    }

    moveLast(intList);
    while( !offEnd(intList) ) {
        printList(stdout, intList, TYP_INT);
        movePrev(intList);
    }

    makeEmpty(intList);
    mutatorTest("makeEmpty( intList)");

    printList(stdout, intList, TYP_INT);
    accessorTest("isEmpty", 1, isEmpty(intList));

    freeList(intList);
/*
 * String list testing
 *
 */
    printHeading(" STRING LIST ", '#', 80);
    printList(stdout, stringList, TYP_STR);
    accessorTest("isEmpty", 1, isEmpty(stringList));
    
    for(int i = 0; i < 29; i++) {
        insertAtBack(stringList, strings[i]);
        mutatorTest("%s : data = %s", "insertAtBack", strings[i]);
    }

    accessorTest("isEmpty", 0, isEmpty(stringList));
    printList(stdout, stringList, TYP_STR);

    moveFirst(stringList);
    while( !offEnd(stringList) ) {
        printList(stdout, stringList, TYP_STR);
        moveNext(stringList);
    }

    moveLast(stringList);
    while( !offEnd(stringList) ) {
        printList(stdout, stringList, TYP_STR);
        movePrev(stringList);
    }

    makeEmpty(stringList);
    mutatorTest("makeEmpty( stringList)");

    printList(stdout, stringList, TYP_STR);
    accessorTest("isEmpty", 1, isEmpty(stringList));

    freeList(stringList);

    return 0;
}
