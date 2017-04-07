#pragma once
#include "Header.h"
#include "ParserHeader.h"


BigNatural getBigNatural();

BigInteger getBigInteger();

RationalFraction getRationalFraction();

BigNatural getBigNatural(char* message, char* errMessage);

BigInteger getBigInteger(char* message, char* errMessage);

RationalFraction getRationalFraction(char* message, char* errMessage);



Polynom getPolynom();

char* getString();