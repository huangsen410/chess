/*
 * Bishop.h
 * Declares a class that represents a chess bishop
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef BISHP_H_INC
#define BISHP_H_INC

//include
#include "Piece.h"

//class declaration
class Bishop final : public Piece
{
	//public fields and methods
	public:
		//constructor
		Bishop(EnumColor newColor);

		//destructor
		~Bishop();

		//copy constructor
		Bishop(const Bishop& b);

		//move constructor
		Bishop(Bishop&& b);

		//assignment operator
		Bishop& operator=(const Bishop& src);

		//move operator
		Bishop& operator=(Bishop&& src);

		//overridden onMove method - called when the Bishop is moved
		void onMove() override;
};

#endif
