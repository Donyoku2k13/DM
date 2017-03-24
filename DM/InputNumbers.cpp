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

	if (result.size == -1)
	{
		infoView(errMessage);
		return getBigNatural(message, errMessage);
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

	if (result.number.size == -1)
	{
		infoView(errMessage);
		return getBigInteger(message, errMessage);
	}

	free(string);

	return result;
}


RationalFraction getRationalFraction()
{
	RationalFraction result;

	result.numenator = getBigInteger("������� ���������" , "��������� ������ �� �����");
	result.denominator = getBigNatural("������� ������������", "����������� ������ �� �����");

	return result;
}


Polynom getPolynom()
{
	Polynom result;
	printf("������� ������� ����������\n");
	scanf("%d",&result.degree);
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

	string = new char[strlen(buffer) + 1];
	memcpy(string, buffer, strlen(buffer) + 1);
	string[strlen(string) - 1] = '\0';
	return string;
}

