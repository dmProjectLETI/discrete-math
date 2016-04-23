#pragma once
#include "Integer.h"
struct Ratio
{
	Integer num;
	Natural denum;
};

Ratio RED_Q_Q(Ratio A); // Функция сокращения дроби
bool INT_Q_Z(Ratio R); // Если рациональное число - целое, то 1, иначе 0
Ratio TRAN_Z_Q(Integer A); // Функция, которая преобразует целое в дробное(со знаменателем = 1)
Integer TRAN_Q_Z(Ratio b); // Преобразование дробного в целое
Ratio ADD_QQ_Q(Ratio A, Ratio B); // Функция сложения двух рациональных чисел
Ratio SUB_QQ_Q(Ratio A, Ratio B); //Вычитание дробей
Ratio MUL_QQ_Q(Ratio A, Ratio B); //умножение дробных чисел
Ratio DIV_QQ_Q(Ratio A, Ratio B); //деление дробных чисел
