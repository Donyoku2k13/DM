#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с многочленами

Polynom GCF_PP_P(Polynom first, Polynom second)
{
	Polynom ost;

	while (DEG_P_N(second) != 0 || NZER_N_B(TRANS_Z_N(second.coef[0].numenator)))
	{
		ost = MOD_PP_P(first, second);
		first = second;
		second = ost;
	}

	return first;
}