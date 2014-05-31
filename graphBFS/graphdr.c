/*
 * graphdr.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#include "graph.h"

int main() {
    Graph testGraph;
    testGraph = newGraph(10);

    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

/*
 * 
 *
 */

    //printHeading(" INTEGER LIST ", '#', 80);
    
    freeGraph(testGraph);

    return 0;
}
