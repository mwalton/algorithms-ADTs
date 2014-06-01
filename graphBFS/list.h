/*
 * list.h
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#ifndef LIST_H
#define LIST_H

#include "util.h"

typedef struct ListStruct*  ListHndl;

/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 */
ListHndl newList();
void freeList(ListHndl L); // Pre: L has been created with newList


/* 
 * ACCESS FUNCTIONS 
 * NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that L has been initialized by newList().
 *
 */
bool isEmpty(ListHndl L); // returns true is list is empty else returns false.
bool offEnd(ListHndl L);  // returns true is current == NULL
bool atFirst(ListHndl L); // returns true if current == first and !offEnd()
bool atLast(ListHndl L);  // returns true if current == last and !offEnd()
int getFirst(ListHndl L); // return the first element; pre: !isEmpty()
int getLast(ListHndl L);  // return the last element; pre: !isEmpty()
int getCurrent(ListHndl L); // return the current element pre: !offEnd()

/*
 * Manipulation procedures 
 *
 */

/* delete all elements from the list,
 * making it empty. Post: isEmpty(), offEnd() are both true
 */

void makeEmpty(ListHndl L);

/* without changing list order, make the first element
 * the current one.  Pre: !isEmpty(); Post: !offEnd()
 */

void moveFirst(ListHndl L);

/* without changing list order, make the last element
 * the current one. Pre: !isEmpty(); Post: !offEnd()
 */

void moveLast(ListHndl L);

/* move the current marker one element earlier in the list
 * Pre: !offEnd();   Post: offEnd() only if atFirst() was true
 */

void movePrev(ListHndl L);

/* move the current marker one element later in the list.
 * Pre: !offEnd();   Post: offEnd() only if atLast() was true
 */

void moveNext(ListHndl L);

/* Inserts new element before first
 * Post: !isEmpty(); doesn't change current element
 */

void insertAtFront(ListHndl L, int data);

/* Inserts new element after last one
 * Post: !isEmpty(); doesn't change current element
 */

void insertAtBack(ListHndl L, int data);

/* Inserts new element before current one
 * Pre: !offEnd(); Post: !isEmpty(), !offEnd(), !atFirst()
 */

void insertBeforeCurrent(ListHndl L, int data);

/* delete the first element. Pre: !isEmpty() */

void deleteFirst(ListHndl L);

/* delete the last element. Pre: !isEmpty() */

void deleteLast(ListHndl L);

/* delete the current element.
 * Pre: !isEmpty(), !offEnd(); Post: offEnd()
 */

void deleteCurrent(ListHndl L);

void printList(FILE* out, ListHndl L);  //prints out the list with the

#endif /* LIST_H_ */
