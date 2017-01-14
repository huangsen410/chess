/*
 * Knight.h
 * Declares a class that represents a chess knight
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef KGT_H_INC
#define KGT_H_INC

//include
#include "Piece.h"

//class declaration
class Knight final : public Piece
{
	//public fields and methods
	public:
		//constructor
		Knight(EnumColor newColor);

		//destructor
		~Knight();

		//copy constructor
		Knight(const Knight& k);

		//move constructor
		Knight(Knight&& k);

		//assignment operator
		Knight& operator=(const Knight& src);

		//move operator
		Knight& operator=(Knight&& src);

		//inherited pure virtual methods
		bool canCastle() const override; //returns whether or not the Knight can castle (always false)
		int getValue() const override; //returns the trade value of the Knight (always 3)

		//overridden onMove method - called when the Knight is moved
		void onMove() override;
};

#endif
