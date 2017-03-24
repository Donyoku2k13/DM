#include "Header.h"

/*Сложение многочленов*/
Polynom ADD_PP_P(Polynom first, Polynom second) {
	return first;
}

/*Вычитание многочленов*/
Polynom SUB_PP_P(Polynom first, Polynom second)
{
	return first;
}

/*Умножение многочлена на рациональное число*/
Polynom MUL_PQ_P(Polynom polynom, RationalFraction factor)
{
	return polynom;
}

/*Умножение многочлена на x^k*/
Polynom MUL_Pxk_P(Polynom polynom, int xDegree)
{
	return polynom;
}

/*Старший коэффициент многочлена*/
RationalFraction LED_P_Q(Polynom polynom)
{
	RationalFraction rf;
	return rf;
}



/*Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей*/
Polynom FAC_P_Q(Polynom polynom)
{
	return polynom;
}

/*Умножение многочленов*/
Polynom MUL_PP_P(Polynom first, Polynom second)
{
	return first;
}

/*Частное от деления многочлена на многочлен при делении с остатком*/
Polynom DIV_PP_P(Polynom first, Polynom second)
{
	return first;
}

/*Остаток от деления многочлена на многочлен при делении с остатком*/
Polynom MOD_PP_P(Polynom first, Polynom second)
{
	return first;
}

/*НОД многочленов*/
Polynom GCF_PP_P(Polynom first, Polynom second)
{
	return first;
}


/*Преобразование многочлена — кратные корни в простые*/
Polynom NMR_P_P(Polynom polynom)
{
	return polynom;
}


/*Сокращение дроби*/
RationalFraction RED_Q_Q(RationalFraction number)
{
	return number;
}

/*Проверка на целое, если рациональное число является целым,
то «да», иначе «нет»*/
int INT_Q_B(RationalFraction number)
{
	return 0;
}




/*Сложение дробей*/
RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second)
{
	return first;
}

/*Вычитание дробей*/
RationalFraction SUB_QQ_Q(RationalFraction first, RationalFraction second)
{
	return first;
}

/*Умножение дробей*/
RationalFraction MUL_QQ_Q(RationalFraction first, RationalFraction second)
{
	return first;
}

/*Деление дробей (делитель отличен от нуля)*/
RationalFraction DIV_QQ_Q(RationalFraction first, RationalFraction second)
{
	return first;
}

/*Абсолютная величина числа, результат - натуральное*/
BigNatural ABS_Z_N(BigInteger number);

/*Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)*/
int POZ_Z_D(BigInteger number)
{
	return 0;
}








/*Умножение целых чисел*/
BigInteger MUL_ZZ_Z(BigInteger first, BigInteger second)
{
	return first;
}

/*Частное от деления большего целого числа на меньшее
или равное натуральное с остатком (делитель отличен от нуля)*/
BigInteger DIV_ZZ_Z(BigInteger first, BigInteger second)
{
	return first;
}

/*Остаток от деления большего целого числа на меньшее или
равное натуральное с остатком (делитель отличен от нуля)*/
BigInteger MOD_ZZ_Z(BigInteger first, BigInteger second)
{
	return first;
}


//Методы для работы с натуральными числами

/*Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.*/
int COM_NN_D(BigNatural first, BigNatural second)
{
	return 0;
}

/*Проверка на ноль: если число не равно нулю, то «да» иначе «нет»*/
bool NZER_N_B(BigNatural number)
{
	return true;
}

/*Добавление 1 к натуральному числу*/
BigNatural ADD_1N_N(BigNatural number)
{
	return number;
}

/*Сложение натуральных чисел*/
BigNatural ADD_NN_N(BigNatural first, BigNatural second)
{
	return first;
}


/*Умножение натурального числа на цифру*/
BigNatural MUL_ND_N(BigNatural number, int factor)
{
	return number;
}

/*
Умножение натурального числа на 10^k*/
BigNatural MUL_Nk_N(BigNatural number, int tenDegree)
{
	return number;
}

/*Умножение натуральных чисел*/
BigNatural MUL_NN_N(BigNatural first, BigNatural second)
{
	return first;
}

/*Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом*/
BigNatural SUB_NDN_N(BigNatural first, BigNatural second, int factor)
{
	return first;
}

/*Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)*/
int DIV_NN_Dk(BigNatural first, BigNatural second, int tenDegree)
{
	return 1;
}

/*Частное от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)*/
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
	return first;
}

/*Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)*/
BigNatural MOD_NN_N(BigNatural first, BigNatural second)
{
	return first;
}

/*НОД натуральных чисел*/
BigNatural GCF_NN_N(BigNatural first, BigNatural second)
{
	return first;
}

/*НОК натуральных чисел*/
BigNatural LCM_NN_N(BigNatural first, BigNatural second)
{
	return first;
}