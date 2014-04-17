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

	printf("%d,%d\n", nCustomers, nPurchases);
	ListHndl customers[nCustomers];

	for (i = 0; i < nCustomers; i++) {
		customers[i] = newList();
	}

	for (i = 0; i < nPurchases; i++) {
		fscanf(stdin, "%d", &customerNum);
		fscanf(stdin, "%ld", &bookID);
		getc(stdin);
		printf("%d,%ld\n", customerNum, bookID);
	}

	return exitStatus;
}