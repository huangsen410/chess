/*
 * Bishop.cpp
 * Implements a class that represents a chess bishop
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//include header
#include "Bishop.h"

//constructor
Bishop::Bishop(EnumColor newColor)
	: Piece(EnumPiece::BISHOP, newColor) //call superclass constructor
{
	//no code needed
}

//destructor
Bishop::~Bishop() {
	//no code needed
}

//copy constructor
Bishop::Bishop(const Bishop& b)
	: Piece(b) //call superclass copy constructor
{
	//no code needed
}

//move constructor
Bishop::Bishop(Bishop&& b)
	: Piece(b) //call superclass move constructor
{
	//no code needed
}

//assignment operator
Bishop& Bishop::operator=(const Bishop& src) {
	Piece::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
Bishop& Bishop::operator=(Bishop&& src) {
	Piece::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//overridden onMove method - called when the Bishop is moved
void Bishop::onMove() {
	Piece::onMove(); //call superclass onMove method
}

//end of implementation
