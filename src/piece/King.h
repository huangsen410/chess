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

		//overridden onMove method - called when the King is moved
		void onMove() override;
};

#endif
