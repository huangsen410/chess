/*
 * SerialContext.h
 * Declares a class that acts as an interface between Bison/Flex and the rest of the Chess program
 * Created by Andrew Davis
 * Created on 1/15/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SERIAL_CTXT_H
#define SERIAL_CTXT_H

//includes
#include <vector>
#include "../move/Move.h"

//class declaration
class SerialContext final {
	
	//public fields and methods
	public:
		//constructor
		SerialContext();

		//destructor
		~SerialContext();

		//copy constructor
		SerialContext(const SerialContext& sc);

		//move constructor
		SerialContext(SerialContext&& sc);

		//assignment operator
		SerialContext& operator=(const SerialContext& src);

		//move operator
		SerialContext& operator=(SerialContext&& src);

		//moves method - returns the moves parsed by the parser and inserted into the context
		std::vector<Move> moves() const;

		//addMove methods - add a Move to the context
		void addMove(Piece& movePiece, Space& startSpace, Space& endSpace); //constructs a Move and adds it
		void addMove(const Move& moveToAdd); //adds a preconstructed Move

		//hasMoves method - returns true if the context is holding one or more Move objects
		bool hasMoves() const;

		//deleteAllMoves method - deletes all moves from the context
		void deleteAllMoves();

	//private fields and methods
	private:
		std::vector<Move> moveAccum; //holds the Move objects stored in the context
};

#endif
