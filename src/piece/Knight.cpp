/*
 * Knight.cpp
 * Implements a class that represents a chess knight
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//include header
#include "Knight.h"

//constructor
Knight::Knight(EnumColor newColor)
	: Piece(EnumPiece::KNIGHT, newColor) //call superclass constructor
{
	//no code needed
}

//destructor
Knight::~Knight() {
	//no code needed
}

//copy constructor
Knight::Knight(const Knight& k)
	: Piece(k) //call superclass copy constructor
{
	//no code needed
}

//move constructor
Knight::Knight(Knight&& k)
	: Piece(k) //call superclass move constructor
{
	//no code needed
}

//assignment operator
Knight& Knight::operator=(const Knight& src) {
	Piece::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
Knight& Knight::operator=(Knight&& src) {
	Piece::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//inherited pure virtual methods

//canCastle method - returns whether or not the Knight can castle (always false)
bool Knight::canCastle() const {
	return false; //knights can't castle
}

//getValue method - returns the trade value of the Knight (always 3)
int Knight::getValue() const {
	return 3; //knights have a value of 3
}

//overridden onMove method - called when the Knight is moved
void Knight::onMove() {
	Piece::onMove(); //call superclass onMove method
}

//end of implementation
