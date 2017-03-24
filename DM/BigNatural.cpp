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

BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
  //Если второе меньше первого, то вызываем наоборот
  if (COM_NN_D(first, second) == 1)
    return DIV_NN_N(second, first);

  BigNatural first_c; //Копия делимого
  BigNatural k = BigNatural(); //Счетчик деления
  if (!NZER_N_B) //Если делитель = нулю
    printf("Делитель должен быть больше нуля!");
  else
  {
    if(COM_NN_D(first, second)==2) //Если первое больше второго
    {
      first_c = first; //Копируем Делимое
      do
      {
        first_c = SUB_NN_N(first, second); //Вычитаем из делимого делитель
        k = ADD_1N_N(k); //Увеличиваем счетчик деления на 1
      } while (COM_NN_D(first_c, second) == 2 || COM_NN_D(first_c, second) == 0); //Пока делимое больше делителя
        return k; //Возвразаем счетчик (частное от целочисленного деления)
    }
    else
    if (COM_NN_D(first, second) == 0) //Если первое равно второму
    {
      k = ADD_1N_N(k); //Увеличиваем счетчик до 1
      return k; //Возвращаем единицу
    }

}
