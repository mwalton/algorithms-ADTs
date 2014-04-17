#include "List.h"
#include "myinclude.h"

int main() {
  ListHndl testList;
  testList = newList();

  /*CHECK THAT THE LIST IS EMPTY*/
  printf( "isEmpty: SHOULD BE 1, ACTUAL VALUE: %d\n", isEmpty(testList));
  printf( "offEnd: SHOULD BE 1, ACTUAL VALUE: %d\n", offEnd(testList));
  printf( "atFirst: SHOULD BE 0, ACTUAL VALUE: %d\n", atFirst(testList));
  printf( "atLast: SHOULD BE 0, ACTUAL VALUE: %d\n\n", atLast(testList));

  /*CHECK THAT ADD AT FRONT WORKS*/
  printf("ADDING NODE AT FRONT WITH VALUE: %ld\n", 0);
  insertAtFront(testList, 0);
  printf("VALUE AT FRONT SHOULD BE %ld, ACTUAL VALUE: %ld\n\n", 0, getFirst(testList) );

  /*CHECK THAT ADD AT BACK WORKS*/
  printf("ADDING NODE AT BACK WITH VALUE: %ld\n", 9);
  insertAtBack(testList, 9);
  printf("VALUE AT FRONT SHOULD BE %ld, ACTUAL VALUE: %ld\n\n", 9, getLast(testList) );

  /*CHECK FIRST AND LAST VALUE*/
  printf( "getFirst: VALUE SHOULD BE %ld, ACTUAL VALUE: %ld\n", 0, getFirst(testList));
  printf( "getLast: VALUE SHOULD BE %ld, ACTUAL VALUE: %ld\n\n", 9, getLast(testList));
  
  /*SET CURRENT TO FIRST*/
  printf("MOVING THE THE FIRST VALUE IN THE LIST\n");
  moveFirst(testList);
  printf( "getCurrent: SHOULD BE %ld, ACTUAL VALUE: %ld\n\n", 0, getCurrent(testList));

  /*MOVE TO THE NEXT NODE*/
  printf("MOVING TO THE NEXT VALUE IN THE LIST\n");
  moveNext(testList);
  printf("getCurrent: SHOULD BE %ld, ACTUAL VALUE: %ld\n\n", 9, getCurrent(testList) );

  /*MOVE BACK*/
  printf("MOVING TO THE PREVIOUS VALUE IN THE LIST\n");
  movePrev(testList);
  printf("getCurrent: SHOULD BE %ld, ACTUAL VALUE: %ld\n\n", 0, getCurrent(testList) );

  /*CHECK THAT ADD AT FRONT/BACK DOESN'T CHANGE CURRENT*/
  printf("ADDING NODE AT FRONT WITH VALUE: %ld\n", 34);
  insertAtFront(testList, 34);
  printf("ADDING NODE AT BACK WITH VALUE: %ld\n", 43);
  insertAtBack(testList, 43);
  printf("VALUE AT FRONT SHOULD BE %ld, ACTUAL VALUE: %ld\n", 34, getFirst(testList) );
  printf("VALUE AT BACK SHOULD BE %ld, ACTUAL VALUE: %ld\n", 43, getLast(testList) );
  printf("CURRENT VALUE SHOULD BE %ld, ACTUAL VALUE: %ld\n", 0, getCurrent(testList) );

  insertBeforeCurrent(testList, 99);
  
  printList(stdout, testList);
  deleteCurrent(testList);
  printList(stdout, testList);
  deleteLast(testList);
  printf("VALUE AT BACK SHOULD BE %ld, ACTUAL VALUE: %ld\n", 9, getLast(testList) );
  printList(stdout, testList);
  deleteLast(testList);
  printList(stdout, testList);
  printf("VALUE AT BACK SHOULD BE %ld, ACTUAL VALUE: %ld\n", 99, getLast(testList) );

  printList(stdout, testList);
  freeList(testList);
  printList(stdout, testList);
  
  return 0;
}
