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




/*Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)*/
int POZ_Z_D(BigInteger number)
{
	return 0;
}


//Методы для работы с натуральными числами

/*Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.*/
int COM_NN_D(BigNatural first, BigNatural second)
{
	return 0;
}



/*


/*Умножение натуральных чисел*/
BigNatural MUL_NN_N(BigNatural first, BigNatural second)
{
	return first;
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

