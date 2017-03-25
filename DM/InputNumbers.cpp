#include "Input.h"
#include "Output.h"
#include "stdio.h"



BigNatural getBigNatural()
{
	return getBigNatural("������� ����������� �����", "������!");
}

BigInteger getBigInteger()
{
	return getBigInteger("������� ����� �����", "������!");
}

BigNatural getBigNatural(char* message, char* errMessage)
{
	BigNatural result;

	printf("%s\n", message);

	char* string = getString();

	result = parseToBigNatural(string);

	while  (result.size == -1)
	{
		printf("%s\n",errMessage);
		char* string = getString();

		result = parseToBigNatural(string);
	}

	free(string);

	return result;
}


BigInteger getBigInteger(char* message, char* errMessage)
{
	BigInteger result;

	printf("%s\n", message);


	char* string = getString();

	result = parseToBigInteger(string);

	while (result.number.size == -1)
	{
		printf("%s\n", errMessage);
		char* string = getString();

		result = parseToBigInteger(string);
	}

	free(string);

	return result;
}


RationalFraction getRationalFraction()
{
	RationalFraction result;

	result.numenator = getBigInteger("" , "��������� ������ �� �����");
	result.denominator = getBigNatural("/", "����������� ������ �� �����");
	while (!NZER_N_B(result.denominator))
	{
		printf("����������� �� ����� ���� ����� ����!!");
		result.denominator = getBigNatural("", "����������� ������ �� �����");
	}
	return result;
}


Polynom getPolynom()
{
	Polynom result;
	printf("������� ������� ����������\n");

	scanf("%d", &result.degree);

	while (result.degree < 1)
	{
		printf("������� ���������� �� ����� ���� ������ 1!!");
		scanf("%d", &result.degree);
	}
	result.coef = (RationalFraction*)malloc(sizeof(RationalFraction)*(result.degree + 1));

	for (int i = 0; i <= result.degree; i++)
	{
		printf("x^%d:\n",result.degree - i);
		result.coef[i] = getRationalFraction();
	}

	return result;
}




char* getString()
{
	char buffer[1000];		//������ ��� ���������� ����� ������
	char* string = nullptr;	//���������� ������

	fgets(buffer, 999, stdin);
	if (buffer[0] == 10)
		return getString();

	string = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	memcpy(string, buffer, strlen(buffer) + 1);
	string[strlen(string) - 1] = '\0';
	return string;
}

