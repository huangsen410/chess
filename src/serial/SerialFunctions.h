/*
 * SerialFunctions.h
 * Declares functions for use by the chess serializer
 * Created by Andrew Davis
 * Created on 1/17/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SERIAL_FUNC_H
#define SERIAL_FUNC_H

//includes
#include "../move/Move.h"
#include "../board/Space.h"
#include "../except/InvalidSymbolException.h"

//function prototype
Move* getMove(char piece, bool blue, int startRank, char startFile, int endRank, char endFile);

#endif
