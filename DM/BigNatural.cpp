#include "Header.h"
#include "Output.h"
#include "ParserHeader.h"
//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������ �������

//����������� - ��������� �������� - 0
BigNatural::BigNatural()
{
	size = 1;
	coef = new short[1];
	coef[0] = 0;

}

//***************************************************************************************

BigNatural::BigNatural(short* coef, int size)
{
	this->size = size;
	this->coef = new short[size];
	memcpy(this->coef, coef, size * sizeof(short) );
}

//***************************************************************************************

BigNatural::BigNatural(const BigNatural & bN)
{
	size = bN.size;
	delete[] coef;
	coef = new short[size];
	memcpy(coef, bN.coef, size * sizeof(short));
}

//***************************************************************************************

BigNatural::~BigNatural()
{
	delete[] coef;
}


//***************************************************************************************

BigNatural BigNatural::operator=(BigNatural & bN)
{
	size = bN.size;
	delete[] coef;
	coef = new short[size];
	memcpy(coef, bN.coef, size * sizeof(short));

	return *this;
}

//***************************************************************************************

BigNatural::BigNatural(int number)
{
	short* tempCoef = nullptr;
	size = 0;
	while (number != 0)
	{
		tempCoef = (short*)realloc(tempCoef, (size + 1) * sizeof(short));
		tempCoef[size] = number % 10;
		number /= 10;
		size++;
	}
	coef = new short[size];

	memcpy(coef, tempCoef, size * sizeof(short));
	free(tempCoef);
}

//***************************************************************************************

BigNatural::BigNatural(char* number)
{
	*this = parseToBigNatural(number);
}

//***************************************************************************************
//��������� �� ������� �������� ������������ ����� ������� �������� ��� �������
//����� �.�. 6307
BigNatural SUB_NN_N(BigNatural & first, BigNatural & second)
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
	short* resCoef = new short[first.size];


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

	result = BigNatural(resCoef, i + 1);

	delete[] resCoef;

	return result;
}


//***************************************************************************************
//�������� �� ����
//������� �.�. 6307
bool NZER_N_B(BigNatural & number)
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
BigNatural ADD_1N_N(BigNatural & number)
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
		result.coef[0] = 0;
		while (counter != result.size && result.coef[counter] == 9) // ���� ��������� ����� �� ����� 9, �� ���� ������ ����� �� ������ 9, ���������� � ��� �������, � ���� ���������� ����������� 0
		{
			result.coef[counter] = 0;
			counter++;
		}
		if (counter == result.size) // ���� ��� ����� ����� 9, ����������� ������ �� �������, ������ ����� ����������� 1
		{
			result.coef = resize(result.coef, result.size + 1, result.size);
			result.size++;
			result.coef[result.size - 1] = 1;
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
BigNatural MUL_Nk_N(BigNatural & number, int tenDegree)
{
	BigNatural result;
	int r = 0;
	int size = number.size + tenDegree;

	if (!NZER_N_B(number))
		return BigNatural();


	short* resCoef = new short[size];


	for (int i = 0; i < tenDegree; i++)
		resCoef[i] = 0;
	for (int i = tenDegree; i < size; i++)
		resCoef[i] = number.coef[i - tenDegree];

	result = BigNatural(resCoef, size);

	delete[] resCoef;

	return result;
}


//***************************************************************************************
/*��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������*/
//������� 6307
BigNatural SUB_NDN_N(BigNatural & first, BigNatural & second, int factor)
{
	if (COM_NN_D(first, second) == 1)
		return first;
	else
		return (SUB_NN_N(first, MUL_ND_N(second, factor)));
}


//***************************************************************************************
/*�������� ����������� �����*/
//������� 6307
BigNatural ADD_NN_N(BigNatural & first, BigNatural & second)
{
	BigNatural result;
	int i;
	int r = 0;

	if (COM_NN_D(first, second) == 1)
		return ADD_NN_N(second, first);

	short* resCoef = new short[first.size];

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
		resCoef = resize(resCoef, first.size + 1, first.size);
		result.size = first.size + 1;
		resCoef[first.size] = r;
	}
	else
		result.size = first.size;
	
	result = BigNatural(resCoef, result.size);

	delete [] resCoef;
	return result;
}


