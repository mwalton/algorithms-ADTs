/*
 * book.h
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#ifndef BOOK_H
#define BOOK_H

#include "util.h"
#include "list.h"

typedef struct BookStruct*  BookHndl;

/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 */
BookHndl newBook();
void freeBook(BookHndl B); // Pre: B has been created with newBook


/* 
 * ACCESS FUNCTIONS 
 * NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that B has been initialized by newBook().
 *
 */
ListHndl getLibraryList(BookHndl B);
String getTitle(BookHndl B);
/*
 * Manipulation procedures 
 *
 */
void setTitle(BookHndl B, String title);

void printBookInfo(FILE* out, BookHndl B);

#endif /* BOOK_H_ */
