#include <iostream>
#include <conio.h>
#include <vector>
#include "test_modules.h"
#include <string>


using namespace std;

Natural natInput()
{
	string str;
	Natural num;
	cin >> str;
	num.A.resize(str.length());
	for (int i(str.length()-1), j(0); i>=0; i--, j++)
	{
		num.A[j] = str[i] - '0';
	}

	return num;
}

void natOutput(Natural num)
{
	for (int i(num.A.size() - 1); i >= 0; i--)
		cout << num.A[i];
	cout << endl;
}

Integer intInput()
{
	string str;
	Integer num;
	cin >> str;
	if (str[0] == '-')
	{
		str.erase(0, 1);
		num.pos = 0;
	}
	else
		num.pos = 1;
	num.A.A.resize(str.length());
	for (int i(str.length() - 1), j(0); i >= 0; i--, j++)
	{
		num.A.A[j] = str[i] - '0';
	}

	return num;
}

void intOutput(Integer num)
{
	if (num.pos == 0)
	{
		cout << '-';
	}
	for (int i(num.A.A.size() - 1); i >= 0; i--)
		cout << num.A.A[i];
	cout << endl;
}

Ratio ratInput()
{
	Ratio num;
	cout << "Введите числитель ";
	num.num = intInput();
	cout << "введите знаменатель ";
	num.denum = natInput();
	return num;
}

void ratOutput(Ratio num)
{
	cout << "Числитель: ";
	intOutput(num.num);
	cout << "Знаменатель: ";
	natOutput(num.denum);
}

Polynomial polInput()
{
	Polynomial num;
	cout << "Введите степень многочлена: ";
	cin >> num.n;
	num.C.resize(num.n+1);
	for (int i(0); i <= num.n; i++)
	{
		cout << "Введите " << i + 1 << " коэффциент" << endl;
		num.C[i] = ratInput();
	}
	return num;
}

void polOutput(Polynomial num)
{
	cout << "Степень многочлена: " << num.n << endl;
	for (int i(0); i <= num.n; i++)
	{
		cout << i + 1 << " коэффициент " << endl;
		ratOutput(num.C[i]);
	}
}

void zeroCheck(Integer num)
{
}

