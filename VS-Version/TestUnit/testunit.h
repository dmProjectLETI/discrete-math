/*
 * created by tim.tim 10.04.2016
 *
 * Unit that contains some functions for testing
 * base modules, like Natural, or Integer, or ...
 *
 * Before using that recommend to do "srand(time(0));"
 * for best random varys
*/

#ifndef TESTUNIT_H
#define TESTUNIT_H

#include <vector>

using namespace std;

struct Natural
{
    vector<unsigned int> A;
};
struct Integer
{
    bool b;
    Natural A;
};
struct Ratio
{
    Integer num;
    Natural denum;
};
struct Polynomial
{
    vector<Ratio>C;
    unsigned int k;
};

// @@@ Block of "write"-functions

//write Natural N to standart output device
void writeNatural(Natural N);
//write Integer I to standart output device
void writeInteger(Integer I);
//write Ratio R to standart output device
void writeRatio(Ratio R);
//write Polynomial P to standart output device
void writePolynomial(Polynomial P);


// @@@ Block of "generate"-functions
//return random-generated Polynomial
Polynomial generatePolynomial();
//return random-generated Ratio
Ratio generateRatio();
//return random-generated Integer
Integer generateInteger();
//return random-generated Natural
Natural generateNatural();

#endif // TESTUNIT_H
