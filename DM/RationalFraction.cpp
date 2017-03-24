#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������� �������

RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second);
DM_Q ADD_QQ_Q(DM_Q q1, DM_Q q2)
{
	RationalFraction res; // �������������� �����
	res.numenator = ADD_ZZ_Z(MUL_ZZ_Z(second.denominator, q1.a), MUL_ZZ_Z(q1.b, q2.a)); // ����������� ���������
	res.denominator = MUL_ZZ_Z(q1.b, q2.b);                                 // ����������� ����� ����������� 
	return res;
}
