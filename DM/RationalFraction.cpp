#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������� �������

RationalFraction::RationalFraction()
{
	numenator = BigInteger();
	denominator = BigNatural();
	denominator.coef[0] = 1;
}

RationalFraction::~RationalFraction()
{

}

RationalFraction::RationalFraction(const RationalFraction & rF)
{
	numenator = BigInteger(rF.numenator);
	denominator = BigNatural(rF.denominator);
}

RationalFraction RationalFraction::operator=(RationalFraction & rF)
{
	numenator = BigInteger(rF.numenator);
	denominator = BigNatural(rF.denominator);
	return *this;
}


//***************************************************************************************
//�������������� �������� � ����� (���� ����������� ����� 1)
//�������� 6307
BigInteger TRANS_Q_Z(RationalFraction number)
{
	return number.numenator;
}


//***************************************************************************************
//�������������� ������ � �������
//�������� 6307
RationalFraction TRANS_Z_Q(BigInteger number)
{
	RationalFraction rezult;

	rezult.numenator.sign = number.sign;
	rezult.numenator.number = TRANS_Z_N(number);

	return rezult;
}


//***************************************************************************************
//�������� ������
//�������� 6307
RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction result; 
	BigInteger nok1, nok2;

	nok1 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (first.denominator)));
	nok2 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (second.denominator)));

	result.numenator = ADD_ZZ_Z(MUL_ZZ_Z(nok1, first.numenator), MUL_ZZ_Z(nok2, second.numenator)); // ����������� ���������
	result.denominator = LCM_NN_N(first.denominator, second.denominator); // ����������� ����� ����������� 


	result = RED_Q_Q(result);

	return result;
}


//***************************************************************************************
//��������� ������
//�������� 6307
RationalFraction SUB_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction result;
	BigInteger nok1, nok2;

	nok1 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (first.denominator)));
	nok2 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (second.denominator)));

	result.numenator =  SUB_ZZ_Z(MUL_ZZ_Z(nok1, first.numenator), MUL_ZZ_Z(nok2, second.numenator));
	result.denominator = LCM_NN_N(first.denominator, second.denominator); 

	result = RED_Q_Q(result);

	return result;
}


//***************************************************************************************
//�������� �� �����, ���� ������������ ����� �������� �����, �� ���, ����� ����
//�������� 6307
bool INT_Q_B(RationalFraction number)
{
	number = RED_Q_Q(number); //��������� �����
	if (number.denominator.coef[0] == 1 && number.denominator.size == 1) //��������� ����������� �� ��������� �������
		return true;
	else
		return false;
}


//***************************************************************************************
//��������� ������
//�������� 6307
RationalFraction MUL_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction res;
	res.numenator = MUL_ZZ_Z(first.numenator, second.numenator);
	res.denominator = MUL_NN_N(first.denominator, second.denominator);

	res = RED_Q_Q(res);

	return res;
}


//***************************************************************************************
//������� ������ (�������� ������� �� ����)
//�������� 6307
RationalFraction DIV_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction res;

	if (!NZER_N_B(second.numenator.number))
	{
		printf("�� ���� ������ ������!!\n");
		return res;
	}
	res.numenator = MUL_ZZ_Z(first.numenator, TRANS_N_Z(second.denominator));
	res.denominator = MUL_NN_N(first.denominator, TRANS_Z_N(second.numenator));
	res.numenator.sign = (first.numenator.sign == second.numenator.sign) ? plus : minus;

	res = RED_Q_Q(res);

	return res;
}


//***************************************************************************************
//���������� �����
//�������� 6307
RationalFraction RED_Q_Q(RationalFraction number)
{
	RationalFraction result;

	result.numenator = TRANS_N_Z(DIV_NN_N(TRANS_Z_N(number.numenator), GCF_NN_N(TRANS_Z_N(number.numenator), number.denominator)));
	result.denominator = DIV_NN_N(number.denominator, GCF_NN_N(TRANS_Z_N(number.numenator), number.denominator));
	result.numenator.sign = number.numenator.sign;
	return result;
}

//***************************************************************************************
//�������� ���������� � ������� ������
//������� 6307
RationalFraction POW_QZ_Q(RationalFraction number, BigInteger power)
{
	RationalFraction result;
	result.numenator = POW_ZN_Z(result.numenator, power.number);
	result.denominator = POW_NN_N(result.denominator, power.number);
	if (power.sign == minus)
		result = DIV_1Q_Q(result);
	return result;
}