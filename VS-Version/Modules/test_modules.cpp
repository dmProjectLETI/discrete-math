#include "test_modules.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;
// Ìîäóëü äëÿ íàòóðàëüíûõ
bool COM_NN_D(Natural First, Natural Second)//Ñðàâíèâàåò äâà ÷èñëà. Âîçâðàùàåò 1,
{											// åñëè ïåðâîå áîëüøå èëè ðàâíî âòîðîìó. 0 - åñëè ìåíüøå.
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

bool NZER_N_B(Natural chislo) //Ïðîâåðÿåò ÷èñëî íà íå ðàâåíñòâî íóëþ
{							  //1- ÷èñëî ïîëîæèòåëüíîå, 0 - ÷èñëî ðàâíî 0
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

Natural ADD_1N_N(Natural chislo) //Ïðèáàâëÿåò 1 ê ÷èñëó
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

Natural ADD_NN_N(Natural chislo1, Natural chislo2)//Ñêëàäûâàåò äâà ÷èñëà
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

Natural SUB_NN_N(Natural First, Natural Second) //Âû÷èòàåò èç îäíîãî ÷èñëà äðóãîå. Ðàáîòàåò òîëüêî
{												//äëÿ íåîòðèöàòåëüíûõ ðåçóëüòàòîâ, ïîýòîìó ïåðåä âûçîâîì ýòîé ôóíêöèè
	int p = 0;									//íåîáõîäèìî óáåäèòüñÿ, ÷òî ïåðâîå ÷èñëî íå ìåíüøå âòîðîãî
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

Natural MUL_ND_N(Natural ch, int cifra) //Óìíîæàåò ÷èñëî íà öèôðó
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

Natural MUL_Nk_N(Natural &Input, int k) //Óìíîæàåò ÷èñëî íà 10^k
{
	for (int i = 0; i < k; ++i)
		Input.A.insert(Input.A.begin(), 0);
	return Input;
}

Natural MUL_NN_N(Natural chislo1, Natural chislo2) //Ïåðåìíîæàåò äâà ÷èñëà
{
	Natural Proizved;
	for (int i = 0; i < chislo2.A.size(); ++i)
	{
		Proizved = ADD_NN_N(MUL_Nk_N(MUL_ND_N(chislo1, chislo2.A[i]), i), Proizved);
	}
	return Proizved;
}

Natural SUB_NDN_N(Natural chislo1, Natural chislo2, int c) //Âû÷èòàåò èç ïåðâîãî ÷èñëà âòîðîå, óìíîæåííîå íà öèôðó
{															//àíàëîãè÷íî âû÷èòàíèþ, ïåðåä âûçîâîì íåîáõîäèìî óáåäèòüñÿ,
	return SUB_NN_N(chislo1, MUL_ND_N(chislo2, c));			//÷òî ðåçóëüòàò âîçìîæåí, ò.å. íåîòðèöàòåëåí
}

Natural DIV_NN_Dk(Natural chislo1, Natural chislo2)//Âû÷èñëÿåò ïåðâóþ öèôðó ÷àñòíîãî, óìíîæåííóþ íà 10^k,
{													//ãäå k - ïîçèöèÿ ýòîé öèôðû â ÷àñòíîì
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

Natural DIV_NN_N(Natural delimoe, Natural delitel) //Íàõîäèò íåïîëíîå ÷àñòíîå äâóõ ÷èñåë
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
		} while (!COM_NN_D(delitel, delimoe));
		return chastnoe;
	}
}

Natural MOD_NN_N(Natural chislo1, Natural chislo2)//Íàõîäèò îñòàòîê îò äåëåíèÿ ïåðâîãî ÷èñëà íà âòîðîå
{
	return SUB_NN_N(chislo1, MUL_NN_N(DIV_NN_N(chislo1, chislo2), chislo2));
}

Natural GCF_NN_N(Natural chislo1, Natural chislo2)//Íàõîäèò ÍÎÄ äâóõ ÷èñåë
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

Natural LCM_NN_N(Natural chislo1, Natural chislo2)//Íàõîäèò ÍÎÊ äâóõ ÷èñåë
{
	return DIV_NN_N(MUL_NN_N(chislo1, chislo2), GCF_NN_N(chislo1, chislo2));
}

// Êîíåö ìîäóëÿ äëÿ íàòóðàëüíûõ

// Ìîäóëü äëÿ öåëûõ
struct Integer 
{
	bool pos = true;
	Natural A;
};

int POZ_Z_D(Integer num) //Ïîêàçàòåëü çíàêà, ñèãíàòóðà.
{
	if (!num.pos)
		return -1;
	else if (NZER_N_B(num.A))
		return 1;
	return 0;
}

Natural ABS_Z_N(Integer num) //Ìîäóëü.
{
	return num.A;
}

Integer MUL_Z_NEGZ(Integer num) //Óìíîæåíèå íà -1.
{
	num.pos = !num.pos;
	return num;
}

Integer ADD_ZZ_Z(Integer first, Integer second) //Ñëîæåíèå äâóõ öåëûõ.
{
	Integer sum;
	if (POZ_Z_D(first) <= 0)
		if (POZ_Z_D(second) <= 0) {
			sum.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
			sum = MUL_Z_NEGZ(sum);
		}
		else {
			if (ABS_Z_N(first) > ABS_Z_N(second)) {
				sum = MUL_Z_NEGZ(sum);
			} 
			sum.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		}
	else 
		if (POZ_Z_D(second) >= 0)
			sum.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		else {
			if (ABS_Z_N(second) > ABS_Z_N(first)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sum.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
	return sum;
}

Integer SUB_ZZ_Z(Integer first, Integer second) //Âû÷èòàíèå äâóõ öåëûõ.
{
	Integer sub;
	sub.pos = 1;
	if (POZ_Z_D(first) <= 0) 
		if (POZ_Z_D(second) <= 0) {
			if (ABS_Z_N(first) > ABS_Z_N(second)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		} else {
			sub.A = ADD_ZZ_Z(first, second);
			sum = MUL_Z_NEGZ(sum);
		}
	else {
		if (POZ_Z_D(second) >= 0) {
			if (ABS_Z_N(second) > ABS_Z_N(first)) {
				sum = MUL_Z_NEGZ(sum);
			}
			sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
		else 
			sub.A = ADD_ZZ_Z(first, second);
	}
	return sub;
}

Integer MOD_ZZ_Z(Integer first, Integer second)
{
	Integer result;
	result.pos = 1;
	if (NZER_N_B(second.A)) //If divisor is not equal to 0
	{
		result.A = MOD_NN_N(first.A, second.A);
		if ((POZ_Z_D(first) < 0)) //If dividend is negative
			result.A = SUB_ZZ_Z(second.A, result.A); // If a < 0 then a mod b = |a|- (|a| mod |b|)
		return result;
        } 
	else //If divisor is equal to 0
		throw invalid_argument("Divided by 0");
};

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
// Êîíåö ìîäóëÿ äëÿ öåëûõ

// Ìîäóëü äëÿ äðîáåé

Ratio ADD_QQ_Q(Ratio A, Ratio B)
{
	Ratio C;
	Natural temp = LCM_NN_N(A.denum, B.denum); // Ïîèñê ÍÎÊ
	A.num.A = MUL_NN_N(A.num.A, DIV_NN_N(temp, A.denum));
	B.num.A = MUL_NN_N(B.num.A, DIV_NN_N(temp, B.denum));
	C.num = ADD_ZZ_Z(A.num, B.num);
	C.denum = temp;
	return C;
}

Integer TRAN_Q_Z(Ratio b) // Ïðåîáðàçîâàíèå äðîáíîãî â öåëîå (Åñëè çíàìåíàòåëü ðàâåí 1)
						  // Ïåðåä âûçîâîì ñëåäóåò óáåäèòüñÿ, ÷òî çíàìåíàòåëü ðàâåí åäèíèöå
{
	return(b.num); // Ãîñïîæè, êàê æå ýòî ñëîæíî áûëî
}

Ratio TRAN_Z_Q(Integer A)
{
	Ratio B; //äðîáü, êîòîðóþ âîçâðàùàåò ôóíêöèÿ
	B.num = A; //÷èñëî À â ÷èñëèòåëü
	B.denum.a.push_back(1); //â çíàìåíàòåëü ñòàâèì 1
	return B;
}

Ratio RED_Q_Q(Ratio A) // Ôóíêöèÿ ñîêðàùåíèÿ äðîáè
{
	Natural B = GVF_NN_N(A.num.A, A.denum); // Íàõîäèì ÍÎÄ îò |÷èñëèòåëÿ| è çíàìåíàòåëÿ
	A.num.A = DIV_ZZ_Z(A.num.A, B); // Äåëèì ÷èñëèòåëü íà ÍÎÄ
	A.denum = DIV_ZZ_Z(A.denum, B); // Äåëèì çíàìåíàòåëü íà ÍÎÄ
	return A;
}

bool INT_Q_Z(Ratio R)
{
	return  (R.denum.A.size() == 1 && R.denum.A[0] == 1) ? 1 : 0; //Åñëè ðàçìåð çíàìåíàòåëÿ è ïåðâûé åãî ýëåìåíò ðàâíû 1 - ôóíêöèÿ âîçâðàùàåò 1, èíà÷å - 0
}
// Êîíåö ìîäóëÿ äëÿ äðîáåé
//Модуль для многочленов
Polynomial MUL_Pxk_P(Polynomial M, int k) //умножает многочлен на x^k
{
	M.n = M.n + k; //увеличила степень
	M.C.resize(M.n + 1); //Выделяем память
	for (int i(M.n), j(k); j>0; i--, j--)
		M.C[i] = M.C[i - k];
	for (int i = 0; i <  k; i++)
		M.C[i].num.A.A[0] = 0;
	return M;
}

Ratio LED_P_Z (Polynomial B) //возвращает старший коэффициент многочлена
{
	return B.C[B.n]; 
}

int DEG_P_N (Polynomial B) // возвращает степень многочлена
{
	return B.n;
}
// конец модуля для многочленов
