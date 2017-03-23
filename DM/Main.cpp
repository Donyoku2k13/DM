#include "Header.h"


int main(void)
{
	printf("Hello world");
	system("pause");
	return 0;
}


void print(BigNatural number)
{
	for (int i = number.size - 1; i > 0; i--)
	{


		printf("%d", number.coef[i]);
	}
}