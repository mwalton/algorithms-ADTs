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
//HashHndl newHashTbl();
HashTable newHashTbl(unsigned long size);

void freeHashTbl(HashTable H); // Pre: B has been created with newBook

/* 
 * ACCESS FUNCTIONS 
 * NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that B has been initialized by newBook().
 *
 */
BookHndl find(HashTable H, String title);
/*
 * Manipulation procedures 
 *
 */
void insertKey(HashTable H, String title, int *libraryId);
void removeKey(HashTable H, String title);

/*
 * Utility Functions
 *
 */
unsigned long hash(String key, unsigned long size);

void printTable(FILE* out, HashTable H);

#endif /* HASHTBL_H_ */
