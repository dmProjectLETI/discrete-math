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
	cout << "������� ��������� ";
	num.num = intInput();
	cout << "������� ����������� ";
	num.denum = natInput();
	return num;
}

void ratOutput(Ratio num)
{
	cout << "���������: ";
	intOutput(num.num);
	cout << "�����������: ";
	natOutput(num.denum);
}

Polynomial polInput()
{
	Polynomial num;
	cout << "������� ������� ����������: ";
	cin >> num.n;
	num.C.resize(num.n+1);
	for (int i(0); i <= num.n; i++)
	{
		cout << "������� " << i + 1 << " ����������" << endl;
		num.C[i] = ratInput();
	}
	return num;
}

void polOutput(Polynomial num)
{
	cout << "������� ����������: " << num.n << endl;
	for (int i(0); i <= num.n; i++)
	{
		cout << i + 1 << " ����������� " << endl;
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
		cout << "\"DmMath\"  - ��������� ��� ������ � �������� �������." << endl;
		cout << "������ ��������� �������� �������� ������������� ������ ���������� ��� �������� �������" << endl;
		cout << "�������� ������� ����� ���������� � �������������� Qt � ����������� �� ������" <<  endl << endl;
		cout << "��������� ���������� ����� 5372, 5373, 5395, 5396" << endl;
		cout << "�������� ������ ��� ������: "  << endl;
		cout << "1) ����������� �����" << endl;
		cout << "2) ����� �����" << endl;
		cout << "3) ������� �����" << endl;
		cout << "4) ���������" << endl;
		cin >> keyCode;
		switch (keyCode)
		{
		case 1: 
		{
			Natural num;
			Natural second;
			system("cls");
			cout << "������� ����������� ����� (���������������)" << endl;
			num = natInput();
			do
			{
				cout << "������� �����: ";
				natOutput(num);
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
		case 2:
		{
			Integer num;
			Integer second;
			system("cls");
			cout << "�������  ����� �����" << endl;
			num = intInput();
			do
			{
				cout << "������� �����: ";
				intOutput(num);
				cout << "�������� ������:" << endl;
				cout << "1)������ ������" << endl;
				cout << "2)����������� ����� ������ �����,�������������, 0 - ����� 0, -1 - �������������" << endl;
				cout << "3)��������� ������ �� -1 " << endl;
				cout << "4)�������������� ������������ � ����� " << endl;
				cout << "5)�������������� ������ ���������������� � ����������� " << endl;
				cout << "6)�������� ����� ����� " << endl;
				cout << "7)��������� ����� �����" << endl;
				cout << "8)��������� ����� �����" << endl;
				cout << "9)������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � ��������" << endl;
				cout << "10)������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � ��������" << endl;
				cout << "11)������ ����� ������" << endl;
				cout << "12) ������� ����� " << endl;
				cout << "13) ������� � ������ �������" << endl;
				cin >> keyCode;
				switch (keyCode)
				{
				case 1:
				{
					cout << "������ �����: ";
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
						cout << "�������������" << endl;
						break;
					}
					case 0:
					{
						cout << "����" << endl;
						break;
					}
					case -1:
					{
						cout << "�������������" << endl;
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
					cout << "������� ����������� �����" << endl;
					Natural temp;
					temp = natInput();
					num = TRANS_N_Z(temp);
					break;
				}
				case 5:
				{
					Natural temp;
					temp = TRANS_Z_N(num);
					cout << "���������: " << endl;
					natOutput(temp);
					
					break;
				}
				case 6:
				{
					cout << "������� ������ �����" << endl;
					second = intInput();
					num = ADD_ZZ_Z(num, second);
					break;
				}
				case 7:
				{
					cout << "������� ������ �����" << endl;
					second = intInput();
					num = SUB_ZZ_Z(num, second);
					break;
				}
				case 8:
				{
					cout << "������� ������ �����" << endl;
					second = intInput();
					num = MUL_ZZ_Z(num, second);
					break;
				}
				case 9:
				{
					cout << "������� ������ �����" << endl;
					Natural temp = natInput();
					cout << "�������: ";
					intOutput(DIV_ZZ_Z(num, temp));
					break;
				}
				case 10:
				{
					cout << "������� ������ �����" << endl;
					Natural temp = natInput();
					cout << "�������: " << endl;
					intOutput(MOD_ZZ_Z(num, temp));
					break;
				}
				case 11:
				{
					cout << "������� ����� �����" << endl;
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
			cout << "������� ������� �����" << endl;
			cout << "���������  - ����� �����, ����������� �����������" << endl;
			num = ratInput();
			do
			{
				cout << "������� �����: " << endl;
				ratOutput(num);
				cout << "�������� ������:" << endl;
				cout << "1)���������� ����� " << endl;
				cout << "2)�������� �� �����, 1 - �����,  0 - ���"<< endl;
				cout << "3)����� � ������� " << endl;
				cout << "4)������� � ����� " << endl;
				cout << "5)�������� ������ " << endl;
				cout << "6)��������� ������ " << endl;
				cout << "7)��������� ������" << endl;
				cout << "8)������� ������" << endl;
				cout << "9)������� �����" << endl;
				cout << "10)������ ����� ������" << endl;
				cout << "11)������� � ������ �������" << endl;
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
						cout << "�����" << endl;
					else
						cout << "�������" << endl;
					break;
				}
				case 3:
				{
					cout << "������� ����� ����� " << endl;
					Integer temp;
					temp = intInput();
					num = TRAN_Z_Q(temp);
					break;
				}
				case 4:
				{
					Integer temp;
					temp = TRAN_Q_Z(num);
					cout << "������������ �����: " << endl;
					intOutput(temp);
					break;
				}
				case 5:
				{
					cout << "������� ������ �����" << endl;
					second = ratInput();
					num = ADD_QQ_Q(num, second);
					break;

				}
				case 6:
				{
					cout << "������� ������ �����" << endl;
					second = ratInput();
					num = SUB_QQ_Q(num, second);
					break;
				}
				case 7:
				{
					cout << "������� ������ �����" << endl;
					second = ratInput();
					num = MUL_QQ_Q(num, second);
					break;
				}
				case 8:
				{
					cout << "������� ������ �����" << endl;
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
					cout << "������� �����" << endl;
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
			cout << "���� ������������� ���������� ���������� �� ����������" << endl;
			num = polInput();
			system("cls");
			do
			{
				cout << "������� ���������: " << endl;
				polOutput(num);
				cout << "1)�������� �����������" << endl;
				cout << "2)��������� �����������" << endl;
				cout << "3)��������� ���������� �� ������������ ����� " << endl;
				cout << "4)��������� ���������� �� x^k " << endl;
				cout << "5)������� ����������� ����������" << endl;
				cout << "6)������� ����������" << endl;
				cout << "7)��������� �� ���������� ��� ������������ ������������� � ��� ���������� " << endl;
				cout << "8)��������� �����������" << endl;
				cout << "9)������� �� ������� divident �� denominator" << endl;
				cout << "10)������� �� ������� divident �� denominator " << endl;
				cout << "11)��� �����������" << endl;
				cout << "12)����������� ����������" << endl;
				cout << "13)�������������� ���������� � ������� ����� � �������" << endl;
				cout << "14)������ ��������� ������" << endl;
				cout << "15)������� � ������ �������" << endl;
				cin >> keyCode;
				switch (keyCode)
				{
				case 1:
				{
					cout << "������� ������ ���������" << endl;
					second = polInput();
					num = ADD_PP_P(num, second);
					cout << "��������� ��������: " << endl;
					polOutput(num);
					break;
				}
				case 2:
				{
					cout << "������� ������ ���������" << endl;
					second = polInput();
					num = SUB_PP_P(num, second);
					cout << "��������� ���������: " << endl;
					polOutput(num);
					break;
				}
				case 3:
				{
					cout << "������� ������������ �����: " << endl;
					Ratio temp;
					temp = ratInput();
					num = MUL_P_Q(num, temp);
					cout << "��������� ���������: " << endl;
					polOutput(num);
					break;
				}
				case 4:
				{
					int k;
					cout << "������� k: ";
					cin >> k;
					num = MUL_Pxk_P(num, k);
					cout << "��������� ���������: " << endl;
					polOutput(num);
					break;
				}
				case 5:
				{
					cout << "������� ���� ������������: " << endl;
					ratOutput(LED_P_Z(num));
					break;
				}
				case 6:
				{
					cout << "������� ����������: " << DEG_P_N(num) << endl;
					break;
				}
				case 7:
				{
					cout << "��� ������������ � ��� ����������: " << endl;
					polOutput(FAC_P_PQ(num));
					break;
				}
				case 8:
				{
					cout << "������� ������ ��������� " << endl;
					second = polInput();
					num = MUL_PP_P(num, second);
					cout << "��������� ���������: " << endl;
					polOutput(num);
					break;

				}
				case 9:
				{
					cout << "������� ������ ��������� " << endl;
					second = polInput();
					cout << "������� �� �������: "<<endl;
					polOutput(DIV_PP_P(num, second));
					break;
				}
				case 10:
				{
					cout << "������� ������ ��������� " << endl;
					second = polInput();
					cout << "������� �� �������: " << endl;
					polOutput(MOV_PP_P(num, second));
					break;
				}
				case 11:
				{
					cout << "������� ������ ��������� " << endl;
					second = polInput();
					cout << "��� �����������: " << endl;
					polOutput(GCF_PP_P(num, second));
					break;
				}
				case 12:
				{
					cout << "����������� ����������: " << endl;
					polOutput(DER_P_P(num));
					break;
				}
				case 13:
				{
					cout << "��������������� ���������: " << endl;
					polOutput(NMR_P_P(num));
					break;
				}
				case 14:
				{
					cout << "������� ���������: " << endl;
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