int main()
{
	setlocale(0, "");
	int keyCode(0);
	do
	{
		cout << "\"DmMath\"  - программа для работы с длинными числами." << endl;
		cout << "Данная программа является тестовой демонстрацией работы алгоритмов над длинными числами" << endl;
		cout << "Конечный вариант будет реализован с использованием Qt и представлен на защите" <<  endl << endl;
		cout << "Выполнено студентами групп 5372, 5373, 5395, 5396" << endl;
		cout << "Выберите модуль для работы: "  << endl;
		cout << "1) Натуральное число" << endl;
		cout << "2) Целое число" << endl;
		cout << "3) Дробное число" << endl;
		cout << "4) Многочлен" << endl;
		cin >> keyCode;
		switch (keyCode)
		{
		case 1: 
		{
			Natural num;
			Natural second;
			system("cls");
			cout << "Введите натуральное число (неотрицательное)" << endl;
			num = natInput();
			do
			{
				cout << "Текущее число: ";
				natOutput(num);
				cout << "Выберите модуль:" << endl;
				cout << "1)Сравнивает два числа. Возвращает 1 если первое больше или равно второму. 0 - если меньше " << endl;
				cout << "2) Проверяет число на не равенство нулю  1- число положительное, 0 - число равно 0" << endl;
				cout << "3)Прибавляет 1 к числу " << endl;
				cout << "4)Складывает два числа " << endl;
				cout << "5)Вычитает из одного числа другое " << endl;
				cout << "6)Умножает число на цифру " << endl;
				cout << "7) Умножает число на 10^k" << endl;
				cout << "8) Перемножает два числа" << endl;
				cout << "9) Вычитает из первого числа второе, умноженное на цифру" << endl;
				cout << "10) Вычисляет первую цифру частного, умноженную на 10^k где k - позиция этой цифры в частном" << endl;
				cout << "11) Находит неполное частное двух чисел" << endl;
				cout << "12) Находит остаток от деления первого числа на второе " << endl;
				cout << "13) Находит НОД двух чисел" << endl;
				cout << "14) Находит НОК двух чисел" << endl;
				cout << "15) Ввести число заново" << endl;
				cout << "16) Вывести число" << endl;
				cout << "17) Выбрать другой модуль" << endl;
				cin >> keyCode;
				switch (keyCode)
				{
				case 1:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					if (COM_NN_D(num, second))
						cout << "Первое больше или равно второму" << endl;
					else
						cout << "Второе больше первого" << endl;
					break;
				}
				case 2:
				{
					if (NZER_N_B(num))
						cout << "Положительное" << endl;
					else
						cout << "Отрицательное" << endl;
					break;
				}
				case 3:
				{
					num = ADD_1N_N(num);
					break;
				}
				case 4:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					num = ADD_NN_N(num, second);
					break;
				}

				case 5:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					num = SUB_NN_N(num, second);
					break;

				}
				case 6:
				{
					cout << "Введите цифру" << endl;
					int k;
					cin >> k;
					num = MUL_ND_N(num, k);
					break;
				}

				case 7:
				{
					cout << "Введите степень" << endl;
					int k;
					cin >> k;
					num = MUL_Nk_N(num, k);
					break;
				}

				case 8:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					num = MUL_NN_N(num, second);
					break;
				}

				case 9:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					cout << "Введите цифру" << endl;
					int k;
					cin >> k;
					num = SUB_NDN_N(num, second, k);
					break;

				}
				case 10:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					num = DIV_NN_Dk(num, second);
					break;
				}
				case 11:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					num = DIV_NN_N(num, second);
					break;
				}
				case 12:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					num = MOD_NN_N(num, second);
					break;
				}
				case 13:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					cout << "НОД" << endl;
					natOutput(GCF_NN_N(num, second));
					break;
				}
				case 14:
				{
					cout << "Введите второе число" << endl;
					second = natInput();
					cout << "НОК" << endl;
					natOutput(LCM_NN_N(num, second));
					break;
				}

				case 15:
				{
					num = natInput();
					break;
				}
				case 16:
				{
					natOutput(num);
					break;
				}

				}
				system("pause");
				system("cls");
			}
			while (keyCode != 17);
			break;
		}
		case 2:
		{
			Integer num;
			Integer second;
			system("cls");
			cout << "Введите  целое число" << endl;
			num = intInput();
			do
			{
				cout << "Текущее число: ";
				intOutput(num);
				cout << "Выберите модуль:" << endl;
				cout << "1)Модуль целого" << endl;
				cout << "2)Определение знака целого числа,положительное, 0 - равно 0, -1 - отрицательное" << endl;
				cout << "3)Умножение целого на -1 " << endl;
				cout << "4)Преобразование натурального в целое " << endl;
				cout << "5)Преобразование целого неотрицательного в натуральное " << endl;
				cout << "6)Сложение целых чисел " << endl;
				cout << "7)Вычитание целых чисел" << endl;
				cout << "8)Умножение целых чисел" << endl;
				cout << "9)Частное от деление большего целого числа на меньшее или равное натуральное с остатком" << endl;
				cout << "10)Остаток от деление большего целого числа на меньшее или равное натуральное с остатком" << endl;
				cout << "11)Ввести число заново" << endl;
				cout << "12) Вывести число " << endl;
				cout << "13) Перейти к другим модулям" << endl;
				cin >> keyCode;
				switch (keyCode)
				{
				case 1:
				{
					cout << "Модуль числа: ";
					natOutput(ABS_Z_N(num));
					cout << endl;
					break;
				}
				case 2:
				{
					switch (POZ_Z_D(num))
					{
					case 1:
					{
						cout << "Положительное" << endl;
						break;
					}
					case 0:
					{
						cout << "Ноль" << endl;
						break;
					}
					case -1:
					{
						cout << "Отрицательное" << endl;
						break;
					}
					}
					break;
				}
				case 3:
				{
					num = MUL_Z_NEGZ(num);
					break;
				}
				case 4:
				{
					cout << "Введите натуральное число" << endl;
					Natural temp;
					temp = natInput();
					num = TRANS_N_Z(temp);
					break;
				}
				case 5:
				{
					Natural temp;
					temp = TRANS_Z_N(num);
					cout << "результат: " << endl;
					natOutput(temp);
					
					break;
				}
				case 6:
				{
					cout << "Введите второе число" << endl;
					second = intInput();
					num = ADD_ZZ_Z(num, second);
					break;
				}
				case 7:
				{
					cout << "Введите второе число" << endl;
					second = intInput();
					num = SUB_ZZ_Z(num, second);
					break;
				}
				case 8:
				{
					cout << "Введите второе число" << endl;
					second = intInput();
					num = MUL_ZZ_Z(num, second);
					break;
				}
				case 9:
				{
					cout << "Введите второе число" << endl;
					Natural temp = natInput();
					cout << "Частное: ";
					intOutput(DIV_ZZ_Z(num, temp));
					break;
				}
				case 10:
				{
					cout << "Введите второе число" << endl;
					Natural temp = natInput();
					cout << "Остаток: " << endl;
					intOutput(MOD_ZZ_Z(num, temp));
					break;
				}
				case 11:
				{
					cout << "Введите целое число" << endl;
					num = intInput();
					break;
				}
				case 12:
				{
					intOutput(num);
					break;
				}
				}
				system("pause");
				system("cls");
			} while (keyCode !=13);
			break;
		}

		case 3:
		{
			Ratio num;
			Ratio second;
			system("cls");
			cout << "Введите дробное число" << endl;
			cout << "Числитель  - целое число, знаменатель натуральное" << endl;
			num = ratInput();
			do
			{
				cout << "Текущее число: " << endl;
				ratOutput(num);
				cout << "Выберите модуль:" << endl;
				cout << "1)Сокращение дроби " << endl;
				cout << "2)Проверка на целое, 1 - целое,  0 - нет"<< endl;
				cout << "3)Целое в дробное " << endl;
				cout << "4)Дробное в целое " << endl;
				cout << "5)Сложение дробей " << endl;
				cout << "6)Вычитание дробей " << endl;
				cout << "7)Умножение дробей" << endl;
				cout << "8)Деление дробей" << endl;
				cout << "9)Вывести дробь" << endl;
				cout << "10)Ввести дробь заново" << endl;
				cout << "11)Перейти к другим модулям" << endl;
				cin >> keyCode;
				switch (keyCode)
				{
				case 1:
				{
					num = RED_Q_Q(num);
					break;
				}
				case 2:
				{
					if (INT_Q_Z(num))
						cout << "Целое" << endl;
					else
						cout << "Дробное" << endl;
					break;
				}
				case 3:
				{
					cout << "Введите целое число " << endl;
					Integer temp;
					temp = intInput();
					num = TRAN_Z_Q(temp);
					break;
				}
				case 4:
				{
					Integer temp;
					temp = TRAN_Q_Z(num);
					cout << "Получившееся число: " << endl;
					intOutput(temp);
					break;
				}
				case 5:
				{
					cout << "Введите вторую дробь" << endl;
					second = ratInput();
					num = ADD_QQ_Q(num, second);
					break;

				}
				case 6:
				{
					cout << "Введите вторую дробь" << endl;
					second = ratInput();
					num = SUB_QQ_Q(num, second);
					break;
				}
				case 7:
				{
					cout << "Введите вторую дробь" << endl;
					second = ratInput();
					num = MUL_QQ_Q(num, second);
					break;
				}
				case 8:
				{
					cout << "Введите вторую дробь" << endl;
					second = ratInput();
					num = DIV_QQ_Q(num, second);
					break;
				}
				case 9:
				{
					ratOutput(num);
					break;
				}
				case 10:
				{
					cout << "Введите дробь" << endl;
					num = ratInput();
					break;
				}
				default:
					break;

				}
				system("pause");
				system("cls");
			} while (keyCode!=11);
			break;
		}
		case 4:
		{
			Polynomial num;
			Polynomial second;
			cout << "Ввод коэффициентов многочлена начинается со свободного" << endl;
			num = polInput();
			system("cls");
			do
			{
				cout << "Текущий многочлен: " << endl;
				polOutput(num);
				cout << "1)Сложение многочленов" << endl;
				cout << "2)Вычитание многочленов" << endl;
				cout << "3)Умножение многочлена на рациональное число " << endl;
				cout << "4)Умножение многочлена на x^k " << endl;
				cout << "5)Старший коэффициент многочлена" << endl;
				cout << "6)Степень многочлена" << endl;
				cout << "7)Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей " << endl;
				cout << "8)Умножение многочленов" << endl;
				cout << "9)Частное от деления divident на denominator" << endl;
				cout << "10)Остаток от деления divident на denominator " << endl;
				cout << "11)НОД многочленов" << endl;
				cout << "12)Производная многочлена" << endl;
				cout << "13)Преобразование многочлена — кратные корни в простые" << endl;
				cout << "14)Ввести многочлен заново" << endl;
				cout << "15)Перейти к другим модулям" << endl;
				cin >> keyCode;
				switch (keyCode)
				{
				case 1:
				{
					cout << "Введите второй многочлен" << endl;
					second = polInput();
					num = ADD_PP_P(num, second);
					cout << "Результат сложения: " << endl;
					polOutput(num);
					break;
				}
				case 2:
				{
					cout << "Введите второй многочлен" << endl;
					second = polInput();
					num = SUB_PP_P(num, second);
					cout << "Результат вычитания: " << endl;
					polOutput(num);
					break;
				}
				case 3:
				{
					cout << "Введите рациональное число: " << endl;
					Ratio temp;
					temp = ratInput();
					num = MUL_P_Q(num, temp);
					cout << "Результат умножения: " << endl;
					polOutput(num);
					break;
				}
				case 4:
				{
					int k;
					cout << "Введите k: ";
					cin >> k;
					num = MUL_Pxk_P(num, k);
					cout << "Результат умножения: " << endl;
					polOutput(num);
					break;
				}
				case 5:
				{
					cout << "Старший член коэффициента: " << endl;
					ratOutput(LED_P_Z(num));
					break;
				}
				case 6:
				{
					cout << "Степень многочлена: " << DEG_P_N(num) << endl;
					break;
				}
				case 7:
				{
					cout << "НОК знаменателей и НОК числителей: " << endl;
					polOutput(FAC_P_PQ(num));
					break;
				}
				case 8:
				{
					cout << "Введите второй многочлен " << endl;
					second = polInput();
					num = MUL_PP_P(num, second);
					cout << "Результат умножения: " << endl;
					polOutput(num);
					break;

				}
				case 9:
				{
					cout << "Введите второй многочлен " << endl;
					second = polInput();
					cout << "Частное от деления: "<<endl;
					polOutput(DIV_PP_P(num, second));
					break;
				}
				case 10:
				{
					cout << "Введите второй многочлен " << endl;
					second = polInput();
					cout << "Остаток от деления: " << endl;
					polOutput(MOV_PP_P(num, second));
					break;
				}
				case 11:
				{
					cout << "Введите второй многочлен " << endl;
					second = polInput();
					cout << "НОД многочленов: " << endl;
					polOutput(GCF_PP_P(num, second));
					break;
				}
				case 12:
				{
					cout << "Производная многочлена: " << endl;
					polOutput(DER_P_P(num));
					break;
				}
				case 13:
				{
					cout << "Преобразованный многочлен: " << endl;
					polOutput(NMR_P_P(num));
					break;
				}
				case 14:
				{
					cout << "Введите многочлен: " << endl;
					num = polInput();
					break;
				}
				case 15:
					break;
				default:
					break;
				}
				system("pause");
				system("cls");
			} while (keyCode!=15);
		}
		}

	} while (keyCode != 27);
	_getch();
	return 0;
}