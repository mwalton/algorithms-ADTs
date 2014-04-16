#include "myinclude.h"
#include "List.h"
#include <assert.h>


typedef struct NodeStruct {
  long data;
  struct NodeStruct* next;
  struct NodeStruct* prev;
} NodeStruct;

typedef struct NodeStruct* NodePtr;

typedef struct ListStruct {
  NodePtr first;
  NodePtr last;
  NodePtr current;
} ListStruct;

/*** Constructors-Destructors ***/
ListHndl newList() {
  ListHndl tmpList;
  tmpList = malloc ( sizeof(ListStruct) );
  tmpList->first = NULL;
  tmpList->last = NULL;
  tmpList->current = NULL;
  return (tmpList);
}

void freeList(ListHndl* L) {
  /*STUB*/
}

/*** Access functions ***/

int isEmpty(ListHndl L) {
  assert (L != NULL);
  return ( L->first == NULL );
}
int offEnd(ListHndl L) { 
  assert (L != NULL);
  return ( L->current == NULL );
}
int atFirst(ListHndl L) { 
  assert (L != NULL);
  return ( !offEnd(L) && L->current == L->first );
}

int atLast(ListHndl L) { 
  assert (L != NULL);
  return ( !offEnd(L) && L->current == L->last );
}

long getFirst(ListHndl L) { 
  assert (L != NULL);
  assert ( !isEmpty(L) );
  return ( L->first->data );
}

long getLast(ListHndl L) { 
  assert (L != NULL);
  assert ( !isEmpty(L) );
  return ( L->last->data );
}

long getCurrent(ListHndl L) { 
  assert (L != NULL);
  assert ( !offEnd(L) );
  return ( L->current->data );
}

/*** Manipulation procedures ***/

void makeEmpty(ListHndl L){}
                          
void moveFirst(ListHndl L){}
                          
void moveLast(ListHndl L){}
              
void movePrev(ListHndl L){}
                          
void moveNext(ListHndl L){}

void insertAtFront(ListHndl L, long data);
                                  
void insertAtBack(ListHndl L, long data);

void insertBeforeCurrent(ListHndl L, long data);

void deleteFirst(ListHndl L){}

void deleteLast(ListHndl L){}

void deleteCurrent(ListHndl L){}

/*** Other operations ***/

void printList(FILE* out, ListHndl L){}
