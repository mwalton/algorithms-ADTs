/*
 * bookdr.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#include "list.h"
#include "book.h"
#include <time.h>

int main() {
    BookHndl odyssey;
    BookHndl geb;
    BookHndl brosKaramazov;

    srand(time(0));

    int randints[] = {0,0,0,0,0};

    odyssey = newBook();
    geb = newBook();
    brosKaramazov = newBook();

    printHeading(" GENERATE 3 BOOKS ", '#', 80);
    
    setTitle(odyssey, "Homer's The Odyssey");
    mutatorTest("%s : %s", "setTitle", "Homer's The Odyssey");

    for (int i = 0; i < 5; i++) {
        randints[i] = rand() % 1000;
        insertAtFront( getLibraryList( odyssey ), &randints[i]);
    }

    setTitle(geb, "Godel Escher Bach");
    mutatorTest("%s : %s", "setTitle", "Godel Escher Bach");

    for (int i = 0; i < 5; i++) {
        randints[i] = rand() % 1000;
        insertAtFront( getLibraryList( geb ), &randints[i]);
    }

    setTitle(brosKaramazov, "The Brothers Karamazov");
    mutatorTest("%s : %s", "setTitle", "The Brothers Karamazov");

    for (int i = 0; i < 5; i++) {
        randints[i] = rand() % 1000;
        insertAtFront( getLibraryList( brosKaramazov ), &randints[i]);
    }


    ListHndl bookList;
    bookList = newList();

    insertAtFront( bookList, odyssey );
    insertAtFront( bookList, geb );
    insertAtFront( bookList, brosKaramazov );

    printHeading(" PRINT BOOKS IN BOOK LIST ", '#', 80);
    moveFirst( bookList );
    while ( !offEnd( bookList )) {
        printBookInfo(stdout, getCurrent ( bookList ));
        printf("\n");
        freeBook( getCurrent( bookList ));
        moveNext( bookList );
    }

    freeList( bookList );

    return 0;
}
