# Makefile for compiling and running the Optimized Matrix Traversal Program
CPP = g++
CPPFLAGS= -g -Wall -Wextra -std=c++20
HEADERS = pathfinder.hpp matrixcell.hpp
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = traverse
CLEAN = $(TARGET) $(OBJS) output.txt

all: $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@
$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@
clean:
	rm -f $(CLEAN)
.PHONY: cleaned safely

#Checks for missing file names
ifeq ($(strip $(SRCS)),)
$(error No dependent source files found.)
endif

ifeq ($(strip $(TARGET)),)
$(error No target source file found.)
endif
