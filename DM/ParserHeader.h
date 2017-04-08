#pragma once
#include "Header.h"
#include "string.h"

#ifndef H_PARSER
#define H_PARSER


BigNatural parseToBigNatural(char* string);

BigInteger parseToBigInteger(char* string);

RationalFraction parseToRationalFraction(char* string);

Polynom parsePolynom(char* string);

void deleteSpace(char* string);

#endif
