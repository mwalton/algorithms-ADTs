/*
 * hashdr.c
 *
 *  	Michael Walton
 * 		mwwalton@ucsc.edu
 */

#include "list.h"
#include "book.h"
#include "hashtbl.h"
#include <time.h>

int main() {
    HashTable hashtable;
    hashtable = newHashTbl(20);

    int libNum = 1134;
    int libNum2 = 2222;

    printHeading(" TEST HASH FUNCTION ", '#', 80);
    printf("hash(Test) = %lu\n", hash("Test", 20));
    printf("hash(Homer's The Odyssey) = %lu\n", hash("Homer's The Odyssey", 20));
    printf("hasht(Godel Escher Bach) = %lu\n", hash("Godel Escher Bach", 20));
    printf("hash(Brothers Karamazov) = %lu\n", hash("Brothers Karamazov", 20));
    printf("hash(Do Androids Dream of Electric Sheep?) = %lu\n",
            hash("Do Androids Dream of Electric Sheep?", 20));


    printHeading(" TEST INSERTIONS ", '#', 80);

    mutatorTest("%s : %s", "insertKey", "Test");
    insertKey( hashtable, "Test", &libNum );
    insertKey( hashtable, "Test", &libNum2 );
    insertKey( hashtable, "Test", &libNum );
    printBookInfo( stdout, find( hashtable, "Test" ) );

    mutatorTest("%s : %s", "insertKey", "Godel Escher Bach");
    insertKey( hashtable, "Godel Escher Bach", &libNum );
    insertKey( hashtable, "Godel Escher Bach", &libNum2 );
    insertKey( hashtable, "Godel Escher Bach", &libNum );
    printBookInfo( stdout, find( hashtable, "Godel Escher Bach" ) );

    mutatorTest("%s : %s", "insertKey", "Homer's The Odyssey");
    insertKey( hashtable, "Homer's The Odyssey", &libNum );
    insertKey( hashtable, "Homer's The Odyssey", &libNum2 );
    insertKey( hashtable, "Homer's The Odyssey", &libNum );
    printBookInfo( stdout, find( hashtable, "Homer's The Odyssey" ) );
    
    mutatorTest("%s : %s", "insertKey", "Do Androids Dream of Electric Sheep?");
    insertKey( hashtable, "Do Androids Dream of Electric Sheep?", &libNum );
    insertKey( hashtable, "Do Androids Dream of Electric Sheep?", &libNum2 );
    insertKey( hashtable, "Do Androids Dream of Electric Sheep?", &libNum );
    printBookInfo( stdout, find( hashtable, "Do Androids Dream of Electric Sheep?" ) );

    printHeading(" PRINT HASHTABLE ", '#', 80);
    printTable(stdout, hashtable);

    mutatorTest("%s : %s", "deleteKey", "Test");
    removeKey(hashtable, "Test");

    printHeading(" PRINT HASHTABLE ", '#', 80);
    printTable(stdout, hashtable);

    freeHashTbl( hashtable );
    return 0;
}
