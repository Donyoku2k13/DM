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
			polynomEnterMenu();
			break;
		case 4:
			help();
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
	char* firstNum = nullptr;
	char* secondNum = nullptr;

	while (true)
	{
		switch (getMenu(enterMenu, "Целые числа"))
		{
		case 0:

			first = getBigInteger("Введите первое число", "Ошибка при вводе числа!");
			second = getBigInteger("Введите второе число", "Ошибка при вводе числа!");
			state = true;
			break;

		case 1:

			if (state)
			{
				if (firstNum)
					free(firstNum);
				if (secondNum)
					free(secondNum);

				firstNum = bigIntegerToString(first);
				secondNum = bigIntegerToString(second);

				printf("Первое число:\n%s\n", firstNum);
				printf("Второе число:\n%s\n", secondNum);

				system("pause");
			}
			else
				infoView("Числа не введены");
			break;

		case 2:

			if (state)
				integerMenu(first, second);
			else
				infoView("Числа не введены");
			break;

		case 3:
			if (firstNum)
				free(firstNum);
			if (secondNum)
				free(secondNum);
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
	char* firstNum = nullptr;
	char* secondNum = nullptr;

	while (true)
	{
		switch (getMenu(enterMenu, "Целые числа"))
		{
		case 0:

			first = getBigNatural("Введите первое число", "Ошибка при вводе числа!");
			second = getBigNatural("Введите второе число", "Ошибка при вводе числа!");
			state = true;
			break;

		case 1:

			if (state)
			{
				if (firstNum)
					free(firstNum);
				if (secondNum)
					free(secondNum);

				firstNum = bigNaturalToString(first);
				secondNum = bigNaturalToString(second);

				printf("Первое число:\n%s\n", firstNum);
				printf("Второе число:\n%s\n", secondNum);

				system("pause");
			}
			else
				infoView("Числа не введены");
			break;

		case 2:

			if (state)
				naturalMenu(first, second);
			else 
				infoView("Числа не введены");
			break;

		case 3:
			if (firstNum)
				free(firstNum);
			if (secondNum)
				free(secondNum);
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
	char* firstNum = nullptr;
	char* secondNum = nullptr;

	while (true)
	{
		switch (getMenu(enterMenu, "Рациональные числа"))
		{
		case 0:
			printf("Введите первое число:\n");
			first = getRationalFraction();
			printf("Введите второе число:\n");
			second = getRationalFraction();
			state = true;
			break;

		case 1:

			if (state)
			{
				if (firstNum)
					free(firstNum);
				if (secondNum)
					free(secondNum);

				firstNum = rationalFractionToString(first);
				secondNum = rationalFractionToString(second);

				printf("Первое число:\n%s\n", firstNum);
				printf("Второе число:\n%s\n", secondNum);

				system("pause");
			}
			else
				infoView("Числа не введены");
			break;

		case 2:

			if (state)
				rFractionMenu(first, second);
			else
				infoView("Числа не введены");

			break;
		case 3:
			if (firstNum)
				free(firstNum);
			if (secondNum)
				free(secondNum);
			return;
		}
	}
}

//************************************************************************

void polynomEnterMenu()
{
	Polynom first;
	Polynom second;
	bool state = false;
	char* firstPol = nullptr;
	char* secondPol = nullptr;

	while (true)
	{
		switch (getMenu(enterPolynomMenu, "Многочлены"))
		{
		case 0:

			first = getPolynom();
			second = getPolynom();
			state = true;
			break;

		case 1:

			if (state)
			{
				if (firstPol)
					free(firstPol);
				if (secondPol)
					free(secondPol);

				firstPol = polynomToString(first);
				secondPol = polynomToString(second);
				
				printf("Первый многочлен:\n%s\n", firstPol);
				printf("Второй многочлен:\n%s\n", secondPol);

				system("pause");
			}
			else
				infoView("Числа не введены");
			break;

		case 2:

			if (state)
				polynomEMenu(first, second);
			else
				infoView("Числа не введены");

			break;
		case 3:
			if (firstPol)
				free(firstPol);
			if (secondPol)
				free(secondPol);
			return;
		}
	}
}

//************************************************************************

void polynomEMenu(Polynom first, Polynom second)
{
	Polynom result;
	int currentCase = 0;
	bool isFirst = true; //Какой многочлен будет при одиночном действии
	char* firstPol = polynomToString(first);
	char* secondPol = polynomToString(second);

	while (true)
	{
		currentCase = getMenu(polynomMenu, "Выберите действие");

		switch (currentCase)
		{
		case 2:
		case 7:
		case 8:
			isFirst = !getMenu(oneOrTwoMenu, "Для какого многочлена выполнить действие?");
		}

		switch (currentCase)
		{
		case 0:
			result = ADD_PP_P(first,second);
			printf("%s + %s = %s\n", firstPol, secondPol, polynomToString(result));
			break;
		case 1:
			result = SUB_PP_P(first, second);
			printf("%s - %s = %s\n", firstPol, secondPol, polynomToString(result));
			break;
		case 2:
			result = FAC_P_Q(isFirst ? first : second);
			printf("%s ==> %s\n", isFirst ? firstPol : secondPol, polynomToString(result));
			break;
		case 3:
			result = MUL_PP_P(first, second);
			printf("%s * %s = %s\n", firstPol, secondPol, polynomToString(result));
			break;
		case 4:
			result = DIV_PP_P(first, second);
			printf("%s / %s = %s\n", firstPol, secondPol, polynomToString(result));
			break;
		case 5:
			result = MOD_PP_P(first, second);
			printf("%s % %s = %s\n", firstPol, secondPol, polynomToString(result));
			break;
		case 6:
			result = GCF_PP_P(first, second);
			printf("НОД( %s , %s ) = %s\n", firstPol, secondPol, polynomToString(result));
			break;
		case 7:
			result = DER_P_P(isFirst ? first : second);
			printf("( %s )' = %s\n", isFirst ? firstPol : secondPol, polynomToString(result));
			break;
		case 8:
			result = NMR_P_P(isFirst ? first : second);
			printf("%s ==> %s\n", isFirst ? firstPol : secondPol, polynomToString(result));
			break;
		case 9:
			free(firstPol);
			free(secondPol);

			return;
		}
		system("pause");
	}
}


//************************************************************************

void rFractionMenu(RationalFraction first, RationalFraction second)
{
	RationalFraction result;
	int currentCase;
	char string[1000];
	bool isFirst = true;
	
	string[0] = 0;



	while (true)
	{
		currentCase = getMenu(rationalFractionMenu, "Выберите действие");
		switch (currentCase)
		{
		case 0:
			sprintf(string, "Для какого числа выполнить действие ? \n1)\t%s\n2)\t%s", rationalFractionToString(second), rationalFractionToString(first));
			isFirst = !getMenu(oneOrTwoMenu, string);
		}

		switch (currentCase)
		{
		case 0:
			result = RED_Q_Q(isFirst ? first : second);
			printf("%s = %s\n", rationalFractionToString(isFirst ? first : second), rationalFractionToString(result));
			break;
		case 1:
			result = ADD_QQ_Q(first, second);
			printf("%s + %s = %s\n", rationalFractionToString(first), rationalFractionToString(second), rationalFractionToString(result));
			break;
		case 2:
			result = SUB_QQ_Q(first, second);
			printf("%s - %s = %s\n", rationalFractionToString(first), rationalFractionToString(second), rationalFractionToString(result));
			break;
		case 3:
			result = MUL_QQ_Q(first, second);
			printf("%s * %s = %s\n", rationalFractionToString(first), rationalFractionToString(second), rationalFractionToString(result));
			break;
		case 4:
			result = DIV_QQ_Q(first, second);
			printf("%s / %s = %s\n", rationalFractionToString(first), rationalFractionToString(second), rationalFractionToString(result));
			break;
		case 5:
			return;
		}
		system("pause");
	}
}


//************************************************************************

void naturalMenu(BigNatural first, BigNatural second)
{
	BigNatural result;

	while (true)
	{
		switch (getMenu(naturalNumberMenu, "Выберите действие"))
		{
		case 0:
			result = ADD_NN_N(first, second);
			printf("%s + %s = %s\n", bigNaturalToString(first), bigNaturalToString(second), bigNaturalToString(result));
			break;
		case 1:
			result = SUB_NN_N(first, second);
			printf("|%s - %s| = %s\n", bigNaturalToString(first), bigNaturalToString(second), bigNaturalToString(result));
			break;
		case 2:
			result = MUL_NN_N(first, second);
			printf("%s * %s = %s\n", bigNaturalToString(first), bigNaturalToString(second), bigNaturalToString(result));
			break;
		case 3:
			result = DIV_NN_N(first, second);
			printf("%s / %s = %s\n", bigNaturalToString(first), bigNaturalToString(second), bigNaturalToString(result));
			break;
		case 4:
			result = MOD_NN_N(first, second);
			printf("%s % %s = %s\n", bigNaturalToString(first), bigNaturalToString(second), bigNaturalToString(result));
			break;
		case 5:
			result = GCF_NN_N(first, second);
			printf("НОД( %s , %s ) = %s\n", bigNaturalToString(first), bigNaturalToString(second), bigNaturalToString(result));
			break;
		case 6:
			result = LCM_NN_N(first, second);
			printf("НОК( %s , %s ) = %s\n", bigNaturalToString(first), bigNaturalToString(second), bigNaturalToString(result));
			break;
		case 7:
			return;
		}
		system("pause");
	}
}


//************************************************************************

void integerMenu(BigInteger first, BigInteger second)
{
	BigInteger result;

	while (true)
	{
		switch (getMenu(integerNumberMenu, "Выберите действие"))
		{
		case 0:
			result = ADD_ZZ_Z(first, second);
			printf("%s + %s = %s\n", bigIntegerToString(first), bigIntegerToString(second), bigIntegerToString(result));
			break;
		case 1:
			result = SUB_ZZ_Z(first, second);
			printf("%s - %s = %s\n", bigIntegerToString(first), bigIntegerToString(second), bigIntegerToString(result));
			break;
		case 2:
			result = MUL_ZZ_Z(first, second);
			printf("%s * %s = %s\n", bigIntegerToString(first), bigIntegerToString(second), bigIntegerToString(result));
			break;
		case 3:
			result = DIV_ZZ_Z(first, ABS_Z_N(second));
			printf("%s / %s = %s\n", bigIntegerToString(first), bigNaturalToString(ABS_Z_N(second)), bigIntegerToString(result));
			break;
		case 4:
			result = MOD_ZZ_Z(first, ABS_Z_N(second));
			printf("%s % %s = %s\n", bigIntegerToString(first), bigNaturalToString(ABS_Z_N(second)), bigIntegerToString(result));
			break;
		case 5:
			return;
		}
		system("pause");
	}
}

//************************************************************************

void help()
{
	printf("Справка!");
	system("cls");
}
