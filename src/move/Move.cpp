/*
 * Move.cpp
 * Implements a class that represents a chess move
 * Created by Andrew Davis
 * Created on 1/15/2017
 * Open source (GPL license)
 */

//include header
#include "Move.h"

//constructor
Move::Move(Piece& newPiece, Space& newStartSpace, Space& newEndSpace)
	: movePiece(newPiece), startSpace(newStartSpace), endSpace(newEndSpace) //init the fields
{
	//no code needed
}

//destructor
Move::~Move() {
	//no code needed
}

//copy constructor
Move::Move(const Move& m)
	: movePiece(m.movePiece), startSpace(m.startSpace), endSpace(m.endSpace) //copy the fields
{
	//no code needed
}

//move constructor
Move::Move(Move&& m)
	: movePiece(m.movePiece), startSpace(m.startSpace), endSpace(m.endSpace) //move the fields
{
	//no code needed
}

//assignment operator
Move& Move::operator=(const Move& src) {
	this->movePiece = src.movePiece; //assign the piece field
	this->startSpace = src.startSpace; //assign the start space field
	this->endSpace = src.endSpace; //assign the end space field
	return *this; //return the object
}

//move operator
Move& Move::operator=(Move&& src) {
	this->movePiece = src.movePiece; //move the piece field
	this->startSpace = src.startSpace; //move the start space field
	this->endSpace = src.endSpace; //move the end space field
	return *this; //return the object
}

//getter methods

//getPiece method - returns the Piece object that is being moved
Piece Move::getPiece() const {
	return this->movePiece; //return the piece field
}

//start method - returns the Space object that represents the start of the move
Space Move::start() const {
	return this->startSpace; //return the start space
}

//end method - returns the Space object that represents the end of the move
Space Move::end() const {
	return this->endSpace; //return the end space
}

//end of implementation
