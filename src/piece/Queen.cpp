/*
 * Queen.cpp
 * Implements a class that represents a chess queen
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//include header
#include "Queen.h"

//constructor
Queen::Queen(EnumColor newColor)
	: Piece(EnumPiece::QUEEN, newColor) //call superclass constructor
{
	//no code needed
}

//destructor
Queen::~Queen() {
	//no code needed
}

//copy constructor
Queen::Queen(const Queen& q)
	: Piece(q) //call superclass copy constructor
{
	//no code needed
}

//move constructor
Queen::Queen(Queen&& q)
	: Piece(q) //call superclass move constructor
{
	//no code needed
}

//assignment operator
Queen& Queen::operator=(const Queen& src) {
	Piece::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
Queen& Queen::operator=(Queen&& src) {
	Piece::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//inherited pure virtual methods

//canCastle method - returns whether or not the Queen can castle (always false)
bool Queen::canCastle() const {
	return false; //queens can't castle
}

//getValue method - returns the trade value of the Queen (always 9)
int Queen::getValue() const {
	return 9; //bishops have a value of 9
}

//overridden onMove method - called when the Queen is moved
void Queen::onMove() {
	Piece::onMove(); //call superclass onMove method
}

//end of implementation
