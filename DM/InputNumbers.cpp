#include "Input.h"
#include "Output.h"
#include "stdio.h"


RationalFraction getRationalFraction()
{
	return getRationalFraction("������� ������������ ����� (a/b)", "������ ��� ����� �����!");
}

BigNatural getBigNatural()
{
	return getBigNatural("������� ����������� �����", "������ ��� ����� �����!");
}

BigInteger getBigInteger()
{
	return getBigInteger("������� ����� �����", "������ ��� ����� �����!");
}

BigNatural getBigNatural(char* message, char* errMessage)
{
	BigNatural result;

	printf("%s\n", message);

	char* string = getString();

	result = parseToBigNatural(string);

	while  (result.size == 0)
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

	while (result.number.size == 0)
	{
		printf("%s\n", errMessage);
		char* string = getString();

		result = parseToBigInteger(string);
	}

	free(string);

	return result;
}


RationalFraction getRationalFraction(char* message, char* errMessage)
{
	RationalFraction result;
	char *string;
	printf("%s\n", message);
	do
	{
		string = getString();

		result = parseToRationalFraction(string);

		if (!NZER_N_B(result.denominator))
			printf("����������� �� ����� ���� ����� ����!!\n");

		if (result.numenator.number.size == 0 || result.denominator.size == 0)
			printf("%s\n", errMessage);
	} 
	while (!NZER_N_B(result.denominator) || result.numenator.number.size == 0 || result.denominator.size == 0);

	return result;
}


Polynom getPolynom()
{
	printf("������� ���������: x^n+...+m\n");

	char* string = getString();

	Polynom result;
	try
	{
		result = parsePolynom(string);
	}
	catch (int a)
	{
		printf("������ ��� ����� ����������!\n���������� ��� ���\n");
		return getPolynom();
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

