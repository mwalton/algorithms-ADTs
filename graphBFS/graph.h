/*
 * graph.h
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "util.h"
#include "list.h"

typedef struct GraphStruct*  Graph;

/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 */
Graph newGraph(int n);
void freeGraph(Graph G); // Pre: G has been created with newGraph


/* 
 * ACCESS FUNCTIONS 
 * NOTE:  all Access functions and Manipulation procedures also have the
 * precondition that G has been initialized by newGraph().
 *
 */
int getDistance(Graph G, int destination); // returns number of edges in shortest path from last BFS
ListHndl getPathTo(Graph G, int destination); //retruns list containing path to dest from last BFS

/*
 * Manipulation procedures 
 *
 */
void doBFS(Graph G, int source); //performs BFS & updates parent & distance arrays
void addEdge(Graph G, int from, int to); //inserts the edge (from, to)


void printGraph(FILE* out, Graph G);  //prints out the Graph

#endif /* GRAPH_H_ */
