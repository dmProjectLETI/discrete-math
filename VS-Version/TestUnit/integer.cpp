#include "integer.h"
#include "natural.h"

int POZ_Z_D(Integer num) //Определение знака целого числа.
{
    if (!num.b)
        return -1;
    else if (NZER_N_B(num.A))
        return 1;
    return 0;
}

Natural ABS_Z_N(Integer num) //Модуль.
{
    return num.A;
}

Integer MUL_Z_NEGZ(Integer num) //Умножение целого на -1.
{
    num.b = !num.b;
    return num;
}

//DO NOT WORK
Integer ADD_ZZ_Z(Integer first, Integer second) //Сложение двух целых.
{
    Integer sum;
    if (POZ_Z_D(first) <= 0)
        if (POZ_Z_D(second) <= 0) {
            sum.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
            sum = MUL_Z_NEGZ(sum);
        }
        else {
            if (first.A > second.A) {
                sum = MUL_Z_NEGZ(sum);
            }
            sum.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
        }
    else
        if (POZ_Z_D(second) >= 0)
            sum.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
        else {
            if (second.A > first.A) {
                sum = MUL_Z_NEGZ(sum);
            }
            sum.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
        }
    return sum;
}

//DO NOT WORK
Integer SUB_ZZ_Z(Integer first, Integer second) //Вычитание двух целых.
{
    Integer sub;
    sub.b = 1;
    if (POZ_Z_D(first) <= 0)
        if (POZ_Z_D(second) <= 0) {
            if (first.A > second.A) {
                sum = MUL_Z_NEGZ(sum);
            }
            sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
        } else {
            sub.A = ADD_ZZ_Z(first, second);
            sum = MUL_Z_NEGZ(sum);
        }
    else {
        if (POZ_Z_D(second) >= 0) {
            if (second.A > first.A) {
                sum = MUL_Z_NEGZ(sum);
            }
            sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
        }
        else
            sub.A = ADD_ZZ_Z(first, second);
    }
    return sub;
}

//DO NOT WORK
Integer MOD_ZZ_Z(Integer first, Integer second) //Остаток от деления двух целых
{
    Integer result;
    result.b = 1;
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