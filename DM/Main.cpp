#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "Locale.h"
#include "Menu.h"



int main(void)
{
	setlocale(LC_ALL, "Rus");

	while (true)
	{
		switch (getMenu(mainMenu, ""))
		{
		case 0:
			naturalEnterMenu();
			break;
		case 1:
			integerEnterMenu();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			return 0;

		}
	}
}

//************************************************************************

void integerEnterMenu()
{
	BigInteger first;
	BigInteger second;
	bool state = false;

	while (true)
	{
		switch (getMenu(enterMenu, "����� �����"))
		{
		case 0:
			first = getBigInteger("������� ������ �����", "������ ��� ����� �����!");
			second = getBigInteger("������� ������ �����", "������ ��� ����� �����!");
			state = true;
			break;
		case 1:
			if (state)
			{
				printf("������ �����:\n");
				printBigInteger(first);

				printf("������ �����:\n");
				printBigInteger(second);
				system("pause");
			}
			else
				infoView("����� �� �������");
			break;
		case 2:

			if (first.number.size == 0)
			{
				first = getBigInteger("������� ������ �����", "������ ��� ����� �����!");
				second = getBigInteger("������� ������ �����", "������ ��� ����� �����!");
			}
			integerMenu(first, second);
			state = true;

			break;
		case 3:
			return;
		}
	}
}

//************************************************************************

void naturalEnterMenu()
{
	BigNatural first;
	BigNatural second;
	bool state = false;

	while (true)
	{
		switch (getMenu(enterMenu, "����� �����"))
		{
		case 0:
			first = getBigNatural("������� ������ �����", "������ ��� ����� �����!");
			second = getBigNatural("������� ������ �����", "������ ��� ����� �����!");
			state = true;
			break;
		case 1:
			if (state)
			{
				printf("������ �����:\n");
				printBigNatural(first);

				printf("������ �����:\n");
				printBigNatural(second);
				system("pause");
			}
			else
				infoView("����� �� �������");
			break;
		case 2:

			if (first.size == 0)
			{
				first = getBigNatural("������� ������ �����", "������ ��� ����� �����!");
				second = getBigNatural("������� ������ �����", "������ ��� ����� �����!");
			}
			naturalMenu(first, second);
			state = true;

			break;
		case 3:
			return;
		}
	}
}

//************************************************************************


void naturalMenu(BigNatural first, BigNatural second)
{
	BigNatural result;

	while (true)
	{
		switch (getMenu(naturalNumberMenu, "�������� ��������"))
		{
		case 0:
			result = ADD_NN_N(first, second);
			break;
		case 1:
			result = SUB_NN_N(first, second);
			break;
		case 2:
			result = MUL_NN_N(first, second);
			break;
		case 3:
			result = DIV_NN_N(first, second);
			break;
		case 4:
			result = MOD_NN_N(first, second);
			break;
		case 5:
			result = GCF_NN_N(first, second);
			break;
		case 6:
			result = LCM_NN_N(first, second);
			break;
		case 7:
			return;
		}
		printf("���������:\n");
		printBigNatural(result);
		system("pause");
	}
}


//************************************************************************

void integerMenu(BigInteger first, BigInteger second)
{
	BigInteger result;

	while (true)
	{
		switch (getMenu(integerNumberMenu, "�������� ��������"))
		{
		case 0:
			result = ADD_ZZ_Z(first, second);
			break;
		case 1:
			result = SUB_ZZ_Z(first, second);
			break;
		case 2:
			result = MUL_ZZ_Z(first, second);
			break;
		case 3:
			result = DIV_ZZ_Z(first, second);
			break;
		case 4:
			result = MOD_ZZ_Z(first, second);
			break;
		case 5:
			return;
		}
		printf("���������:\n");
		printBigInteger(result);
		system("pause");
	}
}

//************************************************************************
