#include "Header.h"
#include "Output.h"
//В этом файле должны быть ТОЛЬКО реализации методов для работы с многочленами

Polynom::Polynom()
{
	coef = new RationalFraction[1];
	coef[0] = RationalFraction();
	degree = 0;
}

Polynom::~Polynom()
{
	delete[] coef;
}

Polynom::Polynom(const Polynom & polynom)
{
	degree = polynom.degree;
	if (coef)
		delete[] coef;
	coef = new RationalFraction[degree + 1]; 
	for (int i = 0; i <= degree; i++)
	{
		coef[i] = RationalFraction(polynom.coef[i]);
	}

}


Polynom::Polynom(RationalFraction* coef, int degree)
{
	this->degree = degree;
	this->coef = new RationalFraction[degree + 1];
	for (int i = 0; i <= degree; i++)
		this->coef[i] = coef[i];
}

Polynom Polynom::operator=(Polynom & polynom)
{
	degree = polynom.degree;
	delete[] coef;
	coef = new RationalFraction[degree + 1];
	for (int i = 0; i <= degree; i++)
		coef[i] = RationalFraction(polynom.coef[i]);

	return *this;
}




int DEG_P_N(Polynom polynom)
{
	return polynom.degree;
}


//***************************************************************************************
//Производная многочлена
//Жмойда 6307
Polynom DER_P_P(Polynom polynom)
{
	Polynom result;
	RationalFraction* coef = new RationalFraction[polynom.degree];

	for (int i = 0; i < polynom.degree; i++)
	{

		coef[i].denominator = polynom.coef[i].denominator;
		coef[i].numenator = MUL_ZZ_Z(polynom.coef[i].numenator, BigInteger(polynom.degree - i));
		coef[i] = RED_Q_Q(coef[i]);
	}

	result = Polynom(coef, polynom.degree - 1);


	delete[] coef;

	return result;
}


//***************************************************************************************
//Старший коэффициент многочлена
//Жмойда 6307
RationalFraction LED_P_Q(Polynom polynom)
{
	return polynom.coef[0];
}


//***************************************************************************************
//Умножение многочлена на x^k
//Тихов 6307
Polynom MUL_Pxk_P(Polynom polynom, int xDegree)
{
	Polynom result;
	int i, j;
	RationalFraction* coef = new RationalFraction[polynom.degree + xDegree + 1];

	for (i = 0; i <= polynom.degree; ++i)
		coef[i] = polynom.coef[i];
	
	result = Polynom(coef, polynom.degree + xDegree);

	delete[] coef;

	return result;
}


//***************************************************************************************
//Вычитание многочленов
//Тихов 6307
Polynom SUB_PP_P(Polynom first, Polynom second)
{
	int i, deg;
	Polynom result;
	RationalFraction current;
	RationalFraction* coef;

	if (first.degree < second.degree)
	{
		result = SUB_PP_P(second, first);

		for (int i = 0; i <= result.degree; i++)
			result.coef[i].numenator = MUL_ZM_Z(result.coef[i].numenator);

		return result;
	}


	coef = new RationalFraction[first.degree + 1];

	result.degree = first.degree;

	deg = first.degree - second.degree;
	for (i = 0; i<deg; ++i)
		coef[i] = first.coef[i];

	for (i = deg; i <= first.degree; i++)
		coef[i] = SUB_QQ_Q(first.coef[i], second.coef[i - deg]);

	//Убираем ведущие нули
	i = 0;
	while (i < result.degree  && !NZER_N_B(coef[i].numenator.number))
	{
		i++;
	}

	if (i != 0)
	{
		for (int j = 0; j <= result.degree - i; j++)
		{
			coef[j] = coef[j + i];
		}

		coef = resize(coef, result.degree + 1 - i, result.degree + 1);
		result.degree -= i;
	}

	result = Polynom(coef, result.degree);


	delete[] coef;

	return result;
}


