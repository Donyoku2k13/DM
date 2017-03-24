#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "Locale.h"
#include "Menu.h"



int main(void)
{
	setlocale(LC_ALL, "Rus");

	while (true)
	{
		switch (getMenu(mainMenu, ""))
		{
		case 0:
			naturalEnterMenu();
			break;
		case 1:
			integerEnterMenu();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			return 0;

		}
	}
}

//************************************************************************

void integerEnterMenu()
{
	BigInteger first;
	BigInteger second;
	bool state = false;

	while (true)
	{
		switch (getMenu(enterMenu, "Целые числа"))
		{
		case 0:
			first = getBigInteger("Введите первое число", "Ошибка при вводе числа!");
			second = getBigInteger("Введите второе число", "Ошибка при вводе числа!");
			state = true;
			break;
		case 1:
			if (state)
			{
				printf("Первое число:\n");
				printBigInteger(first);

				printf("Второе число:\n");
				printBigInteger(second);
				system("pause");
			}
			else
				infoView("Числа не введены");
			break;
		case 2:

			if (first.number.size == 0)
			{
				first = getBigInteger("Введите первое число", "Ошибка при вводе числа!");
				second = getBigInteger("Введите второе число", "Ошибка при вводе числа!");
			}
			integerMenu(first, second);
			state = true;

			break;
		case 3:
			return;
		}
	}
}

//************************************************************************

void naturalEnterMenu()
{
	BigNatural first;
	BigNatural second;
	bool state = false;

	while (true)
	{
		switch (getMenu(enterMenu, "Целые числа"))
		{
		case 0:
			first = getBigNatural("Введите первое число", "Ошибка при вводе числа!");
			second = getBigNatural("Введите второе число", "Ошибка при вводе числа!");
			state = true;
			break;
		case 1:
			if (state)
			{
				printf("Первое число:\n");
				printBigNatural(first);

				printf("Второе число:\n");
				printBigNatural(second);
				system("pause");
			}
			else
				infoView("Числа не введены");
			break;
		case 2:

			if (first.size == 0)
			{
				first = getBigNatural("Введите первое число", "Ошибка при вводе числа!");
				second = getBigNatural("Введите второе число", "Ошибка при вводе числа!");
			}
			naturalMenu(first, second);
			state = true;

			break;
		case 3:
			return;
		}
	}
}

//************************************************************************


void naturalMenu(BigNatural first, BigNatural second)
{
	BigNatural result;

	while (true)
	{
		switch (getMenu(naturalNumberMenu, "Выберите действие"))
		{
		case 0:
			result = ADD_NN_N(first, second);
			break;
		case 1:
			result = SUB_NN_N(first, second);
			break;
		case 2:
			result = MUL_NN_N(first, second);
			break;
		case 3:
			result = DIV_NN_N(first, second);
			break;
		case 4:
			result = MOD_NN_N(first, second);
			break;
		case 5:
			result = GCF_NN_N(first, second);
			break;
		case 6:
			result = LCM_NN_N(first, second);
			break;
		case 7:
			return;
		}
		printf("Результат:\n");
		printBigNatural(result);
		system("pause");
	}
}


//************************************************************************

void integerMenu(BigInteger first, BigInteger second)
{
	BigInteger result;

	while (true)
	{
		switch (getMenu(integerNumberMenu, "Выберите действие"))
		{
		case 0:
			result = ADD_ZZ_Z(first, second);
			break;
		case 1:
			result = SUB_ZZ_Z(first, second);
			break;
		case 2:
			result = MUL_ZZ_Z(first, second);
			break;
		case 3:
			result = DIV_ZZ_Z(first, second);
			break;
		case 4:
			result = MOD_ZZ_Z(first, second);
			break;
		case 5:
			return;
		}
		printf("Результат:\n");
		printBigInteger(result);
		system("pause");
	}
}

//************************************************************************
