# Makefile for compiling and running the Optimized Matrix Traversal Program
CPP = g++
CPPFLAGS= -g -Wall -Wextra -std=c++20
HEADERS = pathfinder.hpp matrixcell.hpp
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = traverse
CLEAN = $(TARGET) $(OBJS) output.txt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(CLEAN)

.PHONY: clean
