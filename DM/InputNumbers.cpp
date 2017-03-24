#include "Input.h"
#include "Output.h"
#include "stdio.h"



BigNatural getBigNatural(char* message, char* errMessage)
{
	BigNatural result;

	system("cls");
	printf("%s\n", message);

	char* string = getString();

	result = parseToBigNatural(string);

	if (result.size == -1)
	{
		infoView(errMessage);
		return getBigNatural(message, errMessage);
	}

	return result;
}


BigInteger getBigInteger(char* message, char* errMessage)
{
	BigInteger result;

	system("cls");
	printf("%s\n", message);


	char* string = getString();

	result = parseToBigInteger(string);

	if (result.number.size == -1)
	{
		infoView(errMessage);
		return getBigInteger(message, errMessage);
	}

	return result;
}


RationalFraction getRationalFraction()
{
	RationalFraction result;

	result.numenator = getBigInteger("Введите числитель" , "Числитель введен не верно");
	result.denominator = getBigNatural("Введите знамсенатель", "Знаменатель введен не верно");

	return result;
}




char* getString()
{
	char buffer[1000];		//Буффер для начального ввода строки
	char* string = nullptr;	//Получаемая строка

	fgets(buffer, 999, stdin);
	if (buffer[0] == 10)
		return getString();

	string = new char[strlen(buffer) + 1];
	memcpy(string, buffer, strlen(buffer) + 1);
	string[strlen(string) - 1] = '\0';
	return string;
}

