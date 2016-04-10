#include "testunit.h"
#include <iostream>

void writeNatural(Natural N)
{
    for(int i = 0; i < N.A.size(); cout << N.A[i], i++);
}

void writeInteger(Integer I)
{
    cout << (I.b ? " - " : "");
    writeNatural(I.A);
}

void writeRatio(Ratio R)
{
    writeInteger(R.num);
    cout << " / ";
    writeNatural(R.denum);
}

void writePolynomial(Polynomial P)
{
    for(int i = 0; i < P.C.size(); i++)
    {
        cout << "[";
        writeRatio(P.C[i]);
        cout << " * x^" << P.k - i << "]";
        if(i + 1 < P.C.size())
        {
            if(P.C[i + 1].num.b)
            {
                cout << " - ";
                P.C[i + 1].num.b = false;
            }
            else
                cout << " + ";
        }
    }
}

Natural generateNatural()
{
    Natural N = Natural();
    int n = rand() % 10 + 1;
    vector<unsigned int> A(n);
    if(n == 1)
        A[0] = rand() % 9 + 1;
    else
        for(int i = 0; i < n; i == 0 ? A[i] = rand() % 9 + 1 : A[i] = rand() % 10, i++);
    N.A = A;

    return N;
}

Integer generateInteger()
{
    Integer I = Integer();
    I.A = generateNatural();
    I.b = rand() % 2;

    return I;
}

Ratio generateRatio()
{
    Ratio R = Ratio();
    R.num = generateInteger();
    Natural N;
    do
    {
        N = generateNatural();
    } while(N.A[0] == 0);
    R.denum = N;

    return R;
}

Polynomial generatePolynomial()
{
    Polynomial P = Polynomial();

    int n = rand() % 10 + 1;
    vector<Ratio> v(n);
    for(int i = 0; i < n; v[i] = generateRatio(), i++);
    P.k = n - 1;
    P.C = v;

    return P;
}
