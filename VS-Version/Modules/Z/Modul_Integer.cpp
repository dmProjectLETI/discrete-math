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
	num.pos = true;
	return num;
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

Integer SUB_ZZ_Z(Integer first, Integer second) //Âû÷èòàíèå äâóõ öåëûõ.
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
	return sub;
}

Integer MOD_ZZ_Z(Integer first, Integer second)
{
	Integer result;
	result.pos = 1; //Result is always positive
	if (!(NZER_N_B(second.A))) //If divisor is not equal to 0
	{
		result.A = MOD_NN_N(first.A, second.A);
		if (NZER_N_B(result.A)) 
			return result;
		if ((POZ_Z_D(first) < 0)) //If dividend is negative
			result.A = SUB_ZZ_Z(second.A, result.A); // If a < 0 then a mod b = |a|- (|a| mod |b|)
		return result;
    } 
	else //If divisor is equal to 0
		throw invalid_argument("Divided by 0");
};
