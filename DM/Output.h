#pragma once
#include "Header.h"
#include "windows.h"
#include "conio.h"


void infoView(char* message);


void gotoXY(short x, short y);


void changeConsoleColor(int, int);


void printBigNatural(BigNatural);


void printBigInteger(BigInteger);


void printRationalFraction(RationalFraction number);


void printPolynom(Polynom polynom);


void polynomEMenu(Polynom first, Polynom second);


void help();
