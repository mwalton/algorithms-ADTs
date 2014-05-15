# Michael Walton : mwwalton@ucsc.edu
# Makefile

GCC = gcc -g -Wall -Wextra -pedantic -std=c99
SOURCE = listdr.c list.c util.c
HEADERS = list.h util.h
OBJECTS = ${SOURCE:.c=.o}
DRIVER = listdr
MAIN_EXEC =

all : ${DRIVER} ${MAIN_EXEC}

${DRIVER} : ${OBJECTS}
	${GCC} -o ${DRIVER} ${OBJECTS}

%.o : %.c
	${GCC} -c $<

clean :
	rm ${OBJECTS} ${DRIVER} ${MAIN_EXEC}
