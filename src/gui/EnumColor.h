/*
 * EnumColor.h
 * Enumerates the two different colors of chess pieces and board squares and provides a conversion function
 * for obtaining ncurses color codes from an enum instance
 * Created by Andrew Davis
 * Created on 1/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_COLOR_H
#define ENUM_COLOR_H

//include
#include <curses.h> //include color ids

//enum definition
enum class EnumColor {
	BLUE,
	WHITE
};

//function that returns the ncurses color ID for a given EnumColor instance
inline int idFromColor(EnumColor color) {
	if(color == EnumColor::BLUE) { //if blue color is passed to the function
		return COLOR_BLUE; //return the ncurses code for blue
	} else { //if white is passed
		return COLOR_WHITE; //return the ncurses code for white
	}
}

#endif
