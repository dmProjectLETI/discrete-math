using namespace std;

//Модуль натуральные числа
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
	vector<ratio>C;
	unsigned int k;
};
// Модуль для натуральных
bool COM_NN_D(Natural First, Natural Second);//Сравнивает два числа. Возвращает 1,
											// если первое больше или равно второму. 0 - если меньше.
bool NZER_N_B(Natural chislo); //Проверяет число на не равенство нулю
							  //1- число положительное, 0 - число равно 0
Natural ADD_1N_N(Natural chislo); //Прибавляет 1 к числу
Natural ADD_NN_N(Natural chislo1, Natural chislo2);//Складывает два числа
Natural SUB_NN_N(Natural First, Natural Second); //Вычитает из одного числа другое. Работает только
												//для неотрицательных результатов, поэтому перед вызовом этой функции
												//необходимо убедиться, что первое число не меньше второго
Natural MUL_ND_N(Natural ch, int cifra); //Умножает число на цифру
Natural MUL_Nk_N(Natural &Input, int k); //Умножает число на 10^k
Natural MUL_NN_N(Natural chislo1, Natural chislo2); //Перемножает два числа
Natural SUB_NDN_N(Natural chislo1, Natural chislo2, int c); //Вычитает из первого числа второе, умноженное на цифру
															//аналогично вычитанию, перед вызовом необходимо убедиться,
															//что результат возможен, т.е. неотрицателен
Natural DIV_NN_Dk(Natural chislo1, Natural chislo2);//Вычисляет первую цифру частного, умноженную на 10^k,
													//где k - позиция этой цифры в частном
Natural DIV_NN_N(Natural delimoe, Natural delitel); //Находит неполное частное двух чисел
Natural MOD_NN_N(Natural chislo1, Natural chislo2);//Находит остаток от деления первого числа на второе
Natural GCF_NN_N(Natural chislo1, Natural chislo2);//Находит НОД двух чисел
Natural LCM_NN_N(Natural chislo1, Natural chislo2);//Находит НОК двух чисел
// Конец модуля для натуральных

// Модуль для целых
int POZ_Z_D(Integer num); //Определение знака целого числа, сигнатура.
Natural ABS_Z_N(Integer num); //Модуль целого.
Integer MUL_Z_NEGZ(Integer num); //Умножение целого на -1.
Integer ADD_ZZ_Z(Integer first, Integer second); //Сложение двух целых.
Integer SUB_ZZ_Z(Integer first, Integer second); //Вычитание двух целых.
Integer MOD_ZZ_Z(Integer first, Integer second); //Остаток от деления двух целых
Integer DIV_ZZ_Z(Integer first, Integer second); //Частное от деления двух целых
// Конец модуля для целых

// Модуль для дробей
Ratio ADD_QQ_Q(Ratio A, Ratio B); // Функция сложения двух рациональных чисел
Ratio TRAN_Z_Q(Integer A); // Функция, которая преобразует целое в дробное(со знаменателем = 1)
Ratio RED_Q_Q(Ratio A); // Функция сокращения дроби
Integer TRAN_Q_Z(Ratio b); // Преобразование дробного в целое
bool INT_Q_Z(Ratio R); // Если рациональное число - целое, то 1, иначе 0
// Конец модуля для дробей

// Модуль для многочленов
Polynomial ADD_PP_P(Polynomial M, Polynomial N) // складывает многочлены
Polynomial SUB_PP_P(Polynomial M, Polynomial N) // вычитает многочлены
Polynomial MUL_Pxk_P(Polynomial M, int k); //умножает многочлен на x^k
Ratio LED_P_Z (Polynomial B); //возвращает старший коэффициент многочлена
int DEG_P_N (Polynomial B); //возвращает степень многочлена
// Конец модуля для многочленов
