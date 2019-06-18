CC = clang-cl

.PHONY:clean

all: TCPServ-iocp_win10-x64.cc IOCompletionPort.o
	$(CC) TCPServ-iocp_win10-x64.cc IOCompletionPort.o -o TCPServ-iocp.exe  /link ws2_32.lib

IOCompletionPort.o: IOCompletionPort.cc
	$(CC) IOCompletionPort.cc -c -o IOCompletionPort.o 

clean:
	rm *.o


