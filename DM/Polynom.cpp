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


Polynom SUB_PP_P(Polynom first, Polynom second)
{
	int i, deg;
	Polynom result;
	if (first.degree >= second.degree)
	{
		result.coef = (RationalFraction*)malloc((first.degree + 1) * sizeof(RationalFraction));
		result.degree = first.degree;
		deg = first.degree - second.degree;
		for (i = 0; i<deg; ++i) result.coef[i] = first.coef[i];
		for (i = deg; i <= first.degree; ++i) result.coef[i] = SUB_QQ_Q(first.coef[i], second.coef[i]);

	}
	else
	{
		result.coef = (RationalFraction*)malloc((second.degree + 1) * sizeof(RationalFraction));
		deg = second.degree - first.degree;
		for (i = 0; i<deg; ++i)
		{
			result.coef[i] = second.coef[i];
			result.coef[i].numenator = MUL_ZM_Z(result.coef[i].numenator);
		}

		for (i = deg; i <= first.degree; ++i) result.coef[i] = SUB_QQ_Q(first.coef[i], second.coef[i]);
	}

	i = 0;
	while (!NZER_N_B(result.coef[i].numenator.number)) i++;


	if (i != 0)
	{
		for (int j = 0; j <= result.degree - i; j++)
		{
			result.coef[j] = result.coef[j + i];
		}

		result.coef = (RationalFraction*)realloc(result.coef, (result.degree + 1 - i) * sizeof(RationalFraction));
	}

	return result;
}


Polynom MUL_PQ_P(Polynom polynom, RationalFraction factor)
{
	int i, j;
	Polynom result;
	result.coef = (RationalFraction*)malloc((polynom.degree + 1) * sizeof(RationalFraction));
	for (i = polynom.degree; i >= 0; --i)
	{
		result.coef[i] = MUL_QQ_Q(polynom.coef[i], factor);
	}
	result.degree = polynom.degree;
	return result;
}


Polynom DIV_PP_P(Polynom polynom1, Polynom polynom2)
{
	Polynom
		prom,
		result;
	int i = 0;

	if (polynom1.degree < polynom2.degree)
	{
		result.degree = 0;
		return result;
	}

	else
	{
		result.degree = polynom1.degree - polynom2.degree;
		result.coef = (RationalFraction*)malloc(result.degree * sizeof(RationalFraction));
		while (polynom1.degree >= polynom2.degree)
		{
			result.coef[i] = DIV_QQ_Q(polynom1.coef[i], polynom2.coef[0]);
			prom = MUL_PQ_P(polynom2, result.coef[i]);
			prom = MUL_Pxk_P(prom, polynom1.degree - polynom2.degree);
			polynom1 = SUB_PP_P(polynom1, prom);
			i++;
		}
	}
	return result;
}