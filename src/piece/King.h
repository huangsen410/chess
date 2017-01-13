/*
 * King.h
 * Declares a class that represents a chess king
 * Created by Andrew Davis
 * Created on 1/13/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef KING_H_INC
#define KING_H_INC

//include
#include "Piece.h"

//class declaration
class King final : public Piece
{
	//public fields and methods
	public:
		//constructor
		King(EnumColor newColor);

		//destructor
		~King();

		//copy constructor
		King(const King& k);

		//move constructor
		King(King&& k);

		//assignment operator
		King& operator=(const King& src);

		//move operator
		King& operator=(King&& src);

		//inherited pure virtual methods
		bool canCastle() const override; //returns whether or not the King can castle
		int getValue() const override; //returns the trade value of the King (1000)

		//overridden onMove method - called when the King is moved
		void onMove() override;
};

#endif
