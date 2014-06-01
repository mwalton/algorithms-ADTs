/*
 * graphdr.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#include "graph.h"

int main(int argc, char **argv) {
    FILE *inFile;
    char str[60];
    char *token;
    int nVerts;
    int nReqs;
    Graph testGraph;

    /*
     * Validate input file
     *
     */

    if (argc < 2) {
        perror("Please specify an input file\n");
        return (-1);
    }

    inFile = fopen(argv[1], "r");
    if (inFile == NULL) {
        perror("Could not open input file");
        return (-1);
    }

    /*
     * Read Input file
     *
     */

    fgets(str, 60, inFile);
    strtok(str, "\n");
    token = strtok(str, " ");
    nVerts = atoi( token );
    token = strtok(NULL, " ");
    nReqs = atoi( token );


    /*
     * Build Graph & Insert Edges
     *
     */

    testGraph = newGraph( nVerts );

    printHeading(" INSERT EDGES ", '#', 80);

    for (int from = 0; from < nVerts; ++from ) {
        fgets (str, 60, inFile);
        strtok(str, "\n");

        token = strtok(str, " ");
        token = strtok (NULL, " ");

        while( token != NULL) {
            int to = atoi( token );

            mutatorTest("%s : (%d, %d)", "insertEdge", from, to );
            insertEdge( testGraph, from, to);
            token = strtok (NULL, " ");
        }
    }

    fclose (inFile);

    printHeading(" PRINT GRAPH ", '#', 80);
    printf("Number of verts: %d, Number of Requests: %d\n", nVerts, nReqs);
    printGraph(stdout, testGraph);
    printHeading(" BREDTH FIRST SEARCH ", '#', 80);

    doBFS(testGraph, 0);
    mutatorTest("%s : source = %d", "doBFS", 0);
    printGraph(stdout, testGraph);


    freeGraph(testGraph);

    return 0;
}
