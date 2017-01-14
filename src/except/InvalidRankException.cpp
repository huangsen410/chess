/*
 * InvalidRankException.cpp
 * Implements an exception that is thrown when a chess rank is invalid
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//include header
#include "InvalidRankException.h"

//constructor
InvalidRankException::InvalidRankException(const char* newMsg)
	: msg("InvalidRankException thrown: ") //init the message field
{
	msg += newMsg; //append the argument to the message field
}

//destructor
InvalidRankException::~InvalidRankException() {
	//no code needed
}

//copy constructor
InvalidRankException::InvalidRankException(const InvalidRankException& ire)
	: msg(ire.msg) //copy the message field
{
	//no code needed
}

//move constructor
InvalidRankException::InvalidRankException(InvalidRankException&& ire)
	: msg(ire.msg) //move the message field
{
	ire.msg = ""; //empty the message field of the argument
}

//assignment operator
InvalidRankException& InvalidRankException::operator=(const InvalidRankException& src) {
	this->msg = src.msg; //assign the message field
	return *this; //and return the object
}

//move operator
InvalidRankException& InvalidRankException::operator=(InvalidRankException&& src) {
	this->msg = src.msg; //move the message field
	src.msg = ""; //empty the message field of the argument
	return *this; //and return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidRankException::what() const throw() {
	return msg.c_str(); //return the message field converted to a C string
}

//end of implementation
