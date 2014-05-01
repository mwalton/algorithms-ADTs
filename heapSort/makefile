# Michael Walton : mwwalton@ucsc.edu
# Makefile for heap ADT, insertion sort & heapsort

sortPrint : util.o heap.o insertionSort.o heapSort.o sortPrint.o
	gcc -ansi -Wall -Wextra -pedantic -o sortPrint util.o heap.o sortPrint.o insertionSort.o heapSort.o

heapDriver : util.o heap.o heapDriver.o 
	gcc -ansi -Wall -Wextra -pedantic -o heapDriver util.o heap.o heapDriver.o

heap.o : heap.h heap.c
	gcc -c -ansi -Wall -Wextra -pedantic heap.c

insertionSort.o : insertionSort.h insertionSort.c
	gcc -c -ansi -Wall -Wextra -pedantic insertionSort.c

heapSort.o : heapSort.h heapSort.c
	gcc -c -ansi -Wall -Wextra -pedantic heapSort.c

heapDriver.o : heapDriver.c
	gcc -c -ansi -Wall -Wextra -pedantic heapDriver.c

sortPrint.o : sortPrint.c
	gcc -c -ansi -Wall -Wextra -pedantic sortPrint.c

util.o : util.h util.c
	gcc -c -ansi -Wall -Wextra -pedantic util.c

clean :
	rm heapDriver sortPrint *.o
