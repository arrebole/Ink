
CC := g++

all: main

main: Library.o
	$(CC) -shared -fPIC Library.o -o Library.dll
Library.o: Library.cc
	$(CC) -c Library.cc -o Library.o