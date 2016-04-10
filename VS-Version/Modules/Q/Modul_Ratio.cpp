Ratio ADD_QQ_Q(Ratio A, Ratio B)
{
	Ratio C;
	Natural temp = LCM_NN_N(A.denum, B.denum); // ����� ���
	A.num.A = MUL_NN_N(A.num.A, DIV_NN_N(temp, A.denum));
	B.num.A = MUL_NN_N(B.num.A, DIV_NN_N(temp, B.denum));
	C.num = ADD_ZZ_Z(A.num, B.num);
	C.denum = temp;
	return C;
}

Integer TRAN_Q_Z(Ratio b) // �������������� �������� � ����� (���� ����������� ����� 1)
						  // ����� ������� ������� ���������, ��� ����������� ����� �������
{
	return(b.num); 
}

Ratio TRAN_Z_Q(Integer A)
{
	Ratio B; //�����, ������� ���������� �������
	B.num = A; //����� � � ���������
	B.denum.a.push_back(1); //� ����������� ������ 1
	return B;
}

Ratio RED_Q_Q(Ratio A) // ������� ���������� �����
{
	Natural B = GVF_NN_N(A.num.A, A.denum); // ������� ��� �� |���������| � �����������
	A.num.A = DIV_ZZ_Z(A.num.A, B); // ����� ��������� �� ���
	A.denum = DIV_ZZ_Z(A.denum, B); // ����� ����������� �� ���
	return A;
}

bool INT_Q_Z(Ratio R)
{
	return  (R.denum.A.size() == 1 && R.denum.A[0] == 1) ? 1 : 0; //���� ������ ����������� � ������ ��� ������� ����� 1 - ������� ���������� 1, ����� - 0
}
Ratio MUL_QQ_Q (Ratio A, Ratio B) //��������� ������� �����
{
 Ratio C;
 C.num = MUL_ZZ_Z(A.num.A, B.num.A);    // ������������ ����������
 C.denum = MUL_ZZ_Z(A.denum, B.denum); // ������������ ������������ 
 return RED_Q_Q(C);                   // ������������ ����������� �����
}


Ratio DIV_QQ_Q (Ratio A, Ratio B) //������� ������� �����
{  
 Ratio C;
 C.num = MUL_ZZ_Z(A.num.A, B.denum);
 C.denum = MUL_ZZ_Z(A.denum, B.num.A);
 return RED_Q_Q(C);
}
