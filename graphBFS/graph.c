/*
 * graph.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 *
 */

#include "graph.h"
#include <assert.h>

typedef enum {WHITE, GREY, BLACK} colorEnum;
typedef struct VertexStruct * Vertex;

typedef struct VertexStruct {
    colorEnum color;
    int distance;
    int parent;
    ListHndl adjacencyList;
} VertexStruct;

typedef struct GraphStruct {
    Vertex* verts;
    int numVerts;

} GraphStruct;


/* 
 * CONSTRUCTORS / DESTRUCTORS
 *
 * newGraph() returns new Graph with n verts
 * freeGraph() frees the Graph
 *
 */
Graph newGraph(int n) {
    Graph G;
    G = malloc( sizeof(GraphStruct) );

    G -> verts = malloc( n * sizeof(VertexStruct) );
    
    for (int i = 0; i < n; i++) {
        G -> verts[i] -> adjacencyList = newList();
        G -> verts[i] -> color = WHITE;
        G -> verts[i] -> distance = -1;
        G -> verts[i] -> parent = -1;
    }

    return ( G );
}

void freeGraph(Graph G) {
    assert( (G) != NULL);

    for (int i = 0; i < G -> numVerts; i++) {
        freeList(G -> verts[i] -> adjacencyList);
    }

    free(G -> verts);
    free (G);
    G = NULL;
}

/* 
 * ACCESS FUNCTIONS 
 *
 */


/*
 * Manipulation procedures 
 *
 */


/*
 * Utility functions
 *
 */


