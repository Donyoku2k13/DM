#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������ �������

BigNatural ABS_Z_N(BigInteger number)
{
	return number.number;
}

BigInteger ADD_ZZ_Z(BigInteger first, BigInteger second)
{
	BigInteger result;
	result.sign = first.sign;
	if (first.sign == second.sign)
		result.number = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
	else
	{
		if (COM_NN_D(ABS_Z_N(first), ABS_Z_N(second)) == 2)//���������� �������� ������� ������ ���������� �������� �������
			result.number = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		else
		{
			result.number = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
			if (!NZER_N_B(result.number))
				result.sign = plus; // ���� ���� �� �������������
			else
				result = MUL_ZM_Z(result);
		}
	}
	return result;
}

BigInteger SUB_ZZ_Z(BigInteger first, BigInteger second)
{
	BigInteger result;
	result.sign = first.sign;
	if (first.sign == second.sign)//��� ����� ������ �����
	{
		if (COM_NN_D(ABS_Z_N(first), ABS_Z_N(second)) == 2)////���������� �������� ������� ������ ���������� �������� �������
			result.number = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		else
		{
			result.number = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
			if (COM_NN_D(ABS_Z_N(first), ABS_Z_N(second)) == 0)//���� ����� �����
				result.sign = plus;
			else
				result = MUL_ZM_Z(result);
		}
	}
	else //����� ������ ������
		result.number = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));

	return result;
}


BigInteger TRANS_N_Z(BigNatural number)
{
	BigInteger temp;
	temp.number.size = number.size;
	temp.sign = plus;
	temp.number.coef = (short*)malloc(number.size * sizeof(short));
	for (int i = 0; i < temp.number.size; i++)
		temp.number.coef[i] = number.coef[i];
	return temp;
}



BigInteger MUL_ZM_Z(BigInteger number)
{
	if (number.sign == plus && (number.number.coef[0] != 0 || number.number.size != 1))
		number.sign = minus;
	else
		if (number.sign == minus)
			number.sign = plus;
	return number;
}


BigNatural TRANS_Z_N(BigInteger number)
{
	BigNatural temp;
	temp.size = number.number.size;
	temp.coef = (short*)malloc(temp.size * sizeof(short));
	for (int i = 0; i < temp.size; i++)
		temp.coef[i] = number.number.coef[i];
	return temp;
}


BigInteger DIV_ZZ_Z(BigInteger first, BigNatural second)
{
	BigInteger res;
	if (second.coef[0] != 0 || second.size != 1) //���� ���������� �� ����, �� �����
	{
		res.sign = first.sign; //������� ��������� ���� ��������
		res.number = DIV_NN_N(ABS_Z_N(first), second); //����������� ����� �������
		if (POZ_Z_D(first) == 1)
			res.number = ADD_1N_N(res.number); //��� ����, ����� ������� ��� �������������
		return(res);
	}
	else
		printf("����������� ������ ���� ������� �� ����");
}