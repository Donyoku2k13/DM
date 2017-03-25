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


//������� � ��������
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
  int k;
  int kM;
  BigNatural n; //�������
  BigNatural m; //��������
  BigNatural res;//���������
  int a; //������ ����� �������

  n = first;
  m = second;
  res.coef[0] = 0;
  if (!NZER_N_B)                                       //���� �������� ����� ����
    printf("�������� ������ ���� ������ ����!");
  else
  {
    if (COM_NN_D(first, second) == 0)                    //���� ������ ����� �������
    {
      res.coef = (short*)malloc(sizeof(short));
      res.coef[0] = 1;
      res.size = 1;
      return res;                                       //���������� �������
    }
    else
      if (COM_NN_D(first, second) == 1)                 //���� ������ ������ �������
      {
        res.coef = (short*)malloc(sizeof(short));
        res.coef[0] = 0;
        res.size = 0;
        return res;                                     //���������� ����
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
//������� �� �������
BigNatural DIV_NN_N(BigNatural first, BigNatural second)
{
  int k;
  int kM;
  BigNatural n; //�������
  BigNatural m; //��������
  BigNatural res;//���������
  int a; //������ ����� �������

  n = first;
  m = second;
  res.coef[0] = 0;
  if (!NZER_N_B)                                       //���� �������� ����� ����
    printf("�������� ������ ���� ������ ����!");
  else
  {
    if (COM_NN_D(first, second) == 0)                    //���� ������ ����� �������
    {
      res.coef = (short*)malloc(sizeof(short));
      res.coef[0] = 0;
      res.size = 0;
      return res;                                       //���������� �������
    }
    else
      if (COM_NN_D(first, second) == 1)                 //���� ������ ������ �������
      {
        return first;                                     //���������� ����
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