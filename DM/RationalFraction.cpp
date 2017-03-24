#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с рациональными числами



RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction result; 
	BigNatural nokfirst, noksecond; // НОК, деленный на знаменатель(Тип верный?) 
	BigInteger nok1, nok2;//Ром, если придумаешь более красивый способ избежать несоответствие типов в расчете числителя расскажи потом)

	nokfirst = DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (first.denominator));
	noksecond = DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (second.denominator));
	nok1.number = nokfirst;
	nok2.number = noksecond;
	result.numenator = ADD_ZZ_Z(MUL_ZZ_Z(nok1, first.numenator), MUL_ZZ_Z(nok2, second.numenator)); // расчитываем числитель
	result.denominator = LCM_NN_N(first.denominator, second.denominator); // расчитываем общий знаменатель 
	return result;
}



