#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������ �������


BigNatural SUB_NN_N(BigNatural first, BigNatural second)
{
	//���� ������ ������ �������, �� �������� ��������
	if (COM_NN_D(first, second) == 1)
		return SUB_NN_N(second, first);
	BigNatural result;
	int i;
	short temp;
	short carry = 0;

	short* a = first.coef; //����������� 

	short* b = second.coef; //����������

	//��������� �� ������ �������, � ����� ����� � ���������
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

	//���������� ��������� ������� �����
	i = first.size - 1;
	while ((i>0) && (resCoef[i] == 0)) i--;
	resCoef = (short*)realloc(resCoef, sizeof(short) * (i + 1));
	

	result.size = i + 1;
	result.coef = resCoef;

	return result;
}

//������� �� ������� � ��������
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
  //���� ������ ������ �������, �� �������� ��������
  if (COM_NN_D(first, second) == 1)
  return DIV_NN_N(second, first);

  BigNatural first_c;                                  //����� ��������
  BigNatural k = BigNatural();                         //������� �������
  if (!NZER_N_B)                                       //���� �������� ����� ����
  printf("�������� ������ ���� ������ ����!");
  else
  {
    if (COM_NN_D(first, second) == 2)                    //���� ������ ������ �������
    {
      first_c = first;                                   //�������� �������
        do
        {
          first_c = SUB_NN_N(first, second);             //�������� �� �������� ��������
          k = ADD_1N_N(k);                               //����������� ������� ������� �� 1
        } 
        while (COM_NN_D(first_c, second) == 2 || COM_NN_D(first_c, second) == 0);//���� ������� ������ ��������
          return k;                                      //���������� ������� (������� �� �������������� �������)
    }
    else
    if (COM_NN_D(first, second) == 0)                    //���� ������ ����� �������
    {
        k = ADD_1N_N(k);                                 //����������� ������� �� 1
        return k;                                        //���������� �������
    }
  }
}

//������� �� �������
/*
BigNatural MOD_NN_N(BigNatural first, BigNatural second)
{
  BigNatural 
}
  */
