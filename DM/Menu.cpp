#include "Header.h"
#include "Output.h"
#include "Input.h"
#include "Menu.h"




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
		"��� 2 �����",
		"�����"
	},
		*integerNumberMenuPuncts[] = {
		"������� 2 �����",
		"������� �� ������� ����� ������",
		"����������� 2 �����",
		"������� �� ������� 2 �����",
		"������� �� ������� 2 �����",
		"�����"
	},
		*rationalFractionMenuPuncts[] = {
		"��������� �����",
		"������� 2 �����",
		"������� 2 �����",
		"�������� ���� ����� �� ������",
		"��������� ���� ����� �� ������",
		"�����"
	},
		*polynomMenuPuncts[] = {
		"�������� �����������",
		"��������� �����������",
		"��������� �� ���������� ��� ������������ ������������� � ��� ����������",
		"��������� �����������",
		"������� �� ������� ���������� �� ��������� ��� ������� � ��������",
		"������� �� ������� ���������� �� ��������� ��� ������� � ��������",
		"��� �����������",
		"����������� ����������",
		"�������������� ���������� � ������� ����� � �������",
		"�����"
	},
		*enterMenuPuncts[] = {
		"������ 2 �����",
		"������� �����",
		"�������� ��� �������",
		"�����"
	},
		*replaceMenuPuncts[] = {
		"�������� ������ ����� �� ���������",
		"�������� ������ ����� �� ���������",
		"�������� �������� �����"
	},
		*enterPolynomMenuPuncts[] = {
		"������ 2 ����������",
		"������� ����������",
		"�������� ��� ������������",
		"�����"
	},
		*oneOrTwoMenuPuncts[] = {
		"1.",
		"2."
	};

	switch (menu)
	{
	case mainMenu:
		return selectMenu(message, mainMenuPuncts, 6);
	case naturalNumberMenu:
		return selectMenu(message, naturalNumberMenuPuncts, 8);
	case integerNumberMenu:
		return selectMenu(message, integerNumberMenuPuncts, 6);
	case rationalFractionMenu:
		return selectMenu(message, rationalFractionMenuPuncts, 6);
	case polynomMenu:
		return selectMenu(message, polynomMenuPuncts, 10);
	case enterMenu:
		return selectMenu(message, enterMenuPuncts, 4);
	case enterPolynomMenu:
		return selectMenu(message, enterPolynomMenuPuncts, 4);
	case repMenu:
		return selectMenu(message, replaceMenuPuncts,3);
	case oneOrTwoMenu:
		return selectMenu(message, oneOrTwoMenuPuncts, 2);

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
		gotoXY(0, i + 4);
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





