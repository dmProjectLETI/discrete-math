#include "testunit.h"

#include <iostream>

void writeNatural(Natural N)
{
    for(int i = N.A.size() - 1; i >= 0; cout << N.A[i], i--);
}

void writeInteger(Integer I)
{
    cout << (!I.pos ? " - " : "");
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
    for(int i = P.C.size() - 1; i >= 0; i--)
    {
        cout << "[";
        writeRatio(P.C[i]);
        cout << " * x^" << i << "]";
        if(i - 1 >= 0)
        {
            if(P.C[i - 1].num.pos)
            {
                cout << " - ";
                P.C[i - 1].num.pos = false;
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
        for(int i = 0; i < n; i == n - 1 ? A[i] = rand() % 9 + 1 : A[i] = rand() % 10, i++);
    N.A = A;

    return N;
}

Natural generateNatural(unsigned n)
{
    Natural N = Natural();
    vector<unsigned int> A;
    do
    {
        A.insert(A.end(), n % 10);
        n /= 10;
    } while(n != 0);
    N.A = A;

    return N;
}

Integer generateInteger()
{
    Integer I = Integer();
    I.A = generateNatural();
    I.pos = rand() % 2;

    return I;
}

Integer generateInteger(int n)
{
    Integer I = Integer();
    I.A = generateNatural(abs(n));
    I.pos = n >= 0;

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
    } while(N.A[N.A.size() - 1] == 0);
    R.denum = N;

    return R;
}

Ratio generateRatio(int n, unsigned dn)
{
    Ratio R = Ratio();
    R.num = generateInteger(n);
    R.denum = generateNatural(dn);

    return R;
}

Polynomial generatePolynomial()
{
    Polynomial P = Polynomial();

    int n = rand() % 10 + 1;
    vector<Ratio> v(n);
    for(int i = 0; i < n; v[i] = generateRatio(), i++);
    P.n = n - 1;
    P.C = v;

    return P;
}

Polynomial generatePolynomial(vector<Ratio> v)
{
    Polynomial P = Polynomial();
    P.C = v;
    P.n = v.size() - 1;

    return P;
}
