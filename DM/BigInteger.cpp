#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������ �������
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