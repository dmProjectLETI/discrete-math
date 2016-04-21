#include "test_modules.h"
#include <vector>
using namespace std;
// Начало модуля для натуральных чисел
bool COM_NN_D(Natural First, Natural Second)//Сравнивает два числа. Возвращает 1, 
{											// если первое больше или равно второму. 0 - если меньше.(Алексеева Анастасия 5372)
	if (First.A.size() < Second.A.size())
		return 0;
	else
	{
		if (First.A.size() > Second.A.size())
			return 1;
		int i = First.A.size() - 1, k = 1;
		do
		{
			if (First.A[i] > Second.A[i])
			{
				return 1;
			}
			else
			{
				if (First.A[i] < Second.A[i])
				{
					return 0;
				}
				else
					if (i == 0)
						return 1;
					else
						--i;
			}
		} while (k);
	}
}

bool NZER_N_B(Natural chislo) //Проверяет число на не равенство нулю
{							  //1- число положительное, 0 - число равно 0 (Чачух Роман 5372)
	if (chislo.A.empty())
		return 0;
	else
	{
		int sum = 0;
		for (int i = 0; i < chislo.A.size(); ++i)
			sum = sum + chislo.A[i];
		if (sum)
			return 1;
		else
			return 0;
	}
}

Natural ADD_1N_N(Natural chislo) //Прибавляет 1 к числу (Синельникова Яна 5372)
{
	int k = 1, i = 0;
	do
	{
		if (chislo.A[i] == 9)
		{
			chislo.A[i] = 0;
			++i;
			if (i == chislo.A.size())
			{
				chislo.A.push_back(1);
				k = 0;
			}
		}
		else
		{
			chislo.A[i] = ++chislo.A[i];
			k = 0;
		}
	} while (k);
	return chislo;
}

Natural ADD_NN_N(Natural chislo1, Natural chislo2)//Складывает два числа (Потапова Юлия 5372)
{
	if (!COM_NN_D(chislo1, chislo2))
		chislo1.A.swap(chislo2.A);
	int s = 0;
	Natural Sum;
	for (int i = 0; i < chislo2.A.size(); ++i)
	{
		Sum.A.push_back((chislo1.A[i] + chislo2.A[i] + s) % (10));
		s = (chislo1.A[i] + chislo2.A[i] + s) / (10);
	}
	if (chislo1.A.size() != chislo2.A.size())
		for (int i = chislo2.A.size(); i < chislo1.A.size(); ++i)
		{
			Sum.A.push_back((chislo1.A[i] + s) % (10));
			s = (chislo1.A[i] + s) / (10);
		}
	if (s > 0)
	{
		Sum.A.push_back(s);
	}
	return Sum;
};

Natural SUB_NN_N(Natural First, Natural Second) //Вычитает из одного числа другое. Работает только
{												//для неотрицательных результатов, поэтому перед вызовом этой функции 
	int p = 0;									//необходимо убедиться, что первое число не меньше второго (Кузина Дарья 5372)
	for (int i = 0; i < Second.A.size(); ++i)
	{
		if (First.A[i] + 10 - Second.A[i] - p < 10)
		{
			First.A[i] = First.A[i] + 10 - Second.A[i] - p;
			p = 1;
		}
		else
		{
			First.A[i] = First.A[i] - Second.A[i] - p;
			p = 0;
		}
	}
	for (int i = Second.A.size(); i < First.A.size(); ++i)
	{
		if (First.A[i] + 10 - p < 10)
		{
			First.A[i] = First.A[i] + 10 - p;
			p = 1;
		}
		else
		{
			First.A[i] = First.A[i] - p;
			p = 0;
		}
	}
	int k = 0;
	int i = First.A.size() - 1;
	for (i; i > 0; --i)
	{
		if (First.A[i])
			k = 1;
		if (!First.A[i] && !k)
			First.A.pop_back();
	}
	return First;
}

Natural MUL_ND_N(Natural ch, int cifra) //Умножает число на цифру (Васильева Ольга 5372)
{
	int s = 0;
	Natural chislo;
	for (int i = 0; i < ch.A.size(); ++i)
	{
		chislo.A.push_back((ch.A[i] * cifra + s) % 10);
		s = (ch.A[i] * cifra + s) / 10;
	}

	if (s > 0)
	{
		chislo.A.push_back(s);
	}
	return chislo;
}

