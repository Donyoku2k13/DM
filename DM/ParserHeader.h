#pragma once
#include "Header.h"
#include "string.h"

#ifndef H_PARSER
#define H_PARSER


BigNatural parseToBigNatural(char* string);

BigInteger parseToBigInteger(char* string);

char* partArrayCopy(char* string, int index);

#endif
