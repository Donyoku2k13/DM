#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������� �������
BigInteger TRANS_Q_Z(RationalFraction number)
{
	BigInteger result;

	if (number.denominator.size == 1 && number.denominator.coef[0]==1)
	{
		result = number.numenator;
		result.sign = number.numenator.sign;
	}

	else
		printf("����� �� ����� ���� ������������ � ���� ������");
	return result;
}
