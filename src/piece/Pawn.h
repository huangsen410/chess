/*
 * Pawn.h
 * Declares a class that represents a chess pawn
 * Created by Andrew Davis
 * Created on 1/12/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef PAWN_H_INC
#define PAWN_H_INC

//include
#include "Piece.h"

//class declaration
class Pawn final : public Piece
{
	//public fields and methods
	public:
		//constructor
		Pawn(EnumColor newColor);

		//destructor
		~Pawn();

		//copy constructor
		Pawn(const Pawn& p);

		//move constructor
		Pawn(Pawn&& p);

		//assignment operator
		Pawn& operator=(const Pawn& src);

		//move operator
		Pawn& operator=(Pawn&& src);
	
		//overridden onMove method - called when the Pawn is moved
		void onMove() override;
};

#endif
