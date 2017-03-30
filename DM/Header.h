#ifndef H_HEADER
#define H_HEADER

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 
enum Sign //Знак целого числа
{
	plus,
	minus
};

struct BigNatural //Натуральное длинное число
{

	short *coef = nullptr;	//Массив коэффициентов
	int size;		//Размер массива (номер старшей позиции)
	int BASE = 10;

	BigNatural();
	~BigNatural();
	BigNatural operator=(BigNatural & bN);
	BigNatural(const BigNatural & bN);
	BigNatural(int number);
};

struct BigInteger	//Длинное целое число
{
	Sign sign;			//Знак числа
	BigNatural number;	//Число 

	BigInteger();
	~BigInteger();
	BigInteger(const BigInteger & bI);
	BigInteger operator=(BigInteger & bI);
	BigInteger(int number);
};

struct RationalFraction	//Рациональная дробь
{
	BigInteger numenator;	//Числитель
	BigNatural denominator;	//Знаменатель

	RationalFraction();
	~RationalFraction();
	RationalFraction(const RationalFraction & rF);
	RationalFraction operator=(RationalFraction & rF);

};

struct Polynom	//Многочлен
{
	int degree;			//Степень многочлена
	RationalFraction* coef = nullptr;		//Массив коэффициентов

	Polynom();
	~Polynom();
	Polynom(const Polynom & polynom);
	Polynom operator=(Polynom & polynom);

};

//***********************************************************************************************
//Методы для работы с натуральными числами

/*Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.*/
int COM_NN_D(BigNatural first, BigNatural second); 

/*Проверка на ноль: если число не равно нулю, то «да» иначе «нет»*/
bool NZER_N_B(BigNatural number);

/*Добавление 1 к натуральному числу*/
BigNatural ADD_1N_N(BigNatural number);

/*Сложение натуральных чисел*/
BigNatural ADD_NN_N(BigNatural first, BigNatural second);

/*Вычитание из первого большего натурального числа второго меньшего или равного*/
BigNatural SUB_NN_N(BigNatural first, BigNatural second);

/*Умножение натурального числа на цифру*/
BigNatural MUL_ND_N(BigNatural number, int factor);

/*	
Умножение натурального числа на 10^k*/
BigNatural MUL_Nk_N(BigNatural number, int tenDegree);

/*Умножение натуральных чисел*/
BigNatural MUL_NN_N(BigNatural first, BigNatural second);

/*Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом*/
BigNatural SUB_NDN_N(BigNatural first, BigNatural second, int factor);

/*Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)*/
int DIV_NN_Dk(BigNatural first, BigNatural second, int tenDegree);

/*Частное от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)*/
BigNatural DIV_NN_N(BigNatural first, BigNatural second);

/*Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)*/
BigNatural MOD_NN_N(BigNatural first, BigNatural second);

/*НОД натуральных чисел*/
BigNatural GCF_NN_N(BigNatural first, BigNatural second);

/*НОК натуральных чисел*/
BigNatural LCM_NN_N(BigNatural first, BigNatural second);


//***********************************************************************************************
//Методы для работы с целыми числами


/*Абсолютная величина числа, результат - натуральное*/
BigNatural ABS_Z_N(BigInteger number);

/*Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)*/
int POZ_Z_D(BigInteger number);

/*Умножение целого на (-1)*/
BigInteger MUL_ZM_Z(BigInteger number);

/*Преобразование натурального в целое*/
BigInteger TRANS_N_Z(BigNatural number);

/*Преобразование целого неотрицательного в натуральное*/
BigNatural TRANS_Z_N(BigInteger number);

/*Сложение целых чисел*/
BigInteger ADD_ZZ_Z(BigInteger first, BigInteger second);

/*Вычитание целых чисел*/
BigInteger SUB_ZZ_Z(BigInteger first, BigInteger second);

/*Умножение целых чисел*/
BigInteger MUL_ZZ_Z(BigInteger first, BigInteger second);

/*Частное от деления большего целого числа на меньшее
или равное натуральное с остатком (делитель отличен от нуля)*/
BigInteger DIV_ZZ_Z(BigInteger first, BigNatural second);

/*Остаток от деления большего целого числа на меньшее или 
равное натуральное с остатком (делитель отличен от нуля)*/
BigInteger MOD_ZZ_Z(BigInteger first, BigNatural second);


//***********************************************************************************************
//Методы для работы с рациональными числами


/*Сокращение дроби*/
RationalFraction RED_Q_Q(RationalFraction number);

/*Проверка на целое, если рациональное число является целым,
то «да», иначе «нет»*/
bool INT_Q_B(RationalFraction number);

/*Преобразование целого в дробное*/
RationalFraction TRANS_Z_Q(BigInteger number);

/*Преобразование дробного в целое 
(если знаменатель равен 1)*/
BigInteger TRANS_Q_Z(RationalFraction number);

/*Сложение дробей*/
RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second);

/*Вычитание дробей*/
RationalFraction SUB_QQ_Q(RationalFraction first, RationalFraction second);

/*Умножение дробей*/
RationalFraction MUL_QQ_Q(RationalFraction first, RationalFraction second);

/*Деление дробей (делитель отличен от нуля)*/
RationalFraction DIV_QQ_Q(RationalFraction first, RationalFraction second);


//***********************************************************************************************
//Методы для работы с многочленами

/*Сложение многочленов*/
Polynom ADD_PP_P(Polynom first, Polynom second);

/*Вычитание многочленов*/
Polynom SUB_PP_P(Polynom first, Polynom second);

/*Умножение многочлена на рациональное число*/
Polynom MUL_PQ_P(Polynom polynom, RationalFraction factor);

/*Умножение многочлена на x^k*/
Polynom MUL_Pxk_P(Polynom polynom, int xDegree);

/*Старший коэффициент многочлена*/
RationalFraction LED_P_Q(Polynom polynom);

/*Степень многочлена*/
int DEG_P_N(Polynom polynom);

/*Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей*/
Polynom FAC_P_Q(Polynom polynom);

/*Умножение многочленов*/
Polynom MUL_PP_P(Polynom first, Polynom second);

/*Частное от деления многочлена на многочлен при делении с остатком*/
Polynom DIV_PP_P(Polynom first, Polynom second);

/*Остаток от деления многочлена на многочлен при делении с остатком*/
Polynom MOD_PP_P(Polynom first, Polynom second);

/*НОД многочленов*/
Polynom GCF_PP_P(Polynom first, Polynom second);

/*Производная многочлена*/
Polynom DER_P_P(Polynom polynom);

/*Преобразование многочлена — кратные корни в простые*/
Polynom NMR_P_P(Polynom polynom);


#endif