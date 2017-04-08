#include "Input.h"
#include "Output.h"
#include "stdio.h"


RationalFraction getRationalFraction()
{
	return getRationalFraction("Введите рациональное число (a/b)", "Ошибка при вводе числа!");
}

BigNatural getBigNatural()
{
	return getBigNatural("Введите натуральное число", "Ошибка при вводе числа!");
}

BigInteger getBigInteger()
{
	return getBigInteger("Введите целое число", "Ошибка при вводе числа!");
}

BigNatural getBigNatural(char* message, char* errMessage)
{
	BigNatural result;

	printf("%s\n", message);

	char* string = getString();
	try
	{
		result = parseToBigNatural(string);
	}
	catch (int err)
	{
		delete[] string;
		printf("%s\n", errMessage);
		return getBigNatural(message, errMessage);
	}

	delete[] string;


	return result;
}


BigInteger getBigInteger(char* message, char* errMessage)
{
	BigInteger result;

	printf("%s\n", message);


	char* string = getString();

	try
	{
		result = parseToBigInteger(string);
	}
	catch (int err)
	{
		delete[] string;
		printf("%s\n", errMessage);
		return getBigInteger(message, errMessage);
	}
	delete[] string;

	return result;
}


RationalFraction getRationalFraction(char* message, char* errMessage)
{
	RationalFraction result;
	char *string;
	printf("%s\n", message);

	string = getString();

	try
	{
		result = parseToRationalFraction(string);

		if (!NZER_N_B(result.denominator))
		{
			throw 1;
		}
	}
	catch (int err)
	{
		printf("%s\n", errMessage);
		delete[] string;
		return getRationalFraction(message, errMessage);
	}

	delete[] string;

	return result;
}


Polynom getPolynom()
{
	printf("Введите многочлен: x^n+...+m\n");

	char* string = getString();

	Polynom result;
	try
	{
		result = parsePolynom(string);
	}
	catch (int a)
	{
		printf("Ошибка при вводе многочлена!\nПопробуйте еще раз\n");
		return getPolynom();
	}
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