Natural MUL_Nk_N(Natural &Input, int k) //Умножает число на 10^k (Макаров Семен 5372)
{
	for (int i = 0; i < k; ++i)
		Input.A.insert(Input.A.begin(), 0);
	return Input;
}

Natural MUL_NN_N(Natural chislo1, Natural chislo2) //Перемножает два числа (Потапова Юлия 5372)
{
	Natural Proizved;
	for (int i = 0; i < chislo2.A.size(); ++i)
	{
		Proizved = ADD_NN_N(MUL_Nk_N(MUL_ND_N(chislo1, chislo2.A[i]), i), Proizved);
	}
	return Proizved;
}

Natural SUB_NDN_N(Natural chislo1, Natural chislo2, int c) //Вычитает из первого числа второе, умноженное на цифру
{															//аналогично вычитанию, перед вызовом необходимо убедиться,
	return SUB_NN_N(chislo1, MUL_ND_N(chislo2, c));			//что результат возможен, т.е. неотрицателен (Волков Артем 5372)
}

Natural DIV_NN_Dk(Natural chislo1, Natural chislo2)//Вычисляет первую цифру частного, умноженную на 10^k, 
{													//где k - позиция этой цифры в частном (Моногошева Ирина 5372)
	Natural chislo;
	int j = (chislo1.A.size() - 1);
	for (int i = 0; i < chislo2.A.size(); ++i, --j)
		chislo.A.insert(chislo.A.begin(), chislo1.A[j]);
	if (!COM_NN_D(chislo, chislo2))
		chislo.A.insert(chislo.A.begin(), chislo1.A[j]);

	int i = 10;
	do
	{
		--i;
	} while (!COM_NN_D(chislo, MUL_ND_N(chislo2, i)));
	chislo.A.erase(chislo.A.begin(), chislo.A.end());
	chislo.A.push_back(i);
	return MUL_Nk_N(chislo, j);
}

Natural DIV_NN_N(Natural delimoe, Natural delitel) //Находит неполное частное двух чисел (Козак Мария 5372)
{
	Natural chastnoe;
	if (!COM_NN_D(delimoe, delitel))
	{
		chastnoe.A.push_back(0);
		return chastnoe;
	}
	else
	{
		do
		{
			chastnoe = ADD_NN_N(chastnoe, DIV_NN_Dk(delimoe, delitel));
			delimoe = SUB_NN_N(delimoe, MUL_NN_N(delitel, DIV_NN_Dk(delimoe, delitel)));
		} while (COM_NN_D(delimoe, delitel));
		return chastnoe;
	}
}

Natural MOD_NN_N(Natural chislo1, Natural chislo2)//Находит остаток от деления первого числа на второе (Лисицын Захар 5372)
{
	return SUB_NN_N(chislo1, MUL_NN_N(DIV_NN_N(chislo1, chislo2), chislo2));
}

Natural GCF_NN_N(Natural chislo1, Natural chislo2)//Находит НОД двух чисел (Кузина Дарья 5372)
{
	if (!COM_NN_D(chislo1, chislo2))
		chislo1.A.swap(chislo2.A);
	Natural n;
	n.A.push_back(0);
	while (!(MOD_NN_N(chislo1, chislo2).A == n.A))
	{
		chislo1 = MOD_NN_N(chislo1, chislo2);
		chislo1.A.swap(chislo2.A);
		if ((chislo2.A.size() == 1) && (chislo2.A[0] == 0))
			return chislo1;
	}
	return chislo2;
}

Natural LCM_NN_N(Natural chislo1, Natural chislo2)//Находит НОК двух чисел (Кузина Дарья 5372)
{
	return DIV_NN_N(MUL_NN_N(chislo1, chislo2), GCF_NN_N(chislo1, chislo2));
}
 //Конец модуля для натуральных чисел
//---------------------------------------------------------------------------------------------------------
 //начало модуля для целых чисел

int POZ_Z_D(Integer num) //Сигнатура, определение знака целого числа.	
{			 //Выполнил Предтеченский Дмитрий (5396).
	if (!num.pos)
		return -1;
	else if (NZER_N_B(num.A))
		return 1;
	return 0;
}

