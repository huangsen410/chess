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
#include "SerialContext.h"
#include "../except/InvalidSymbolException.h"

//function prototype
void addMoveToContext(SerialContext& ctxt, char piece, bool blue, int startRank, char startFile, int endRank, char endFile);

#endif
