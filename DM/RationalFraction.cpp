#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с рациональными числами
BigInteger TRANS_Q_Z(RationalFraction number)
{
	BigInteger result;
	//Результат - целое, у него нет знаменателя
	if (number.denominator.size == 1)
	{//Эта звездочка явно не отсюда, и опять же в результате нет числителя
		result = number.numenator;
		result.sign = number.numenator.sign;
	}
	//Не мешало бы еще и знак числа сохранять в результате
	else
		printf("Число не может быть представлено в виде целого");
	return result;
}
