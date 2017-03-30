#ifndef H_HEADER
#define H_HEADER

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 
enum Sign //���� ������ �����
{
	plus,
	minus
};

struct BigNatural //����������� ������� �����
{

	short *coef = nullptr;	//������ �������������
	int size;		//������ ������� (����� ������� �������)
	int BASE = 10;

	BigNatural();
	~BigNatural();
	BigNatural operator=(BigNatural & bN);
	BigNatural(const BigNatural & bN);
	BigNatural(int number);
};

struct BigInteger	//������� ����� �����
{
	Sign sign;			//���� �����
	BigNatural number;	//����� 

	BigInteger();
	~BigInteger();
	BigInteger(const BigInteger & bI);
	BigInteger operator=(BigInteger & bI);
	BigInteger(int number);
};

struct RationalFraction	//������������ �����
{
	BigInteger numenator;	//���������
	BigNatural denominator;	//�����������

	RationalFraction();
	~RationalFraction();
	RationalFraction(const RationalFraction & rF);
	RationalFraction operator=(RationalFraction & rF);

};

struct Polynom	//���������
{
	int degree;			//������� ����������
	RationalFraction* coef = nullptr;		//������ �������������

	Polynom();
	~Polynom();
	Polynom(const Polynom & polynom);
	Polynom operator=(Polynom & polynom);

};

//***********************************************************************************************
//������ ��� ������ � ������������ �������

/*��������� ����������� �����: 2 - ���� ������ ������ �������, 0, ���� �����, 1 �����.*/
int COM_NN_D(BigNatural first, BigNatural second); 

/*�������� �� ����: ���� ����� �� ����� ����, �� ��� ����� ����*/
bool NZER_N_B(BigNatural number);

/*���������� 1 � ������������ �����*/
BigNatural ADD_1N_N(BigNatural number);

/*�������� ����������� �����*/
BigNatural ADD_NN_N(BigNatural first, BigNatural second);

/*��������� �� ������� �������� ������������ ����� ������� �������� ��� �������*/
BigNatural SUB_NN_N(BigNatural first, BigNatural second);

/*��������� ������������ ����� �� �����*/
BigNatural MUL_ND_N(BigNatural number, int factor);

/*	
��������� ������������ ����� �� 10^k*/
BigNatural MUL_Nk_N(BigNatural number, int tenDegree);

/*��������� ����������� �����*/
BigNatural MUL_NN_N(BigNatural first, BigNatural second);

/*��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������*/
BigNatural SUB_NDN_N(BigNatural first, BigNatural second, int factor);

/*���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k, ��� k - ����� ������� ���� ����� (����� ��������� � ����)*/
int DIV_NN_Dk(BigNatural first, BigNatural second, int tenDegree);

/*������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)*/
BigNatural DIV_NN_N(BigNatural first, BigNatural second);

/*������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)*/
BigNatural MOD_NN_N(BigNatural first, BigNatural second);

/*��� ����������� �����*/
BigNatural GCF_NN_N(BigNatural first, BigNatural second);

/*��� ����������� �����*/
BigNatural LCM_NN_N(BigNatural first, BigNatural second);


//***********************************************************************************************
//������ ��� ������ � ������ �������


/*���������� �������� �����, ��������� - �����������*/
BigNatural ABS_Z_N(BigInteger number);

/*����������� ��������������� ����� (2 - �������������, 0 � ������ ����, 1 - �������������)*/
int POZ_Z_D(BigInteger number);

/*��������� ������ �� (-1)*/
BigInteger MUL_ZM_Z(BigInteger number);

/*�������������� ������������ � �����*/
BigInteger TRANS_N_Z(BigNatural number);

/*�������������� ������ ���������������� � �����������*/
BigNatural TRANS_Z_N(BigInteger number);

/*�������� ����� �����*/
BigInteger ADD_ZZ_Z(BigInteger first, BigInteger second);

/*��������� ����� �����*/
BigInteger SUB_ZZ_Z(BigInteger first, BigInteger second);

/*��������� ����� �����*/
BigInteger MUL_ZZ_Z(BigInteger first, BigInteger second);

/*������� �� ������� �������� ������ ����� �� �������
��� ������ ����������� � �������� (�������� ������� �� ����)*/
BigInteger DIV_ZZ_Z(BigInteger first, BigNatural second);

/*������� �� ������� �������� ������ ����� �� ������� ��� 
������ ����������� � �������� (�������� ������� �� ����)*/
BigInteger MOD_ZZ_Z(BigInteger first, BigNatural second);


//***********************************************************************************************
//������ ��� ������ � ������������� �������


/*���������� �����*/
RationalFraction RED_Q_Q(RationalFraction number);

/*�������� �� �����, ���� ������������ ����� �������� �����,
�� ���, ����� ����*/
bool INT_Q_B(RationalFraction number);

/*�������������� ������ � �������*/
RationalFraction TRANS_Z_Q(BigInteger number);

/*�������������� �������� � ����� 
(���� ����������� ����� 1)*/
BigInteger TRANS_Q_Z(RationalFraction number);

/*�������� ������*/
RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second);

/*��������� ������*/
RationalFraction SUB_QQ_Q(RationalFraction first, RationalFraction second);

/*��������� ������*/
RationalFraction MUL_QQ_Q(RationalFraction first, RationalFraction second);

/*������� ������ (�������� ������� �� ����)*/
RationalFraction DIV_QQ_Q(RationalFraction first, RationalFraction second);


//***********************************************************************************************
//������ ��� ������ � ������������

/*�������� �����������*/
Polynom ADD_PP_P(Polynom first, Polynom second);

/*��������� �����������*/
Polynom SUB_PP_P(Polynom first, Polynom second);

/*��������� ���������� �� ������������ �����*/
Polynom MUL_PQ_P(Polynom polynom, RationalFraction factor);

/*��������� ���������� �� x^k*/
Polynom MUL_Pxk_P(Polynom polynom, int xDegree);

/*������� ����������� ����������*/
RationalFraction LED_P_Q(Polynom polynom);

/*������� ����������*/
int DEG_P_N(Polynom polynom);

/*��������� �� ���������� ��� ������������ ������������� � ��� ����������*/
Polynom FAC_P_Q(Polynom polynom);

/*��������� �����������*/
Polynom MUL_PP_P(Polynom first, Polynom second);

/*������� �� ������� ���������� �� ��������� ��� ������� � ��������*/
Polynom DIV_PP_P(Polynom first, Polynom second);

/*������� �� ������� ���������� �� ��������� ��� ������� � ��������*/
Polynom MOD_PP_P(Polynom first, Polynom second);

/*��� �����������*/
Polynom GCF_PP_P(Polynom first, Polynom second);

/*����������� ����������*/
Polynom DER_P_P(Polynom polynom);

/*�������������� ���������� � ������� ����� � �������*/
Polynom NMR_P_P(Polynom polynom);


#endif