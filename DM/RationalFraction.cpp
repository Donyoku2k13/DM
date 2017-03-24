#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������� �������



RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction result; 
	BigNatural nokfirst, noksecond; // ���, �������� �� �����������(��� ������?) 
	BigInteger nok1, nok2;//���, ���� ���������� ����� �������� ������ �������� �������������� ����� � ������� ��������� �������� �����)

	nokfirst = DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (first.denominator));
	noksecond = DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (second.denominator));
	nok1.number = nokfirst;
	nok2.number = noksecond;
	result.numenator = ADD_ZZ_Z(MUL_ZZ_Z(nok1, first.numenator), MUL_ZZ_Z(nok2, second.numenator)); // ����������� ���������
	result.denominator = LCM_NN_N(first.denominator, second.denominator); // ����������� ����� ����������� 
	return result;
}



