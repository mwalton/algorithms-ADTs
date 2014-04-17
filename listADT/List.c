#include "myinclude.h"
#include "List.h"
#include <assert.h>


typedef struct NodeStruct * NodePtr;

typedef struct NodeStruct {
  long data;
  struct NodeStruct* next;
  struct NodeStruct* prev;
} NodeStruct;

typedef struct ListStruct {
  NodePtr first;
  NodePtr last;
  NodePtr current;
} ListStruct;

/* 
 * GLOBAL VARIABLES:
 * The main global variables used in this implementation are the
 * deal with the free list.  This is a list of free nodePtrs
 * that can be referenced in insert operations instead of malloc'ing
 * more space
 */

NodePtr FreeList;

/*
 * UTILITY FUNCTION PROTOTYPES
 * Mainly for allocating / deallocating memory
 */

NodePtr newNode(); /*gets a new node from the freelist or malloc*/
void freeNode (NodePtr Node); /* puts un-needed nodes on free list */
void freeFreeList (); /* Free the storage used by the free list */
void printList(FILE* out, ListHndl L);  /* prints out the list with the
                                     current element marked, helpful for debugging */

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
  assert( (*L) != NULL);

  makeEmpty(L);
  free (*L);
  (L) = NULL;

  freeFreeList();
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

void makeEmpty(ListHndl L){
  while( !isEmpty(L) ) { deleteFirst(L); }
}
                          
void moveFirst(ListHndl L) {
  assert( !isEmpty(L) ); 

  L->current = L->first;
}
                          
void moveLast(ListHndl L){
  assert( !isEmpty(L) ); 

  L->current = L->last;
}
              
void movePrev(ListHndl L){
  assert( !offEnd(L) );

  L->current = L->current->prev;
}
                          
void moveNext(ListHndl L){
  assert( !offEnd(L) );

  L->current = L->current->next;
}

void insertAtFront(ListHndl L, long data) {
  NodePtr tmpNode;

  tmpNode = newNode();

  tmpNode->data = data;
  tmpNode->next = L->first;
 
  /*If the list is not empty*/
  if (L->first != NULL) {
    L->first->prev = tmpNode;
  }

  L->first = tmpNode;

  /*If this is the first element added to the list*/
  if(tmpNode->next == NULL) {
    L->last = tmpNode;
  }
}
                                  
void insertAtBack(ListHndl L, long data) {
  NodePtr tmpNode;

  tmpNode = newNode();

  tmpNode->data = data;
  tmpNode->prev = L->last;

  /*If the list is not empty*/
  if (L->last != NULL) {
    L->last->next = tmpNode;
  }

  L->last = tmpNode;

  /*If this is the first element added to the list*/
  if(tmpNode->prev == NULL) {
    L->first = tmpNode;
  }
}

void insertBeforeCurrent(ListHndl L, long data) {
  NodePtr tmpNode;

  assert( !offEnd(L) );

  tmpNode = newNode();
  tmpNode->data = data;
  tmpNode->next = L->current;
  tmpNode->prev = L->current->prev;

  L->current->prev->next = tmpNode;
  L->current->prev = tmpNode;
}

void deleteFirst(ListHndl L){
  NodePtr tmpNode = L->first;

  assert(!isEmpty(L));

  L->first = L->first->next;
  freeNode ( tmpNode );
  if (L->first !=NULL) { L->first->prev = NULL; }
}

void deleteLast(ListHndl L) {
  NodePtr tmpNode = L->last;

  assert(!isEmpty(L));

  L->last = L->last->prev;

  freeNode ( tmpNode );
  if ( L->last != NULL ) { L->last->next = NULL; }
}

void deleteCurrent(ListHndl L){
  assert( !offEnd(L) );

  if (L->current->prev != NULL) {
    L->current->prev->next = L->current->next;
  }
  if (L->current->next != NULL) {
    L->current->next->prev = L->current->prev;
  }

  freeNode ( L->current );

  L->current = NULL;
}

/*** Utility functions ***/

NodePtr newNode() {
  NodePtr tmpNode;
  
  if (FreeList == NULL)
    {
      tmpNode = malloc ( sizeof( NodeStruct ));
    }
  else
    {
      tmpNode = FreeList;
      FreeList = FreeList->prev;
    }

  tmpNode->data = -1357;
  tmpNode->prev = NULL;
  tmpNode->next = NULL;
  return(tmpNode);
}

/* puts un-needed nodes on free list */
void freeNode (NodePtr Node)
{
  Node->data = -7531;
  Node->prev = FreeList;
  Node->next = NULL;
  FreeList = Node;
}

/* Free the storage used by the free list */ 
void freeFreeList ()
{
  NodePtr tmpNode;

  /*  printf("Freeing Free list \n"); */

  while (FreeList != NULL)
    {
      tmpNode = FreeList;
      FreeList = FreeList->prev;
      free (tmpNode);
    }
}

void printList(FILE* out, ListHndl L) {
  NodePtr tmpNode;

  if ( isEmpty(L) ) { fprintf(out, "LIST IS EMPTY"); }

  tmpNode = L->first;
  while (tmpNode != NULL) {
    if (tmpNode == L->current) {
      fprintf(out, "[%ld] ", tmpNode->data );
    } else {
      fprintf(out, "%ld ", tmpNode->data );
  }
    tmpNode = tmpNode->next;
  }
  fprintf(out, "\n");
}
