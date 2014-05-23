/*
 * hashtbl.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 *
 */

#include "list.h"
#include "book.h"
#include "hashtbl.h"
#include <assert.h>

typedef struct HashTableStruct {
    ListHndl* table;
    unsigned long size;
} HashTableStruct;


/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 */
HashTable newHashTbl(unsigned long size) {
    HashTable tmpHashTbl;
    tmpHashTbl = malloc ( sizeof ( HashTableStruct ) );

    tmpHashTbl -> size = size;
    tmpHashTbl -> table = malloc (size * sizeof ( ListHndl ) );

    for (unsigned long i = 0; i < size; i++) {
        tmpHashTbl -> table[i] = newList();
    }

    return tmpHashTbl;
}

void freeHashTbl(HashTable H) {
    for (unsigned long i = 0; i < H -> size; i++) {
        if ( !isEmpty( H -> table[i] ) ) {
            moveFirst( H -> table[i] );
            while ( !offEnd( H -> table[i] ) ) {
                freeBook( getCurrent( H -> table[i] ));
                moveNext( H -> table[i] );
            }
        }

        freeList( H -> table[i] );
    }

    free( H -> table );
    free(H);
}

/* 
 * ACCESS FUNCTIONS 
 * NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that B has been initialized by newBook().
 *
 */
BookHndl find(HashTable H, String title) {
    unsigned long bucket = hash(title, H -> size);
    
    ListHndl chain = H -> table[bucket];
    if ( !isEmpty( chain ) ) {
        moveFirst( chain );
        while ( !offEnd( chain ) ) {
            BookHndl book = getCurrent( chain );
            if (title == getTitle( book ) ) {
                return book;
            } else {
                moveNext( chain );
            }
        }
    }

    return NULL;
}
/*
 * Manipulation procedures 
 *
 */
void insertKey(HashTable H, String title, int *libraryId) {
    unsigned long bucket = hash(title, H -> size);
    
    ListHndl chain = H -> table[bucket];
    if ( !isEmpty( chain ) ) {
        moveFirst( chain );
        while ( !offEnd( chain ) ) {
            BookHndl book = getCurrent( chain );
            if (title == getTitle( book ) ) {
                ListHndl libraries = getLibraryList( book );
                if ( !isEmpty( libraries ) ) {
                    moveFirst( libraries );
                    while ( !offEnd( libraries ) ) {
                        if ( getCurrent( libraries ) == libraryId ) {
                            return;
                        } else {
                            moveNext( libraries );
                        }
                    }
                }
                insertAtFront( libraries, libraryId );
                return;
            } else {
                moveNext( chain );
            }
        }
    }

    BookHndl newbook;
    newbook = newBook();
    setTitle( newbook, title );

    insertAtFront( getLibraryList( newbook ), libraryId );
    insertAtFront( chain, newbook);

}
//void removeKey(HashHndl H, String title);

/*
 * Utility Functions
 *
 */

//djb2 hashing algorithm implementation
unsigned long hash(String s, unsigned long size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *s++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % size;
}
//void printTable(FILE* out, HashHndl H);
