#include "Header.h"


void freePolynom(Polynom polynom)
{
	for (int i = 0; i <= polynom.degree; i++)
		freeRFraction(polynom.coef[i]);
	if (polynom.coef)
		free(polynom.coef);
}

void freeRFraction(RationalFraction number)
{
	freeBigInteger(number.numenator);
	freeBigNatural(number.denominator);
}

void freeBigInteger(BigInteger number)
{
	freeBigNatural(number.number);
}

void freeBigNatural(BigNatural number)
{
	if (number.coef)
		free(number.coef);
}