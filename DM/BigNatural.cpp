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
	int i;
	for (i = 0; i < number.size; i++)
	{
		if (number.coef[i] != 0) // Если хотя бы одна цифра не равна нулю, то возвращаем true
		{
			return true;
		}
	}
	return false; 
}

//Добавление единицы к длинному числу
BigNatural ADD_1N_N(BigNatural number)
{
	int counter = 1;
	BigNatural result;
	result = number;
	if (result.coef[result.size - 1] != 9) // Если последняя цифра не равна девяти, прибавляем единицу
	{
		result.coef[result.size - 1]++;
	}
	else
	{
		while (result.coef[result.size - counter] == 9 && counter != result.size) // Если последняя цифра не равна 9, то ищем первую цифру не равную 9, прибавляем к ней единицу, и всем предыдущем присваиваем 0
		{
			result.coef[result.size - counter] = 0;
			counter++;
		}
		if (counter == result.size) // Если все цифры равны 9, увеличиваем массив на единицу, первой цифре присваеваем 1, всем остальным присваеваем 0
		{
			result.coef = (short*) realloc(result.coef, sizeof(short)* (result.size + 1));
			result.coef[0] = 1;
			for (int i = 1; i < result.size; i++)
			{
				result.coef[i] = 0;
			}
		}
		else
		{
			result.coef[result.size - counter]++;
		}
	}
	return result;
}