//***************************************************************************************
//Сложение многочленов
//Жмойда 6307
Polynom ADD_PP_P(Polynom first, Polynom second)
{
	int i, deg;
	Polynom result;
	RationalFraction current;
	RationalFraction* coef;

	if (first.degree < second.degree)
		return ADD_PP_P(second, first);;
	

	coef = new RationalFraction[first.degree + 1];

	result.degree = first.degree;

	deg = first.degree - second.degree;
	for (i = 0; i<deg; ++i)
		coef[i] = first.coef[i];

	for (i = deg; i <= first.degree; i++)
		coef[i] = ADD_QQ_Q(first.coef[i], second.coef[i - deg]);

	//Убираем ведущие нули

	i = 0;
	while (i < result.degree && !NZER_N_B(coef[i].numenator.number))
		i++;
	

	if (i != 0)
	{
		for (int j = 0; j <= result.degree - i; j++)
		{
			coef[j] = coef[j + i];
		}

		coef = resize(coef, result.degree + 1 - i, result.degree + 1);

		result.degree -= i;
	}

	result = Polynom(coef, result.degree);

	delete[] coef;

	return result;
}


//***************************************************************************************
//Умножение многочлена на рациональное число
//Тихов 6307
Polynom MUL_PQ_P(Polynom polynom, RationalFraction factor)
{
	int i;
	Polynom result;

	RationalFraction* coef = new RationalFraction[polynom.degree + 1];
	for (i = polynom.degree; i >= 0; --i)
	{
		coef[i] = MUL_QQ_Q(polynom.coef[i], factor);
	}
	result = Polynom(coef, polynom.degree);

	delete[] coef;

	return result;
}


//***************************************************************************************
//Частное от деления многочлена на многочлен при делении с остатком
//Васин 6307
Polynom DIV_PP_P(Polynom polynom1, Polynom polynom2)
{
	Polynom
		prom,
		result;
	int j = 0 , i = 0;
	RationalFraction* coef = nullptr;

	if (polynom1.degree < polynom2.degree)
		return Polynom();
	else
	{
		result.degree = polynom1.degree - polynom2.degree;
		coef = new RationalFraction[result.degree + 1];

		for (i = result.degree; i >= 0; i--)
		{
			coef[j] = DIV_QQ_Q(LED_P_Q(polynom1), LED_P_Q(polynom2));
			prom = MUL_PQ_P(polynom2, coef[j]);
			prom = MUL_Pxk_P(prom, i);
			if (prom.degree <= polynom1.degree)
				polynom1 = SUB_PP_P(polynom1, prom);

			j++;
		}
	}

	//Убираем ведущие нули
	i = 0;
	while (i < result.degree && !NZER_N_B(coef[i].numenator.number))
	{
		i++;
	}

	if (i != 0)
	{
		for (int j = 0; j <= result.degree - i; j++)
		{
			coef[j] = coef[j + i];
		}

		coef = resize(result.coef, result.degree + 1 - i, result.degree + 1);
		result.degree -= i;
	}

	result = Polynom(coef, result.degree);

	delete[] coef;

	return result;
}


//***************************************************************************************
//Остаток от деления многочлена на многочлен при делении с остатком
//Васин 6307
Polynom MOD_PP_P(Polynom polynom1, Polynom polynom2)
{
	Polynom result;
	result = DIV_PP_P(polynom1, polynom2);
	result = MUL_PP_P(result, polynom2);
	result = SUB_PP_P(polynom1, result);
	return result;
}


//***************************************************************************************
//Преобразование многочлена — кратные корни в простые
//Васин 6307
Polynom NMR_P_P(Polynom polynom)
{
	Polynom result;
	Polynom nod;
	Polynom der = DER_P_P(polynom);

	nod = GCF_PP_P(polynom, der);
	result = DIV_PP_P(polynom, nod);

	result = FAC_P_Q(result);

	return result;
}


//***************************************************************************************
//НОД многочленов
//Инкина 6307
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


//***************************************************************************************
//Умножение многочленов
//Тихов 6307
Polynom MUL_PP_P(Polynom first, Polynom second)
{
	Polynom result;

	if (DEG_P_N(first) < DEG_P_N(second))
		return MUL_PP_P(second, first);

	for (int i = 0; i <= second.degree; i++)
		result = ADD_PP_P(result, MUL_Pxk_P(MUL_PQ_P(first, second.coef[i]), second.degree - i));
	

	return result;
}


//***************************************************************************************
//Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
//Васин 6307
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


RationalFraction* resize(RationalFraction* arr, int size, int oldSize)
{
	RationalFraction* nArr = new RationalFraction[max(size, 1)];

	for (int i = 0 ; i < min(size, oldSize); i++)
		nArr[i] = arr[i];
	
	if (arr)
		delete[] arr;

	return nArr;
}