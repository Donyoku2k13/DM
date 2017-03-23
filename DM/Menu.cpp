#include "conio.h"
#include "windows.h"
#include "Header.h"



enum Menu
{
	mainMenu,
	criteriaMenu,
	deleteMenu,
	addMenu,
	updateMenu,
	outputMenu
};


//************************************************************************

//����� ����
int getMenu(Menu menu, char* message)
{
	static char *mainMenuPuncts[] = {
		"����������� �����",
		"����� �����",
		"������������ �����",
		"����������",
		"�������",
		"�����"
	},
		*naturalNumberMenuPuncts[] = {
		"������� 2 �����",
		"������� �� �������� ����� �������",
		"����������� 2 �����",
		"������� �� ������� 2 �����",
		"������� �� ������� 2 �����",
		"��� 2 �����",
		"��� 2 �����"
	},
		*integerNumberMenuPuncts[] = {
		"������� 2 �����",
		"������� �� �������� ����� �������",
		"����������� 2 �����",
		"������� �� ������� 2 �����",
		"������� �� ������� 2 �����",
	},
		*deleteMenuPuncts[] = {
		"������� ����� �� ��������",
		"������� ��� ����� ������",
		"������� ��� ����� ������������",
		"�����"
	},
		*addMenuPuncts[] = {
		"�������� � ������",
		"�������� � �����",
		"�����"
	},
		*outputMenuPuncts[] = {
		"������� � ������ �������",
		"������� � �������� �������",
		"�������� ���-�� ���� �� ��������",
		"�����"
	};

	switch (menu)
	{
	case mainMenu:
		return selectMenu(message, mainMenuPuncts, 6);
	case criteriaMenu:
		return selectMenu(message, criteriaMenuPuncts, 5);
	case updateMenu:
		return selectMenu(message, updateMenuPuncts, 4);
	case deleteMenu:
		return selectMenu(message, deleteMenuPuncts, 4);
	case addMenu:
		return selectMenu(message, addMenuPuncts, 3);
	case outputMenu:
		return selectMenu(message, outputMenuPuncts, 3);
	}
	return 0;
}


//************************************************************************

//����� ������ ����
int selectMenu(char* message, char** menu, int size)
{
	int current = 0;	//������� ��������� �������
	bool exit = false;	//������� ������

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

//����� ���� �� �����
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

//�������� �� ����
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