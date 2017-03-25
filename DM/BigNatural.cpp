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


//Деление с остатком
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
  int k;
  int kM;
  BigNatural n; //Делимое
  BigNatural m; //Делитель
  BigNatural res;//Результат
  int a; //Первая цифра деления

  n = first;
  m = second;
  res.coef[0] = 0;
  if (!NZER_N_B)                                       //Если делитель равен нулю
    printf("Делитель должен быть больше нуля!");
  else
  {
    if (COM_NN_D(first, second) == 0)                    //Если первое равно второму
    {
      res.coef = (short*)malloc(sizeof(short));
      res.coef[0] = 1;
      res.size = 1;
      return res;                                       //Возвращаем единицу
    }
    else
      if (COM_NN_D(first, second) == 1)                 //Если второе больше первого
      {
        res.coef = (short*)malloc(sizeof(short));
        res.coef[0] = 0;
        res.size = 0;
        return res;                                     //Возвращаем нуль
      }
    else
    if (COM_NN_D(first, second) == 2)
    {
      kM = first.size - second.size;
      k = kM;
      for (k; k >= 0; k--)
      {
        a = DIV_NN_Dk(n, m, k);
        m = MUL_Nk_N(m, 1);
        n = SUB_NDN_N(n, m, a);
        res.coef[kM - k + 1] = res.coef[kM - k];
        res.coef[kM - k] = a;
      }
    }
    return res;
  }
}
//Остаток от деления
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
  int k;
  int kM;
  BigNatural n; //Делимое
  BigNatural m; //Делитель
  BigNatural res;//Результат
  int a; //Первая цифра деления

  n = first;
  m = second;
  res.coef[0] = 0;
  if (!NZER_N_B)                                       //Если делитель равен нулю
    printf("Делитель должен быть больше нуля!");
  else
  {
    if (COM_NN_D(first, second) == 0)                    //Если первое равно второму
    {
      res.coef = (short*)malloc(sizeof(short));
      res.coef[0] = 0;
      res.size = 0;
      return res;                                       //Возвращаем единицу
    }
    else
      if (COM_NN_D(first, second) == 1)                 //Если второе больше первого
      {
        return first;                                     //Возвращаем нуль
      }
      else
        if (COM_NN_D(first, second) == 2)
        {
          kM = first.size - second.size;
          k = kM;
          for (k; k >= 0; k--)
          {
            a = DIV_NN_Dk(n, m, k);
            m = MUL_Nk_N(m, 1);
            n = SUB_NDN_N(n, m, a);
            res.coef[kM - k + 1] = res.coef[kM - k];
            res.coef[kM - k] = a;
          }
        }
    return n;
  }
}