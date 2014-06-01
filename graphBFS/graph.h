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
 * getDistance returns -1 if there is no path from source to dest
 * getPathTo returns null if there is no path from source to dest
 *
 * parent and distance values are set to -1 to indicate null and infinity respectively
 *
 */
int getDistance(Graph G, int destination); // returns number of edges in shortest path from last BFS
ListHndl getPathTo(Graph G, int destination); //retruns list containing path to dest from last BFS

/*
 * Manipulation procedures 
 *
 */

void doBFS(Graph G, int source); //performs BFS & updates parent & distance arrays

/*
 * addEdge
 * pre: G has been initilized with newGraph
 *      to and from are within the range [0, numVerts]
 * post: an edge (from, to) is inserted into the graph
 * (to is added to from's adjacency list)
 */
void insertEdge(Graph G, int from, int to);


void printGraph(FILE* out, Graph G);  //prints out the Graph

#endif /* GRAPH_H_ */
