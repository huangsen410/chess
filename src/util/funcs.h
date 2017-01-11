/*
 * funcs.h
 * Declares utility functions that are used in Chess
 * Created by Andrew Davis
 * Created on 1/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef FUNC_H_INC
#define FUNC_H_INC

//includes
#include <fstream>
#include <string>

//function prototypes

//first fileExistsAtPath function - checks if a file exists at a path given in a C string
bool fileExistsAtPath(const char* path);

//second fileExistsAtPath function - checks if a file exists at a path given in a std::string
bool fileExistsAtPath(const std::string& path);

#endif
