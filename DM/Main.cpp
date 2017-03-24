#include "Header.h"
#include "ParserHeader.h"
#include "Input.h"
#include "Output.h"
#include "Locale.h"




int main(void)
{
	setlocale(LC_ALL, "Rus");
	printBigInteger(getBigInteger("¬ведите число","„исло введено не верно"));

	system("pause");
	return 0;
}



