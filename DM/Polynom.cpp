#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������


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
		result.coef[i].numenator.number = MUL_ND_N(polynom.coef[i].numenator.number, polynom.degree - i);
	}

	return result;
}