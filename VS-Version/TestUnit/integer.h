#ifndef INTEGER_H
#define INTEGER_H

#include "structs.h"

int POZ_Z_D(Integer num); //Определение знака целого числа, сигнатура.
Natural ABS_Z_N(Integer num); //Модуль целого.
Integer MUL_Z_NEGZ(Integer num); //Умножение целого на -1.
Integer ADD_ZZ_Z(Integer first, Integer second); //Сложение двух целых.
Integer SUB_ZZ_Z(Integer first, Integer second); //Вычитание двух целых.
Integer MOD_ZZ_Z(Integer first, Integer second); //Остаток от деления двух целых
Integer DIV_ZZ_Z(Integer first, Integer second); //Частное от деления двух целых

#endif // INTEGER_H