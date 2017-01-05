######################
# Makefile for Chess #
######################

CC=g++

CFLAGS=-c -Wall -Wno-unused-value -std=c++11
LIBFLAGS=-lboost_serialization -lncurses

MAIN=$(shell ls src/*.cpp)

SOURCES=$(MAIN)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=chess

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/
	

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf bin
	rm -rf obj

