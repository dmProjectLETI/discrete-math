#include "Ratio.h"



Ratio ADD_QQ_Q(Ratio A, Ratio B)// �������� ������ (������� ������/������������� ������)
{
	Ratio C;
	Natural temp = LCM_NN_N(A.denum, B.denum); // ����� ���
	A.num.A = MUL_NN_N(A.num.A, DIV_NN_N(temp, A.denum));
	B.num.A = MUL_NN_N(B.num.A, DIV_NN_N(temp, B.denum));
	C.num = ADD_ZZ_Z(A.num, B.num);
	C.denum = temp;
	return C;
}

Integer TRAN_Q_Z(Ratio b) // �������������� �������� � ����� (���� ����������� ����� 1) (����� ������/������������� ������)
						  // ����� ������� ������� ���������, ��� ����������� ����� �������
{
	return(b.num);
}

Ratio TRAN_Z_Q(Integer A) // �������������� ������ � ������� (����� ������/��������� ���������)
{
	Ratio B;//�����, ������� ���������� �������
	B.num = A; //����� � � ���������
	B.denum.A.push_back(1); //� ����������� ������ 1
	return B;
}



bool INT_Q_Z(Ratio R)//�������� �� �����, ���� ������������ ����� �������� �����, �� ���, ����� ���� (����� ������/��������� ���������)
{
	return  (R.denum.A.size() == 1 && R.denum.A[0] == 1) ? 1 : 0; //���� ������ ����������� � ������ ��� ������� ����� 1 - ������� ���������� 1, ����� - 0
}
Ratio MUL_QQ_Q(Ratio A, Ratio B) //��������� ������� ����� (��������� ���������/�������� ������ )
{
	A.num = MUL_ZZ_Z(A.num, B.num);    // ������������ ����������
	A.denum = MUL_NN_N(A.denum, B.denum); // ������������ ������������ 
	return RED_Q_Q(A);                   // ������������ ����������� �����
}

Ratio SUB_QQ_Q(Ratio A, Ratio B) //��������� ������ (�������� ��������)
{
	Ratio C;
	Natural temp = LCM_NN_N(A.denum, B.denum); // ����� ���
	A.num.A = MUL_NN_N(A.num.A, DIV_NN_N(temp, A.denum));
	B.num.A = MUL_NN_N(B.num.A, DIV_NN_N(temp, B.denum));
	C.num = SUB_ZZ_Z(A.num, B.num);
	C.denum = temp;
	return C;
}

Ratio RED_Q_Q(Ratio A) // ������� ���������� ����� (�������� ������)
{
	if (POZ_Z_D(A.num))
	{
		Natural B = GCF_NN_N(A.num.A, A.denum); // ������� ��� �� |���������| � �����������
		A.num.A = DIV_NN_N(A.num.A, B); // ����� ��������� �� ���
		A.denum = DIV_NN_N(A.denum, B); // ����� ����������� �� ���
	}
	return A;
}
Ratio DIV_QQ_Q(Ratio A, Ratio B) //������� ������� ����� (��������� ���������/�������� ������ )
{
	Ratio C;
	Integer G;
	G.A = B.denum;
	G.pos = 0;
	C.num = MUL_ZZ_Z(A.num, G);
	C.denum = MUL_NN_N(A.denum, B.num.A);
	if (B.num.pos == 1)
		if (C.num.pos == 1)
			C.num.pos = 0;
		else
			C.num.pos = 1;
	return RED_Q_Q(C);
}