#include "Ratio.h"



Ratio ADD_QQ_Q(Ratio A, Ratio B)// Сложение дробей (Калинин Максим/Константинова Ксения)
{
	Ratio C;
	Natural temp = LCM_NN_N(A.denum, B.denum); // Поиск НОК
	A.num.A = MUL_NN_N(A.num.A, DIV_NN_N(temp, A.denum));//Вычисление числителя
	B.num.A = MUL_NN_N(B.num.A, DIV_NN_N(temp, B.denum));//Вычисление знаменателя
	C.num = ADD_ZZ_Z(A.num, B.num);
	C.denum = temp;
	return C;
}

Integer TRAN_Q_Z(Ratio b) // Преобразование дробного в целое (Если знаменатель равен 1) (Хамец Максим/Константинова Ксения)
						  // Перед вызовом следует убедиться, что знаменатель равен единице
{
	return(b.num);
}

Ratio TRAN_Z_Q(Integer A) // Преобразование целого в дробное (Хамец Максим/Филиппова Анастасия)
{
	Ratio B;//дробь, которую возвращает функция
	B.num = A; //число А в числитель
	B.denum.A.push_back(1); //в знаменатель ставим 1
	return B;
}



bool INT_Q_Z(Ratio R)//Проверка на целое, если рациональное число является целым, то «да», иначе «нет» (Хамец Максим/Филиппова Анастасия)
{
	return  (R.denum.A.size() == 1 && R.denum.A[0] == 1) ? 1 : 0; //Если размер знаменателя и первый его элемент равны 1 - функция возвращает 1, иначе - 0
}
Ratio MUL_QQ_Q(Ratio A, Ratio B) //умножение дробных чисел (Климанова Анастасия/Лавренов Андрей )
{
	A.num = MUL_ZZ_Z(A.num, B.num);    // перемножение числителей
	A.denum = MUL_NN_N(A.denum, B.denum); // перемножение знаменателей 
	return RED_Q_Q(A);                   // возвращается сокращенная дробь
}

Ratio SUB_QQ_Q(Ratio A, Ratio B) //Вычитание дробей (Айсабаев Закиржан)
{
	Ratio C;
	Natural temp = LCM_NN_N(A.denum, B.denum); // Поиск НОК
	A.num.A = MUL_NN_N(A.num.A, DIV_NN_N(temp, A.denum));//Вычисление числителя
	B.num.A = MUL_NN_N(B.num.A, DIV_NN_N(temp, B.denum));//Вычисление знаменателя
	C.num = SUB_ZZ_Z(A.num, B.num);
	C.denum = temp;
	return C;
}

Ratio RED_Q_Q(Ratio A) // Функция сокращения дроби (Шершаков Никита)
{
	if (POZ_Z_D(A.num))
	{
		Natural B = GCF_NN_N(A.num.A, A.denum); // Находим НОД от |числителя| и знаменателя
		A.num.A = DIV_NN_N(A.num.A, B); // Делим числитель на НОД
		A.denum = DIV_NN_N(A.denum, B); // Делим знаменатель на НОД
	}
	return A;
}
Ratio DIV_QQ_Q(Ratio A, Ratio B) //деление дробных чисел (Климанова Анастасия/Лавренов Андрей )
{
	Ratio C;
	Integer G;
	G.A = B.denum;
	G.pos = 0;
	C.num = MUL_ZZ_Z(A.num, G);//Вычисление числителя
	C.denum = MUL_NN_N(A.denum, B.num.A);//Вычисление знаменателя
	if(C.num.pos == 1 && C.num.pos == 1)//Определение знака дроби
		C.num.pos = 0;
	else
			C.num.pos = 1;
	return RED_Q_Q(C);
}
