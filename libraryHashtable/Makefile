# Michael Walton : mwwalton@ucsc.edu
# Makefile

GCC = gcc -g -Wall -Wextra -pedantic -std=c99
SOURCE = listdr.c list.c util.c bookdr.c book.c hashtbl.c hashdr.c findBooks.c
HEADERS = list.h util.h book.h hashtbl.h
OBJECTS = ${SOURCE:.c=.o}
EXECBIN = listdr bookdr hashdr findBooks
MISC = Makefile README

all : listdr bookdr hashdr findBooks

findBooks : findBooks.o hashtbl.o list.o book.o util.o
	${GCC} -o findBooks findBooks.o hashtbl.o list.o book.o util.o
hashdr : hashdr.o hashtbl.o list.o book.o util.o
	${GCC} -o hashdr hashdr.o hashtbl.o list.o book.o util.o

listdr : listdr.o list.o util.o
	${GCC} -o listdr listdr.o list.o util.o

bookdr : bookdr.o book.o list.o util.o
	${GCC} -o bookdr bookdr.o book.o list.o util.o

%.o : %.c
	${GCC} -c $<

zip :
	zip WaltonMProg4.zip ${HEADERS} ${SOURCE} ${MISC}

clean :
	rm ${OBJECTS} ${EXECBIN}
