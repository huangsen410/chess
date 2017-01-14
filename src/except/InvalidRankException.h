/*
 * InvalidRankException.h
 * Declares an exception that is thrown when a chess rank is invalid
 * Created by Andrew Davis
 * Created on 1/14/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef INVAL_RNK_EXCP
#define INVAL_RNK_EXCP

//include
#include <exception>
#include <string>

//class declaration
class InvalidRankException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidRankException(const char* newMsg);

		//destructor
		~InvalidRankException();

		//copy constructor
		InvalidRankException(const InvalidRankException& ire);

		//move constructor
		InvalidRankException(InvalidRankException&& ire);

		//assignment operator
		InvalidRankException& operator=(const InvalidRankException& src);

		//move operator
		InvalidRankException& operator=(InvalidRankException&& src);

		//overridden what() method - called when the exception is thrown
		virtual const char* what() const throw();
	
	//private fields and methods
	private:
		std::string msg; //returned by the what() method

};

#endif
