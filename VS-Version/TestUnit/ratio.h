#pragma once
#include "Integer.h"
struct Ratio
{
	Integer num;
	Natural denum;
};

Ratio RED_Q_Q(Ratio A); // ������� ���������� �����
bool INT_Q_Z(Ratio R); // ���� ������������ ����� - �����, �� 1, ����� 0
Ratio TRAN_Z_Q(Integer A); // �������, ������� ����������� ����� � �������(�� ������������ = 1)
Integer TRAN_Q_Z(Ratio b); // �������������� �������� � �����
Ratio ADD_QQ_Q(Ratio A, Ratio B); // ������� �������� ���� ������������ �����
Ratio SUB_QQ_Q(Ratio A, Ratio B); //��������� ������
Ratio MUL_QQ_Q(Ratio A, Ratio B); //��������� ������� �����
Ratio DIV_QQ_Q(Ratio A, Ratio B); //������� ������� �����
