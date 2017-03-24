#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с рациональными числами


RationalFraction SUB_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction result;
	BigInteger nok1, nok2;

	nok1 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (first.denominator)));
	nok2 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (second.denominator)));

	result.numenator =  SUB_ZZ_Z(MUL_ZZ_Z(nok1, first.numenator), MUL_ZZ_Z(nok2, second.numenator));
	result.denominator = LCM_NN_N(first.denominator, second.denominator); 

	return result;
}