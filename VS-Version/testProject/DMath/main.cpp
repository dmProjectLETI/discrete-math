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

int main()
{
	setlocale(0, "");
	int keyCode(0);
	Natural num;
	Natural second;
	do
	{
		cout << "Выберите модуль для работы: " << endl;
		cout << "1) Натуральное число" << endl;
		cout << "2) Целое число" << endl;
		cout << "3) Дробное число" << endl;
		cout << "4) Многочлен" << endl;
		cin >> keyCode;
		switch (keyCode)
		{
		case 1: 
		{
			system("cls");
			cout << "Введите натуральное число" << endl;
			num = natInput();
			do
			{
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
						cout << "Отричательное" << endl;
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
		}

	} while (keyCode != 27);
	_getch();
	return 0;
}