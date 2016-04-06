#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

struct Integer 
{
	bool pos = true;
	Natural A;
};

int POZ_Z_D(Integer num) //Показатель знака, сигнатура.
{
	if (!num.pos)
		return -1;
	else if (NZER_N_B(num.A))
		return 1;
	return 0;
}

Natural ABS_Z_N(Integer num) //Модуль.
{
	num.pos = true;
	return num;
}

Integer MUL_Z_NEGZ(Integer num) //Умножение на -1.
{
	num.pos = !num.pos;
	return num;
}

Integer ADD_ZZ_Z(Integer first, Integer second) //Сложение двух целых.
{
	Integer sum;
	if (POZ_Z_D(first) <= 0)
		if (POZ_Z_D(second) <= 0) {
			sum = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
			sum = MUL_Z_NEGZ(sum);
		}
		else {
			if (ABS_Z_N(first) > ABS_Z_N(second)) {
				sum = MUL_Z_NEGZ(sum);
			} 
			sum = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		}
	else {
		if (POZ_Z_D(second) >= 0)
			sum = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		else {
			if (ABS_Z_N(second) > ABS_Z_N(first)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sum = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
	}
	return sum;
}

Integer SUB_ZZ_Z(Integer first, Integer second) //Вычитание двух целых.
{
	Integer sub;
	sub.pos = 1;
	if (POZ_Z_D(first) <= 0) 
		if (POZ_Z_D(second) <= 0) {
			if (ABS_Z_N(first) > ABS_Z_N(second)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sub = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		} else {
			sub = ADD_ZZ_Z(first, second);
			sum = MUL_Z_NEGZ(sum);
		}
	else {
		if (POZ_Z_D(second) >= 0) {
			if (ABS_Z_N(second) > ABS_Z_N(first)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sub = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
		else 
			sub = ADD_ZZ_Z(first, second);
	}
}
