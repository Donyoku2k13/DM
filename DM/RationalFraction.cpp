#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������� �������

RationalFraction TRANS_Z_Q(BigInteger number)
{
	RationalFraction rezult;

	(short*)malloc(sizeof(short) * (1));
	rezult.numenator = number;
	rezult.denominator.coef = { (short*)malloc(sizeof(short) * (1)) };
	rezult.denominator.size = 1;
	return rezult;
}

