#include "ParserHeader.h"


BigNatural parseToBigNatural(char* string)
{
	BigNatural result;
	int size;
	short currentNumber;
	char current;

	size = strlen(string);

	short* coef = (short*)malloc(size * sizeof(coef));

	for (int i = 0; string[i] != '\0'; i++)
	{
		current = string[i];

		switch (current)
		{
		case '0':
			currentNumber = 0;
			break;
		case '1':
			currentNumber = 1;
			break;
		case '2':
			currentNumber = 2;
			break;
		case '3':
			currentNumber = 3;
			break;
		case '4':
			currentNumber = 4;
			break;
		case '5':
			currentNumber = 5;
			break;
		case '6':
			currentNumber = 6;
			break;
		case '7':
			currentNumber = 7;
			break;
		case '8':
			currentNumber = 8;
			break;
		case '9':
			currentNumber = 9;
			break;
		default:
			result.size = -1;
			return result;
		}

		coef[size - i - 1] = currentNumber;
	}

	result.size = size;
	result.coef = coef;

	return result;
}



BigInteger parseToBigInteger(char* string)
{
	BigInteger result;
	BigNatural number;
	if (string[0] == '-')
	{
		result.sign = minus;
		string = partArrayCopy(string, 1);
	}
	else
		result.sign = plus;

	number = parseToBigNatural(string);

	result.number = number;

	return result;
}



char* partArrayCopy(char* string, int index)
{
	char* res = (char*)malloc((strlen(string) - index + 1)*sizeof(char));
	for (int i = index; string[i] != '\0'; i++)
	{
		res[i - index] = string[i];
	}

	res[strlen(string) - index] = '\0';
	return res;
}