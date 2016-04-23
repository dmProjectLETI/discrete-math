#pragma once
#include "Natural.h"
struct Integer
{
	bool pos;
	Natural A;
};

Natural ABS_Z_N(Integer num); //Модуль целого.
int POZ_Z_D(Integer num); //Определение знака целого числа,1-положительное, 0 - равно 0, -1 - отрицательное.
Integer MUL_Z_NEGZ(Integer num); //Умножение целого на -1.
Integer TRANS_N_Z(Natural num); //Натуральное в целое
Natural TRANS_Z_N(Integer num);//Целое в натуральное
Integer ADD_ZZ_Z(Integer first, Integer second); //Сложение двух целых
Integer SUB_ZZ_Z(Integer first, Integer second); //Вычитание двух целых.
Integer MUL_ZZ_Z(Integer first, Integer second); //Умножение целых чисел
Integer DIV_ZZ_Z(Integer first, Natural second); //Частное от деления большего целого числа на меньшее 
Integer MOD_ZZ_Z(Integer first, Natural second); //Остаток от деление 