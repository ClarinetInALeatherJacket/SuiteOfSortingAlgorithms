all: mergeSort

libParseArgs.o: libParseArgs.c libParseArgs.h
	gcc -g -c libParseArgs.c

libSort.o: libSort.c libSort.h
	gcc -g -c libSort.c

mergeSort: mergeSort.c libParseArgs.o libSort.o
	gcc -g -o mergeSort mergeSort.c libParseArgs.o libSort.o