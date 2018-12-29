

CC := gcc

fexec := -fexec-charset=gbk
encoding :=  $(fexec)

all: main

main: WinMain.cc Windowproc.o
	$(CC) WinMain.cc Windowproc.o $(encoding) -luser32 -lgdi32 -o app

Windowproc: Windowproc.cc
	$(CC) -c Windowproc $(encoding)

