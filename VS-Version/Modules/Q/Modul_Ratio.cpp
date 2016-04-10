Ratio ADD_QQ_Q(Ratio A, Ratio B)
{
	Ratio C;
	Natural temp = LCM_NN_N(A.denum, B.denum); // Поиск НОК
	A.num.A = MUL_NN_N(A.num.A, DIV_NN_N(temp, A.denum));
	B.num.A = MUL_NN_N(B.num.A, DIV_NN_N(temp, B.denum));
	C.num = ADD_ZZ_Z(A.num, B.num);
	C.denum = temp;
	return C;
}

Integer TRAN_Q_Z(Ratio b) // Преобразование дробного в целое (Если знаменатель равен 1)
						  // Перед вызовом следует убедиться, что знаменатель равен единице
{
	return(b.num); 
}

Ratio TRAN_Z_Q(Integer A)
{
	Ratio B; //дробь, которую возвращает функция
	B.num = A; //число А в числитель
	B.denum.a.push_back(1); //в знаменатель ставим 1
	return B;
}

Ratio RED_Q_Q(Ratio A) // Функция сокращения дроби
{
	Natural B = GVF_NN_N(A.num.A, A.denum); // Находим НОД от |числителя| и знаменателя
	A.num.A = DIV_ZZ_Z(A.num.A, B); // Делим числитель на НОД
	A.denum = DIV_ZZ_Z(A.denum, B); // Делим знаменатель на НОД
	return A;
}

bool INT_Q_Z(Ratio R)
{
	return  (R.denum.A.size() == 1 && R.denum.A[0] == 1) ? 1 : 0; //Если размер знаменателя и первый его элемент равны 1 - функция возвращает 1, иначе - 0
}
Ratio MUL_QQ_Q (Ratio A, Ratio B) //умножение дробных чисел
{
 Ratio C;
 C.num = MUL_ZZ_Z(A.num.A, B.num.A);    // перемножение числителей
 C.denum = MUL_ZZ_Z(A.denum, B.denum); // перемножение знаменателей 
 return RED_Q_Q(C);                   // возвращается сокращенная дробь
}


Ratio DIV_QQ_Q (Ratio A, Ratio B) //деление дробных чисел
{  
 Ratio C;
 C.num = MUL_ZZ_Z(A.num.A, B.denum);
 C.denum = MUL_ZZ_Z(A.denum, B.num.A);
 return RED_Q_Q(C);
}
