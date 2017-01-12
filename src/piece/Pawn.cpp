/*
 * Pawn.cpp
 * Implements a class that represents a chess pawn
 * Created by Andrew Davis
 * Created on 1/12/2017
 * Open source (GPL license)
 */

//include header
#include "Pawn.h"

//constructor
Pawn::Pawn(EnumColor newColor)
	: Piece(EnumPiece::PAWN, newColor) //call superclass constructor
{
	//no code needed
}

//destructor
Pawn::~Pawn() {
	//no code needed
}

//copy constructor
Pawn::Pawn(const Pawn& p)
	: Piece(p) //call superclass copy constructor
{
	//no code needed
}

//move constructor
Pawn::Pawn(Pawn&& p)
	: Piece(p) //call superclass move constructor
{
	//no code needed
}

//assignment operator
Pawn& Pawn::operator=(const Pawn& src) {
	Piece::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
Pawn& Pawn::operator=(Pawn&& src) {
	Piece::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//inherited pure virtual methods

//canCastle method - returns whether or not the Pawn can castle (always false)
bool Pawn::canCastle() const {
	return false; //pawns can't castle
}

//getValue method - returns the trade value of the Pawn (always 1)
int Pawn::getValue() const {
	return 1; //pawns have a value of 1
}

//overridden onMove method - called when the Pawn is moved
void Pawn::onMove() {
	Piece::onMove(); //call superclass onMove method
}

//end of implementation
