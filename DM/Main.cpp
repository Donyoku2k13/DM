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
			freeBigInteger(first);
			freeBigInteger(second);

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

			freeBigInteger(first);
			freeBigInteger(second);

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
			freeBigNatural(first);
			freeBigNatural(second);

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

			freeBigNatural(first);
			freeBigNatural(second);

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
			freeRFraction(first);
			freeRFraction(second);

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

			freeRFraction(first);
			freeRFraction(second);

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
			freePolynom(first);
			freePolynom(second);

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

			freePolynom(first);
			freePolynom(second);

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
	char* resultPol = nullptr;

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
			freePolynom(result);

			result = ADD_PP_P(first,second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("%s + %s = %s\n", firstPol, secondPol, resultPol);
			break;
		case 1:
			freePolynom(result);

			result = SUB_PP_P(first, second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("%s - %s = %s\n", firstPol, secondPol, resultPol);
			break;
		case 2:
			freePolynom(result);

			result = FAC_P_Q(isFirst ? first : second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("%s ==> %s\n", isFirst ? firstPol : secondPol, resultPol);
			break;
		case 3:
			freePolynom(result);

			result = MUL_PP_P(first, second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("%s * %s = %s\n", firstPol, secondPol, resultPol);
			break;
		case 4:
			freePolynom(result);

			result = DIV_PP_P(first, second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("%s / %s = %s\n", firstPol, secondPol, resultPol);
			break;
		case 5:
			freePolynom(result);

			result = MOD_PP_P(first, second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("%s % %s = %s\n", firstPol, secondPol, resultPol);
			break;
		case 6:
			freePolynom(result);

			result = GCF_PP_P(first, second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("НОД( %s , %s ) = %s\n", firstPol, secondPol, resultPol);
			break;
		case 7:
			freePolynom(result);

			result = DER_P_P(isFirst ? first : second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("( %s )' = %s\n", isFirst ? firstPol : secondPol, resultPol);
			break;
		case 8:
			freePolynom(result);

			result = NMR_P_P(isFirst ? first : second);

			if (resultPol)
				free(resultPol);
			resultPol = polynomToString(result);

			printf("%s ==> %s\n", isFirst ? firstPol : secondPol, resultPol);
			break;
		case 9:
			freePolynom(result);
			free(firstPol);
			free(secondPol);
			if (resultPol)
				free(resultPol);

			return;
		}
		system("pause");
	}
}


//************************************************************************

void rFractionMenu(RationalFraction first, RationalFraction second)
{
	RationalFraction result;
	bool isFirst = true;
	char* firstStr = rationalFractionToString(first);
	char* secondStr = rationalFractionToString(second);
	char* resultStr = nullptr;



	while (true)
	{
		switch (getMenu(rationalFractionMenu, "Выберите действие"))
		{
		case 0:
			isFirst = !getMenu(oneOrTwoMenu, "Для какого числа выполнить действие ?");
			freeRFraction(result);

			result = RED_Q_Q(isFirst ? first : second);

			if (resultStr)
				free(resultStr);
			resultStr = rationalFractionToString(result);

			printf("%s = %s\n", isFirst ? firstStr : secondStr, resultStr);
			break;
		case 1:
			freeRFraction(result);

			result = ADD_QQ_Q(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = rationalFractionToString(result);

			printf("%s + %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 2:
			freeRFraction(result);

			result = SUB_QQ_Q(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = rationalFractionToString(result);

			printf("%s - %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 3:
			freeRFraction(result);

			result = MUL_QQ_Q(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = rationalFractionToString(result);

			printf("%s * %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 4:
			freeRFraction(result);

			result = DIV_QQ_Q(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = rationalFractionToString(result);

			printf("%s / %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 5:

			freeRFraction(result);
			free(firstStr);
			free(secondStr);
			if (resultStr)
				free(resultStr);

			return;
		}
		system("pause");
	}
}


//************************************************************************

void naturalMenu(BigNatural first, BigNatural second)
{
	BigNatural result;
	char* firstStr = bigNaturalToString(first);
	char* secondStr = bigNaturalToString(second);
	char* resultStr = nullptr;

	while (true)
	{
		switch (getMenu(naturalNumberMenu, "Выберите действие"))
		{
		case 0:
			freeBigNatural(result);

			result = ADD_NN_N(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigNaturalToString(result);

			printf("%s + %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 1:
			freeBigNatural(result);

			result = SUB_NN_N(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigNaturalToString(result);

			printf("|%s - %s| = %s\n", firstStr, secondStr, resultStr);
			break;
		case 2:
			freeBigNatural(result);

			result = MUL_NN_N(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigNaturalToString(result);

			printf("%s * %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 3:
			freeBigNatural(result);

			result = DIV_NN_N(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigNaturalToString(result);

			printf("%s / %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 4:
			freeBigNatural(result);

			result = MOD_NN_N(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigNaturalToString(result);

			printf("%s % %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 5:
			freeBigNatural(result);

			result = GCF_NN_N(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigNaturalToString(result);

			printf("НОД( %s , %s ) = %s\n", firstStr, secondStr, resultStr);
			break;
		case 6:
			freeBigNatural(result);

			result = LCM_NN_N(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigNaturalToString(result);

			printf("НОК( %s , %s ) = %s\n", firstStr, secondStr, resultStr);
			break;
		case 7:

			freeBigNatural(result);
			free(firstStr);
			free(secondStr);
			if (resultStr)
				free(resultStr);
			return;
		}
		system("pause");
	}
}


//************************************************************************

void integerMenu(BigInteger first, BigInteger second)
{
	BigInteger result;
	char* firstStr = bigIntegerToString(first);
	char* secondStr = bigIntegerToString(second);
	char* resultStr = nullptr;

	while (true)
	{
		switch (getMenu(integerNumberMenu, "Выберите действие"))
		{
		case 0:
			freeBigInteger(result);

			result = ADD_ZZ_Z(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigIntegerToString(result);

			printf("%s + %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 1:
			freeBigInteger(result);

			result = SUB_ZZ_Z(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigIntegerToString(result);

			printf("%s - %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 2:
			freeBigInteger(result);

			result = MUL_ZZ_Z(first, second);

			if (resultStr)
				free(resultStr);
			resultStr = bigIntegerToString(result);

			printf("%s * %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 3:
			freeBigInteger(result);

			result = DIV_ZZ_Z(first, ABS_Z_N(second));

			if (resultStr)
				free(resultStr);
			resultStr = bigIntegerToString(result);

			printf("%s / %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 4:
			freeBigInteger(result);

			result = MOD_ZZ_Z(first, ABS_Z_N(second));

			if (resultStr)
				free(resultStr);
			resultStr = bigIntegerToString(result);

			printf("%s % %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 5:
			freeBigInteger(result);
			free(firstStr);
			free(secondStr);
			if (resultStr)
				free(resultStr);

			return;
		}
		system("pause");
	}
}

//************************************************************************

void help()
{
	printf("Справка!");
	system("pause");
}
