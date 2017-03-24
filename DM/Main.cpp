#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "Locale.h"




int main(void)
{
	setlocale(LC_ALL, "Rus");

	BigNatural natural = getBigNatural();

	printBigNatural(natural);

	system("pause");

	BigInteger integer = getBigInteger();

	printBigInteger(integer);

	system("pause");

	RationalFraction rFraction = getRationalFraction();

	printRationalFraction(rFraction);

	system("pause");
	return 0;
}

