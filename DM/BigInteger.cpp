#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с целыми числами
BigInteger MUL_ZZ_Z(BigInteger first, BigInteger second)
{
	BigInteger result;
	result.number = MUL_NN_N(ABS_Z_N(first), ABS_Z_N(second));
	if (first.sign == second.sign)
		result.sign = plus;
	else
		result.sign = minus;
	return result;
}