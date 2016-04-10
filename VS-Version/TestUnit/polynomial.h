#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "structs.h"

Polynomial ADD_PP_P(Polynomial M, Polynomial N); // складывает многочлены
Polynomial SUB_PP_P(Polynomial M, Polynomial N); // вычитает многочлены
Polynomial MUL_Pxk_P(Polynomial M, int k); //умножает многочлен на x^k
Ratio LED_P_Z (Polynomial B); //возвращает старший коэффициент многочлена
int DEG_P_N (Polynomial B); //возвращает степень многочлена
Polynomial MUL_P_Q(Polynomial chlen, Ratio ratio_number); //Умножение многочлена на рациональное число
Polynomial NMR_P_P(Polynomial chlen); //Преобразование многочлена — кратные корни в простые
Polynomial GCF_PP_P(Polynomial PA, Polynomial PB); //НОД многочленов
Polynomial FAC_P_PQ(Polynomial P); //Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей

#endif // POLYNOMIAL_H
