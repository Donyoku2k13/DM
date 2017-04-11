#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "Locale.h"
#include "Menu.h"
#include "ParserHeader.h"


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

			if (firstNum)
				delete[] firstNum;
			if (secondNum)
				delete[] secondNum;

			firstNum = bigIntegerToString(first);
			secondNum = bigIntegerToString(second);

			printf("Первое число:\n%s\n", firstNum);
			printf("Второе число:\n%s\n", secondNum);

			system("pause");
			
			break;

		case 2:

			integerMenu(first, second);

			break;

		case 3:
			if (firstNum)
				delete[] firstNum;
			if (secondNum)
				delete[] secondNum;

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
		switch (getMenu(enterMenu, "Натуральные числа"))
		{
		case 0:

			first = getBigNatural("Введите первое число", "Ошибка при вводе числа!");
			second = getBigNatural("Введите второе число", "Ошибка при вводе числа!");

			state = true;
			break;

		case 1:


			if (firstNum)
				delete[] firstNum;
			if (secondNum)
				delete[] secondNum;

			firstNum = bigNaturalToString(first);
			secondNum = bigNaturalToString(second);

			printf("Первое число:\n%s\n", firstNum);
			printf("Второе число:\n%s\n", secondNum);

			system("pause");

			break;

		case 2:

			naturalMenu(first, second);

			break;

		case 3:
			if (firstNum)
				delete[] firstNum;
			if (secondNum)
				delete[] secondNum;

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
			first = getRationalFraction("Введите первое число (a/b)", "Ошибка при вводе числа!");
			second = getRationalFraction("Введите второе число (a/b)", "Ошибка при вводе числа!");
			state = true;
			break;

		case 1:

			if (firstNum)
				delete[] firstNum;
			if (secondNum)
				delete[] secondNum;

			firstNum = rationalFractionToString(first);
			secondNum = rationalFractionToString(second);

			printf("Первое число:\n%s\n", firstNum);
			printf("Второе число:\n%s\n", secondNum);

			system("pause");
			

			break;

		case 2:

			rFractionMenu(first, second);
	

			break;
		case 3:
			if (firstNum)
				delete[] firstNum;
			if (secondNum)
				delete[] secondNum;

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

			if (firstPol)
				delete[] firstPol;
			if (secondPol)
				delete[] secondPol;

			firstPol = polynomToString(first);
			secondPol = polynomToString(second);
				
			printf("Первый многочлен:\n%s\n", firstPol);
			printf("Второй многочлен:\n%s\n", secondPol);

			system("pause");
			
			break;

		case 2:

			polynomEMenu(first, second);

			break;
		case 3:

			if (firstPol)
				delete[] firstPol;
			if (secondPol)
				delete[] secondPol;
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

			result = ADD_PP_P(first,second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("%s\n+\n%s\n=\n%s\n", firstPol, secondPol, resultPol);
			break;
		case 1:

			result = SUB_PP_P(first, second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("%s\n-\n%s\n=\n%s\n", firstPol, secondPol, resultPol);
			break;
		case 2:

			result = FAC_P_Q(isFirst ? first : second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("%s ==> %s\n", isFirst ? firstPol : secondPol, resultPol);
			break;
		case 3:

			result = MUL_PP_P(first, second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("%s\n*\n%s\n=\n%s\n", firstPol, secondPol, resultPol);
			break;
		case 4:

			result = DIV_PP_P(first, second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("%s\n/\n%s\n=\n%s\n", firstPol, secondPol, resultPol);
			break;
		case 5:

			result = MOD_PP_P(first, second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("%s\n%%\n%s\n=\n%s\n", firstPol, secondPol, resultPol);
			break;
		case 6:

			result = GCF_PP_P(first, second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("НОД( %s , %s ) = %s\n", firstPol, secondPol, resultPol);
			break;
		case 7:

			result = DER_P_P(isFirst ? first : second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("( %s )' = %s\n", isFirst ? firstPol : secondPol, resultPol);
			break;
		case 8:

			result = NMR_P_P(isFirst ? first : second);

			if (resultPol)
				delete[] resultPol;
			resultPol = polynomToString(result);

			printf("%s ==> %s\n", isFirst ? firstPol : secondPol, resultPol);
			break;
		case 9:

			delete[] firstPol;
			delete[] secondPol;
			if (resultPol)
				delete[] resultPol;

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

			result = RED_Q_Q(isFirst ? first : second);

			if (resultStr)
				delete[] resultStr;
			resultStr = rationalFractionToString(result);

			printf("%s = %s\n", isFirst ? firstStr : secondStr, resultStr);
			break;
		case 1:

			result = ADD_QQ_Q(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = rationalFractionToString(result);

			printf("%s + %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 2:

			result = SUB_QQ_Q(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = rationalFractionToString(result);

			printf("%s - %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 3:

			result = MUL_QQ_Q(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = rationalFractionToString(result);

			printf("%s * %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 4:

			result = DIV_QQ_Q(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = rationalFractionToString(result);

			printf("( %s ) / ( %s ) = %s\n", firstStr, secondStr, resultStr);
			break;
		case 5:

			delete[] firstStr;
			delete[] secondStr;
			if (resultStr)
				delete[] resultStr;

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

			result = ADD_NN_N(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigNaturalToString(result);

			printf("%s + %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 1:

			result = SUB_NN_N(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigNaturalToString(result);

			printf("|%s - %s| = %s\n", firstStr, secondStr, resultStr);
			break;
		case 2:

			result = MUL_NN_N(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigNaturalToString(result);

			printf("%s * %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 3:

			result = DIV_NN_N(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigNaturalToString(result);

			printf("%s / %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 4:

			result = MOD_NN_N(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigNaturalToString(result);

			printf("%s %% %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 5:

			result = GCF_NN_N(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigNaturalToString(result);

			printf("НОД( %s , %s ) = %s\n", firstStr, secondStr, resultStr);
			break;
		case 6:

			result = LCM_NN_N(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigNaturalToString(result);

			printf("НОК( %s , %s ) = %s\n", firstStr, secondStr, resultStr);
			break;
		case 7:
			free(firstStr);
			free(secondStr);
			if (resultStr)
				delete[] resultStr;
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

			result = ADD_ZZ_Z(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigIntegerToString(result);

			printf("%s + %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 1:

			result = SUB_ZZ_Z(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigIntegerToString(result);

			printf("%s - %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 2:

			result = MUL_ZZ_Z(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigIntegerToString(result);

			printf("%s * %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 3:

			result = DIV_ZZ_Z(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigIntegerToString(result);

			printf("%s / %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 4:

			result = MOD_ZZ_Z(first, second);

			if (resultStr)
				delete[] resultStr;
			resultStr = bigIntegerToString(result);

			printf("%s %% %s = %s\n", firstStr, secondStr, resultStr);
			break;
		case 5:
			free(firstStr);
			free(secondStr);
			if (resultStr)
				delete[] resultStr;

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
