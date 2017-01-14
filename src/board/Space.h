/*
 * Space.h
 * Declares a class that represents a space on a chessboard
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SPACE_H_INC
#define SPACE_H_INC

//includes
#include "../except/InvalidRankException.h"
#include "../gui/EnumColor.h"
#include "../piece/Pawn.h"
#include "../piece/Rook.h"
#include "../piece/Knight.h"
#include "../piece/Bishop.h"
#include "../piece/Queen.h"
#include "../piece/King.h"
#include "../piece/Piece.h"
#include "EnumFile.h"

//class declaration
class Space final {
	//public fields and methods
	public:
		//constructor
		Space(int newRank, EnumFile newFile);

		//destructor
		~Space();

		//copy constructor
		Space(const Space& s);

		//move constructor
		Space(Space&& s);

		//assignment operator
		Space& operator=(const Space& src);

		//move operator
		Space& operator=(Space&& src);

		//getter methods
		bool hasPiece() const; //returns true if the Space has a Piece on it, false otherwise
		Piece* getPiece() const; //returns a pointer to the Piece on top of the Space and returns nullptr if none exists
		int getRank() const; //returns the row that the Space is located in on the chessboard
		EnumFile getFile() const; //returns the Space's column on the chessboard
		int getFileIndex() const; //returns the index of the Space's column on the chessboard
		EnumColor getColor() const; //returns the Space's color as an EnumColor instance
		int getColorID() const; //returns the ncurses color ID for the Space's color

		//piece methods
		void placePiece(const Piece& newPiece); //places a given Piece on the Space
		void removePiece(); //removes a Piece from the Space, does nothing if no Piece exists on the Space
	
	//private fields and methods
	private:
		int rank; //the row the Space is on
		EnumFile file; //the column the Space is on
		EnumColor color; //the color the Space is
		Piece* pieceOn; //the Piece resting on the Space

};

#endif
