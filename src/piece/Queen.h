/*
 * Queen.h
 * Declares a class that represents a chess queen
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef QUEEN_H_INC
#define QUEEN_H_INC

//include
#include "Piece.h"

//class declaration
class Queen final : public Piece
{
	//public fields and methods
	public:
		//constructor
		Queen(EnumColor newColor);

		//destructor
		~Queen();

		//copy constructor
		Queen(const Queen& q);

		//move constructor
		Queen(Queen&& q);

		//assignment operator
		Queen& operator=(const Queen& src);

		//move operator
		Queen& operator=(Queen&& src);

		//inherited pure virtual methods
		bool canCastle() const override; //returns whether or not the Queen can castle (always false)
		int getValue() const override; //returns the trade value of the Queen (always 9)

		//overridden onMove method - called when the Queen is moved
		void onMove() override;
};

#endif
