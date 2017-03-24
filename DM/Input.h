#pragma once
#include "Header.h"
#include "ParserHeader.h"


BigNatural getBigNatural();

BigInteger getBigInteger();

BigNatural getBigNatural(char* message, char* errMessage);

BigInteger getBigInteger(char* message, char* errMessage);

RationalFraction getRationalFraction();

Polynom getPolynom();

char* getString();