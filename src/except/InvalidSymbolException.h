/*
 * InvalidSymbolException.h
 * Declares an exception that is thrown when a symbol is invalid
 * Created by Andrew Davis
 * Created on 1/17/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef INVAL_SYM_EXCP
#define INVAL_SYM_EXCP

//include
#include <exception>
#include <string>

//class declaration
class InvalidSymbolException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidSymbolException(const char* newMsg);

		//destructor
		~InvalidSymbolException();

		//copy constructor
		InvalidSymbolException(const InvalidSymbolException& ise);

		//move constructor
		InvalidSymbolException(InvalidSymbolException&& ise);

		//assignment operator
		InvalidSymbolException& operator=(const InvalidSymbolException& src);

		//move operator
		InvalidSymbolException& operator=(InvalidSymbolException&& src);

		//overridden what() method - called when the exception is thrown
		virtual const char* what() const throw();
	
	//private fields and methods
	private:
		std::string msg; //returned by the what() method

};

#endif
