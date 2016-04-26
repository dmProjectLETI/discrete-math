#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

struct Integer 
{
	bool pos = true;
	Natural A;
};

int POZ_Z_D(Integer num) //Сигнатура, определение знака целого числа.	
{			 //Выполнил Предтеченский Дмитрий (5396).
	if (!num.pos)
		return -1;
	else if (NZER_N_B(num.A))
		return 1;
	return 0;
}

Integer TRANS_N_Z(Natural num) //Преобразование натурального числа в целое число.
{			       //Выполнил Предтеченский Дмитрий (5396).	
	Integer newNum;
	newNum.A = num;
	return newNum;
}

Natural TRANS_Z_N(Integer num) //Преобразование целого положительного числа в натуральное число.
{			       //Выполнил Предтеченский Дмитрий (5396).	
	return num.A;
}

Natural ABS_Z_N(Integer num) //Модуль целого числа.
{			     //Выполнил Предтеченский Дмитрий (5396).
	return num.A;
}

Integer MUL_Z_NEGZ(Integer num) //Умножение целого числа на -1
{				//Выполнил Предтеченский Дмитрий (5396).
	num.pos = !num.pos;
	return num;
}

Integer ADD_ZZ_Z(Integer first, Integer second) //Сложение двух целых чисел.
{						//Выполнили Предтеченский Дмитрий (5396) и Квятковский Антон (5395).
	Integer sum;

	if (((first.pos == 1) && (second.pos == 1)) || ((first.pos == 0) && (second.pos == 0)))
	{
		sum.A = ADD_NN_N(first.A, second.A);
		if (first.pos == 0 || (second.pos == 0))
			MUL_Z_NEGZ(sum);
	}
	else
	{
		if (COM_NN_D(first.A, second.A))
		{
			sum.A = SUB_NN_N(first.A, second.A);
			if (first.pos == 0)
				MUL_Z_NEGZ(sum);
		}
		else
		{
			sum.A = SUB_NN_N(second.A, first.A);
			if (second.pos == 0)
				MUL_Z_NEGZ(sum);
		}
	}
	return sum;
}

Integer SUB_ZZ_Z(Integer first, Integer second) //Вычитание двух целых чисел.
{						//Выполнил Предтеченский Дмитрий (5396).
	Integer sub;

	if (POZ_Z_D(first) <= 0)
		if (POZ_Z_D(second) <= 0)
			if (COM_NN_D(first.A, second.A))
			{
				sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
				sub = MUL_Z_NEGZ(sub);
			}
			else
				sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		else {
			sub.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
			sub = MUL_Z_NEGZ(sub);
		}
	else {
		if (POZ_Z_D(second) >= 0) {
			if (!COM_NN_D(first.A, second.A)) {
				sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
				sub = MUL_Z_NEGZ(sub);
			}
			else
				sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
		else
			sub.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
	}
	return sub;
}

Integer MUL_ZZ_Z(Integer first, Integer second) //Умножение двух целых чисел.
{						//Выполнил Предтеченский Дмитрий (5396).
	Integer mul; 
	mul.A = MUL_NN_N(first.A, second.A); 
	
	if (((first.pos == 0) && (second.pos == 0)) || ((first.pos == 1) && (second.pos == 1))) 
		mul.pos = 1; 
	else 
		mul.pos = 0; 

	return mul;
}

Integer MOD_ZZ_Z(Integer first, Natural second) //Остаток от деления целого числа на целое число. 
{						//Выполнила Чаркова Дарья (5396).
	Integer result;

	result.A = MOD_NN_N(first.A, second);

	return result;
};

Integer DIV_ZZ_Z(Integer first, Natural second) //Частное от деления большего целого числа на меньшее 
						//или равное натуральное число с остатком (делитель отличен от нуля).
{						//Выполнил Уразаев Евгений (5396).
	Integer div;

	div.A = DIV_NN_N(first.A, second);

	if (POZ_Z_D(first) < 0)
		div.pos = 0;

	return div;
}
