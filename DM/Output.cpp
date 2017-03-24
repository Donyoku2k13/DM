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

void printBigNatural(BigNatural number)
{
	for (int i = number.size - 1; i >= 0; i--)
		printf("%d", number.coef[i]);
	
}

//************************************************************************

void printBigInteger(BigInteger number)
{
	if (number.sign == minus)
		printf("-");
	printBigNatural(number.number);

}
