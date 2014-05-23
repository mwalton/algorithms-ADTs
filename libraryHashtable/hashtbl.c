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

    // allocate dynamic array of ListStruct pointers aka ListHndls
    tmpHashTbl -> size = size;
    tmpHashTbl -> table = malloc (size * sizeof ( ListHndl ) );

    // need to inititialize the lists so we have something in the buckets
    for (unsigned long i = 0; i < size; i++) {
        tmpHashTbl -> table[i] = newList();
    }

    return tmpHashTbl;
}

void freeHashTbl(HashTable H) {
    assert( H != NULL);
    // for each bucket
    for (unsigned long i = 0; i < H -> size; i++) {
        // if it contains a chain of size > 0 (not empty)
        if ( !isEmpty( H -> table[i] ) ) {
            // iterate over the length of the chain
            moveFirst( H -> table[i] );
            while ( !offEnd( H -> table[i] ) ) {
                // free each book in the chain
                freeBook( getCurrent( H -> table[i] ));
                moveNext( H -> table[i] );
            }
        }

        // free the table list element
        freeList( H -> table[i] );
    }
    // free the table and hashTableStruct
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
    assert( H != NULL);
    // generate a hash from the key % table size
    unsigned long bucket = hash(title, H -> size);

    ListHndl chain = H -> table[bucket];

    // if the chain is not empty, iterate until offend
    if ( !isEmpty( chain ) ) {
        moveFirst( chain );
        while ( !offEnd( chain ) ) {
            BookHndl book = (BookHndl) getCurrent( chain );
            // if the current element has the key title, return it
            if (strcmp(title, getTitle( book )) == 0 ) {
                return book;
            } else {
                moveNext( chain );
            }
        }
    }
    /*
     * if there are no books at the bucket index generated from the
     * hash, or if a book with the target title could not be found
     * in the corresponding chain, return NULL
     */

    return NULL;
}
/*
 * Manipulation procedures 
 *
 */

void insertKey(HashTable H, String title, int *libraryId) {
    assert( H != NULL);
    // generate a hash from the key % table size
    unsigned long bucket = hash(title, H -> size);

    ListHndl chain = H -> table[bucket];

    // if the chain is not empty, iterate until offend
    if ( !isEmpty( chain ) ) {
        moveFirst( chain );
        while ( !offEnd( chain ) ) {
            BookHndl book = (BookHndl) getCurrent( chain );

            /* 
             * if the current element has the key title
             * we need to check if the libraryId is already
             * in the book's libraryList to prevent inserting
             * it twice
             */

            if (strcmp( title, getTitle( book )) == 0 ) {
                ListHndl libraries = getLibraryList( book );
                // iterate over the libraryList
                if ( !isEmpty( libraries ) ) {
                    moveFirst( libraries );
                    while ( !offEnd( libraries ) ) {
                        // the libId is already there, nothing to do
                        if ( *(int*) getCurrent( libraries ) == *libraryId ) {
                            return;
                        } else {
                            moveNext( libraries );
                        }
                    }
                }
                // insert a new id on the book's libraryList
                insertAtFront( libraries, libraryId );
                return;
            } else {
                moveNext( chain );
            }
        }
    }

    // the title wasn't there, insert a new book w/ one libraryId
    BookHndl newbook;
    newbook = newBook();
    setTitle( newbook, title );

    insertAtFront( getLibraryList( newbook ), libraryId );
    insertAtFront( chain, newbook);

}

void removeKey(HashTable H, String title) {
    assert( H != NULL );
    // generate a hash from the key % table size
    unsigned long bucket = hash(title, H -> size);

    ListHndl chain = H -> table[bucket];

    // if the chain is not empty, iterate until offend
    if ( !isEmpty( chain ) ) {
        moveFirst( chain );
        while ( !offEnd( chain ) ) {
            BookHndl book = (BookHndl) getCurrent( chain );
            // if the current element has the key title, delete it
            if (strcmp(title, getTitle( book )) == 0 ) {
                freeBook( book );
                deleteCurrent( chain );
            } else {
                moveNext( chain );
            }
        }
    }
}

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

void printTable(FILE* out, HashTable H) {
    assert( H != NULL);
    for (unsigned long i = 0; i < H -> size; i++) {
        ListHndl chain = H -> table[i];
        if ( isEmpty ( chain ) ) {
            fprintf(out, "Bucket %lu: EMPTY\n", i);
        } else {
            fprintf(out, "Bucket %lu:\n", i);
            moveFirst( chain );
            while( !offEnd( chain ) ) {
                BookHndl book = (BookHndl) getCurrent( chain );
                //printBookInfo(stdout, book); //debug
                fprintf(out, "\t%s: ", getTitle( book ) );
                ListHndl libraries = getLibraryList( book );
                if ( !isEmpty( libraries ) ) {
                    moveFirst( libraries );
                    while ( !offEnd( libraries ) ) {
                        fprintf(out, "%d ", *(int*) getCurrent( libraries ) );
                        moveNext( libraries );
                    }
                }
                moveNext( chain );
                fprintf(out, "\n");
            }
        }
    }
}


