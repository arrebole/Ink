
CC := g++
Program := a

CCFLAG :=
CCOBJFLAG := $(CCFLAG) -c
CCOUTFLAG := $(CCFLAG) -o
# ------------------------

all: main

main: main.cc quickSelect.cc lomutoPartition.cc
	$(CC) main.cc quickSelect.cc lomutoPartition.cc -o $(Program)

# quickSelect.o: quickSelect.cc lomutoPartition.cc
# 	$(CC) $(CCOBJFLAG) quickSelect.cc lomutoPartition.cc

# ------------------------

.PHONY: clean
clean:
	@echo "Clean up garbage..."
	rm *.o 