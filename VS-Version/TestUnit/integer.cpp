#include "integer.h"
#include "natural.h"
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

Integer TRANS_N_Z(Natural num) 
{
	Integer newNum;
	newNum.A = num;
	return newNum;
}

Natural TRANS_Z_N(Integer num) 
{
	return num.A;
}

Natural ABS_Z_N(Integer num) //??????.
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
			sum.A = ADD_NN_N(first.A, second.A);
			sum = MUL_Z_NEGZ(sum);
		}
		else {
			if (!COM_NN_D(first.A, second.A)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sum.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		}
	else
		if (POZ_Z_D(second) >= 0)
			sum.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		else {
			if (COM_NN_D(first.A, second.A)) {
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
			if (COM_NN_D(first.A, second.A)) {
				sub = MUL_Z_NEGZ(sub);
			}
			sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		}
		else {
			sub.A = ADD_ZZ_Z(first, second).A;
			sub.pos = 0;
		}
	else {
		if (POZ_Z_D(second) >= 0) {
			if (!COM_NN_D(first.A, second.A)) {
				sub = MUL_Z_NEGZ(sub);
			}
			sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
		else
			sub.A = ADD_ZZ_Z(first, second).A;
	}
	return sub;
}

Integer MUL_ZZ_Z(Integer first, Integer second) {
	Integer mul;
	mul.A = MUL_NN_N(first.A, second.A);

	if (POZ_Z_D(first) == -1)
		MUL_Z_NEGZ(mul);
	if (POZ_Z_D(second) == -1)
		MUL_Z_NEGZ(mul);

	return mul;
}

Natural MOD_ZZ_Z(Integer first, Natural second)
{
	Natural result;

		result = MOD_NN_N(first.A, second);
		if ((POZ_Z_D(first) < 0)) //If dividend is negative
			result = MOD_NN_N(ADD_NN_N(second, result), second);
		return result;
};


Integer DIV_ZZ_Z(Integer first, Natural second) //Частное от деления большего целого числа на меньшее 
											 //или равное натуральное с остатком (делитель отличен от нуля)
{
	Integer div;

	div.A=DIV_NN_N(first.A, second.A);

	if (POZ_Z_D(first) == -1)
		MUL_Z_NEGZ(div);

	return div;
}

