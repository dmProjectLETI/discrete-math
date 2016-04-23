#pragma once
#include "Ratio.h"
struct Polynomial
{
	vector<Ratio>C;
	unsigned int n;
};

Polynomial ADD_PP_P(Polynomial first, Polynomial second); // ���������� ����������
Polynomial SUB_PP_P(Polynomial first, Polynomial second); // �������� ����������
Polynomial MUL_P_Q(Polynomial chlen, Ratio ratio_number); //��������� ���������� �� ������������ �����
Polynomial MUL_Pxk_P(Polynomial M, int k); //�������� ��������� �� x^k
Ratio LED_P_Z(Polynomial B); //���������� ������� ����������� ����������
int DEG_P_N(Polynomial B); //���������� ������� ����������
Polynomial FAC_P_PQ(Polynomial P); //��������� �� ���������� ��� ������������ ������������� � ��� ����������
Polynomial MUL_PP_P(Polynomial M, Polynomial N); //��������� �����������
Polynomial DIV_PP_P(Polynomial dividend, Polynomial denominator); // ���������� ������� �� ������� divident �� denominator
Polynomial MOV_PP_P(Polynomial dividend, Polynomial denominator); // ���������� ������� �� ������� divident �� denominator
Polynomial GCF_PP_P(Polynomial PA, Polynomial PB); //��� �����������
Polynomial DER_P_P(Polynomial B); //�����������
Polynomial NMR_P_P(Polynomial chlen); //���������������� ���������� � ������� ����� � �������

