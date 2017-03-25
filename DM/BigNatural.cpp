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


//������� � ��������
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
	int k = 0;
	int kM = 0;
	BigNatural res;//���������
	int a; //������ ����� �������
	short* coefReverse = nullptr;
	int current = 0;


	if (!NZER_N_B)                                       //���� �������� ����� ����
		printf("�������� ������ ���� ������ ����!");
	else
	{
		if (COM_NN_D(first, second) == 0)                    //���� ������ ����� �������
		{
			res.coef = (short*)malloc(sizeof(short));
			res.coef[0] = 1;
			res.size = 0;
			return res;                                       //���������� �������
		}
		else
			if (COM_NN_D(first, second) == 1)                 //���� ������ ������ �������
			{
				return first;                                     //���������� ����
			}
			else
				while (COM_NN_D(first, second) == 2)
				{
					coefReverse = (short*)realloc(coefReverse, sizeof(short) * (current + 1));
					k = first.size - second.size - kM;
					a = DIV_NN_Dk(first, second, k);
					if (a == 0)
						kM = 1;
					else
						kM = 0;
					coefReverse[current] = a;
					first = SUB_NDN_N(first, MUL_Nk_N(second, k), a);
					current++;

				}
	}
	res.size = current;
	res.coef = (short*)malloc(sizeof(short)*current);
	for (int i = 0; i < current; i++)
	{
		res.coef[i] = coefReverse[current - i - 1];
	}

	return res;
}


/*��������� ����������� �����: 2 - ���� ������ ������ �������, 0, ���� �����, 1 �����.*/
int COM_NN_D(BigNatural first, BigNatural second)
{
	if (first.size > second.size)
		return 2;
	else if (second.size > first.size)
		return 1;
	else
	{
		for (int i = first.size - 1; i >= 0; i--)
		{
			if (first.coef[i] > second.coef[i])
				return 2;
			else if (second.coef[i] > first.coef[i])
				return 1;
		}
	}
	return 0;
}
