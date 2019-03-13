

CC := gcc

fexec := -fexec-charset=gbk
encoding :=  $(fexec)

all: main

main: WinMain.cc Windowproc.o
	$(CC) WinMain.cc Windowproc.o -luser32 -lgdi32 -o app

Windowproc.o: Windowproc.cc
	$(CC) -c Windowproc.cc

