/*
 * SerialContext.cpp
 * Implements a class that acts as an interface between Bison/Flex and the rest of the Chess program
 * Created by Andrew Davis
 * Created on 1/15/2017
 * Open source (GPL license)
 */

//include header
#include "SerialContext.h"

//constructor
SerialContext::SerialContext()
	: moveAccum() //init the move accumulator
{
	//no code needed
}

//destructor
SerialContext::~SerialContext() {
	this->deleteAllMoves(); //clear the move accumulator
}

//copy constructor
SerialContext::SerialContext(const SerialContext& sc)
	: moveAccum(sc.moveAccum) //copy the move accumulator
{
	//no code needed
}

//move constructor
SerialContext::SerialContext(SerialContext&& sc)
	: moveAccum(sc.moveAccum) //move the move accumulator
{
	sc.deleteAllMoves(); //clear the argument's move accumulator
}

//assignment operator
SerialContext& SerialContext::operator=(const SerialContext& src) {
	this->moveAccum = src.moveAccum; //assign the move accumulator
	return *this; //return the object
}

//move operator
SerialContext& SerialContext::operator=(SerialContext&& src) {
	this->moveAccum = src.moveAccum; //move the move accumulator
	src.deleteAllMoves(); //clear the argument's move accumulator
	return *this; //return the object
}

//moves method - returns the moves stored by the context
std::vector<Move> SerialContext::moves() const {
	return this->moveAccum; //return the move accumulator
}

//first addMove method - adds a Move to the context by constructing the Move from parameters
void SerialContext::addMove(Piece& movePiece, Space& startSpace, Space& endSpace) {
	this->addMove(Move(movePiece, startSpace, endSpace)); //construct the move and add it using the second addMove method
}

//second addMove method - adds an already-constructed Move to the context
void SerialContext::addMove(const Move& moveToAdd) {
	this->moveAccum.push_back(moveToAdd); //add the Move to the accumulator
}

//third addMove method - adds a pointer to an already-constructed Move to the context
void SerialContext::addMove(Move* moveToAdd) {
	this->addMove(*moveToAdd); //dereference the move and add it using the second addMove method
}

//hasMoves method - returns true if the accumulator is not empty
bool SerialContext::hasMoves() const {
	bool isEmpty = this->moveAccum.empty(); //get whether or not the accumulator is empty
	return !isEmpty; //return if the accumulator is not empty
}

//deleteAllMoves method - clears the move accumulator
void SerialContext::deleteAllMoves() {
	this->moveAccum.clear(); //clear the accumulator
}

//end of implementation
