#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>

using namespace std;

struct Natural
{
    vector<unsigned int> A;
};
struct Integer
{
    bool pos = true;
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
    unsigned int n;
};

#endif // STRUCTS_H
