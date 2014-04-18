/* Michael Walton
 * mwwalton@ucsc.edu
 * List.h
 * Header for list ADT
 */

#ifndef LIST_H
#define LIST_H

typedef struct ListStruct*  ListHndl;

/*** Constructors-Destructors ***/
ListHndl newList();
void freeList(ListHndl* L); /* Pre: L has been created with newList */

/* NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that L has been initialized by newList().
 */

/*** Access functions ***/
int isEmpty(ListHndl L); /* returns true is list is empty else returns false.*/
int offEnd(ListHndl L);  /* returns true is current == NULL*/
int atFirst(ListHndl L); /* returns true if current == first and !offEnd()*/
int atLast(ListHndl L);  /* returns true if current == last and !offEnd()*/
long getFirst(ListHndl L); /* return the first element; pre: !isEmpty()*/
long getLast(ListHndl L);  /* return the last element; pre: !isEmpty()*/
long getCurrent(ListHndl L); /* return the current element pre: !offEnd()*/

/*** Manipulation procedures ***/

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
 * Post: !isEmpty(); doesn’t change current element
 */

void insertAtFront(ListHndl L, long data);

/* Inserts new element after last one
 * Post: !isEmpty(); doesn’t change current element
 */

void insertAtBack(ListHndl L, long data);

/* Inserts new element before current one
 * Pre: !offEnd(); Post: !isEmpty(), !offEnd(), !atFirst()
 */

void insertBeforeCurrent(ListHndl L, long data);

/* delete the first element. Pre: !isEmpty() */

void deleteFirst(ListHndl L);

/* delete the last element. Pre: !isEmpty() */

void deleteLast(ListHndl L);

/* delete the current element.
 * Pre: !isEmpty(), !offEnd(); Post: offEnd()
 */

void deleteCurrent(ListHndl L);

#endif