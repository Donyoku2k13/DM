#include "Output.h"


//************************************************************************


void gotoXY(short x, short y)
{
	static HANDLE outputHande = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(outputHande, { x, y });
}


//************************************************************************


void changeConsoleColor(int bg, int text)
{
	static HANDLE outputHande = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(outputHande, bg << 4 | text);
}


//************************************************************************


//Вывод сообщения
void infoView(char* message)
{
	int code = 0;							//Код нажатой клавиши
	short pos = strlen(message) / 2 + 9;	//Позиция середины сообщения

	system("cls");
	gotoXY(10, 3);
	printf("%s", message);
	do
	{
		changeConsoleColor(0, 14);
		gotoXY(pos, 6);
		printf("<Да>");
		code = getch();

	} while (code != 13);

	system("cls");
	changeConsoleColor(0, 7);

}


//************************************************************************

char* bigNaturalToString(BigNatural number)
{
	char* result = new char[number.size + 1];
	result[0] = '\0';
	for (int i = number.size - 1; i >= 0; i--)
		sprintf(result ,"%s%d",result , number.coef[i]);
	return result;
}

//************************************************************************

char* bigIntegerToString(BigInteger number)
{
	char* result = new char[number.number.size + 2];
	result[0] = '\0';
	if (number.sign == minus)
	{
		result[0] = '-';
		result[1] = '\0';
	}
	char* natural = bigNaturalToString(number.number);

	sprintf(result, "%s%s", result, natural);

	delete[] natural;

	return result;
}

//************************************************************************

char* rationalFractionToString(RationalFraction number)
{
	//Если представимо в виде целого, то представляем
	if (INT_Q_B(number))
		return bigIntegerToString(TRANS_Q_Z(RED_Q_Q(number)));


	char* numenator = bigIntegerToString(number.numenator);
	char* denominator = bigNaturalToString(number.denominator);

	char* result = new char[strlen(numenator) + strlen(denominator) + 2];
	result[0] = '\0';

	sprintf(result, "%s/%s", numenator, denominator);

	delete[] numenator;
	delete[] denominator;

	return result;
}

//************************************************************************


char* polynomToString(Polynom polynom)
{
	char* result = nullptr;
	char* rFraction = nullptr;
	bool one = false;
	bool sign = true;
	int resSize = 0;


	for (int i = 0; i <= polynom.degree; i++)
	{
		rFraction = rationalFractionToString(polynom.coef[i]);

		//Выясняем знак числа
		sign = rFraction[0] != '-';
		if (!sign)
			strcpy(rFraction, rFraction + 1);

		one = strcmp(rFraction, "1") != 0;
		


		if (strcmp(rFraction, "0") != 0)
		{
			if (result)
				resSize = strlen(result);

			//Свободный член печатаем без икса
			if (i == polynom.degree)
			{
				result = resize(result, strlen(rFraction) + resSize + 4);
				sprintf(result, "%s%s%s", result, sign ? " + " : " - ", rFraction);
			}
			//x^1
			else if (i + 1 == polynom.degree)
			{
				result = resize(result, strlen(rFraction) + resSize + 5);
				sprintf(result, "%s%s%sx", result, sign ? (i == 0 ? "" : " + ") : (i == 0 ? "- " : " - "), one ? rFraction : "");
			}
			//Вывод всех остальных иксов
			else
			{
				result = resize(result, strlen(rFraction) + resSize + 9);
				sprintf(result, "%s%s%sx^%d", result, sign ? (i == 0 ? "" : " + ") : (i == 0 ? "- " : " - "), one ? rFraction : "", polynom.degree - i);
			}
		}
		else if (polynom.degree == 0)
		{
			return rFraction;
		}

		delete[] rFraction;
	}

	return result;
}


char* resize(char* arr, int size)
{
	char* nArr = new char[size + 1];
	if (arr)
	{
		strcpy(nArr, arr);
		delete[] arr;
	}
	else
		nArr[0] = '\0';
	

	return nArr;
}
