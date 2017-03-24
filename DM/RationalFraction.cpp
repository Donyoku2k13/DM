#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с рациональными числами

RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second);
{
	RationalFraction result; // 
	BigInteger nokfirst, noksecond; // НОК, деленный на знаменатель(Тип верный?)

	nokfirst = LCM_NN_N(first.denuminator, second.denuminator) / (first.denominator);
	noksecond = LCM_NN_N(first.denuminator, second.denuminator) / (second.denominator);
	result.numenator = ADD_ZZ_Z(MUL_ZZ_Z((nokfirst, first.numinator), MUL_ZZ_Z(noksecond, second.numenator)); // расчитываем числитель
	result.denominator = LCM_NN_N(first.denuminator, second.denuminator);                                 // расчитываем общий знаменатель 
	return result;
}



