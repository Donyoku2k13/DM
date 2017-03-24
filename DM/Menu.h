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

void printMenu(char**, int, int);	//Вывод меню

int selectMenu(char*, char**, int);	//Выбор пункта меню

int menuMove(int, int, bool*);		//Движение по меню

int getMenu(Menu, char*);			//Вывод меню

