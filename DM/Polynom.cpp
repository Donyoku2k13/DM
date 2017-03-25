#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с многочленами


int DEG_P_N(Polynom polynom)
{
	return polynom.degree;
}


Polynom DER_P_P(Polynom polynom)
{
	Polynom result;


	result.degree = polynom.degree - 1;
	result.coef = (RationalFraction*)malloc(polynom.degree * sizeof(RationalFraction));

	for (int i = 0; i < polynom.degree; i++)
	{
		result.coef[i].numenator.number = MUL_ND_N(polynom.coef[i].numenator.number, polynom.degree - i);
		result.coef[i].denominator = polynom.coef[i].denominator;
		result.coef[i] = RED_Q_Q(result.coef[i]);
	}

	return result;
}

RationalFraction LED_P_Q(Polynom polynom)
{
	return polynom.coef[0];
}