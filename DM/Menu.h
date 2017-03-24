#pragma once

enum Menu
{
	mainMenu,
	naturalNumberMenu,
	integerNumberMenu,
	rationalFractionMenu,
	polynomMenu,
	outputMenu
};

void printMenu(char**, int, int);	//����� ����

int selectMenu(char*, char**, int);	//����� ������ ����

int menuMove(int, int, bool*);		//�������� �� ����

int getMenu(Menu, char*);			//����� ����

