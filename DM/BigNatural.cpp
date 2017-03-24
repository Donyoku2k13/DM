#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������ �������


BigNatural SUB_NN_N(BigNatural first, BigNatural second)
{
	//���� ������ ������ �������, �� �������� ��������
	if (COM_NN_D(first, second) == 1)
		return SUB_NN_N(second, first);
	BigNatural result;
	int i;
	short temp; 
	short carry = 0;

	short* a = first.coef; //����������� 

	short* b = second.coef; //����������

	//��������� �� ������ �������, � ����� ����� � ���������
	short* resCoef = (short*)malloc(sizeof(short) * first.size);


	for (int i = 0; i < second.size; i++)
	{
		temp = a[i] - b[i] + carry;
		if (temp < 0)
		{
			resCoef[i] = temp + first.BASE;
			carry = -1;
		}
		else
		{
			resCoef[i] = temp;
			carry = 0;
		}
	}


	for (i = second.size; i<first.size; i++) {
		temp = a[i] + carry;
		if (temp < 0) {
			resCoef[i] = temp + first.BASE;
			carry = -1;
		}
		else {
			resCoef[i] = temp;
			carry = 0;
		}
	}

	//���������� ��������� ������� �����
	i = first.size - 1;
	while ((i>0) && (resCoef[i] == 0)) i--;
	resCoef = (short*)realloc(resCoef, sizeof(short) * (i + 1));
	

	result.size = i + 1;
	result.coef = resCoef;

	return result;
}


//�������� �� ����
bool NZER_N_B(BigNatural number)
{
	int i;
	for (i = 0; i < number.size; i++)
	{
		if (number.coef[i] != 0) // ���� ���� �� ���� ����� �� ����� ����, �� ���������� true
		{
			return true;
		}
	}
	return false; 
}

//���������� ������� � �������� �����
BigNatural ADD_1N_N(BigNatural number)
{
	int counter = 1;
	BigNatural result;
	result = number;
	if (result.coef[result.size - 1] != 9) // ���� ��������� ����� �� ����� ������, ���������� �������
	{
		result.coef[result.size - 1]++;
	}
	else
	{
		while (result.coef[result.size - counter] == 9 && counter != result.size) // ���� ��������� ����� �� ����� 9, �� ���� ������ ����� �� ������ 9, ���������� � ��� �������, � ���� ���������� ����������� 0
		{
			result.coef[result.size - counter] = 0;
			counter++;
		}
		if (counter == result.size) // ���� ��� ����� ����� 9, ����������� ������ �� �������, ������ ����� ����������� 1, ���� ��������� ����������� 0
		{
			result.coef = (short*) realloc(result.coef, sizeof(short)* (result.size + 1));
			result.coef[0] = 1;
			for (int i = 1; i < result.size; i++)
			{
				result.coef[i] = 0;
			}
		}
		else
		{
			result.coef[result.size - counter]++;
		}
	}
	return result;
}



