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
	: pieceID(newPieceID), colorID(newColorID), symbol('\0'), name(""), moved(false), castle(false), value(1) //init fields
{
	//now we determine the symbol and name fields
	switch(pieceID) {
		case EnumPiece::PAWN: { //if the piece is a pawn
			symbol = colorID == EnumColor::WHITE ? 'P' : 'p'; //the symbol is a P
			name = "pawn"; //self-explanatory
			//default castle and value names work
			break;
		}
		case EnumPiece::ROOK: { //if the piece is a rook
			symbol = colorID == EnumColor::WHITE ? 'R' : 'r'; //the symbol is an R
			name = "rook"; //self-explanatory
			castle = true; //rooks can castle
			value = 5; //rooks have a value of 5
			break;
		}
		case EnumPiece::KNIGHT: { //if the piece is a knight
			symbol = colorID == EnumColor::WHITE ? 'N' : 'n'; //the symbol is an N
			name = "knight"; //self-explanatory
			//default castle value works
			value = 3; //knights have a value of 3
			break;
		}
		case EnumPiece::BISHOP: { //if the piece is a bishop
			symbol = colorID == EnumColor::WHITE ? 'B' : 'b'; //the symbol is a B
			name = "bishop"; //self-explanatory
			//default castle value works
			value = 3; //bishops have a value of 3
			break;
		}
		case EnumPiece::KING: { //if the piece is a king
			symbol = colorID == EnumColor::WHITE ? 'K' : 'k'; //the symbol is a K
			name = "king"; //self-explanatory
			castle = true; //kings can castle
			value = 1000; //kings are worth the game
			break;
		}
		case EnumPiece::QUEEN: { //if the piece is a queen
			symbol = colorID == EnumColor::WHITE ? 'Q' : 'q'; //the symbol is a Q
			name = "queen"; //self-explanatory
			//default castle value works
			value = 9; //queens are worth 9 points
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
	: pieceID(p.pieceID), colorID(p.colorID), symbol(p.symbol), name(p.name), moved(p.moved), castle(p.castle), value(p.value)
{
	//no code needed
}

//move constructor
Piece::Piece(Piece&& p)
	: pieceID(p.pieceID), colorID(p.colorID), symbol(p.symbol), name(p.name), moved(p.moved), castle(p.castle), value(p.value)
{
	p.pieceID = static_cast<EnumPiece>(0); //assign 0 to the piece ID of the argument
	p.colorID = static_cast<EnumColor>(0); //assign 0 to the color ID of the argument
	p.symbol = '\0'; //zero out the argument's symbol
	p.name = ""; //empty the argument's name
	p.moved = false; //and reset the argument's moved flag
	p.castle = false; //reset the castle flag
	p.value = 0; //set the value to 0
}

//assignment operator
Piece& Piece::operator=(const Piece& src) {
	this->pieceID = src.pieceID; //assign the piece ID
	this->colorID = src.colorID; //assign the color ID
	this->symbol = src.symbol; //assign the symbol
	this->name = src.name; //assign the name
	this->moved = src.moved; //assign the moved flag
	this->castle = src.castle; //assign the castle flag
	this->value = src.value; //assign the value
	return *this; //and return the object
}

//move operator
Piece& Piece::operator=(Piece&& src) {
	this->pieceID = src.pieceID; //move the piece ID
	this->colorID = src.colorID; //move the color ID
	this->symbol = src.symbol; //move the symbol
	this->name = src.name; //move the name
	this->moved = src.moved; //move the moved flag
	this->castle = src.castle; //move the castle flag
	this->value = src.value; //move the value
	src.pieceID = static_cast<EnumPiece>(0); //assign 0 to the piece ID of the argument
	src.colorID = static_cast<EnumColor>(0); //assign 0 to the color ID of the argument
	src.symbol = '\0'; //zero out the argument's symbol
	src.name = ""; //empty the argument's name
	src.moved = false; //and reset the argument's moved flag
	src.castle = false; //reset the castle flag
	src.value = 0; //set the value to 0
	return *this; //and return the object
}

//getter methods

//canCastle method - returns whether the Piece can castle
bool Piece::canCastle() const {
	return this->castle; //return the castle flag
}

//getValue method - returns the trade value of the Piece
int Piece::getValue() const {
	return this->value; //return the value field
}

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

