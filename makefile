# Makefile for compiling and running the Optimized Matrix Traversal Program
CC = g++
CFLAGS= -I, -Wall
DEPS = pathfinder.hpp 
OBJ = pathfinder.o main.o

run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
%.o: %.cpp $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)
clean:
	rm -f *.o
