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

void printMenu(char**, int, int);	//Вывод меню

int selectMenu(char*, char**, int);	//Выбор пункта меню

int menuMove(int, int, bool*);		//Движение по меню

int getMenu(Menu, char*);			//Вывод меню




void integerEnterMenu();

void naturalEnterMenu();

void rFractionEnterMenu();

void polynomEnterMenu();

void rFractionMenu(RationalFraction first, RationalFraction second);

void naturalMenu(BigNatural first, BigNatural second);

void integerMenu(BigInteger first, BigInteger second);

void polynomEMenu(Polynom first, Polynom second);



