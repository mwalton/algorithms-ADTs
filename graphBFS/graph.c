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

    G -> verts = malloc( n * sizeof(Vertex) );
    G -> numVerts = n;

    for (int i = 0; i < n; i++) {
        G -> verts[i] = malloc( sizeof(VertexStruct) );
        G -> verts[i] -> adjacencyList = newList();
        G -> verts[i] -> color = WHITE;
        G -> verts[i] -> distance = -1;
        G -> verts[i] -> parent = -1;
    }

    return ( G );
}

void freeGraph(Graph G) {
    assert( G != NULL);

    for (int i = 0; i < G -> numVerts; i++) {
        freeList(G -> verts[i] -> adjacencyList);
        free(G -> verts[i]);
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
 * addEdge
 * pre: G has been initilized with newGraph
 *      to and from are within the range [0, numVerts]
 * post: an edge (from, to) is inserted into the graph
 * (to is added to from's adjacency list)
 */
void insertEdge(Graph G, int from, int to) {
    assert( G != NULL);
    assert( from < G -> numVerts );
    assert( to < G ->numVerts );
    assert( from >= 0);
    assert( to >= 0);

    ListHndl fromVerts = G -> verts[from] -> adjacencyList;
    insertAtBack(fromVerts, to);
}

/* doBFS
 * pre: G has been init with newGraph
 * post: BFS is run from source, parent and
 *        distance values values are set
 * 
 * BFS algorithm:
 * initialize parents to null, distances to inf
 * source.color = grey
 * source.d = 0
 * Q = null
 * ENQUEUE( Q, source)
 * while Q != null
 *  u = DEQUEUE(Q)
 *  for each v in G.adj[u]
 *    if v.color == WHITE
 *      v.color = GREY
 *      v.d = u.d + 1
 *      v.parent = u
 *      ENQUEUE(Q, v)
 *  u.color = BLACK
 *
 */
void doBFS(Graph G, int source) {
    for (int i = 0; i < G -> numVerts; i++) {
        G -> verts[i] -> color = WHITE;
        G -> verts[i] -> distance = -1;
        G -> verts[i] -> parent = -1;
    }

    G -> verts[source] -> color = GREY;
    G -> verts[source] -> distance = 0;
    G -> verts[source] -> parent = -1;

    ListHndl Q;
    Q = newList();

    //ENQUEUE SOURCE
    insertAtFront(Q, source);

    while ( !isEmpty( Q ) ) {
        // DEQUEUE U
        int uIndex = getLast(Q);
        deleteLast(Q);
        Vertex u = G -> verts[uIndex];

        if ( !isEmpty( u -> adjacencyList )) {
            moveFirst( u -> adjacencyList );
        }

        while( !offEnd( u -> adjacencyList )) {
            int vIndex = getCurrent( u -> adjacencyList );
            Vertex v = G -> verts[vIndex];

            if ( v -> color == WHITE ) {
                v -> color = GREY;
                v -> distance = (u -> distance) + 1;
                v -> parent = uIndex;
                // ENQUEUE V
                insertAtFront(Q, vIndex);
            }

            moveNext( u -> adjacencyList );
        }

        u -> color = BLACK;
    }

    freeList(Q);
}


/*
 * Utility functions
 *
 */

void printGraph(FILE* out, Graph G) {
    for (int i = 0; i < G -> numVerts; i++) {
        fprintf(out, "Vertex %d:\n\tColor: ", i);
        switch(G -> verts[i] -> color) {
            case WHITE:
                fprintf(out, "WHITE\n");
                break;
            case GREY:
                fprintf(out, "GREY\n");
                break;
            case BLACK:
                fprintf(out, "BLACK\n");
                break;
        }

        fprintf(out, "\tParent: %d\n\tEdges: ", G -> verts[i] -> parent);

        printList(out, G -> verts[i] -> adjacencyList);
    }
}

