#include "test_modules.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;


struct Natural
{
	vector<unsigned int> A;
};

bool COM_NN_D(Natural First, Natural Second)//Сравнивает два числа. Возвращает 1, 
{											// если первое больше или равно второму. 0 - если меньше.
	if (First.A.size()<Second.A.size())
		return 0;
	else
	{
		if (First.A.size() > Second.A.size())
			return 1;
		int i = First.A.size() - 1, k = 1;
		do
		{
			if (First.A[i] > Second.A[i])
			{
				return 1;
			}
			else
			{
				if (First.A[i] < Second.A[i])
				{
					return 0;
				}
				else
					if (i == 0)
						return 1;
					else
						--i;
			}
		} while (k);
	}

}

bool NZER_N_B(Natural chislo) //Проверяет число на не равенство нулю
{							  //1- число положительное, 0 - число равно 0
	if (chislo.A.empty())
		return 0;
	else
	{
		int sum = 0;
		for (int i = 0; i < chislo.A.size(); ++i)
			sum = sum + chislo.A[i];
		if (sum)
			return 1;
		else
			return 0;
	}
}

Natural ADD_1N_N(Natural chislo) //Прибавляет 1 к числу
{
	int k = 1, i = 0;
	do
	{
		if (chislo.A[i] == 9)
		{
			chislo.A[i] = 0;
			++i;
			if (i == chislo.A.size())
			{
				chislo.A.push_back(1);
				k = 0;
			}
		}
		else
		{
			chislo.A[i] = ++chislo.A[i];
			k = 0;
		}

	} while (k);
	return chislo;
}

Natural ADD_NN_N(Natural chislo1, Natural chislo2)//Складывает два числа
{
	if (!COM_NN_D(chislo1, chislo2))
		chislo1.A.swap(chislo2.A);
	int s = 0;
	Natural Sum;
	for (int i = 0; i < chislo2.A.size(); ++i)
	{
		Sum.A.push_back((chislo1.A[i] + chislo2.A[i] + s) % (10));
		s = (chislo1.A[i] + chislo2.A[i] + s) / (10);
	}
	if (chislo1.A.size() != chislo2.A.size())
		for (int i = chislo2.A.size(); i < chislo1.A.size(); ++i)
		{
			Sum.A.push_back((chislo1.A[i] + s) % (10));
			s = (chislo1.A[i] + s) / (10);
		}
	if (s > 0)
	{
		Sum.A.push_back(s);
	}
	return Sum;
};

Natural SUB_NN_N(Natural First, Natural Second) //Вычитает из одного числа другое. Работает только
{												//для неотрицательных результатов, поэтому перед вызовом этой функции 
	int p = 0;									//необходимо убедиться, что первое число не меньше второго
	for (int i = 0; i < Second.A.size(); ++i)
	{
		if (First.A[i] + 10 - Second.A[i] - p < 10)
		{
			First.A[i] = First.A[i] + 10 - Second.A[i] - p;
			p = 1;
		}
		else
		{
			First.A[i] = First.A[i] - Second.A[i] - p;
			p = 0;
		}
	}
	for (int i = Second.A.size(); i < First.A.size(); ++i)
	{
		if (First.A[i] + 10 - p < 10)
		{
			First.A[i] = First.A[i] + 10 - p;
			p = 1;
		}
		else
		{
			First.A[i] = First.A[i] - p;
			p = 0;
		}
	}
	int k = 0;
	int i = First.A.size() - 1;
	for (i; i > 0; --i)
	{
		if (First.A[i])
			k = 1;
		if (!First.A[i] && !k)
			First.A.pop_back();

	}
	return First;
}

Natural MUL_ND_N(Natural ch, int cifra) //Умножает число на цифру
{
	int s = 0;
	Natural chislo;
	for (int i = 0; i < ch.A.size(); ++i)
	{
		chislo.A.push_back((ch.A[i] * cifra + s) % 10);
		s = (ch.A[i] * cifra + s) / 10;
	}

	if (s > 0)
	{
		chislo.A.push_back(s);
	}
	return chislo;
}

Natural MUL_Nk_N(Natural &Input, int k) //Умножает число на 10^k
{
	for (int i = 0; i < k; ++i)
		Input.A.insert(Input.A.begin(), 0);
	return Input;
}

Natural MUL_NN_N(Natural chislo1, Natural chislo2) //Перемножает два числа
{
	Natural Proizved;
	for (int i = 0; i < chislo2.A.size(); ++i)
	{
		Proizved = ADD_NN_N(MUL_Nk_N(MUL_ND_N(chislo1, chislo2.A[i]), i), Proizved);
	}
	return Proizved;
}

Natural SUB_NDN_N(Natural chislo1, Natural chislo2, int c) //Вычитает из первого числа второе, умноженное на цифру
{															//аналогично вычитанию, перед вызовом необходимо убедиться,
	return SUB_NN_N(chislo1, MUL_ND_N(chislo2, c));			//что результат возможен, т.е. неотрицателен
}

Natural DIV_NN_Dk(Natural chislo1, Natural chislo2)//Вычисляет первую цифру частного, умноженную на 10^k, 
{													//где k - позиция этой цифры в частном
	Natural chislo;
	int j = (chislo1.A.size() - 1);
	for (int i = 0; i < chislo2.A.size(); ++i, --j)
		chislo.A.insert(chislo.A.begin(), chislo1.A[j]);
	if (!COM_NN_D(chislo, chislo2))
		chislo.A.insert(chislo.A.begin(), chislo1.A[j]);

	int i = 10;
	do
	{
		--i;
	} while (!COM_NN_D(chislo, MUL_ND_N(chislo2, i)));
	chislo.A.erase(chislo.A.begin(), chislo.A.end());
	chislo.A.push_back(i);
	return MUL_Nk_N(chislo, j);
}

Natural DIV_NN_N(Natural delimoe, Natural delitel) //Находит неполное частное двух чисел
{
	Natural chastnoe;
	if (!COM_NN_D(delimoe, delitel))
	{
		chastnoe.A.push_back(0);
		return chastnoe;
	}
	else
	{
		do
		{
			chastnoe = ADD_NN_N(chastnoe, DIV_NN_Dk(delimoe, delitel));
			delimoe = SUB_NN_N(delimoe, MUL_NN_N(delitel, DIV_NN_Dk(delimoe, delitel)));
		} while (!COM_NN_D(delitel, delimoe));
		return chastnoe;
	}
}

Natural MOD_NN_N(Natural chislo1, Natural chislo2)//Находит остаток от деления первого числа на второе
{
	return SUB_NN_N(chislo1, MUL_NN_N(DIV_NN_N(chislo1, chislo2), chislo2));
}

Natural GCF_NN_N(Natural chislo1, Natural chislo2)//Находит НОД двух чисел
{
	if (!COM_NN_D(chislo1, chislo2))
		chislo1.A.swap(chislo2.A);
	Natural n;
	n.A.push_back(0);
	while (!(MOD_NN_N(chislo1, chislo2).A == n.A))
	{
		chislo1 = MOD_NN_N(chislo1, chislo2);
		chislo1.A.swap(chislo2.A);
		if ((chislo2.A.size() == 1) && (chislo2.A[0] == 0))
			return chislo1;
	}
	return chislo2;
}

Natural LCM_NN_N(Natural chislo1, Natural chislo2)//Находит НОК двух чисел
{
	return DIV_NN_N(MUL_NN_N(chislo1, chislo2), GCF_NN_N(chislo1, chislo2));
}