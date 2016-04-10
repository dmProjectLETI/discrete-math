#include "ratio.h"

// Функция сложения двух рациональных чисел
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

// Функция, которая преобразует целое в дробное(со знаменателем = 1)
Integer TRAN_Q_Z(Ratio b)
{
    return(b.num); // Ãîñïîæè, êàê æå ýòî ñëîæíî áûëî
}

// Функция сокращения дроби
Ratio TRAN_Z_Q(Integer A)
{
    Ratio B; //äðîáü, êîòîðóþ âîçâðàùàåò ôóíêöèÿ
    B.num = A; //÷èñëî À â ÷èñëèòåëü
    B.denum.a.push_back(1); //â çíàìåíàòåëü ñòàâèì 1
    return B;
}

// Преобразование дробного в целое
Ratio RED_Q_Q(Ratio A)
{
    Natural B = GVF_NN_N(A.num.A, A.denum); // Íàõîäèì ÍÎÄ îò |÷èñëèòåëÿ| è çíàìåíàòåëÿ
    A.num.A = DIV_ZZ_Z(A.num.A, B); // Äåëèì ÷èñëèòåëü íà ÍÎÄ
    A.denum = DIV_ZZ_Z(A.denum, B); // Äåëèì çíàìåíàòåëü íà ÍÎÄ
    return A;
}

// Если рациональное число - целое, то 1, иначе 0
bool INT_Q_Z(Ratio R)
{
    return  (R.denum.A.size() == 1 && R.denum.A[0] == 1) ? 1 : 0; //Åñëè ðàçìåð çíàìåíàòåëÿ è ïåðâûé åãî ýëåìåíò ðàâíû 1 - ôóíêöèÿ âîçâðàùàåò 1, èíà÷å - 0
}
