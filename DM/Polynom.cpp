#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с многочленами

Polynom::Polynom()
{
	coef = (RationalFraction*)malloc(sizeof(RationalFraction));
	degree = 0;
}

Polynom::~Polynom()
{
	free(coef);
}

Polynom::Polynom(const Polynom & polynom)
{
	degree = polynom.degree;
	coef = (RationalFraction*)malloc(sizeof(RationalFraction)*(degree + 1));
	for (int i = 0; i <= degree; i++)
	{
		coef[i] = RationalFraction(polynom.coef[i]);
	}

}

Polynom Polynom::operator=(Polynom & polynom)
{
	degree = polynom.degree;
	coef = (RationalFraction*)malloc(sizeof(RationalFraction)*(degree + 1));
	for (int i = 0; i <= degree; i++)
	{
		coef[i] = RationalFraction(polynom.coef[i]);
	}

	return *this;
}

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
		//Для того, чтобы не было проблем с памятью
		result.coef[i].denominator = TRANS_N_Z(polynom.coef[i].denominator).number;

		result.coef[i].numenator.number = MUL_ND_N(polynom.coef[i].numenator.number, polynom.degree - i);
		//result.coef[i] = RED_Q_Q(result.coef[i]);
	}

	return result;
}

RationalFraction LED_P_Q(Polynom polynom)
{
	return polynom.coef[0];
}

Polynom MUL_Pxk_P(Polynom polynom, int xDegree)
{
	Polynom result;
	int i, j;
	result.coef = (RationalFraction*)malloc((polynom.degree + xDegree + 1) * sizeof(RationalFraction));

	for (i = 0; i <= polynom.degree + xDegree; ++i)
	{
		if (i > polynom.degree)
		{
			result.coef[i].numenator.number.size = 1;
			result.coef[i].numenator.sign = plus;
			result.coef[i].denominator.size = 1;
			result.coef[i].numenator.number.coef = (short*)malloc(sizeof(short));
			result.coef[i].denominator.coef = (short*)malloc(sizeof(short));

			result.coef[i].numenator.number.coef[0] = 0;
			result.coef[i].denominator.coef[0] = 1;


		}
		else
		{
			result.coef[i].numenator.number.size = polynom.coef[i].numenator.number.size;
			result.coef[i].numenator.sign = polynom.coef[i].numenator.sign;
			result.coef[i].denominator.size = polynom.coef[i].denominator.size;


			result.coef[i].numenator.number = TRANS_Z_N(polynom.coef[i].numenator);
			result.coef[i].denominator = TRANS_N_Z(polynom.coef[i].denominator).number;


		}
	}

	result.degree = polynom.degree + xDegree;

	return result;
}