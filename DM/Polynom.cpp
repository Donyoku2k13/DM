#include "Header.h"
#include "Output.h"
//В этом файле должны быть ТОЛЬКО реализации методов для работы с многочленами

Polynom::Polynom()
{
	coef = (RationalFraction*)malloc(sizeof(RationalFraction));
	coef[0] = RationalFraction();
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
		result.coef[i].denominator = TRANS_N_Z(polynom.coef[i].denominator).number;

		result.coef[i].numenator.number = MUL_ND_N(polynom.coef[i].numenator.number, polynom.degree - i);
		result.coef[i] = RED_Q_Q(result.coef[i]);
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
			result.coef[i] = RationalFraction();

		else
			result.coef[i] = polynom.coef[i];
	}

	result.degree = polynom.degree + xDegree;

	return result;
}


Polynom SUB_PP_P(Polynom first, Polynom second)
{
	int i, deg;
	Polynom result;
	RationalFraction current;
	if (first.degree >= second.degree)
	{
		result.coef = (RationalFraction*)malloc((first.degree + 1) * sizeof(RationalFraction));
		for (i = 0; i <= first.degree; i++)
			result.coef[i] = RationalFraction();

		result.degree = first.degree;

		deg = first.degree - second.degree;
		for (i = 0; i<deg; ++i)
			result.coef[i] = first.coef[i];

		for (i = deg; i <= first.degree; i++) 
			result.coef[i] = SUB_QQ_Q(first.coef[i], second.coef[i - deg]);

	}
	else
	{
		result.coef = (RationalFraction*)malloc((second.degree + 1) * sizeof(RationalFraction));
		for (i = 0; i <= second.degree; i++)
			result.coef[i] = RationalFraction();

		result.degree = second.degree;

		deg = second.degree - first.degree;
		for (i = 0; i<deg; ++i)
		{
			result.coef[i] = second.coef[i];
			result.coef[i].numenator = MUL_ZM_Z(result.coef[i].numenator);
		}

		for (i = deg; i <= first.degree; ++i)
			result.coef[i] = SUB_QQ_Q(first.coef[i - deg], second.coef[i]);
	}

	i = 0;
	while (i < result.degree  && !NZER_N_B(result.coef[i].numenator.number))
	{
		i++;
	}

	if (i != 0)
	{
		for (int j = 0; j <= result.degree - i; j++)
		{
			result.coef[j] = result.coef[j + i];
		}

		result.coef = (RationalFraction*)realloc(result.coef, (result.degree + 1 - i) * sizeof(RationalFraction));
		result.degree -= i;
	}

	return result;
}


