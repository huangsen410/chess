/*
 * funcs.cpp
 * Implements utility functions that are used in Chess
 * Created by Andrew Davis
 * Created on 1/11/2017
 * Open source (GPL license)
 */

//include header
#include "funcs.h"

//first fileExistsAtPath function - checks if a file exists at a path given in a C string
bool fileExistsAtPath(const char* path) {
	std::ifstream test(path); //get a stream to test
	return test.good(); //test the stream and return the result
}

//second fileExistsAtPath function - checks if a file exists at a path given in a std::string
bool fileExistsAtPath(const std::string& path) {
	return fileExistsAtPath(path.c_str()); //use the other fileExistsAtPath function
}


//end of function implementation
