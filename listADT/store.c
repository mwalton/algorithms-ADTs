/* Michael Walton
 * mwwalton@ucsc.edu
 * store.c
 * bookstore application of list ADT
 */

#include "List.h"
#include "myinclude.h"

#define MAX_LINE_SIZE 4096
#define MAX_WORD_SIZE 512

int main() {
	int exitStatus = EXIT_SUCCESS;

	char line[MAX_LINE_SIZE];
	int nCustomers;
	int nPurchases;
	int i;
	long bookID;
	int customerNum;

	/*Get the first line of input denoting n customers */
	fscanf(stdin, "%d", &nCustomers);
	fgets(line, MAX_LINE_SIZE, stdin); /*ignore the rest of the line*/

	/*Get the second line of input denoting n purchases */
	fscanf(stdin, "%d", &nPurchases);
	fgets(line, MAX_LINE_SIZE, stdin); /*ignore the rest of the line*/

	ListHndl customers[nCustomers];

	for (i = 0; i < nCustomers; i++) {
		customers[i] = newList();
	}

	for (i = 0; i < nPurchases; i++) {
		fscanf(stdin, "%d", &customerNum);
		fscanf(stdin, "%ld", &bookID);
		getc(stdin);
		/*printf("%d,%ld\n", customerNum, bookID);*/

		insertAtFront(customers[customerNum - 1], bookID);
	}

	printf("CUSTOMER #\tBOOKS PURCHASED\n");


	for (i = 0; i < nCustomers; i++) {
		insertionSort(customers[i]);
		fprintf(stdout, "%d\t\t", i + 1);
		printList(stdout, customers[i]);

		freeList(customers[i]);
	}

	return exitStatus;
}