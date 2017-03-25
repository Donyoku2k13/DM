#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с натуральными числами


BigNatural SUB_NN_N(BigNatural first, BigNatural second)
{
	//Если второе меньше первого, то вызываем наоборот
	if (COM_NN_D(first, second) == 1)
		return SUB_NN_N(second, first);
	BigNatural result;
	int i;
	short temp; 
	short carry = 0;

	short* a = first.coef; //Уменьшаемое 

	short* b = second.coef; //Вычитаемое

	//Результат не больше первого, а потом можно и уменьшить
	short* resCoef = (short*)malloc(sizeof(short) * first.size);


	for (int i = 0; i < second.size; i++)
	{
		temp = a[i] - b[i] + carry;
		if (temp < 0)
		{
			resCoef[i] = temp + first.BASE;
			carry = -1;
		}
		else
		{
			resCoef[i] = temp;
			carry = 0;
		}
	}


	for (i = second.size; i<first.size; i++) {
		temp = a[i] + carry;
		if (temp < 0) {
			resCoef[i] = temp + first.BASE;
			carry = -1;
		}
		else {
			resCoef[i] = temp;
			carry = 0;
		}
	}

	//Вычисление реального размера числа
	i = first.size - 1;
	while ((i>0) && (resCoef[i] == 0)) i--;
	resCoef = (short*)realloc(resCoef, sizeof(short) * (i + 1));
	

	result.size = i + 1;
	result.coef = resCoef;

	return result;
}

//Проверка на ноль
bool NZER_N_B(BigNatural number)
{
	if (number.coef[0] == 0 && number.size == 1) // Если первый разряд равен нулю и размер равен единице возвращаем false
	{
		return false;
	}
	return true; 
}


//Добавление единицы к длинному числу
BigNatural ADD_1N_N(BigNatural number)
{
	int counter = 1;
	BigNatural result;
	result = number;
	if (result.coef[0] != 9) // Если последняя цифра не равна девяти, прибавляем единицу
	{
		result.coef[0]++;
	}
	else
	{
		while (counter != result.size && result.coef[counter] == 9) // Если последняя цифра не равна 9, то ищем первую цифру не равную 9, прибавляем к ней единицу, и всем предыдущем присваиваем 0
		{
			result.coef[counter] = 0;
			counter++;
		}
		if (counter == result.size) // Если все цифры равны 9, увеличиваем массив на единицу, первой цифре присваеваем 1
		{
			result.coef = (short*) realloc(result.coef, sizeof(short)* (result.size + 1));
			result.size++;
			result.coef[result.size-1] = 1;
		}
		else
		{
			result.coef[counter]++;
		}
	}
	return result;
}


BigNatural GCF_NN_N(BigNatural first, BigNatural second)
{
	BigNatural result;
	BigNatural ost;
	while (NZER_N_B(second))
	{
		ost = MOD_NN_N(first, second);
		first.coef = second.coef;
		first.size = second.size;
		second.coef = ost.coef;
		second.size = ost.size;
	}

	result.size = first.size;
	result.coef = first.coef;
	return result;
}

	//Умножение натурального числа на 10^k 
BigNatural MUL_Nk_N(BigNatural number, int tenDegree)
{
	BigNatural result;
	int r = 0;
	int size = number.size + tenDegree;

	short* resCoef = (short*)malloc(sizeof(short) * (size));

	for (int i = number.size - 1; i >= 0; i--)
		resCoef[i + tenDegree] = number.coef[i];
	for (int i = 0; i < tenDegree; i++)
		resCoef[i] = 0;
	result.size = size;
	result.coef = resCoef;
	return result;
}


/*Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом*/
BigNatural SUB_NDN_N(BigNatural first, BigNatural second, int factor)
{
	return (SUB_NN_N(first, MUL_ND_N(second, factor)));
}

/*Сложение натуральных чисел*/
BigNatural ADD_NN_N(BigNatural first, BigNatural second)
{
	BigNatural result;
	int i;
	int r = 0;

	if (COM_NN_D(first, second) == 1)
		return ADD_NN_N(second, first);

	short* resCoef = (short*)malloc(sizeof(short) * (first.size));

	for (i = 0; i < second.size; i++)
	{
		resCoef[i] = (first.coef[i] + second.coef[i] + r) % 10;
		r = (first.coef[i] + second.coef[i] + r) / 10;
	}

	for (i = second.size; i<first.size; i++)
	{
		resCoef[i] = (first.coef[i] + r) % 10;
		r = (first.coef[i] + r) / 10;
	}

	if (r)
	{
		resCoef = (short*)realloc(resCoef, sizeof(short) * (first.size + 1));
		result.size = first.size + 1;
		resCoef[first.size] = r;
	}
	else
		result.size = first.size;
	result.coef = resCoef;
	return result;
}