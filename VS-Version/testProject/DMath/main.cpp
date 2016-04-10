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
		cout << "�������� ������ ��� ������: " << endl;
		cout << "1) ����������� �����" << endl;
		cout << "2) ����� �����" << endl;
		cout << "3) ������� �����" << endl;
		cout << "4) ���������" << endl;
		cin >> keyCode;
		switch (keyCode)
		{
		case 1: 
		{
			system("cls");
			cout << "������� ����������� �����" << endl;
			num = natInput();
			do
			{
				cout << "�������� ������:" << endl;
				cout << "1)���������� ��� �����. ���������� 1 ���� ������ ������ ��� ����� �������. 0 - ���� ������ " << endl;
				cout << "2) ��������� ����� �� �� ��������� ����  1- ����� �������������, 0 - ����� ����� 0" << endl;
				cout << "3)���������� 1 � ����� " << endl;
				cout << "4)���������� ��� ����� " << endl;
				cout << "5)�������� �� ������ ����� ������ " << endl;
				cout << "6)�������� ����� �� ����� " << endl;
				cout << "7) �������� ����� �� 10^k" << endl;
				cout << "8) ����������� ��� �����" << endl;
				cout << "9) �������� �� ������� ����� ������, ���������� �� �����" << endl;
				cout << "10) ��������� ������ ����� ��������, ���������� �� 10^k ��� k - ������� ���� ����� � �������" << endl;
				cout << "11) ������� �������� ������� ���� �����" << endl;
				cout << "12) ������� ������� �� ������� ������� ����� �� ������ " << endl;
				cout << "13) ������� ��� ���� �����" << endl;
				cout << "14) ������� ��� ���� �����" << endl;
				cout << "15) ������ ����� ������" << endl;
				cout << "16) ������� �����" << endl;
				cout << "17) ������� ������ ������" << endl;
				cin >> keyCode;
				switch (keyCode)
				{
				case 1:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					if (COM_NN_D(num, second))
						cout << "������ ������ ��� ����� �������" << endl;
					else
						cout << "������ ������ �������" << endl;
					break;
				}
				case 2:
				{
					if (NZER_N_B(num))
						cout << "�������������" << endl;
					else
						cout << "�������������" << endl;
					break;
				}
				case 3:
				{
					num = ADD_1N_N(num);
					break;
				}
				case 4:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					num = ADD_NN_N(num, second);
					break;
				}

				case 5:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					num = SUB_NN_N(num, second);
					break;

				}
				case 6:
				{
					cout << "������� �����" << endl;
					int k;
					cin >> k;
					num = MUL_ND_N(num, k);
					break;
				}

				case 7:
				{
					cout << "������� �������" << endl;
					int k;
					cin >> k;
					num = MUL_Nk_N(num, k);
					break;
				}

				case 8:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					num = MUL_NN_N(num, second);
					break;
				}

				case 9:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					cout << "������� �����" << endl;
					int k;
					cin >> k;
					num = SUB_NDN_N(num, second, k);
					break;

				}
				case 10:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					num = DIV_NN_Dk(num, second);
					break;
				}
				case 11:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					num = DIV_NN_N(num, second);
					break;
				}
				case 12:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					num = MOD_NN_N(num, second);
					break;
				}
				case 13:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					cout << "���" << endl;
					natOutput(GCF_NN_N(num, second));
					break;
				}
				case 14:
				{
					cout << "������� ������ �����" << endl;
					second = natInput();
					cout << "���" << endl;
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