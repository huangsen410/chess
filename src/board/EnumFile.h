/*
 * EnumFile.h
 * Enumerates columns on a chessboard
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_FILE_H
#define ENUM_FILE_H

//enum definition
enum class EnumFile {
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H
};

//indexFromFile function - returns the numerical index of an EnumFile instance
inline int indexFromFile(EnumFile file) {
	int ret = static_cast<int>(file); //get the return value by converting the EnumFile instance to an int
	return ret + 1; //return one more than the converted value
}

//fileFromIndex function - returns the EnumFile instance corresponding to a numerical index ranging from 1 to 8
inline EnumFile fileFromIndex(int index) {
	if(index <= 0) { //if the index is too low
		return EnumFile::A; //return the lowest EnumFile value
	} else if(index > 8) { //if the index is too high
		return EnumFile::H; //return the highest EnumFile value
	} else {
		index--; //decrement the index so that a supplied 1 is now 0
		return static_cast<EnumFile>(index); //return the index, cast to an EnumFile instance
	}
}

#endif
