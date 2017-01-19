######################
# Makefile for Chess #
######################

CC=g++

CFLAGS=-c -Wall -fPIC -Wno-unused-value -std=c++14
LIBFLAGS=-lncurses -lfl
LDFLAGS=-lgnustl_shared

MAIN=$(shell ls src/*.cpp)
UTIL=$(shell ls src/util/*.cpp)
PIECE=$(shell ls src/piece/*.cpp)
EXCEP=$(shell ls src/except/*.cpp)
BOARD=$(shell ls src/board/*.cpp)
MOVE=$(shell ls src/move/*.cpp)
SERIAL=$(shell ls src/serial/*.cpp)

PARSER=src/serial/SerialParser.y
LEXER=src/serial/SerialLexer.l
CLEXER=lex.yy.c
PHEAD=SerialParser.tab.hh
PIMPL=SerialParser.tab.cc
LOC=location.hh
POS=position.hh
STK=stack.hh
MCLEXER=src/serial/lex.yy.c
MPHEAD=src/serial/SerialParser.tab.hh
MPIMPL=src/serial/SerialParser.tab.cc
MLOC=src/serial/location.hh
MPOS=src/serial/position.hh
MSTK=src/serial/stack.hh


PARSEBASE=$(PARSER) $(LEXER)
PARSECODE=$(MCLEXER) $(MPHEAD) $(MPIMPL) $(MLOC) $(MPOS) $(MSTK)

SOURCES=$(MAIN) $(UTIL) $(PIECE) $(EXCEP) $(BOARD) $(MOVE) $(SERIAL)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=chess

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(PARSECODE)
	$(CC) $(OBJECTS) $(MPIMPL) $(MCLEXER) -o $(EXECUTABLE) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mkdir parse
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/
	mv -f $(PARSECODE) parse/

debug: $(OBJECTS) $(PARSECODE)
	$(CC) -g $(OBJECTS) $(MPIMPL) $(MCLEXER) -o $(EXECUTABLE) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mkdir parse
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/
	mv -f $(PARSECODE) parse/

android: $(OBJECTS) $(PARSECODE)
	$(CC) $(OBJECTS) $(MPIMPL) $(MCLEXER) -o $(EXECUTABLE) $(LDFLAGS) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mkdir parse
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/
	mv -f $(PARSECODE) parse/

debug-android: $(OBJECTS) $(PARSECODE)
	$(CC) -g $(OBJECTS) $(MPIMPL) $(MCLEXER) -o $(EXECUTABLE) $(LDFLAGS) $(LIBFLAGS)
	mkdir obj
	mkdir bin
	mkdir parse
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/
	mv -f $(PARSECODE) parse/

$(PARSECODE): $(PARSEBASE)
	bison -d $(PARSER)
	flex $(LEXER)
	mv -f $(PHEAD) $(MPHEAD)
	mv -f $(PIMPL) $(MPIMPL)
	mv -f $(CLEXER) $(MCLEXER)
	mv -f $(LOC) $(MLOC)
	mv -f $(POS) $(MPOS)
	mv -f $(STK) $(MSTK)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf bin
	rm -rf obj
	rm -rf parse
