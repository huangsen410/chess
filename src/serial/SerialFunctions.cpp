/*
 * SerialFunctions.cpp
 * Implements functions for use by the chess serializer
 * Created by Andrew Davis
 * Created on 1/17/2017
 * Open source (GPL license)
 */

//include header
#include "SerialFunctions.h"

//function implementations

//addMoveToContext function - adds a move to a SerialContext instance
void addMoveToContext(SerialContext& ctxt, char piece, bool blue, int startRank, char startFile, int endRank, char endFile) {
	//first we get a Piece instance based on the piece argument
	Piece* pieceToAdd = nullptr; //the piece instance to be created
	switch(piece) { //switch on the piece argument
		case 'P': //found a pawn
		{
			EnumColor pieceColor = blue ? EnumColor::BLUE : EnumColor::WHITE; //get the color of the piece
			pieceToAdd = new Pawn(pieceColor); //create a Pawn
			break;
		}
		case 'R': //found a rook
		{
			EnumColor pieceColor = blue ? EnumColor::BLUE : EnumColor::WHITE; //get the color of the piece
			pieceToAdd = new Rook(pieceColor); //create a Rook
			break;
		}
		case 'N': //found a knight
		{
			EnumColor pieceColor = blue ? EnumColor::BLUE : EnumColor::WHITE; //get the color of the piece
			pieceToAdd = new Knight(pieceColor); //create a Knight
			break;
		}
		case 'B': //found a bishop
		{
			EnumColor pieceColor = blue ? EnumColor::BLUE : EnumColor::WHITE; //get the color of the piece
			pieceToAdd = new Bishop(pieceColor); //create a Bishop
			break;
		}
		case 'K': //found a king
		{
			EnumColor pieceColor = blue ? EnumColor::BLUE : EnumColor::WHITE; //get the color of the piece
			pieceToAdd = new King(pieceColor); //create a King
			break;
		}
		case 'Q': //found a queen
		{
			EnumColor pieceColor = blue ? EnumColor::BLUE : EnumColor::WHITE; //get the color of the piece
			pieceToAdd = new Queen(pieceColor); //create a Queen
			break;
		}
		default: //invalid symbol
		{
			throw InvalidSymbolException("Invalid piece symbol"); //throw an exception

		}
	}
	//next we verify that the startFile and endFile arguments are valid
	if(startFile < 'a' || startFile > 'h') { //invalid values
		throw InvalidSymbolException("File symbol for move start is invalid"); //throw an exception
	}
	if(endFile < 'a' || endFile > 'h') { //invalid values
		throw InvalidSymbolException("File symbol for move end is invalid"); //throw an exception
	}
	//next we get the adjusted file values from the file arguments
	int startFileAsInt = static_cast<int>(startFile); //cast the startFile argument to an integer
	int endFileAsInt = static_cast<int>(endFile); //cast the endFile argument to an integer
	startFileAsInt -= 96; //reset to the start of the character set
	endFileAsInt -= 96; //reset to the start of the character set
	//then we get EnumFile values from the integer values
	EnumFile start = fileFromIndex(startFileAsInt); //get an EnumFile instance representing the start file
	EnumFile end = fileFromIndex(endFileAsInt); //get an EnumFile instance representing the end file
	Space startSpace(startRank, start); //get the start space
	Space endSpace(endRank, end); //get the end space
	ctxt.addMove(*pieceToAdd, startSpace, endSpace); //add a move to the context
	delete pieceToAdd; //deallocate the Piece instance
	pieceToAdd = nullptr; //and zero it out
}

//end of implementation
	


