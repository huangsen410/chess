######################
# Makefile for Chess #
######################

CC=g++

CFLAGS=-c -Wall -Wno-unused-value -std=c++14
LIBFLAGS=-lncurses
LDFLAGS=-lgnustl_shared

MAIN=$(shell ls src/*.cpp)
UTIL=$(shell ls src/util/*.cpp)
PIECE=$(shell ls src/piece/*.cpp)
EXCEP=$(shell ls src/except/*.cpp)
BOARD=$(shell ls src/board/*.cpp)
MOVE=$(shell ls src/move/*.cpp)
SERIAL=$(shell ls src/serial/*.cpp)

SOURCES=$(MAIN) $(UTIL) $(PIECE) $(EXCEP) $(BOARD) $(MOVE) $(SERIAL)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=chess

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/

debug: $(OBJECTS)
	$(CC) -g $(OBJECTS) -o $(EXECUTABLE) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/

android: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/

debug-android: $(OBJECTS)
	$(CC) -g $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf bin
	rm -rf obj

