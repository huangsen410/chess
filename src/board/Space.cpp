/*
 * Space.cpp
 * Implements a class that represents a space on a chessboard
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//include header
#include "Space.h"

//constructor
Space::Space(int newRank, EnumFile newFile)
	: rank(newRank), file(newFile), color(EnumColor::NONE), pieceOn(nullptr) //init the fields
{
	if(rank < 1 || rank > 8) { //if the rank is invalid (out of bounds)
		throw InvalidRankException("Rank parameter is out of bounds in Space class constructor"); //then throw an error
	}
	int fileIndex = indexFromFile(file); //get the index of the file field
	if((fileIndex % 2) == (rank % 2)) { //if the file index and the rank are both even or both odd
		color = EnumColor::BLUE; //then the Space's color is blue
	} else { //if one is even and the other odd
		color = EnumColor::WHITE; //then the Space's color is white
	}
}

//destructor
Space::~Space() {
	if(pieceOn != nullptr) { //if the piece field isn't null
		delete pieceOn; //deallocate it
		pieceOn = nullptr; //and zero it out
	}
}

//copy constructor
Space::Space(const Space& s)
	: rank(s.rank), file(s.file), color(s.color), pieceOn(nullptr) //copy the fields
{
	if(s.pieceOn != nullptr) { //if the argument's Piece member isn't null
		pieceOn = new Piece(*s.pieceOn); //then construct a copy of it and assign it to this object's Piece member
	}
}

//move constructor
Space::Space(Space&& s)
	: rank(s.rank), file(s.file), color(s.color), pieceOn(nullptr) //move the fields
{
	if(s.pieceOn != nullptr) { //if the argument's Piece member isn't null
		pieceOn = new Piece(*s.pieceOn); //then construct a copy of it and assign it to this object's Piece member
	}
	s.rank = 0; //zero the argument's rank
	s.file = static_cast<EnumFile>(0); //zero the argument's file
	s.color = static_cast<EnumColor>(0); //zero the argument's color
	delete s.pieceOn; //deallocate the argument's Piece field
	s.pieceOn = nullptr; //and zero it out
}

//assignment operator
Space& Space::operator=(const Space& src) {
	this->rank = src.rank; //assign the rank field
	this->file = src.file; //assign the file field
	this->color = src.color; //assign the color field
	if(src.pieceOn != nullptr) { //if the argument's Piece field isn't null
		if(this->pieceOn == nullptr) { //if this object's Piece field is
			this->pieceOn = new Piece(EnumPiece::NONE, EnumColor::NONE); //then initialize it
		}
		*this->pieceOn = *src.pieceOn; //then assign the pieceOn field
	} else { //if the argument's Piece field is null
		delete this->pieceOn; //then deallocate this object's Piece field
		this->pieceOn = nullptr; //and zero it out
	}
	return *this; //return the object
}

//move operator
Space& Space::operator=(Space&& src) {
	this->rank = src.rank; //move the rank field
	this->file = src.file; //move the file field
	this->color = src.color; //move the color field
	if(src.pieceOn != nullptr) { //if the argument's Piece field isn't null
		if(this->pieceOn == nullptr) { //if this object's Piece field is
			this->pieceOn = new Piece(EnumPiece::NONE, EnumColor::NONE); //then initialize it
		}
		*this->pieceOn = *src.pieceOn; //then move the pieceOn field
	} else { //if the argument's Piece field is null
		delete this->pieceOn; //then deallocate this object's Piece field
		this->pieceOn = nullptr; //and zero it out
	}
	src.rank = 0; //zero the argument's rank
	src.file = static_cast<EnumFile>(0); //zero the argument's file
	src.color = static_cast<EnumColor>(0); //zero the argument's color
	delete src.pieceOn; //deallocate the argument's Piece field
	src.pieceOn = nullptr; //and zero it out
	return *this; //return the object
}

//getter methods

//hasPiece method - returns whether or not the Space has a Piece object on it
bool Space::hasPiece() const {
	return this->pieceOn != nullptr; //return whether or not the Piece field isn't null
}

//getPiece method - returns a pointer to the Piece object stored on the Space if one exists, nullptr otherwise
Piece* Space::getPiece() const {
	return this->pieceOn; //return the Piece field
}

//getRank method - returns the chessboard row the Space is located in
int Space::getRank() const {
	return this->rank; //return the rank field
}

//getFile method - returns the chessboard column the Space is located in
EnumFile Space::getFile() const {
	return this->file; //return the file field
}

//getFileIndex method - returns the index of the chessboard column the Space is located in
int Space::getFileIndex() const {
	return indexFromFile(this->file); //use the indexFromFile function to get the file index and return it
}

//getColor method - returns the EnumColor instance for the Space
EnumColor Space::getColor() const {
	return this->color; //return the color field
}

//getColorID method - returns the ncurses color ID for the Space's color
int Space::getColorID() const {
	return idFromColor(this->color); //use the idFromColor function to get the color ID and return it
}

//piece methods

//placePiece method - places a Piece on the Space
void Space::placePiece(const Piece& newPiece) {
	if(this->hasPiece()) { //if a piece already is there
		return; //then return
	}
	this->pieceOn = new Piece(newPiece); //copy the argument
}

//removePiece method - removes a Piece from the Space
void Space::removePiece() {
	if(this->hasPiece()) { //if a piece is on the Space
		delete this->pieceOn; //then deallocate it
		this->pieceOn = nullptr; //and zero it out
	}
}

//end of implementation
