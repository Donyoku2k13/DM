#include "Header.h"

/*�������� �����������*/
Polynom ADD_PP_P(Polynom first, Polynom second) {
	return first;
}

/*��������� �����������*/
Polynom SUB_PP_P(Polynom first, Polynom second)
{
	return first;
}

/*��������� ���������� �� ������������ �����*/
Polynom MUL_PQ_P(Polynom polynom, RationalFraction factor)
{
	return polynom;
}

/*��������� ���������� �� x^k*/
Polynom MUL_Pxk_P(Polynom polynom, int xDegree)
{
	return polynom;
}


/*��������� �� ���������� ��� ������������ ������������� � ��� ����������*/
Polynom FAC_P_Q(Polynom polynom)
{
	return polynom;
}

/*��������� �����������*/
Polynom MUL_PP_P(Polynom first, Polynom second)
{
	return first;
}

/*������� �� ������� ���������� �� ��������� ��� ������� � ��������*/
Polynom DIV_PP_P(Polynom first, Polynom second)
{
	return first;
}

/*������� �� ������� ���������� �� ��������� ��� ������� � ��������*/
Polynom MOD_PP_P(Polynom first, Polynom second)
{
	return first;
}

/*��� �����������*/
Polynom GCF_PP_P(Polynom first, Polynom second)
{
	return first;
}


/*�������������� ���������� � ������� ����� � �������*/
Polynom NMR_P_P(Polynom polynom)
{
	return polynom;
}


/*���������� �����*/
RationalFraction RED_Q_Q(RationalFraction number)
{
	return number;
}




/*����������� ��������������� ����� (2 - �������������, 0 � ������ ����, 1 - �������������)*/
int POZ_Z_D(BigInteger number)
{
	return 0;
}


//������ ��� ������ � ������������ �������

/*��������� ����������� �����: 2 - ���� ������ ������ �������, 0, ���� �����, 1 �����.*/
int COM_NN_D(BigNatural first, BigNatural second)
{
	return 0;
}



/*


/*��������� ����������� �����*/
BigNatural MUL_NN_N(BigNatural first, BigNatural second)
{
	return first;
}



/*���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k, ��� k - ����� ������� ���� ����� (����� ��������� � ����)*/
int DIV_NN_Dk(BigNatural first, BigNatural second, int tenDegree)
{
	return 1;
}

/*������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)*/
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
	return first;
}

/*������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)*/
BigNatural MOD_NN_N(BigNatural first, BigNatural second)
{
	return first;
}



/*��� ����������� �����*/
BigNatural LCM_NN_N(BigNatural first, BigNatural second)
{
	return first;
}