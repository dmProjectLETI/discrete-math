#pragma once
#include "Ratio.h"
struct Polynomial
{
	vector<Ratio>C;
	unsigned int n;
};

Polynomial ADD_PP_P(Polynomial first, Polynomial second); // складывает многочлены
Polynomial SUB_PP_P(Polynomial first, Polynomial second); // вычитает многочлены
Polynomial MUL_P_Q(Polynomial chlen, Ratio ratio_number); //Умножение многочлена на рациональное число
Polynomial MUL_Pxk_P(Polynomial M, int k); //умножает многочлен на x^k
Ratio LED_P_Z(Polynomial B); //возвращает старший коэффициент многочлена
int DEG_P_N(Polynomial B); //возвращает степень многочлена
Polynomial FAC_P_PQ(Polynomial P); //Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
Polynomial MUL_PP_P(Polynomial M, Polynomial N); //Умножение многочленов
Polynomial DIV_PP_P(Polynomial dividend, Polynomial denominator); // возвращает частное от деления divident на denominator
Polynomial MOV_PP_P(Polynomial dividend, Polynomial denominator); // возвращает остаток от деления divident на denominator
Polynomial GCF_PP_P(Polynomial PA, Polynomial PB); //НОД многочленов
Polynomial DER_P_P(Polynomial B); //Производная
Polynomial NMR_P_P(Polynomial chlen); //Преобразоводание многочлена — кратные корни в простые

