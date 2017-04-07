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
			result.size = 0;
			return result;
		}

		if (j == 0 && currentNumber == 0 && size > 1)
			size--;
		else
		{
			coef[size - j - 1] = currentNumber;
			j++;
		}
	}

	coef = (short*)realloc(coef, size * sizeof(coef));
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
		strcpy(string, string + 1);
	}
	else
		result.sign = plus;

	number = parseToBigNatural(string);

	result.number = number;

	return result;
}



RationalFraction parseToRationalFraction(char* string)
{
	RationalFraction result;

	char* numenator = strtok(string, "/");
	char* denominator = strtok(NULL, "\n");

	result.numenator = parseToBigInteger(numenator);

	if (denominator != NULL)
		result.denominator = parseToBigNatural(denominator);

	return result;
}


Polynom parsePolynom(char* string)
{
	Polynom res;
	char *subString, *xPos, *position, *rFraction, *degreePos, *signPos;
	RationalFraction current;
	RationalFraction* coef = nullptr;
	Sign sign = plus;
	int degree = 0, resDegree = 0;
	subString = strdup(string);
	
	
	while (subString)
	{

		xPos = strchr(subString, 'x');

		if (xPos != nullptr)
		{
			int size = xPos - subString;

			if (size == 1 && subString[0] == '-')
			{
				sign = minus;
				size = 0;
				strcpy(subString, subString + 1);
			}


			if (size != 0)
			{
				rFraction = (char*)malloc((size + 1) * sizeof(int));
				memcpy(rFraction, subString, size);
				rFraction[size] = '\0';
				current = parseToRationalFraction(rFraction);
				if (!NZER_N_B(current.denominator) || current.numenator.number.size == 0 || current.denominator.size == 0)
				{
					throw 1;
				}
			}
			else
				current = parseToRationalFraction("1");

			if (current.numenator.sign == plus)
				current.numenator.sign = sign;


			degreePos = strchr(subString, '^');
			signPos = strpbrk(subString, "+-");

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
						throw 1;
				}
				else
					size = strlen(subString);
				
				position = (char*)malloc((size + 1) * sizeof(int));
				memcpy(position, degreePos, size);
				position[size] = '\0';
				degree = atoi(position);

			}
			if (resDegree < degree)
			{
				coef = (RationalFraction*)realloc(coef, (degree + 1) * sizeof(RationalFraction));
				for (int i = 0; i <= degree; i++)
					coef[i] = RationalFraction();
				resDegree = degree;
			}
			coef[degree] = ADD_QQ_Q(coef[degree], current);


		}
		else
		{
			signPos = nullptr;
			degreePos = nullptr;
			if (!coef)
				coef = (RationalFraction*)malloc(sizeof(RationalFraction));
			coef[0] = parseToRationalFraction(subString);
			if (!NZER_N_B(coef[0].denominator) || coef[0].numenator.number.size == 0 || coef[0].denominator.size == 0)
			{
				throw 1;
			}

			if (coef[0].numenator.sign == plus)
				coef[0].numenator.sign = sign;
		}
		if (signPos != nullptr)
			subString = signPos + 1;
		else 
			subString = nullptr;
	}


	res.coef = (RationalFraction*)malloc(sizeof(RationalFraction) * (resDegree + 1));
	res.degree = resDegree;
	for (int i = 0; i <= resDegree; i++)
	{
		res.coef[i] = coef[resDegree - i];
	}

	

	return res;
}
