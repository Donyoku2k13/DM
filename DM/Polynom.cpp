#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с многочленами


int DEG_P_N(Polynom polynom)
{
	return polynom.degree;
}


Polynom DER_P_P(Polynom polynom)
{
	Polynom first_numenator;
	first_numenator.coef = (RationalFraction*)malloc(polynom.degree * sizeof(RationalFraction));
	first_numenator.coef->numenator.number.coef = (short*)malloc(polynom.coef->numenator.number.size * sizeof(short));
	for (int i = 0; i<polynom.coef->denominator.size; i++)
	{
		first_numenator.coef[i].numenator.number.coef[i] = polynom.coef[i].numenator.number.coef[i] * polynom.degree;
		polynom.degree--;
	}
	return first_numenator;
}