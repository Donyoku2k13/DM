#pragma once
#include "Header.h"
#include "windows.h"
#include "conio.h"


void infoView(char* message);


void gotoXY(short x, short y);


void changeConsoleColor(int, int);



char* bigNaturalToString(BigNatural number);

char* bigIntegerToString(BigInteger number);

char* rationalFractionToString(RationalFraction number);

char* polynomToString(Polynom polynom);

void polynomEMenu(Polynom first, Polynom second);

void help();

char* resize(char* arr, int size);