Polynom ADD_PP_P(Polynom first, Polynom second)
{
	int i, deg;
	Polynom result;
	RationalFraction current;
	if (first.degree >= second.degree)
	{
		result.coef = (RationalFraction*)malloc((first.degree + 1) * sizeof(RationalFraction));
		for (i = 0; i <= first.degree; i++)
			result.coef[i] = RationalFraction();

		result.degree = first.degree;

		deg = first.degree - second.degree;
		for (i = 0; i<deg; ++i)
			result.coef[i] = first.coef[i];

		for (i = deg; i <= first.degree; i++)
			result.coef[i] = ADD_QQ_Q(first.coef[i], second.coef[i - deg]);

	}
	else
	{
		result.coef = (RationalFraction*)malloc((second.degree + 1) * sizeof(RationalFraction));
		for (i = 0; i <= second.degree; i++)
			result.coef[i] = RationalFraction();

		result.degree = second.degree;

		deg = second.degree - first.degree;
		for (i = 0; i<deg; ++i)
		{
			result.coef[i] = second.coef[i];
			result.coef[i].numenator = MUL_ZM_Z(result.coef[i].numenator);
		}

		for (i = deg; i <= first.degree; ++i)
			result.coef[i] = ADD_QQ_Q(first.coef[i - deg], second.coef[i]);
	}

	i = 0;
	while (i < result.degree && !NZER_N_B(result.coef[i].numenator.number))
	{
		i++;
	}

	if (i != 0)
	{
		for (int j = 0; j <= result.degree - i; j++)
		{
			result.coef[j] = result.coef[j + i];
		}

		result.coef = (RationalFraction*)realloc(result.coef, (result.degree + 1 - i) * sizeof(RationalFraction));
		result.degree -= i;
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
	int j = 0 , i = 0;

	if (polynom1.degree < polynom2.degree)
	{
		result = Polynom();
		return result;
	}

	else
	{
		result.degree = polynom1.degree - polynom2.degree;
		result.coef = (RationalFraction*)malloc((result.degree  + 1)* sizeof(RationalFraction));
		for (i = result.degree; i >= 0; i--)
		{
			result.coef[j] = DIV_QQ_Q(LED_P_Q(polynom1), LED_P_Q(polynom2));
			prom = MUL_PQ_P(polynom2, result.coef[j]);
			prom = MUL_Pxk_P(prom, i);
			if (prom.degree <= polynom1.degree)
				polynom1 = SUB_PP_P(polynom1, prom);
			else

				result.coef[j] = RationalFraction();
			j++;
		}
	}

	i = 0;
	while (i < result.degree && !NZER_N_B(result.coef[i].numenator.number))
	{
		i++;
	}

	if (i != 0)
	{
		for (int j = 0; j <= result.degree - i; j++)
		{
			result.coef[j] = result.coef[j + i];
		}

		result.coef = (RationalFraction*)realloc(result.coef, (result.degree + 1 - i) * sizeof(RationalFraction));
		result.degree -= i;
	}

	return result;
}

Polynom MOD_PP_P(Polynom polynom1, Polynom polynom2)
{
	Polynom result;
	result = DIV_PP_P(polynom1, polynom2);
	result = MUL_PP_P(result, polynom2);
	result = SUB_PP_P(polynom1, result);
	return result;
}

//Это должно работать, но не работает, проблему найти не могу
Polynom NMR_P_P(Polynom polynom)
{
	Polynom result;
	Polynom nod;
	Polynom der = DER_P_P(polynom);

	nod = GCF_PP_P(der, polynom);
	result = DIV_PP_P(polynom, nod);
	return result;
}

Polynom GCF_PP_P(Polynom first, Polynom second)
{
	Polynom ost;


	while (DEG_P_N(second) != 0 || NZER_N_B(TRANS_Z_N(second.coef[0].numenator)))
	{
		ost = MOD_PP_P(first, second);
		first = second;
		second = ost;
	}

	return first;
}


/*Умножение многочленов*/
Polynom MUL_PP_P(Polynom first, Polynom second)
{
	int k;

	Polynom result;
	int degree = first.degree + second.degree;

	RationalFraction copy;

	result.degree = degree;
	result.coef = (RationalFraction*)malloc((degree + 1)* sizeof(RationalFraction));
	for (int i = 0; i <= result.degree; i++)
		result.coef[i] = RationalFraction();

	for (int i = 0; i <= degree; i++)
	{
		for (int j = 0; j <= first.degree; j++)
		{
			k = degree - i - j;
			if (k < 0) break;

			if (k <= second.degree && j <= first.degree)
			{
				copy = result.coef[i];
				result.coef[i] = ADD_QQ_Q(copy, MUL_QQ_Q(first.coef[first.degree - j], second.coef[second.degree - k]));
				
			}
		}
	}


	return result;
}


/*Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей*/
Polynom FAC_P_Q(Polynom polynom)
{
	BigNatural NOD;
	BigNatural NOK;
	RationalFraction NN;

	NOD = TRANS_Z_N(polynom.coef[0].numenator);
	NOK = polynom.coef[0].denominator;

	for (int i = 0; i <= polynom.degree; i++)
	{
		NOD = GCF_NN_N(NOD, TRANS_Z_N(polynom.coef[i].numenator));
		NOK = LCM_NN_N(NOK, polynom.coef[i].denominator);
	}
	NN.numenator = TRANS_N_Z(NOK);
	NN.denominator = NOD;

	return MUL_PQ_P(polynom, NN);
}