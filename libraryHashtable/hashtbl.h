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

typedef struct HashTable*  HashHndl;

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
BookHndl find(HashHndl H, String title);
/*
 * Manipulation procedures 
 *
 */
void insert(HashHndl H, String title, listHndl libraries);
void remove(HashHndl H, String title);
void makeEmpty(HashHndl H);

void printTable(FILE* out, HashHndl H);

#endif /* HASHTBL_H_ */
