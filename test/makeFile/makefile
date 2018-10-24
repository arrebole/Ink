
CC := g++
Program := hello

CCFLAG :=
CCOBJFLAG := $(CCFLAG) -c

Depends := sayHello.o
# ------------------------

all: main

main: main.cc $(Depends)
	$(CC) main.cc $(Depends) -o $(Program)

sayHello.o: sayHello.cc
	$(CC) $(CCOBJFLAG) sayHello.cc

# ------------------------

.PHONY: clean
clean:
	@echo "Clean up garbage..."
	rm *.o 
