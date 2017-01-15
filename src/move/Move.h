/*
 * Move.h
 * Declares a class that represents a chess move
 * Created by Andrew Davis
 * Created on 1/15/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef MOVE_H_INC
#define MOVE_H_INC

//includes
#include "../piece/Piece.h"
#include "../board/Space.h"

//class declaration
class Move final {
	//public fields and methods
	public:
		//constructor
		Move(Piece& newPiece, Space& newStartSpace, Space& newEndSpace);

		//destructor
		~Move();

		//copy constructor
		Move(const Move& m);

		//move constructor
		Move(Move&& m);

		//assignment operator
		Move& operator=(const Move& src);

		//move operator
		Move& operator=(Move&& src);

		//getter methods
		Piece getPiece() const; //returns the Move's Piece field
		Space start() const; //returns the Space object representing the start of the Move
		Space end() const; //returns the Space object representin the end of the Move
	
	//private fields and methods
	private:
		Piece movePiece; //the piece that is moving
		Space startSpace; //the start space for the Move
		Space endSpace; //the end space for the Move
};

#endif
