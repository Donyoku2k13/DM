#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������� �������

RationalFraction RED_Q_Q(RationalFraction number)
{
	RationalFraction result;
	result.numenator = DIV_ZZ_Z(number.numenator, TRANS_N_Z(GCF_NN_N(TRANS_Z_N(number.numenator), number.denominator)));
	result.denominator = DIV_NN_N(number.denominator, GCF_NN_N(TRANS_Z_N(number.numenator), number.denominator));
	return result;
}