Integer TRANS_N_Z(Natural num) //Преобразование натурального числа в целое число.
{			       //Выполнил Предтеченский Дмитрий (5396).	
	Integer newNum;
	newNum.A = num;
	return newNum;
}

Natural TRANS_Z_N(Integer num) //Преобразование целого положительного числа в натуральное число.
{			       //Выполнил Предтеченский Дмитрий (5396).	
	return num.A;
}

Natural ABS_Z_N(Integer num) //Модуль целого числа.
{			     //Выполнил Предтеченский Дмитрий (5396).
	return num.A;
}

Integer MUL_Z_NEGZ(Integer num) //Умножение целого числа на -1
{				//Выполнил Предтеченский Дмитрий (5396).
	num.pos = !num.pos;
	return num;
}

Integer ADD_ZZ_Z(Integer first, Integer second) //Сложение двух целых чисел.
{						//Выполнил Предтеченский Дмитрий (5396).
	Integer sum;

	if (((first.pos == 1) && (second.pos == 1)) || ((first.pos == 0) && (second.pos == 0)))
	{
		sum.A = ADD_NN_N(first.A, second.A);
		if (first.pos == 0 || (second.pos == 0))
			sum.pos = 0;
		else
			sum.pos = 1;
	}
	else
	{
		if (COM_NN_D(first.A, second.A))
		{
			sum.A = SUB_NN_N(first.A, second.A);
			if (first.pos == 0)
				sum.pos = 0;
			else
				sum.pos = 1;
		}
		else
		{
			sum.A = SUB_NN_N(second.A, first.A);
			if (second.pos == 0)
				sum.pos = 0;
			else
				sum.pos = 1;
		}
	}
	return sum;
}

