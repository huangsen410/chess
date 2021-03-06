/*
 * Rook.cpp
 * Implements a class that represents a chess rook
 * Created by Andrew Davis
 * Created on 1/13/2017
 * Open source (GPL license)
 */

//include header
#include "Rook.h"

//constructor
Rook::Rook(EnumColor newColor)
	: Piece(EnumPiece::ROOK, newColor) //call superclass constructor
{
	//no code needed
}

//destructor
Rook::~Rook() {
	//no code needed
}

//copy constructor
Rook::Rook(const Rook& r)
	: Piece(r) //call superclass copy constructor
{
	//no code needed
}

//move constructor
Rook::Rook(Rook&& r)
	: Piece(r) //call superclass move constructor
{
	//no code needed
}

//assignment operator
Rook& Rook::operator=(const Rook& src) {
	Piece::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
Rook& Rook::operator=(Rook&& src) {
	Piece::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//overridden onMove method - called when the Rook is moved
void Rook::onMove() {
	Piece::onMove(); //call superclass onMove method
}

//end of implementation
