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


RationalFraction TRANS_Z_Q(BigInteger number)
{
	RationalFraction rezult;

	rezult.numenator = number;
	rezult.denominator.coef =  (short*)malloc(sizeof(short) * (1));
	rezult.denominator.coef[0] = 1;
	rezult.denominator.size = 1;
	return rezult;
}