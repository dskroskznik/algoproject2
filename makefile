# Makefile for compiling and running the Optimized Matrix Traversal Program
CC = g++
CFLAGS= -I, -std=c++98, -Wall
DEPS = pathfinder.hpp 
OBJ = pathfinder.o main.o

%.o: %.cpp $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)
	
run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
