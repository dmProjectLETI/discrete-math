#include <iostream>
#include "DIV_NN_N.h"
#include "Modul1_14.h"
void DIV_NN_N(Natural first,Natural second) //������� �� ������� �������� ������������ ����� �� ������� 
											//��� ������ ����������� � �������� (�������� ������� �� ����)
{
	Natural quotient=0; // �������
	if (first > second && second != 0) // ���� ������ ����� ������ ������� � �������� �� ����� 0
	{
		while(first >= second) // ���� ������� >= �������� �������� �� ���� �� ����� � ������� ������� 
		{
			first -= second;
			quotient++;
		}
		cout << quotient << endl; // ������� �������
	}
	else
	{
		if(first < second && first != 0) // ���� ������ ����� ������ ������� � �������� �� ����� 0
		{
			while(b >= first) // ���� ������� >= �������� �������� �� ���� �� ����� � ������� ������� 
			{
				second -= first;
				quotient++;
			}
			cout << quotient << endl; // ������� �������
		}
		else 
		{
			if(first = second && first != 0) // ���� ������ ����� ����� ������� � ��� �� ����, �� ������� ����� 1
			{
				quotient = 1;
				cout << quotient << endl; // ������� �������
			}
			else
				cout << "Error" << endl; // �������� =0 ��� ��� ����� ����� 0
		}
	}
}