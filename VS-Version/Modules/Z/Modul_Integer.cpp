#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

struct Integer 
{
	bool pos = true;
	Natural A;
};

int POZ_Z_D(Integer num) //Ïîêàçàòåëü çíàêà, ñèãíàòóðà.
{
	if (!num.pos)
		return -1;
	else if (NZER_N_B(num.A))
		return 1;
	return 0;
}

Natural ABS_Z_N(Integer num) //Ìîäóëü.
{
	return num.A;
}

Integer MUL_Z_NEGZ(Integer num) //Óìíîæåíèå íà -1.
{
	num.pos = !num.pos;
	return num;
}

Integer ADD_ZZ_Z(Integer first, Integer second) //Ñëîæåíèå äâóõ öåëûõ.
{
	Integer sum;
	if (POZ_Z_D(first) <= 0)
		if (POZ_Z_D(second) <= 0) {
			sum.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
			sum = MUL_Z_NEGZ(sum);
		}
		else {
			if (ABS_Z_N(first) > ABS_Z_N(second)) {
				sum = MUL_Z_NEGZ(sum);
			} 
			sum.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		}
	else 
		if (POZ_Z_D(second) >= 0)
			sum.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		else {
			if (ABS_Z_N(second) > ABS_Z_N(first)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sum.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
	return sum;
}

Integer SUB_ZZ_Z(Integer first, Integer second) //Âû÷èòàíèå äâóõ öåëûõ.
{
	Integer sub;
	sub.pos = 1;
	if (POZ_Z_D(first) <= 0) 
		if (POZ_Z_D(second) <= 0) {
			if (ABS_Z_N(first) > ABS_Z_N(second)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		} else {
			sub.A = ADD_ZZ_Z(first, second);
			sum = MUL_Z_NEGZ(sum);
		}
	else {
		if (POZ_Z_D(second) >= 0) {
			if (ABS_Z_N(second) > ABS_Z_N(first)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
		else 
			sub.A = ADD_ZZ_Z(first, second);
	}
	return sub;
}

Natural MOD_ZZ_Z(Integer first, Integer second)
{
	Natural result;
	if (NZER_N_B(second.A)) //If divisor is not equal to 0
	{
		result.A = MOD_NN_N(first.A, second.A);
		if ((POZ_Z_D(first) < 0)) //If dividend is negative
			result.A = SUB_ZZ_Z(second.A, result.A); // If a < 0 then a mod b = |a|- (|a| mod |b|)
		return result;
        } 
	else //If divisor is equal to 0
		throw invalid_argument("Divided by 0");
};

void DIV_NN_N(Natural first,Natural second) //Частное от деления большего натурального числа на меньшее 
											//или равное натуральное с остатком (делитель отличен от нуля)
{
	Natural quotient=0; // частное
	if (first > second && second != 0) // если первое число больше второго и делитель не равен 0
	{
		while(first >= second) // пока делимое >= делителя вычитаем их друг из друга и считаем частное 
		{
			first -= second;
			quotient++;
		}
		cout << quotient << endl; // выводим частное
	}
	else
	{
		if(first < second && first != 0) // если второе число больше первого и делитель не равен 0
		{
			while(b >= first) // пока делимое >= делителя вычитаем их друг из друга и считаем частное 
			{
				second -= first;
				quotient++;
			}
			cout << quotient << endl; // выводим частное
		}
		else 
		{
			if(first = second && first != 0) // если первое число равно второму и они не нули, то частное равно 1
			{
				quotient = 1;
				cout << quotient << endl; // выводим частное
			}
			else
				cout << "Error" << endl; // делитель =0 или два числа равны 0
		}
	}
}
