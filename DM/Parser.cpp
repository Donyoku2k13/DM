#include "ParserHeader.h"


BigNatural parseToBigNatural(char* string)
{
	BigNatural result;
	int size;
	short currentNumber;
	char current;
	int j = 0;

	if (strlen(string) == 0)
	{
		result.size = 0;
		return result;
	}

	size = strlen(string);

	short* coef = new short[size];

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
			delete[] coef;
			throw 1;
		}

		if (j == 0 && currentNumber == 0 && size > 1)
			size--;
		else
		{
			coef[size - j - 1] = currentNumber;
			j++;
		}
	}
	if (size != strlen(string))
		coef = resize(coef, size, strlen(string));

	result = BigNatural(coef, size);

	free(coef);

	return result;
}



BigInteger parseToBigInteger(char* string)
{
	BigInteger result;
	BigNatural number;
	if (string[0] == '-')
	{
		result.sign = minus;
		strcpy(string, string + 1);
	}
	else 
		result.sign = plus;
	try
	{
		number = parseToBigNatural(string);
	}
	catch (int err)
	{
		throw err;
	}
	result.number = number;

	return result;
}



RationalFraction parseToRationalFraction(char* string)
{
	RationalFraction result;

	if (strlen(string) == 0)
	{
		result.numenator.number.size = 0;
		return result;
	}
	char* numenator = strtok(string, "/");
	char* denominator = strtok(NULL, "\n");

	try
	{

		result.numenator = parseToBigInteger(numenator);

		if (denominator != NULL)
			result.denominator = parseToBigNatural(denominator);
	}
	catch (int err)
	{
		throw err;
	}

	return result;
}


Polynom parsePolynom(char* string)
{
	Polynom res;
	char *xPos = nullptr,
		*degreeStr = nullptr,
		*rFraction = nullptr,
		*degreePos = nullptr,
		*signPos = nullptr;
	RationalFraction current;
	RationalFraction* coef = nullptr,
		*resCoef = nullptr;
	Sign sign = plus;
	int degree = 0,
		resDegree = 0,
		size = 0;


	deleteSpace(string);

	try
	{
		while (string)
		{

			xPos = strchr(string, 'x');

			if (xPos != nullptr) //Парсинг значения при иксе и степени икса
			{
				size = xPos - string; //Количество символов в значении при х

				if (size == 1 && string[0] == '-')
				{
					sign = minus;
					size = 0;
					string += 1;
				}


				if (size != 0)
				{
					rFraction = new char[size + 1];
					memcpy(rFraction, string, size);
					rFraction[size] = '\0';

					current = parseToRationalFraction(rFraction);

					if (!NZER_N_B(current.denominator))
						throw 1;

					delete[] rFraction;
					rFraction = nullptr;
				}
				else
					current = parseToRationalFraction("1");

				if (current.numenator.sign == plus)
					current.numenator.sign = sign;

				//Нахождени степени при иксе
				degreePos = strchr(string, '^');
				signPos = strpbrk(string, "+-");

				if (degreePos == nullptr)
				{
					degree = 1;
				}
				else
				{
					degreePos += 1;
					if (signPos != nullptr)
					{
						sign = signPos[0] == '+' ? plus : minus;
						size = signPos - degreePos;
						if (size <= 0)
						{
							throw 1;
						}
					}
					else
						size = strlen(string);

					degreeStr = new char[size + 1];
					memcpy(degreeStr, degreePos, size);
					degreeStr[size] = '\0';
					degree = atoi(degreeStr);

					if (degree == 0 && degreeStr[0] != '0')
						throw 1;
					

					delete[] degreeStr;
					degreeStr = nullptr;
				}
				if (resDegree < degree)
				{
					coef = new RationalFraction[degree + 1];
					for (int i = 0; i <= degree; i++)
						coef[i] = RationalFraction();
					resDegree = degree;
				}
				coef[degree] = ADD_QQ_Q(coef[degree], current);


			}
			else //Парсинг свободного члена
			{
				signPos = nullptr;
				degreePos = nullptr;

				if (!coef)
					coef = new RationalFraction[1];
				coef[0] = parseToRationalFraction(string);
				if (!NZER_N_B(coef[0].denominator) || coef[0].numenator.number.size == 0 || coef[0].denominator.size == 0)
					throw 1;

				if (coef[0].numenator.sign == plus)
					coef[0].numenator.sign = sign;
			}
			if (signPos != nullptr)
				string = signPos + 1;
			else
				string = nullptr;

		}
	}
	catch (int err)
	{
		if (rFraction)
			delete[] rFraction;

		if (degreeStr)
			delete[] degreeStr;

		delete[] coef;

		throw 1;
	}


	resCoef = new RationalFraction[resDegree + 1];
	for (int i = 0; i <= resDegree; i++)
	{
		resCoef[i] = coef[resDegree - i];
	}

	res = Polynom(resCoef, resDegree);

	delete[] coef;
	delete[] resCoef;

	return res;
}


void deleteSpace(char* string)
{

	char* i = string;
	char* j = string;
	while (*j != 0)
	{
		*i = *j++;
		if (*i != ' ')
			i++;
	}
	*i = 0;

}
