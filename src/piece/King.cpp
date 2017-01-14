/*
 * King.cpp
 * Implements a class that represents a chess king
 * Created by Andrew Davis
 * Created on 1/13/2017
 * Open source (GPL license)
 */

//include header
#include "King.h"

//constructor
King::King(EnumColor newColor)
	: Piece(EnumPiece::KING, newColor) //call superclass constructor
{
	//no code needed
}

//destructor
King::~King() {
	//no code needed
}

//copy constructor
King::King(const King& k)
	: Piece(k) //call superclass copy constructor
{
	//no code needed
}

//move constructor
King::King(King&& k)
	: Piece(k) //call superclass move constructor
{
	//no code needed
}

//assignment operator
King& King::operator=(const King& src) {
	Piece::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
King& King::operator=(King&& src) {
	Piece::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//overridden onMove method - called when the King is moved
void King::onMove() {
	Piece::onMove(); //call superclass onMove method
}

//end of implementation
