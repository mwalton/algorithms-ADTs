/* 
 * Michael Walton : mwwalton@ucsc.edu
 * Decimal to binary converter using
 * intstack ADT
 *
 * Read a non-negative integer from stdin
 * Using the division method, convert to binary
 */

#include "myinclude.h"
#include "intstack.h"

int main()
{
  int decNum;
  int tmpNum;
  StackHndl binStack;

  /*Initialize and allocate memory for the binary stack*/
  binStack = NULL;
  binStack = NewStack ();

  /*Prompt and read in a decimal value*/
  printf("Input a non-negative decimal integer to convert to binary:\n");
  scanf("%d", &decNum);

  while (decNum < 0) {
    printf("Invalid input: decimal integer must be positive\n");
    scanf("%d", &decNum);
  }

  if (decNum == 0) {Push(binStack, 0);}
  
  /*
   * Assign tmpNum to the user-defined Decimal
   * while tmpNum is non-negative:
   *    if its odd, push 1
   *    else push 0
   *    divide the value by 2
   */
  tmpNum = decNum;
  while (tmpNum > 0) {
    if (tmpNum % 2 != 0) Push(binStack, 1);
    else Push(binStack, 0);
    tmpNum = tmpNum / 2;
  }

  printf("Decimal %d is ", decNum);

  /*Print and empty the binary stack*/
  while (! IsEmpty(binStack)) {
    printf("%d", Top(binStack));
    Pop(binStack);
  }

  printf(" in binary.\n");

  FreeStack(&binStack);
  return(0);
}
