#include <iostream>
#include "DIV_NN_N.h"
#include "Modul1_14.h"
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