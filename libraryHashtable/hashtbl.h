/*
 * hashtbl.h
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#ifndef HASHTBL_H
#define HASHTBL_H

#include "util.h"
#include "list.h"
#include "book.h"

typedef struct HashTableStruct*  HashTable;

/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 */

// returns a new hashtable of a given size
HashTable newHashTbl(unsigned long size);

void freeHashTbl(HashTable H); // Pre: H has been created with newHashTbl

/* 
 * ACCESS FUNCTIONS 
 * NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that H has been initialized by newHashTbl().
 *
 */
BookHndl find(HashTable H, String title);
/*
 * Manipulation procedures 
 *
 */

/* insertKey:
 * post: either a new book is put in the appropriate table element
 * (if the title wasn't already there) or the libraryId is appended
 * (if the tiele was already in the element's book list
 */
void insertKey(HashTable H, String title, int *libraryId);
void removeKey(HashTable H, String title); // post: the corresponding key is deleted

/*
 * Utility Functions
 *
 */
unsigned long hash(String key, unsigned long size);

void printTable(FILE* out, HashTable H);

#endif /* HASHTBL_H_ */
