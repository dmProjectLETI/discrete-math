#include "natural.h"
#include "integer.h"
#include "ratio.h"
#include "polynomial.h"

Polynomial ADD_PP_P(Polynomial M, Polynomial N) // складывает многочлены
{
    Polynomial B;
    if (M.n > N.n)
        N.C.resize (M.C.size());
    else
        M.C.resize (N.C.size());
    B.C.resize(M.C.size());
    for(int i = 0; i < M.n + 1; i++)
        B.C[i] = ADD_QQ_Q(M.C[i], N.C[i]);
    return B;
}

Polynomial SUB_PP_P(Polynomial M, Polynomial N) // вычитает многочлены
{
    Polynomial B;
    if (M.n > N.n)
        N.C.resize (M.C.size());
    else
        M.C.resize (N.C.size());
    B.C.resize(M.C.size());
    for(int i = 0; i < M.n + 1; i++)
        B.C[i] = SUB_ZZ_Z(M.C[i], N.C[i]);
    return B;
}

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

Polynomial MUL_P_Q(Polynomial chlen, Ratio ratio_number) //Умножение многочлена на рациональное число
{
    for (unsigned int i = 0; i > chlen.n - 1; i++)
    {
        MUL_ZZ_Z(chlen.C[i].num.A[i], ratio_number.num.A[i]);
        MUL_ZZ_Z(chlen.C[i].denum.A[i], ratio_number.denum.A[i]);
    }
    return chlen;
}

Polynomial NMR_P_P(Polynomial chlen) //Преобразование многочлена — кратные корни в простые
{

        DIV_PP_P(chlen.C, GCF_PP_P(DER_P_P(chlen.C), chlen.C));
}

//Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
Polynomial FAC_P_PQ(Polynomial P)
{

    Natural nok = P.C[0].denum;
    for(int i = 1; i < P.k + 1; i++)
        nok = LCM_NN_N(nok, P.C[i].denum);

    Natural nod = ABS_Z_N(P.C[0].num);
    for(int i = 1; i < P.k + 1; i++)
        nod = GCF_NN_N(nod, ABS_Z_N(P.C[i].num));

    for(int i = 0; i < P.k + 1; i++)
        P.C[i].num = DIV_ZZ_Z(P.C[i].num, TRANS_N_Z(nod));

    for(int i = 0; i < P.k + 1; i++)
        P.C[i].denum = DIV_ZZ_Z(P.C[i].denum, TRANS_N_Z(nok));

    return P;
}

//НОД многочленов
Polynomial GCF_PP_P(Polynomial PA, Polynomial PB)
{
    if(PA.k < PB.k)
        return GCF_PP_P(PB, PA);

    while(PA.k != 0 || PA.C[0] != 0)
    {
        PA = MOD_PP_P(PA, PB);
        Polynomial T = PA;
        PA = PB;
        PB = T;
    }

    return PB;
}
