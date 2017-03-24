#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������� �������

RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second);
{
	RationalFraction result; // 
	BigInteger nokfirst, noksecond; // ���, �������� �� �����������(��� ������?)

	nokfirst = LCM_NN_N(first.denuminator, second.denuminator) / (first.denominator);
	noksecond = LCM_NN_N(first.denuminator, second.denuminator) / (second.denominator);
	result.numenator = ADD_ZZ_Z(MUL_ZZ_Z((nokfirst, first.numinator), MUL_ZZ_Z(noksecond, second.numenator)); // ����������� ���������
	result.denominator = LCM_NN_N(first.denuminator, second.denuminator);                                 // ����������� ����� ����������� 
	return result;
}



