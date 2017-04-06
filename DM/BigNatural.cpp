#include "Header.h"
#include "Output.h"
//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������ �������

//����������� - ��������� �������� - 0
BigNatural::BigNatural()
{

	size = 1;
	coef = (short*)malloc(sizeof(short));
	coef[0] = 0;

}


BigNatural::BigNatural(const BigNatural & bN)
{
	size = bN.size;
	coef = (short*)malloc(sizeof(short) * size);
	memcpy(coef, bN.coef, size * sizeof(short));

}

BigNatural::~BigNatural()
{
	free(coef);
}

BigNatural BigNatural::operator=(BigNatural & bN)
{
	size = bN.size;
	coef = (short*)malloc(sizeof(short) * size);
	memcpy(coef, bN.coef, size * sizeof(short));

	return *this;
}

BigNatural::BigNatural(int number)
{
	size = 0;
	while (number != 0)
	{
		coef = (short*)realloc(coef, (size + 1) * sizeof(short));
		coef[size] = number % 10;
		number /= 10;
		size++;
	}
}

//***************************************************************************************
//��������� �� ������� �������� ������������ ����� ������� �������� ��� �������
//����� �.�. 6307
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


//***************************************************************************************
//�������� �� ����
//������� �.�. 6307
bool NZER_N_B(BigNatural number)
{
	if (number.coef[0] == 0 && number.size == 1) // ���� ������ ������ ����� ���� � ������ ����� ������� ���������� false
	{
		return false;
	}
	return true; 
}


//***************************************************************************************
//���������� ������� � �������� �����
//������� �.�. 6307
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


//������� �.�. 6307
//��� ����������� �����
//������ �.�. 6307
BigNatural GCF_NN_N(BigNatural first, BigNatural second)
{
	BigNatural ost;
	while (NZER_N_B(second))
	{
		ost = MOD_NN_N(first, second);
		first = second;
		second = ost;
	}

	return first;
}


//***************************************************************************************
//��������� ������������ ����� �� 10^k 
//��������� �.�. 6307
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


//***************************************************************************************
/*��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������*/
//������� 6307
BigNatural SUB_NDN_N(BigNatural first, BigNatural second, int factor)
{
	if (COM_NN_D(first, second) == 1)
		return first;
	else
		return (SUB_NN_N(first, MUL_ND_N(second, factor)));
}


//***************************************************************************************
/*�������� ����������� �����*/
//������� 6307
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


//***************************************************************************************
/*��������� ������������ ����� �� �����*/
//������� 6307
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


//***************************************************************************************
/*���������� ������ ����� ������� �������� ������������ �� �������,
����������� �� 10 ^ k, ��� k - ����� ������� ���� �����(����� ��������� � ����)*/
//�������� �.�. 6307
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
	while (COM_NN_D(first, second) != 1);

	return i;
}


//***************************************************************************************
//��� ����������� �����
//������ 6307
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


//***************************************************************************************
//������� � ��������
//�������� �.�. 6307
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
	int k = 0;

	BigNatural res;//���������
	short* coefReverse = nullptr;
	int current = 0;


	if (!NZER_N_B(second))//���� �������� ����� ����
	{
		printf("�������� ������ ���� ������ ����!");
		return BigNatural();
	}
	else
	{
		if (COM_NN_D(first, second) == 0)                    //���� ������ ����� �������
		{
			res.coef = (short*)malloc(sizeof(short));
			res.coef[0] = 1;
			res.size = 1;
			return res;                                       //���������� �������
		}
		else
			if (COM_NN_D(first, second) == 1)                 //���� ������ ������ �������
			{
				return res;                                     //���������� ����
			}
			else
				for (k = first.size - second.size; k >= 0; k--)
				{
					coefReverse = (short*)realloc(coefReverse, sizeof(short) * (current + 1));
					coefReverse[current] = DIV_NN_Dk(first, second, k);

					current++;

					first = SUB_NDN_N(first, MUL_Nk_N(second, k), coefReverse[current - 1]);

				}
	}
	res.size = current;
	res.coef = (short*)malloc(sizeof(short)*current);
	for (int i = 0; i < current; i++)
	{
		res.coef[i] = coefReverse[current - i - 1];
	}

	k = res.size - 1;
	while ((k>0) && (res.coef[k] == 0)) k--;
	res.coef = (short*)realloc(res.coef, sizeof(short) * (k + 1));


	res.size = k + 1;

	return res;
}



//***************************************************************************************
//������� �� �������
//�������� �.�. 6307
BigNatural MOD_NN_N(BigNatural first, BigNatural second)
{
	BigNatural res;
	BigNatural first_c;

	first_c = first;
	if (COM_NN_D(first, second) == 1)
		return first;
	else
	{
		res = SUB_NN_N(first, (MUL_NN_N((DIV_NN_N(first, second)), second)));
		return res;
	}
}


//***************************************************************************************
/*��������� ����������� �����: 2 - ���� ������ ������ �������, 0, ���� �����, 1 �����.*/
//��������� 6307
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


//***************************************************************************************
/*��������� ����������� �����*/
//��������� 6307
BigNatural MUL_NN_N(BigNatural first, BigNatural second)
{
	BigNatural res;

	if (COM_NN_D(first, second) == 1)
		return MUL_NN_N(second, first);

	for (int i = 0; i < second.size; i++)
	{
		res = ADD_NN_N(res, MUL_Nk_N(MUL_ND_N(first, second.coef[i]), i));
	}

	return res;
}