//***************************************************************************************
/*��������� ������������ ����� �� �����*/
//������� 6307
BigNatural MUL_ND_N(BigNatural & number, int factor)
{
	BigNatural result;
	int r = 0;

	if (factor == 0)
		return BigNatural();

	short* resCoef = new short[number.size];

	for (int j = 0; j < number.size; j++)
	{
		resCoef[j] = (number.coef[j] * factor + r) % 10;
		r = (number.coef[j] * factor + r) / 10;
	}
	result.size = number.size;
	if (r) 
	{
		resCoef = resize(resCoef, number.size + 1, number.size);
		resCoef[result.size] = r;
		result.size++;
	}
	result = BigNatural(resCoef, result.size);

	delete[] resCoef;

	return result;
}


//***************************************************************************************
/*���������� ������ ����� ������� �������� ������������ �� �������,
����������� �� 10 ^ k, ��� k - ����� ������� ���� �����(����� ��������� � ����)*/
//�������� �.�. 6307
int DIV_NN_Dk(BigNatural & first, BigNatural & second, int tenDegree)
{
	int i = 0;
	BigNatural dSecond = MUL_Nk_N(second, tenDegree);

	if (COM_NN_D(first, dSecond) == 1)
		return 0;

	if (COM_NN_D(first, dSecond) == 0)
		return 1;

	BigNatural res = first;

	do
	{
		res = SUB_NN_N(res, dSecond);
		i++;
	}
	while (COM_NN_D(res, dSecond) != 1);

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
BigNatural DIV_NN_N(BigNatural & first, BigNatural & second)
{
	int k = 0;

	BigNatural res;//���������
	short *coef = nullptr;
	int current = 0;
	int size = first.size - second.size;



	if (!NZER_N_B(second))//���� �������� ����� ����
		throw 1;

	if (COM_NN_D(first, second) == 0)                    //���� ������ ����� �������
		return BigNatural(1);                                  //���������� �������

	if (COM_NN_D(first, second) == 1)                 //���� ������ ������ �������
		return BigNatural();                   //���������� ����


	coef = new short[size + 1];
	res = first;
	for (k = size; k >= 0; k--)
	{
		coef[k] = DIV_NN_Dk(res, second, k);
		res = SUB_NDN_N(res, MUL_Nk_N(second, k), coef[k]);
	}
	


	k = size;

	while ((k>0) && (coef[k] == 0)) k--;

	res = BigNatural(coef, k + 1);

	delete[] coef;

	return res;
}



//***************************************************************************************
//������� �� �������
//�������� �.�. 6307
BigNatural MOD_NN_N(BigNatural & first, BigNatural & second)
{
	BigNatural res;

	if (COM_NN_D(first, second) == 1)
		return first;
	else
	{
		res = SUB_NN_N(first, MUL_NN_N(DIV_NN_N(first, second), second));
		return res;
	}
}


//***************************************************************************************
//��������� ����������� �����: 2 - ���� ������ ������ �������, 0, ���� �����, 1 �����.
//��������� 6307
int COM_NN_D(BigNatural & first, BigNatural & second)
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
BigNatural MUL_NN_N(BigNatural & first, BigNatural & second)
{
	BigNatural res;

	if (COM_NN_D(first, second) == 1)
		return MUL_NN_N(second, first);

	for (int i = 0; i < second.size; i++)
		res = ADD_NN_N(res, MUL_Nk_N(MUL_ND_N(first, second.coef[i]), i));
	

	return res;
}


short* resize(short* arr, int size, int oldSize)
{
	short* nArr = new short[size];
	memcpy(nArr, arr, min(size, oldSize) * sizeof(short));

	if (arr)
		delete[] arr;

	return nArr;
}