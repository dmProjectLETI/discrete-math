#pragma once
#include "Natural.h"
struct Integer
{
	bool pos;
	Natural A;
};

Natural ABS_Z_N(Integer num); //������ ������.
int POZ_Z_D(Integer num); //����������� ����� ������ �����,1-�������������, 0 - ����� 0, -1 - �������������.
Integer MUL_Z_NEGZ(Integer num); //��������� ������ �� -1.
Integer TRANS_N_Z(Natural num); //����������� � �����
Natural TRANS_Z_N(Integer num);//����� � �����������
Integer ADD_ZZ_Z(Integer first, Integer second); //�������� ���� �����
Integer SUB_ZZ_Z(Integer first, Integer second); //��������� ���� �����.
Integer MUL_ZZ_Z(Integer first, Integer second); //��������� ����� �����
Integer DIV_ZZ_Z(Integer first, Natural second); //������� �� ������� �������� ������ ����� �� ������� 
Integer MOD_ZZ_Z(Integer first, Natural second); //������� �� ������� 