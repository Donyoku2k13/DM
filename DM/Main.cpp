#include "ParserHeader.h"


void print(BigNatural);

int main(void)
{
	/*BigNatural first;
	BigNatural second;

	short firstCoef[] = { 7,3 };
	short secondCoef[] = { 7,3 };

	first.coef = firstCoef;
	first.size = 2;

	second.coef = secondCoef;
	second.size = 2;

	print(SUB_NN_N(first, second));
	*/

	char string[] = "-5445362";
	printf("%s", partArrayCopy(string, 2));

	system("pause");
	return 0;
}


void print(BigNatural number)
{
	for (int i = number.size - 1; i >= 0; i--)
	{


		printf("%d", number.coef[i]);
	}
}