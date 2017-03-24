#include "Header.h"
#include "ParserHeader.h"



void print(BigNatural);
void print(BigInteger);

int main(void)
{

	char string[] = "-5445362";
	print(parseToBigInteger(string));

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

void print(BigInteger number)
{
	if (number.sign = minus)
		printf("-");
	print(number.number);

}