/*
 * Piece.cpp
 * Implements a class that represents a chess piece
 * Created by Andrew Davis
 * Created on 1/12/2017
 * Open source (GPL license)
 */

//include header
#include "Piece.h"

//constructor
Piece::Piece(EnumPiece newPieceID, EnumColor newColorID)
	: pieceID(newPieceID), colorID(newColorID), symbol('\0'), name(""), moved(false) //init the fields
{
	//now we determine the symbol and name fields
	switch(pieceID) {
		case EnumPiece::PAWN: { //if the piece is a pawn
			symbol = 'P'; //the symbol is a P
			name = "pawn"; //self-explanatory
			break;
		}
		case EnumPiece::ROOK: { //if the piece is a rook
			symbol = 'R'; //the symbol is an R
			name = "rook"; //self-explanatory
			break;
		}
		case EnumPiece::KNIGHT: { //if the piece is a knight
			symbol = 'N'; //the symbol is an N
			name = "knight"; //self-explanatory
			break;
		}
		case EnumPiece::BISHOP: { //if the piece is a bishop
			symbol = 'B'; //the symbol is a B
			name = "bishop"; //self-explanatory
			break;
		}
		case EnumPiece::KING: { //if the piece is a king
			symbol = 'K'; //the symbol is a K
			name = "king"; //self-explanatory
			break;
		}
		case EnumPiece::QUEEN: { //if the piece is a queen
			symbol = 'Q'; //the symbol is a Q
			name = "queen"; //self-explanatory
			break;
		}
		default: { //no match
			break; //use default values
		}
	}
}

//destructor
Piece::~Piece() {
	//no code needed
}

//copy constructor
Piece::Piece(const Piece& p)
	: pieceID(p.pieceID), colorID(p.colorID), symbol(p.symbol), name(p.name), moved(p.moved) //copy the fields
{
	//no code needed
}

//move constructor
Piece::Piece(Piece&& p)
	: pieceID(p.pieceID), colorID(p.colorID), symbol(p.symbol), name(p.name), moved(p.moved) //move the fields
{
	p.pieceID = static_cast<EnumPiece>(0); //assign 0 to the piece ID of the argument
	p.colorID = static_cast<EnumColor>(0); //assign 0 to the color ID of the argument
	p.symbol = '\0'; //zero out the argument's symbol
	p.name = ""; //empty the argument's name
	p.moved = false; //and reset the argument's moved flag
}

//assignment operator
Piece& Piece::operator=(const Piece& src) {
	this->pieceID = src.pieceID; //assign the piece ID
	this->colorID = src.colorID; //assign the color ID
	this->symbol = src.symbol; //assign the symbol
	this->name = src.name; //assign the name
	this->moved = src.moved; //assign the moved flag
	return *this; //and return the object
}

//move operator
Piece& Piece::operator=(Piece&& src) {
	this->pieceID = src.pieceID; //move the piece ID
	this->colorID = src.colorID; //move the color ID
	this->symbol = src.symbol; //move the symbol
	this->name = src.name; //move the name
	this->moved = src.moved; //move the moved flag
	src.pieceID = static_cast<EnumPiece>(0); //assign 0 to the piece ID of the argument
	src.colorID = static_cast<EnumColor>(0); //assign 0 to the color ID of the argument
	src.symbol = '\0'; //zero out the argument's symbol
	src.name = ""; //empty the argument's name
	src.moved = false; //and reset the argument's moved flag
	return *this; //and return the object
}

//getter methods

//hasMoved method - returns whether or not the Piece has moved
bool Piece::hasMoved() const {
	return this->moved; //return the moved flag
}

//getSymbol method - returns the Piece's symbol
char Piece::getSymbol() const {
	return this->symbol; //return the symbol
}

//getColorID method - returns the EnumColor instance of the Piece
EnumColor Piece::getColorID() const {
	return this->colorID; //return the colorID field
}

//getColor method - returns the ncurses color code of the Piece
int Piece::getColor() const {
	return idFromColor(this->colorID); //use the idFromColor function in EnumColor.h to get the color code of the Piece
}

//getName method - returns the name of the Piece
std::string Piece::getName() const {
	return this->name; //return the name field
}

//getPieceID method - returns the EnumPiece instance of the Piece
EnumPiece Piece::getPieceID() const {
	return this->pieceID; //return the pieceID field
}

//other methods

//onMove method - called when the Piece is moved
void Piece::onMove() {
	if(!this->moved) { //if the Piece hasn't moved
		this->moved = true; //set its moved flag to true
	}
}

//end of implementation

