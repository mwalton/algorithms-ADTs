#include "List.h"
#include "myinclude.h"

int main() {
  ListHndl testList;
  testList = newList();
  printf( "isEmpty: %d\n", isEmpty(testList));
  printf( "offEnd: %d\n", offEnd(testList));
  printf( "atFirst: %d\n", atFirst(testList));
  printf( "atLast: %d\n", atLast(testList));
  printf( "getFirst: %ld\n", getFirst(testList));
  printf( "getLast: %ld\n", getLast(testList));
  printf( "getCurrent: %ld\n", getCurrent(testList));
  return 0;
}