Integer SUB_ZZ_Z(Integer first, Integer second) //Вычитание двух целых чисел.
{						//Выполнил Предтеченский Дмитрий (5396).
	Integer sub;

	if (POZ_Z_D(first) <= 0)
		if (POZ_Z_D(second) <= 0)
			if (COM_NN_D(first.A, second.A))
			{
				sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
				sub = MUL_Z_NEGZ(sub);
			}
			else
				sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		else {
			sub.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
			sub = MUL_Z_NEGZ(sub);
		}
	else {
		if (POZ_Z_D(second) >= 0) {
			if (!COM_NN_D(first.A, second.A)) {
				sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
				sub = MUL_Z_NEGZ(sub);
			}
			else
				sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
		else
			sub.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
	}
	return sub;
}

Integer MUL_ZZ_Z(Integer first, Integer second) //Умножение двух целых чисел.
{						//Выполнил Предтеченский Дмитрий (5396).
	Integer mul;
	mul.A = MUL_NN_N(first.A, second.A);

	if (POZ_Z_D(first) == -1)
		MUL_Z_NEGZ(mul);
	if (POZ_Z_D(second) == -1)
		MUL_Z_NEGZ(mul);

	return mul;
}

Integer MOD_ZZ_Z(Integer first, Natural second) //Остаток от деления целого числа на целое число. 
{						//Выполнила Чаркова Дарья (5396).
	Integer result;

	result.A = MOD_NN_N(first.A, second);

	return result;
};

Integer DIV_ZZ_Z(Integer first, Natural second) //Частное от деления большего целого числа на меньшее 
						//или равное натуральное число с остатком (делитель отличен от нуля).
{						//Выполнил Уразаев Евгений (5396).
	Integer div;

	div.A = DIV_NN_N(first.A, second);

	if (POZ_Z_D(first) < 0)
		div.pos = 0;

	return div;
}

// конец модуля для целых чисел
////---------------------------------------------------------------------------------------------------------
//// Начало модуля для рациональных чисел(дробей)
Ratio ADD_QQ_Q(Ratio A, Ratio B)// Сложение дробей
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

Ratio TRAN_Z_Q(Integer A) // Преобразование целого в дробное
{
	Ratio B;//дробь, которую возвращает функция
	B.num = A; //число А в числитель
	B.denum.A.push_back(1); //в знаменатель ставим 1
	return B;
}



bool INT_Q_Z(Ratio R)//Проверка на целое, если рациональное число является целым, то «да», иначе «нет»
{
	return  (R.denum.A.size() == 1 && R.denum.A[0] == 1) ? 1 : 0; //Если размер знаменателя и первый его элемент равны 1 - функция возвращает 1, иначе - 0
}
Ratio MUL_QQ_Q(Ratio A, Ratio B) //умножение дробных чисел
{
	A.num = MUL_ZZ_Z(A.num, B.num);    // перемножение числителей
	A.denum = MUL_NN_N(A.denum, B.denum); // перемножение знаменателей 
	return RED_Q_Q(A);                   // возвращается сокращенная дробь
}

Ratio SUB_QQ_Q(Ratio A, Ratio B) //Вычитание дробей
{
	Ratio C;
	Natural temp = LCM_NN_N(A.denum, B.denum); // Поиск НОК
	A.num.A = MUL_NN_N(A.num.A, DIV_NN_N(temp, A.denum));
	B.num.A = MUL_NN_N(B.num.A, DIV_NN_N(temp, B.denum));
	C.num = SUB_ZZ_Z(A.num, B.num);
	C.denum = temp;
	return C;
}

Ratio RED_Q_Q(Ratio A) // Функция сокращения дроби
{
	Natural B = GCF_NN_N(A.num.A, A.denum); // Находим НОД от |числителя| и знаменателя
	A.num.A = DIV_NN_N(A.num.A, B); // Делим числитель на НОД
	A.denum = DIV_NN_N(A.denum, B); // Делим знаменатель на НОД
	return A;
}
Ratio DIV_QQ_Q(Ratio A, Ratio B) //деление дробных чисел
{
	Ratio C;
	Integer G;
	G.A = B.denum;
	G.pos = 0;
	C.num = MUL_ZZ_Z(A.num, G);
	C.denum = MUL_NN_N(A.denum, B.num.A);
		if (B.num.pos == 1)
			if (C.num.pos == 1)
				C.num.pos = 0;
			else
				C.num.pos = 1;
	return RED_Q_Q(C);
}
//// конец модуля для рациональных чисел(дробей)
////---------------------------------------------------------------------------------------------------------
////Модуль для многочленов
Polynomial MUL_Pxk_P(Polynomial M, int k) //умножает многочлен на x^k
{
	M.n = M.n + k; //увеличила степень
	M.C.resize(M.n + 1); //Выделяем память
	for (int i(M.n), j(k); j>0; i--, j--)
		M.C[i] = M.C[i - k];
	for (int i = 0; i < k; i++)
		M.C[i].num.A.A[0] = 0;
	return M;
}

Ratio LED_P_Z(Polynomial B) //возвращает старший коэффициент многочлена
{
	return B.C[B.n];
}

int DEG_P_N(Polynomial B) // возвращает степень многочлена
{
	return B.n;
}

Polynomial DIV_PP_P(Polynomial dividend, Polynomial denominator) // возвращает частное от деления divident на denominator
{
	int k(0);
	Polynomial quotient; // Частное
	quotient.n = dividend.n - denominator.n; //Степень частного
	quotient.C.resize(quotient.n + 1);
	Polynomial temp;
	Polynomial tempPol;
	while (dividend.n >= denominator.n);
	{
		quotient.C[quotient.n - k] = DIV_QQ_Q(dividend.C[dividend.n], denominator.C[denominator.n]);
		for (int i(quotient.n-k); i >= 0; i--)
		{
			tempPol.C[i] = quotient.C[i];
		}
		temp = MUL_PP_P(denominator, tempPol);
		dividend = (SUB_PP_P(dividend, temp));

	}

	return quotient;



}

Polynomial MOV_PP_P(Polynomial dividend, Polynomial denominator) // возвращает остаток от деления divident на denominator
{
	int k(0);
	Polynomial quotient; // Частное
	quotient.n = dividend.n - denominator.n; //Степень частного
	quotient.C.resize(quotient.n + 1);
	Polynomial temp;
	Polynomial tempPol;
	while (dividend.n >= denominator.n);
	{
		quotient.C[quotient.n - k] = DIV_QQ_Q(dividend.C[dividend.n], denominator.C[denominator.n]);
		for (int i(quotient.n - k); i >= 0; i--)
		{
			tempPol.C[i] = quotient.C[i];
		}
		temp = MUL_PP_P(denominator, tempPol);
		dividend = (SUB_PP_P(dividend, temp));

	}

	return dividend;



}

Polynomial DER_P_P(Polynomial B)
{
	Integer oneInt;
	oneInt.A.A[0] = 1;
	oneInt.pos = 1;
	return B;
}



Polynomial MUL_PP_P(Polynomial first, Polynomial second) //Умножение многочленов
{
	Polynomial res;
	res.n = first.n + second.n;
	for ()
}

Polynomial ADD_PP_P(Polynomial first, Polynomial second) // складывает многочлены
{
	Polynomial res;
	if (first.n >= second.n)
	{
		res.n = first.n;
		res.C.resize(res.n + 1);
		for (int i(0); i <= second.n; i++)
			res.C[i] = ADD_QQ_Q(first.C[i], second.C[i]);
		for (int i(second.n + 1); i <= first.n; i++)
			res.C[i] = first.C[i];
	}
	else
	{
		res.n = second.n;
		res.C.resize(res.n + 1);
		for (int i(0); i <= first.n; i++)
			res.C[i] = ADD_QQ_Q(first.C[i], second.C[i]);
		for (int i(first.n + 1); i <= second.n; i++)
			res.C[i] = second.C[i];
	}
	for (int i(res.n); i >= 0; i--)
	{
		if (res.C[i].num.A.A[0] == 0)
		{
			res.C.resize(res.n);
			res.n--;
		}
		else
			break;
	}
	return res;
}

Polynomial SUB_PP_P(Polynomial first, Polynomial second) // вычитает многочлены
{
	Polynomial res;
	if (first.n >= second.n)
	{
		res.n = first.n;
		res.C.resize(res.n + 1);
		for (int i(0); i <= second.n; i++)
			res.C[i] = SUB_QQ_Q(first.C[i], second.C[i]);
		for (int i(second.n + 1); i <= first.n; i++)
			res.C[i] = first.C[i];
	}
	else
	{
		res.n = second.n;
		res.C.resize(res.n + 1);
		for (int i(0); i <= first.n; i++)
			res.C[i] = SUB_QQ_Q(first.C[i], second.C[i]);
		for (int i(first.n + 1); i <= second.n; i++)
			res.C[i] = second.C[i];
	}
	for (int i(res.n); i >= 0; i--)
	{
		if (res.C[i].num.A.A[0] == 0)
		{
			res.C.resize(res.n);
			res.n--;
		}
		else
			break;
	}
	return res;
}

Polynomial MUL_P_Q(Polynomial chlen, Ratio ratio_number) //Умножение многочлена на рациональное число
{
	for (unsigned int i = 0; i <= chlen.n; i++)
	{
		chlen.C[i] = MUL_QQ_Q(chlen.C[i], ratio_number);
	}
	return chlen;
}

Polynomial FAC_P_PQ(Polynomial P) //Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
{

	Natural nok = P.C[0].denum;
	for (int i = 1; i < P.n + 1; i++)
		nok = LCM_NN_N(nok, P.C[i].denum);

	Natural nod = ABS_Z_N(P.C[0].num);
	for (int i = 1; i < P.n + 1; i++)
		nod = GCF_NN_N(nod, ABS_Z_N(P.C[i].num));

	for (int i = 0; i < P.n + 1; i++)
		P.C[i].num = DIV_ZZ_Z(P.C[i].num, nod);

	for (int i = 0; i < P.n + 1; i++)
		P.C[i].denum = DIV_NN_N(P.C[i].denum, nok);

	return P;
}

Polynomial GCF_PP_P(Polynomial PA, Polynomial PB) //НОД Многочлена
{
	if (PA.n < PB.n)
		return GCF_PP_P(PB, PA);

	while (PA.n != 0)
	{
		PA = MOV_PP_P(PA, PB);
		Polynomial T = PA;
		PA = PB;
		PB = T;
	}

	return PB;
}

Polynomial NMR_P_P(Polynomial chlen) //Преобразование многочлена — кратные корни в простые
{

	return DIV_PP_P(chlen, GCF_PP_P(DER_P_P(chlen), chlen));
	
}

//// конец модуля для многочленов
////---------------------------------------------------------------------------------------------------------
