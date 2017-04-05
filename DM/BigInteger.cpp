#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с целыми числами

BigInteger::BigInteger()
{
	sign = plus;
	number = BigNatural();
}

BigInteger::BigInteger(const BigInteger & bI)
{
	sign = bI.sign;
	number = BigNatural(bI.number);
}

BigInteger BigInteger::operator=(BigInteger & bI)
{
	sign = bI.sign;
	number = BigNatural(bI.number);
	return *this;
}

BigInteger::~BigInteger()
{

}

BigInteger::BigInteger(int number)
{
	if (number < 0)
	{
		number = -number;
		sign = minus;
	}
	else
		sign = plus;

	this->number = BigNatural(number);
}


//***************************************************************************************
//Абсолютная величина числа, результат - натуральное
//Лапонина 6307
BigNatural ABS_Z_N(BigInteger number)
{
	return number.number;
}


//***************************************************************************************
//Сложение целых чисел
//Лапонина 6307
BigInteger ADD_ZZ_Z(BigInteger first, BigInteger second)
{
	BigInteger result;
	result.sign = first.sign;
	if (first.sign == second.sign)
		result.number = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
	else
	{
		if (COM_NN_D(ABS_Z_N(first), ABS_Z_N(second)) == 2)//абсолютная величина первого больше абсолютной величины второго
			result.number = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		else
		{
			result.number = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
			if (!NZER_N_B(result.number))
				result.sign = plus; // беру ноль за положительное
			else
				result = MUL_ZM_Z(result);
		}
	}
	return result;
}


//***************************************************************************************
//Вычитание целых чисел
//Лапонина 6307
BigInteger SUB_ZZ_Z(BigInteger first, BigInteger second)
{
	BigInteger result;
	result.sign = first.sign;
	if (first.sign == second.sign)//оба числа одного знака
	{
		if (COM_NN_D(ABS_Z_N(first), ABS_Z_N(second)) == 2)////абсолютная величина первого больше абсолютной величины второго
			result.number = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		else
		{
			result.number = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
			if (COM_NN_D(ABS_Z_N(first), ABS_Z_N(second)) == 0)//если числа равны
				result.sign = plus;
			else
				result = MUL_ZM_Z(result);
		}
	}
	else //числа разных знаков
		result.number = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));

	return result;
}


//***************************************************************************************
//Преобразование натурального в целое
//Лазарев С. 6307
BigInteger TRANS_N_Z(BigNatural number)
{
	BigInteger temp;

	temp.number = number;
	temp.sign = plus;

	return temp;
}


//***************************************************************************************
//Умножение целого на (-1)
//Лазарев С. 6307
BigInteger MUL_ZM_Z(BigInteger number)
{
	if (number.sign == plus && (number.number.coef[0] != 0 || number.number.size != 1))
		number.sign = minus;
	else
		if (number.sign == minus)
			number.sign = plus;
	return number;
}


//***************************************************************************************
//Преобразование целого неотрицательного в натуральное
//Лазарев С. 6307
BigNatural TRANS_Z_N(BigInteger number)
{
	return number.number;
}


//***************************************************************************************
//Частное от деления целого на натуральное
//Медведев 6307
BigInteger DIV_ZZ_Z(BigInteger first, BigInteger second)
{
	BigInteger res;
	if (second.number.coef[0] != 0 || second.number.size != 1) //Если знаментель не ноль, то делим
	{

		res.number = DIV_NN_N(ABS_Z_N(first), ABS_Z_N(second)); //Натуральные части делятся

		res.sign = first.sign == second.sign ? plus : minus;

		if (POZ_Z_D(first) == 1)
			res.number = ADD_1N_N(res.number); //Для того, чтобы остаток был положительным
	}
	else
	{
		printf("Знаменатель должен быть отличен от нуля");
		res.number.size = 0;
	}
	return res;
}


//***************************************************************************************
//Умножение целых чисел
//Лапонина 6307
BigInteger MUL_ZZ_Z(BigInteger first, BigInteger second)
{
	BigInteger result;
	result.number = MUL_NN_N(ABS_Z_N(first), ABS_Z_N(second));
	if (first.sign == second.sign)
		result.sign = plus;
	else
		result.sign = minus;
	return result;
}


//***************************************************************************************
//Остаток от деления целого на натуральное
//Медведев 6307
BigInteger MOD_ZZ_Z(BigInteger first, BigInteger second)
{
	return SUB_ZZ_Z(first, MUL_ZZ_Z(second, DIV_ZZ_Z(first, second)));
}


//***************************************************************************************
/*Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)*/
//Лошаченко 6307
int POZ_Z_D(BigInteger number)
{
	if (NZER_N_B(number.number))
	{
		if (number.sign == plus)
			return 2;
		else
			return 1;
	}
	else 
		return 0;
}