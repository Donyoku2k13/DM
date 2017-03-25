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
	char* result = (char*)malloc((number.size + 1) * sizeof(char));
	result[0] = '\0';
	for (int i = number.size - 1; i >= 0; i--)
		sprintf(result ,"%s%d",result , number.coef[i]);
	return result;
}

//************************************************************************

char* bigIntegerToString(BigInteger number)
{
	char* result = (char*)malloc((number.number.size + 2) * sizeof(char));
	result[0] = '\0';
	if (number.sign == minus)
	{
		result = (char*)malloc((number.number.size + 2) * sizeof(char));
		result[0] = '-';
		result[1] = '\0';
	}
	sprintf(result, "%s%s", result, bigNaturalToString(number.number));

	return result;
}

//************************************************************************

char* rationalFractionToString(RationalFraction number)
{
	char* result = (char*)malloc(1000 * sizeof(char));
	result[0] = '\0';
	char* numenator = bigIntegerToString(number.numenator);
	char* denominator = bigNaturalToString(number.denominator);

	sprintf(result,"%s / %s",numenator, denominator);

	return result;
}

//************************************************************************


char* polynomToString(Polynom polynom)
{
	char* result = (char*)malloc(1000 * sizeof(char));
	result[0] = '\0';
	for (int i = 0; i <= polynom.degree; i++)
		sprintf(result,"%s%s * x^%d%s", result, rationalFractionToString(polynom.coef[i]) , polynom.degree - i , i == polynom.degree ? "": " + ");

	return result;
}
