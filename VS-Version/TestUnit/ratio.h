#ifndef RATIO_H
#define RATIO_H

#include "structs.h"

// Модуль для дробей
Ratio ADD_QQ_Q(Ratio A, Ratio B); // Функция сложения двух рациональных чисел
Ratio TRAN_Z_Q(Integer A); // Функция, которая преобразует целое в дробное(со знаменателем = 1)
Ratio RED_Q_Q(Ratio A); // Функция сокращения дроби
Integer TRAN_Q_Z(Ratio b); // Преобразование дробного в целое
bool INT_Q_Z(Ratio R); // Если рациональное число - целое, то 1, иначе 0
Ratio MUL_QQ_Q (Ratio A, Ratio B) //умножение дробных чисел
Ratio DIV_QQ_Q (Ratio A, Ratio B) //деление дробных чисел
Ratio SUB_QQ_Q(Ratio A, Ratio B) //Вычитание дробей
// Конец модуля для дробей

#endif // RATIO_H
