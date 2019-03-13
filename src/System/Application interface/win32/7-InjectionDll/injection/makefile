

CC := g++

all: lib main

lib: lib.cc 
	$(CC) lib.cc -shared -fPIC -o lib.dll

main: main.cc
	$(CC) main.cc -o main.exe