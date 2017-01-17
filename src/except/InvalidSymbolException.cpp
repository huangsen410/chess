/*
 * InvalidSymbolException.cpp
 * Implements an exception that is thrown when a symbol is invalid
 * Created by Andrew Davis
 * Created on 1/17/2017
 * Open source (GPL license)
 */

//include header
#include "InvalidSymbolException.h"

//constructor
InvalidSymbolException::InvalidSymbolException(const char* newMsg)
	: msg("InvalidSymbolException thrown: ") //init the message field
{
	msg += newMsg; //append the argument to the message field
}

//destructor
InvalidSymbolException::~InvalidSymbolException() {
	//no code needed
}

//copy constructor
InvalidSymbolException::InvalidSymbolException(const InvalidSymbolException& ise)
	: msg(ise.msg) //copy the message field
{
	//no code needed
}

//move constructor
InvalidSymbolException::InvalidSymbolException(InvalidSymbolException&& ise)
	: msg(ise.msg) //move the message field
{
	ise.msg = ""; //empty the message field of the argument
}

//assignment operator
InvalidSymbolException& InvalidSymbolException::operator=(const InvalidSymbolException& src) {
	this->msg = src.msg; //assign the message field
	return *this; //and return the object
}

//move operator
InvalidSymbolException& InvalidSymbolException::operator=(InvalidSymbolException&& src) {
	this->msg = src.msg; //move the message field
	src.msg = ""; //empty the message field of the argument
	return *this; //and return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidSymbolException::what() const throw() {
	return msg.c_str(); //return the message field converted to a C string
}

//end of implementation
