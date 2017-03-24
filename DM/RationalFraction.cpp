#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с рациональными числами
BigInteger TRANS_Q_Z(RationalFraction number)
{
	BigInteger result;

	if (number.denominator.size == 1 && number.denominator.coef[0]==1)
	{
		result = number.numenator;
		result.sign = number.numenator.sign;
	}

	else
		printf("Число не может быть представлено в виде целого");
	return result;
}
