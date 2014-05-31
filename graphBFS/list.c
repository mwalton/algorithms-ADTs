/*
 * list.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 *
 */

#include "list.h"
#include <assert.h>

typedef struct NodeStruct * NodePtr;

typedef struct NodeStruct {
    void* data;
    struct NodeStruct* next;
    struct NodeStruct* prev;
} NodeStruct;

typedef struct ListStruct {
    NodePtr first;
    NodePtr last;
    NodePtr current;
} ListStruct;


/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 * newList() returns new ListHndl
 * free(ListHndl) frees the list
 *
 */
ListHndl newList() {
    ListHndl tmpList;

    tmpList = malloc ( sizeof(ListStruct) );

    tmpList->first = NULL;
    tmpList->last = NULL;
    tmpList->current = NULL;

    return (tmpList);
}

void freeList(ListHndl L) {
    assert( (L) != NULL);

    makeEmpty(L);
    free (L);
    (L) = NULL;
}

/* 
 * ACCESS FUNCTIONS 
 *
 */

bool isEmpty(ListHndl L) {
    assert (L != NULL);

    return ( L->first == NULL && L->last == NULL );
}

bool offEnd(ListHndl L) {
    assert (L != NULL);

    return ( L->current == NULL );
}

bool atFirst(ListHndl L) {
    assert (L != NULL);

    return ( !offEnd(L) && L->current == L->first );
}

bool atLast(ListHndl L) {
    assert (L != NULL);

    return ( !offEnd(L) && L->current == L->last );
}

void* getFirst(ListHndl L) {
    assert (L != NULL);
    assert ( !isEmpty(L) );

    return ( L->first->data );
}

void* getLast(ListHndl L) {
    assert (L != NULL);
    assert ( !isEmpty(L) );

    return ( L->last->data );
}

void* getCurrent(ListHndl L) {
    assert (L != NULL);
    assert ( !offEnd(L) );

    return ( L->current->data );
}

/*
 * Manipulation procedures 
 *
 */

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


void deleteFirst(ListHndl L){
    assert(!isEmpty(L));

    NodePtr tmpNode = L->first;

    if (L->first == L->last) {
        L->first = NULL;
        L->last = NULL;
    } else {
        L->first = L->first->next;
        L->first->prev = NULL;
    }

    free ( tmpNode );

}

void deleteLast(ListHndl L){
    assert(!isEmpty(L));

    NodePtr tmpNode = L->last;

    if (L->first == L->last) {
        L->first = NULL;
        L->last = NULL;
    } else {
        L->last = L->last->prev;
        L->last->next = NULL;
    }

    free ( tmpNode );

}

void deleteCurrent(ListHndl L){
    assert( !offEnd(L) );

    NodePtr tmpNode = L->current;

    if ( !atFirst( L ) ) {
        L->current->prev->next = L->current->next;
    } else {
        L->first = L->first->next;
    }

    if ( !atLast( L ) ) {
        L->current->next->prev = L->current->prev;
    } else {
        L->last = L->last->prev;
    }

    free ( tmpNode );

    L->current = NULL;
}

void insertAtFront(ListHndl L, void* data) {

    NodePtr tmpNode;
    tmpNode = malloc ( sizeof( NodeStruct ));

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

void insertAtBack(ListHndl L, void* data) {
    NodePtr tmpNode;

    tmpNode = malloc ( sizeof( NodeStruct ));

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

void insertBeforeCurrent(ListHndl L, void* data) {
    assert( !offEnd(L) );

    NodePtr tmpNode;

    tmpNode = malloc ( sizeof( NodeStruct ));
    tmpNode->data = data;
    tmpNode->next = L->current;
    tmpNode->prev = L->current->prev;

    if ( atFirst( L ) ) {
        L->first = tmpNode;
    } else {
        L->current->prev->next = tmpNode;
    }

    L->current->prev = tmpNode;
}

/*
 * Utility functions
 *
 */


void printList(FILE* out, ListHndl L, int typ) {
    NodePtr tmpNode;
    int size = 0;

    assert(L != NULL);
    fflush(out);

    if ( isEmpty(L) ) {
        fprintf(out, "LIST IS EMPTY\n");
        return;
    }

    tmpNode = L->first;

    while (tmpNode != NULL) {

        if (tmpNode == L->first) { fprintf(out, "< "); }

        if (tmpNode == L->current) {

            switch(typ) {
                case TYP_INT: 
                    fprintf(out, "[%d] ", *((int*)tmpNode->data) );
                    break;

                case TYP_STR:
                    fprintf(out, "[%s] ", ((String)tmpNode->data) );
                    break;
            }
        } else {

            switch(typ) {
                case TYP_INT: 
                    fprintf(out, "%d ", *((int*)tmpNode->data) );
                    break;
                case TYP_STR: 
                    fprintf(out, "%s ", ((String)tmpNode->data) );
                    break;
            }

            if (tmpNode == L->last) { fprintf(out, ">"); }

        }
        tmpNode = tmpNode->next;
        size++;
    }

    fprintf(out, " (Size: %d)\n", size);
}
