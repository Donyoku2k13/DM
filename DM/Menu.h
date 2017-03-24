#pragma once

enum Menu
{
	mainMenu,
	naturalNumberMenu,
	integerNumberMenu,
	rationalFractionMenu,
	polynomMenu,
	outputMenu,
	enterMenu,
	enterIntegerMenu,
	enterNaturalMenu,
	enterRFractionMenu,
	enterPolynomMenu,
	repIntegerMenu,
	repNaturalMenu,
	repRFractionMenu,
	repPolynomMenu,
	firstLevelSubMenu
};

void printMenu(char**, int, int);	//����� ����

int selectMenu(char*, char**, int);	//����� ������ ����

int menuMove(int, int, bool*);		//�������� �� ����

int getMenu(Menu, char*);			//����� ����


void integerEnterMenu();

void integerMenu(BigInteger first, BigInteger second);



