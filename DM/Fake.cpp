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

/*������� ����������� ����������*/
RationalFraction LED_P_Q(Polynom polynom)
{
	RationalFraction rf;
	return rf;
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

/*�������� �� �����, ���� ������������ ����� �������� �����,
�� ���, ����� ����*/
int INT_Q_B(RationalFraction number)
{
	return 0;
}




/*�������� ������*/
RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second)
{
	return first;
}

/*��������� ������*/
RationalFraction SUB_QQ_Q(RationalFraction first, RationalFraction second)
{
	return first;
}

/*��������� ������*/
RationalFraction MUL_QQ_Q(RationalFraction first, RationalFraction second)
{
	return first;
}

/*������� ������ (�������� ������� �� ����)*/
RationalFraction DIV_QQ_Q(RationalFraction first, RationalFraction second)
{
	return first;
}

/*���������� �������� �����, ��������� - �����������*/
BigNatural ABS_Z_N(BigInteger number);

/*����������� ��������������� ����� (2 - �������������, 0 � ������ ����, 1 - �������������)*/
int POZ_Z_D(BigInteger number)
{
	return 0;
}








/*��������� ����� �����*/
BigInteger MUL_ZZ_Z(BigInteger first, BigInteger second)
{
	return first;
}

/*������� �� ������� �������� ������ ����� �� �������
��� ������ ����������� � �������� (�������� ������� �� ����)*/
BigInteger DIV_ZZ_Z(BigInteger first, BigInteger second)
{
	return first;
}

/*������� �� ������� �������� ������ ����� �� ������� ���
������ ����������� � �������� (�������� ������� �� ����)*/
BigInteger MOD_ZZ_Z(BigInteger first, BigInteger second)
{
	return first;
}


//������ ��� ������ � ������������ �������

/*��������� ����������� �����: 2 - ���� ������ ������ �������, 0, ���� �����, 1 �����.*/
int COM_NN_D(BigNatural first, BigNatural second)
{
	return 0;
}

/*�������� �� ����: ���� ����� �� ����� ����, �� ��� ����� ����*/
bool NZER_N_B(BigNatural number)
{
	return true;
}

/*���������� 1 � ������������ �����*/
BigNatural ADD_1N_N(BigNatural number)
{
	return number;
}

/*�������� ����������� �����*/
BigNatural ADD_NN_N(BigNatural first, BigNatural second)
{
	return first;
}


/*��������� ������������ ����� �� �����*/
BigNatural MUL_ND_N(BigNatural number, int factor)
{
	return number;
}

/*
��������� ������������ ����� �� 10^k*/
BigNatural MUL_Nk_N(BigNatural number, int tenDegree)
{
	return number;
}

/*��������� ����������� �����*/
BigNatural MUL_NN_N(BigNatural first, BigNatural second)
{
	return first;
}

/*��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������*/
BigNatural SUB_NDN_N(BigNatural first, BigNatural second, int factor)
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
BigNatural GCF_NN_N(BigNatural first, BigNatural second)
{
	return first;
}

/*��� ����������� �����*/
BigNatural LCM_NN_N(BigNatural first, BigNatural second)
{
	return first;
}