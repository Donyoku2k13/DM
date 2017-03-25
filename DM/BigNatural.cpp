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


//��������� ������������ ����� �� 10^k 
BigNatural MUL_Nk_N(BigNatural number, int tenDegree)
{
	BigNatural result;
	int r = 0;
	int size = number.size + tenDegree;

	short* resCoef = (short*)malloc(sizeof(short) * (size));

	for (int i = number.size - 1; i >= 0; i--)
		resCoef[i + tenDegree] = number.coef[i];
	for (int i = 0; i < tenDegree; i++)
		resCoef[i] = 0;
	result.size = size;
	result.coef = resCoef;
	return result;
}


/*��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������*/
BigNatural SUB_NDN_N(BigNatural first, BigNatural second, int factor)
{
	return (SUB_NN_N(first, MUL_ND_N(second, factor)));
}

/*�������� ����������� �����*/
BigNatural ADD_NN_N(BigNatural first, BigNatural second)
{
	BigNatural result;
	int i;
	int r = 0;

	if (COM_NN_D(first, second) == 1)
		return ADD_NN_N(second, first);

	short* resCoef = (short*)malloc(sizeof(short) * (first.size));

	for (i = 0; i < second.size; i++)
	{
		resCoef[i] = (first.coef[i] + second.coef[i] + r) % 10;
		r = (first.coef[i] + second.coef[i] + r) / 10;
	}

	for (i = second.size; i<first.size; i++)
	{
		resCoef[i] = (first.coef[i] + r) % 10;
		r = (first.coef[i] + r) / 10;
	}

	if (r)
	{
		resCoef = (short*)realloc(resCoef, sizeof(short) * (first.size + 1));
		result.size = first.size + 1;
		resCoef[first.size] = r;
	}
	else
		result.size = first.size;
	result.coef = resCoef;
	return result;
}