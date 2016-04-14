#include <iostream>
#include "testunit.h"
#include "natural.h"
#include "integer.h"
#include "ratio.h"
#include <ctime>

using namespace std;

void naturalTest()
{
    unsigned a, b;
    cout << "Введите первое число" << endl;
    cin >> a;
    cout << "Введите второе число" << endl;
    cin >> b;

    Natural A, B;
    A = generateNatural(a);
    B = generateNatural(b);

    cout << "Сравнение натуральных чисел: 2 - если первое больше либо равно второму, 0, если равно, 1 иначе."
         << endl << COM_NN_D(A, B) << endl << endl;
    cout << "Проверка на ноль: если число не равно нулю, то «да» иначе «нет»"
         << endl << NZER_N_B(A) << endl << endl;
    cout << "Добавление 1 к натуральному числу"
         << endl; writeNatural(ADD_1N_N(A)); cout << endl << endl;
    cout << "Сложение натуральных чисел"
         << endl; writeNatural(ADD_NN_N(A, B)); cout << endl << endl;
    cout << "Вычитание из первого большего натурального числа второго меньшего или равного"
         << endl; writeNatural(SUB_NN_N(A, B)); cout << endl << endl;
    cout << "Умножение натурального числа на цифру"
         << endl; writeNatural(MUL_ND_N(A, b % 10)); cout << endl << endl;
    cout << "Умножение натурального числа на 10 ^ k"
         << endl; writeNatural(MUL_Nk_N(A, b % 10)); cout << endl << endl;
    cout << "Умножение натуральных чисел"
         << endl; writeNatural(MUL_NN_N(A, B)); cout << endl << endl;
    cout << "Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом"
         << endl; writeNatural(SUB_NDN_N(A, B, b % 10)); cout << endl << endl;
    cout << "Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k, где k - номер позиции этой цифры (номер считается с нуля)"
         << endl; writeNatural(DIV_NN_Dk(A, B)); cout << endl << endl;
    cout << "Частное от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)"
         << endl; writeNatural(DIV_NN_N(A, B)); cout << endl << endl;
    cout << "Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)"
         << endl; writeNatural(MOD_NN_N(A, B)); cout << endl << endl;
    cout << "НОД натуральных чисел"
         << endl; writeNatural(GCF_NN_N(A, B)); cout << endl << endl;
    cout << "НОК натуральных чисел"
         << endl; writeNatural(LCM_NN_N(A, B)); cout << endl << endl;
}

void integerTest()
{
    int a, b;
    cout << "Введите первое число" << endl;
    cin >> a;
    cout << "Введите второе число" << endl;
    cin >> b;

    Integer A, B;
    A = generateInteger(a);
    B = generateInteger(b);

    Natural N;
    N = generateNatural(static_cast<unsigned>(abs(b)));

    cout << "Определение знака целого числа"
         << endl << POZ_Z_D(A) << endl << endl;
    cout << "Модуль целого."
         << endl; writeNatural(ABS_Z_N(A)); cout << endl << endl;
    cout << "Умножение целого на -1."
         << endl; writeInteger(MUL_Z_NEGZ(A)); cout << endl << endl;
    cout << "Сложение двух целых."
         << endl; writeInteger(ADD_ZZ_Z(A, B)); cout << endl << endl;
    cout << "Вычитание двух целых."
         << endl; writeInteger(SUB_ZZ_Z(A, B)); cout << endl << endl;
    cout << "Остаток от деления двух целых"
         << endl; writeInteger(MOD_ZZ_Z(A, N)); cout << endl << endl;
    cout << "Частное от деления двух целых"
         << endl; writeInteger(DIV_ZZ_Z(A, N)); cout << endl << endl;
}

void ratioTest()
{
    int a, b;
    unsigned da, db;
    cout << "Введите числитель первого числа" << endl;
    cin >> a;
    cout << "Введите знаменатель первого числа" << endl;
    cin >> da;
    cout << "Введите числитель второго числа" << endl;
    cin >> b;
    cout << "Введите знаменатель второго числа" << endl;
    cin >> db;

    Ratio A, B;
    A = generateRatio(a, da);
    B = generateRatio(b, db);

    cout << "Функция сложения двух рациональных чисел"
         << endl; writeRatio(ADD_QQ_Q(A, B)); cout << endl << endl;
    cout << "Функция, которая преобразует целое в дробное(со знаменателем = 1)"
         << endl; writeRatio(TRAN_Z_Q(A.num)); cout << endl << endl;
    cout << "Функция сокращения дроби"
         << endl; writeRatio(RED_Q_Q(A)); cout << endl << endl;
    cout << "Преобразование дробного в целое"
         << endl; writeInteger(TRAN_Q_Z(A)); cout << endl << endl;
    cout << "Если рациональное число - целое, то 1, иначе 0"
         << endl << INT_Q_Z(A) << endl << endl;
}
/*
Polynomial readPolynomial()
{
    unsigned n;
    cout << "Введите степень многочлена" << endl;
    cin >> n;

    vector<Ratio> v(n + 1);
    for(int i = 0; i < n + 1; i++)
    {
        int a, b;
        unsigned da, db;
        cout << "Введите числитель " << i + 1 << "-го коэффициента" << endl;
        cin >> a;
        cout << "Введите знаменатель " << i + 1 << "-го коэффициента" << endl;
        cin >> da;

        Ratio A = generateRatio(a, da);;
        v[i] = A;
    }

    return generatePolynomial(v);
}

void polynomialTest()
{
    Polynomial A = readPolynomial(),
                B = readPolynomial();
    int k;
    cout << "Введите k" << endl;
    cin >> k;

    int a, b;
    unsigned da, db;
    cout << "Введите числитель рационального числа" << endl;
    cin >> a;
    cout << "Введите знаменатель рационального числа" << endl;
    cin >> da;

    Ratio R = generateRatio(a, da);

    cout << "Функция складывает многочлены"
         << endl; writePolynomial(ADD_PP_P(A, B)); cout << endl << endl;
    cout << "Функция вычитает многочлены"
         << endl; writePolynomial(SUB_PP_P(A, B)); cout << endl << endl;
    cout << "Функция умножает многочлен на x^k"
         << endl; writePolynomial(MUL_Pxk_P(A, k)); cout << endl << endl;
    cout << "Функция возвращает старший коэффициент многочлена"
         << endl; writeRatio(LED_P_Z(A)); cout << endl << endl;
    cout << "Функция возвращает степень многочлена"
         << endl << DEG_P_N(A) << endl << endl;
    cout << "Функция умножения многочлена на рациональное число"
         << endl; writePolynomial(MUL_P_Q(A, R)); cout << endl << endl;
    cout << "Функция преобразования многочлена — кратные корни в простые"
         << endl; writePolynomial(NMR_P_P(A)); cout << endl << endl;
    cout << "Функция НОД многочленов"
         << endl; writePolynomial(GCF_PP_P(A, B)); cout << endl << endl;
    cout << "Функция вынесения из многочлена НОК знаменателей коэффициентов и НОД числителей"
         << endl; writePolynomial(FAC_P_PQ(A)); cout << endl << endl;
}
*/
int main()
{
    setlocale(0, "");
    srand(time(0));
    char c = '\0';

    do
    {
        //naturalTest();
        //integerTest();
        ratioTest();
        //polynomialTest();
        cin >> c;
    } while(c != 'q');

    return 0;
}

