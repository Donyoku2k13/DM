#include "Header.h"
#include "ParserHeader.h"
#include "Input.h"
#include "Output.h"
#include "Locale.h"




int main(void)
{
	setlocale(LC_ALL, "Rus");
	printBigInteger(getBigInteger("������� �����","����� ������� �� �����"));

	system("pause");
	return 0;
}



