/*
 * book.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 *
 */

#include "list.h"
#include "book.h"
#include <assert.h>

typedef struct BookStruct {
    String title;
    ListHndl libraryList;
} BookStruct;

/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 */
BookHndl newBook() {
    BookHndl tmpBook;
    tmpBook = malloc ( sizeof(BookStruct) );
    
    tmpBook -> libraryList = newList();
    tmpBook -> title = NULL;

    return tmpBook;
}
    
void freeBook(BookHndl B) {
    freeList( B -> libraryList);
    free( B );
}


/* 
 * ACCESS FUNCTIONS 
 * NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that B has been initialized by newBook().
 *
 */
ListHndl getLibraryList(BookHndl B) {
    return B -> libraryList;
}

String getTitle(BookHndl B) {
    return B -> title;
}

/*
 * Manipulation procedures 
 *
 */
void setTitle(BookHndl B, String title) {
    B -> title = title;
}

void printBookInfo(FILE* out, BookHndl B) {
    fprintf(out, "%s:\n", B -> title);
    printList(out, B -> libraryList, TYP_INT); 
}
