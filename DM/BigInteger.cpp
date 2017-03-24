#include "Header.h"

//В этом файле должны быть ТОЛЬКО реализации методов для работы с целыми числами

BigNatural ABS_Z_N(BigInteger number)
{
	return number.number;
}

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


BigNatural TRANS_Z_N(BigInteger number)
{
	BigNatural temp;
	temp.size = number.number.size;
	temp.coef = (short*)malloc(temp.size * sizeof(short));
	temp.coef = new short(temp.size);
	for (int i = 0; i < temp.size; i++)
		temp.coef[i] = number.number.coef[i];
	return temp;
}
