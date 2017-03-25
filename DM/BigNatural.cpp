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
	if (number.coef[0] == 0 && number.size == 1) // ���� ������ ������ ����� ���� � ������ ����� ������� ���������� false
	{
		return false;
	}
	return true; 
}


//���������� ������� � �������� �����
BigNatural ADD_1N_N(BigNatural number)
{
	int counter = 1;
	BigNatural result;
	result = number;
	if (result.coef[0] != 9) // ���� ��������� ����� �� ����� ������, ���������� �������
	{
		result.coef[0]++;
	}
	else
	{
		while (counter != result.size && result.coef[counter] == 9) // ���� ��������� ����� �� ����� 9, �� ���� ������ ����� �� ������ 9, ���������� � ��� �������, � ���� ���������� ����������� 0
		{
			result.coef[counter] = 0;
			counter++;
		}
		if (counter == result.size) // ���� ��� ����� ����� 9, ����������� ������ �� �������, ������ ����� ����������� 1
		{
			result.coef = (short*) realloc(result.coef, sizeof(short)* (result.size + 1));
			result.size++;
			result.coef[result.size-1] = 1;
		}
		else
		{
			result.coef[counter]++;
		}
	}
	return result;
}


BigNatural GCF_NN_N(BigNatural first, BigNatural second)
{
	BigNatural result;
	BigNatural ost;
	while (NZER_N_B(second))
	{
		ost = MOD_NN_N(first, second);
		first.coef = second.coef;
		first.size = second.size;
		second.coef = ost.coef;
		second.size = ost.size;
	}

	result.size = first.size;

	result.coef = (short*)malloc(first.size*sizeof(short));
	memcpy(result.coef, first.coef, first.size * sizeof(short));

	return result;
}

//��������� ������������ ����� �� 10^k 
BigNatural MUL_Nk_N(BigNatural number, int tenDegree)
{
	BigNatural result;
	int r = 0;
	int size = number.size + tenDegree;

	short* resCoef = (short*)malloc(sizeof(short) * (size));

	for (int i = 0; i < tenDegree; i++)
		resCoef[i] = 0;
	for (int i = tenDegree; i < size; i++)
		resCoef[i] = number.coef[i - tenDegree];
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


/*��������� ������������ ����� �� �����*/
BigNatural MUL_ND_N(BigNatural number, int factor)
{
	BigNatural result;
	int r = 0;

	short* resCoef = (short*)malloc(sizeof(short) * (number.size));

	for (int j = 0; j < number.size; j++)
	{
		resCoef[j] = (number.coef[j] * factor + r) % 10;
		r = (number.coef[j] * factor + r) / 10;
	}
	result.size = number.size;
	if (r) 
	{
		resCoef = (short*)realloc(resCoef, sizeof(short) * (number.size + 1));
		resCoef[result.size] = r;
		result.size++;
	}
	result.coef = resCoef;
	return result;
}


int DIV_NN_Dk(BigNatural first, BigNatural second, int tenDegree)
{
	int i = 0;
	second = MUL_Nk_N(second, tenDegree);
	if (COM_NN_D(first, second) == 1)
		return 0;

	if (COM_NN_D(first, second) == 0)
		return 1;

	do
	{
		first = SUB_NN_N(first, second);
		i++;
	}
	while (COM_NN_D(first, second) == 2);

	return i-1;
}


BigNatural LCM_NN_N(BigNatural first, BigNatural second)
{
	BigNatural result;
	BigNatural prois;
	BigNatural NOD;

	NOD = GCF_NN_N(first, second);
	prois = MUL_NN_N(first, second);
	result = DIV_NN_N(prois, NOD);
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