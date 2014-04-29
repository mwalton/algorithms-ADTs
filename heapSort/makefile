# Michael Walton : mwwalton@ucsc.edu
# Makefile for heap ADT, insertion sort & heapsort

heapDriver : util.o heap.o heapDriver.o 
	gcc -ansi -Wall -Wextra -pedantic -o heapDriver util.o heap.o heapDriver.o

heap.o : heap.h heap.c
	gcc -c -ansi -Wall -Wextra -pedantic heap.c

heapDriver.o : heapDriver.c
	gcc -c -ansi -Wall -Wextra -pedantic heapDriver.c

util.o : util.h util.c
	gcc -c -ansi -Wall -Wextra -pedantic util.c

clean :
	rm heapDriver heapDriver.o heap.o
