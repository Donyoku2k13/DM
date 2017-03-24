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
	enterPolynomMenu,
	repMenu,
};

void printMenu(char**, int, int);	//����� ����

int selectMenu(char*, char**, int);	//����� ������ ����

int menuMove(int, int, bool*);		//�������� �� ����

int getMenu(Menu, char*);			//����� ����




void integerEnterMenu();

void naturalEnterMenu();

void rFractionEnterMenu();

void polynomEnterMenu();

void rFractionMenu(RationalFraction first, RationalFraction second);

void naturalMenu(BigNatural first, BigNatural second);

void integerMenu(BigInteger first, BigInteger second);

void polynomEMenu(Polynom first, Polynom second);



