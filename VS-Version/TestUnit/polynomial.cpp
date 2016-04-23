#include "Polynomial.h"

Ratio zeroRat(Ratio num)
{
	num.num.A.A.resize(1);
	num.num.A.A[0] = 0;
	num.denum.A.resize(1);
	num.denum.A[0] = 1;
	num.num.pos = 1;

	return num;
}
Ratio oneRat(Ratio num)
{
	num.num.A.A.resize(1);
	num.num.A.A[0] = 1;
	num.denum.A.resize(1);
	num.denum.A[0] = 1;
	num.num.pos = 1;
	return num;
}
Polynomial MUL_Pxk_P(Polynomial M, int k) //умножает многочлен на x^k, выполнила Гаврильева Александра (5395)
{
	M.n = M.n + k; //увеличила степень
	M.C.resize(M.n + 1); //Выделяем память
	for (int i(M.n), j(k); j>0; i--, j--)
		M.C[i] = M.C[i - k];
	for (int i = 0; i < k; i++)
		M.C[i].num.A.A[0] = 0;
	return M;
}

Ratio LED_P_Z(Polynomial B) //возвращает старший коэффициент многочлена, выполнил Савчук Максим (5395)
{
	return B.C[B.n];
}

int DEG_P_N(Polynomial B) // возвращает степень многочлена,  выполнил Савчук Максим (5395)
{
	return B.n;
}

Polynomial DIV_PP_P(Polynomial dividend, Polynomial denominator) // возвращает частное от деления divident на denominator, выполнил Квятковский Антон (5395)
{
	int k(0);
	Ratio null;
	null = zeroRat(null);
	Polynomial quotient; // Частное
	quotient.n = dividend.n - denominator.n; //Степень частного
	quotient.C.resize(quotient.n + 1);
	for (int i(0); i <= quotient.n; i++)
	{
		quotient.C[i] = null;
	}
	Polynomial temp;
	Polynomial tempPol;
	while (dividend.n >= denominator.n)
	{
		quotient.C[quotient.n - k] = DIV_QQ_Q(dividend.C[dividend.n], denominator.C[denominator.n]);
		tempPol.C.resize(quotient.n + 1 - k);
		tempPol.n = quotient.n - k;
		for (int i(tempPol.n); i >= 0; i--)
			tempPol.C[i] = quotient.C[i];
		temp = MUL_PP_P(denominator, tempPol);
		dividend = SUB_PP_P(dividend, temp);
		k++;

	}

	return quotient;



}

Polynomial MOV_PP_P(Polynomial dividend, Polynomial denominator) // возвращает остаток от деления divident на denominator, выполнил Квятковский Антон (5395)
{
	int k(0);
	Ratio null;
	null = zeroRat(null);
	Polynomial quotient; // Частное
	quotient.n = dividend.n - denominator.n; //Степень частного
	quotient.C.resize(quotient.n + 1);
	for (int i(0); i <= quotient.n; i++)
	{
		quotient.C[i] = null;
	}
	Polynomial temp;
	Polynomial tempPol;
	while (dividend.n >= denominator.n)
	{
		quotient.C[quotient.n - k] = DIV_QQ_Q(dividend.C[dividend.n], denominator.C[denominator.n]);
		tempPol.C.resize(quotient.n + 1 - k);
		tempPol.n = quotient.n - k;
		for (int i(tempPol.n); i >= 0; i--)
			tempPol.C[i] = quotient.C[i];
		temp = MUL_PP_P(denominator, tempPol);
		dividend = SUB_PP_P(dividend, temp);
		k++;

	}

	return dividend;



}

Polynomial DER_P_P(Polynomial B) // Производная, выполнил Большаков Виктор (5395)
{
	Integer oneInt;
	oneInt.A.A.resize(1);
	oneInt.A.A[0] = 1;
	oneInt.pos = 1;
	Ratio ratOne = TRAN_Z_Q(oneInt);
	Polynomial res;
	res.C.resize(B.C.size() - 1);
	res.n = B.n - 1;
	for (int i(0); i <= res.n; i++)
	{
		res.C[i] = MUL_QQ_Q(B.C[i + 1], ratOne);
		ratOne = ADD_QQ_Q(ratOne, ratOne);
	}
	return res;
}



Polynomial MUL_PP_P(Polynomial first, Polynomial second) //Умножение многочленов, выполнила Гаврильева Александра (5395)
{
	Polynomial res;
	res.n = first.n + second.n;
	res.C.resize(res.n + 1);
	Ratio null;
	null = zeroRat(null);
	first.C.resize(res.n + 1);
	second.C.resize(res.n + 1);
	for (int i(first.n + 1); i <= res.n; i++)
		first.C[i] = null;

	for (int i(second.n + 1); i <= res.n; i++)
		second.C[i] = null;
	for (int i(0); i <= res.n; i++)
		res.C[i] = null;
	for (int i(0); i <= res.n; i++)
		for (int j(0); j <= i; j++)
			res.C[i] = ADD_QQ_Q(res.C[i], MUL_QQ_Q(first.C[j], second.C[i - j]));
	return res;
}

Polynomial ADD_PP_P(Polynomial first, Polynomial second) // складывает многочлены , выполнил Бах Артём (5395)
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

Polynomial SUB_PP_P(Polynomial first, Polynomial second) // вычитает многочлены, выполнил Бах Артём (5395)
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

Polynomial MUL_P_Q(Polynomial chlen, Ratio ratio_number) //Умножение многочлена на рациональное число, выполнил Павел Укропов (5395)
{
	for (unsigned int i = 0; i <= chlen.n; i++)
	{
		chlen.C[i] = MUL_QQ_Q(chlen.C[i], ratio_number);
	}
	return chlen;
}

Polynomial FAC_P_PQ(Polynomial P) //Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей, выполнил Тимофей Кузьмин (5395)
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

Polynomial GCF_PP_P(Polynomial PA, Polynomial PB) //НОД Многочлена,  выполнил Тимофей Кузьмин (5395)
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

Polynomial NMR_P_P(Polynomial chlen) //Преобразование многочлена — кратные корни в простые, выполнил Павел Укропов (5395)
{
	Polynomial temp;
	Polynomial res;
	Polynomial one;
	one.C.resize(1);
	one.C[0] = oneRat(one.C[0]);
	while (chlen.n != 0)
	{
		temp = GCF_PP_P(DIV_PP_P(chlen, GCF_PP_P(DER_P_P(chlen), chlen)), DER_P_P(chlen));
		one = MUL_PP_P(one, DIV_PP_P(DIV_PP_P(chlen, GCF_PP_P(DER_P_P(chlen), chlen)), temp));
		chlen = GCF_PP_P(chlen, DER_P_P(chlen));
	}
	return one;


}