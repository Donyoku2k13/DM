#include "Header.h"
#include "Output.h"
#include "Menu.h"




//Выбор меню
int getMenu(Menu menu, char* message)
{
	static char *mainMenuPuncts[] = {
		"Натуральные числа",
		"Целые числа",
		"Рациональные числа",
		"Многочлены",
		"Справка",
		"Выход"
	},
		*naturalNumberMenuPuncts[] = {
		"Сложить 2 числа",
		"Вычесть из большего числа меньшее",
		"Перемножить 2 числа",
		"Частное от деления 2 чисел",
		"Остаток от деления 2 чисел",
		"НОД 2 чисел",
		"НОК 2 чисел"
	},
		*integerNumberMenuPuncts[] = {
		"Сложить 2 числа",
		"Вычесть из большего числа меньшее",
		"Перемножить 2 числа",
		"Частное от деления 2 чисел",
		"Остаток от деления 2 чисел",
		"Назад"
	},
		*rationalFractionMenuPuncts[] = {
		"Сократить дробь",
		"Сложить 2 дроби",
		"Вычесть 2 дроби",
		"Умножить одну дробь на другую",
		"Разделить одну дробь на другую",
		"Назад"
	},
		*polynomMenuPuncts[] = {
		"Сложение многочленов",
		"Вычитание многочленов",
		"Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей",
		"Умножение многочленов",
		"Частное от деления многочлена на многочлен при делении с остатком",
		"Остаток от деления многочлена на многочлен при делении с остатком",
		"НОД многочленов",
		"Производная многочлена",
		"Преобразование многочлена — кратные корни в простые",
		"Назад"
	};

	switch (menu)
	{
	case mainMenu:
		return selectMenu(message, mainMenuPuncts, 6);
	case naturalNumberMenu:
		return selectMenu(message, naturalNumberMenuPuncts, 7);
	case integerNumberMenu:
		return selectMenu(message, integerNumberMenuPuncts, 6);
	case rationalFractionMenu:
		return selectMenu(message, rationalFractionMenuPuncts, 6);
	case polynomMenu:
		return selectMenu(message, polynomMenuPuncts, 10);
	}
	return 0;
}


//************************************************************************

//Выбор пункта меню
int selectMenu(char* message, char** menu, int size)
{
	int current = 0;	//Текущий выбранный элемент
	bool exit = false;	//Условие выхода

	system("cls");
	gotoXY(3, 1);
	printf("%s", message);

	do
	{
		printMenu(menu, size, current);
		current = menuMove(current, size, &exit);
	} while (!exit);

	system("cls");
	changeConsoleColor(0, 7);

	return current;
}

//************************************************************************

//Вывод меню на экран
void printMenu(char** menu, int size, int current)
{

	for (int i = 0; i < size; i++)
	{
		gotoXY(0, i + 3);
		changeConsoleColor(0, current == i ? 14 : 7);
		printf("%-6s%s%s", current == i ? "  -->  " : "", menu[i], current == i ? "  <--" : "        ");
	}
}

//************************************************************************

//Движение по меню
int menuMove(int current, int size, bool* exit)
{
	int code;
	code = getch();
	if (code == 224 || code == 0)
		code = getch();
	if (code == 72)
		current = --current < 0 ? current + size : current;
	else if (code == 80)
		current = ++current % size;
	*exit = code == 13;

	return current;
}


