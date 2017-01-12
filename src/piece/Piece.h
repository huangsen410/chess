/*
 * Piece.h
 * Declares a class that represents a chess piece
 * Created by Andrew Davis
 * Created on 1/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef PIECE_H_INC
#define PIECE_H_INC

//includes
#include "../gui/EnumColor.h"
#include "EnumPiece.h"
#include <string>

//class declaration
class Piece {
	//public fields and methods
	public:
		//constructor
		Piece(EnumPiece newPieceID, EnumColor newColorID);

		//destructor
		virtual ~Piece();

		//copy constructor
		Piece(const Piece& p);

		//move constructor
		Piece(Piece&& p);

		//assignment operator
		Piece& operator=(const Piece& src);

		//move operator
		Piece& operator=(Piece&& src);

		//pure virtual methods
		virtual bool canCastle() const = 0; //returns whether or not the Piece can castle
		virtual int getValue() const = 0; //returns the trade value of the Piece

		//getter methods
		bool hasMoved() const; //returns whether or not the Piece has moved
		char getSymbol() const; //returns the board symbol of the Piece
		EnumColor getColorID() const; //returns the EnumColor instance of the Piece
		int getColor() const; //returns the ncurses color code of the Piece
		std::string getName() const; //returns the name of the Piece
		EnumPiece getPieceID() const; //returns the ID of the Piece

		//other methods
		virtual void onMove(); //called when the Piece moves
	
	//protected fields and methods
	protected:
		//fields
		EnumPiece pieceID; //the ID of the Piece
		EnumColor colorID; //the ID of the Piece's color
		char symbol; //the symbol that is shown on the board at the Piece's location
		std::string name; //the actual name of the Piece
		bool moved; //has the Piece moved?
};

#endif
