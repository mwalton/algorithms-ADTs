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

typedef struct HashTable {
    ListHndl table[];
    size_t size;
} HashTable;


/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 */
HashHndl newHashTbl();
void freeHashTbl(HashHndl H); // Pre: B has been created with newBook

/* 
 * ACCESS FUNCTIONS 
 * NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that B has been initialized by newBook().
 *
 */
//BookHndl find(HashHndl H, String title);
/*
 * Manipulation procedures 
 *
 */
//void insert(HashHndl H, String title, listHndl libraries);
//void remove(HashHndl H, String title);
//void makeEmpty(HashHndl H);

//void printTable(FILE* out, HashHndl H);
