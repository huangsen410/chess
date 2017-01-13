/*
 * Rook.h
 * Declares a class that represents a chess rook
 * Created by Andrew Davis
 * Created on 1/13/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ROOK_H_INC
#define ROOK_H_INC

//include
#include "Piece.h"

//class declaration
class Rook final : public Piece
{
	//public fields and methods
	public:
		//constructor
		Rook(EnumColor newColor);

		//destructor
		~Rook();

		//copy constructor
		Rook(const Rook& r);

		//move constructor
		Rook(Rook&& r);

		//assignment operator
		Rook& operator=(const Rook& src);

		//move operator
		Rook& operator=(Rook&& src);

		//inherited pure virtual methods
		bool canCastle() const override; //returns whether or not the Rook can castle
		int getValue() const override; //returns the trade value of the Rook (always 5)

		//overridden onMove method - called when the Rook is moved
		void onMove() override;
};

#endif
