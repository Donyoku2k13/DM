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
			rFractionEnterMenu();
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

void rFractionEnterMenu()
{
	RationalFraction first;
	RationalFraction second;
	bool state = false;

	while (true)
	{
		switch (getMenu(enterMenu, "������������ �����"))
		{
		case 0:
			first = getRationalFraction();
			second = getRationalFraction();
			state = true;
			break;
		case 1:
			if (state)
			{
				printf("������ �����:\n");
				printRationalFraction(first);

				printf("������ �����:\n");
				printRationalFraction(second);
				system("pause");
			}
			else
				infoView("����� �� �������");
			break;
		case 2:

			if (first.denominator.size == 0)
			{
				first = getRationalFraction();
				second = getRationalFraction();
			}
			rFractionMenu(first, second);
			state = true;

			break;
		case 3:
			return;
		}
	}
}

//************************************************************************

void rFractionMenu(RationalFraction first, RationalFraction second)
{
	RationalFraction result;

	while (true)
	{
		switch (getMenu(rationalFractionMenu, "�������� ��������"))
		{
		case 0:
			//TODO

			break;
		case 1:
			result = ADD_QQ_Q(first, second);
			break;
		case 2:
			result = SUB_QQ_Q(first, second);
			break;
		case 3:
			result = MUL_QQ_Q(first, second);
			break;
		case 4:
			result = DIV_QQ_Q(first, second);
			break;
		case 5:
			return;
		}
		printf("���������:\n");
		printRationalFraction(result);
		system("pause");
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
