/*
 * findPath.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#include "graph.h"
#include "list.h"

int main(int argc, char **argv) {
    FILE *inFile;
    char str[20000];
    char *token;
    int nVerts;
    int nReqs;
    Graph pathGraph;

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

    pathGraph = newGraph( nVerts );

    for (int from = 0; from < nVerts; ++from ) {
        fgets (str, 20000, inFile);
        strtok(str, "\n");

        token = strtok(str, " ");
        token = strtok (NULL, " ");

        while( token != NULL) {
            int to = atoi( token );

            insertEdge( pathGraph, from, to);
            token = strtok (NULL, " ");
        }
    }

    /*
     * Process requests and find paths
     *
     */

    for (int from = 0; from < nReqs; ++from ) {
        int source;
        int dest;
        fgets (str, 20000, inFile);
        strtok(str, "\n");

        token = strtok(str, " ");
        source = atoi( token );
        token = strtok(NULL, " ");
        dest = atoi( token );

        doBFS(pathGraph, source);
        int dist = getDistance( pathGraph, dest);
        if ( dist > -1) {
            printf("The shortest path from %d to %d requires %d edge(s):\n", source, dest, dist);
            ListHndl path = getPathTo( pathGraph, dest);
            moveFirst( path );
            while( !offEnd( path )) {
                printf("%d ", getCurrent( path));
                if ( !atLast( path )) { printf( "-> "); }
                else { printf("\n\n"); }
                moveNext( path );
            }

            freeList( path );

        } else {
            printf("No path from %d to %d exists\n\n", source, dest);
        }
    }

    fclose (inFile);

    freeGraph(pathGraph);

    return 0;
}
