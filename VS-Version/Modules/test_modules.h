using namespace std;

//������ ����������� �����
struct Natural
{
	vector<unsigned int> A;
};
struct Integer
{
	bool b;
	Natural A;
};
struct Ratio
{
	Integer num;
	Natural denum;
};
// ������ ��� �����������
bool COM_NN_D(Natural First, Natural Second);//���������� ��� �����. ���������� 1,
											// ���� ������ ������ ��� ����� �������. 0 - ���� ������.
bool NZER_N_B(Natural chislo); //��������� ����� �� �� ��������� ����
							  //1- ����� �������������, 0 - ����� ����� 0
Natural ADD_1N_N(Natural chislo); //���������� 1 � �����
Natural ADD_NN_N(Natural chislo1, Natural chislo2);//���������� ��� �����
Natural SUB_NN_N(Natural First, Natural Second); //�������� �� ������ ����� ������. �������� ������
												//��� ��������������� �����������, ������� ����� ������� ���� �������
												//���������� ���������, ��� ������ ����� �� ������ �������
Natural MUL_ND_N(Natural ch, int cifra); //�������� ����� �� �����
Natural MUL_Nk_N(Natural &Input, int k); //�������� ����� �� 10^k
Natural MUL_NN_N(Natural chislo1, Natural chislo2); //����������� ��� �����
Natural SUB_NDN_N(Natural chislo1, Natural chislo2, int c); //�������� �� ������� ����� ������, ���������� �� �����
															//���������� ���������, ����� ������� ���������� ���������,
															//��� ��������� ��������, �.�. �������������
Natural DIV_NN_Dk(Natural chislo1, Natural chislo2);//��������� ������ ����� ��������, ���������� �� 10^k,
													//��� k - ������� ���� ����� � �������
Natural DIV_NN_N(Natural delimoe, Natural delitel); //������� �������� ������� ���� �����
Natural MOD_NN_N(Natural chislo1, Natural chislo2);//������� ������� �� ������� ������� ����� �� ������
Natural GCF_NN_N(Natural chislo1, Natural chislo2);//������� ��� ���� �����
Natural LCM_NN_N(Natural chislo1, Natural chislo2);//������� ��� ���� �����
// ����� ������ ��� �����������

// ������ ��� �����

// ����� ������ ��� �����

// ������ ��� ������
Ratio ADD_QQ_Q(Ratio A, Ratio B); // ������� �������� ���� ������������ �����
Ratio TRAN_Z_Q(Integer A); // �������, ������� ����������� ����� � �������(�� ������������ = 1)
Ratio RED_Q_Q(Ratio A); // ������� ���������� �����
Integer TRAN_Q_Z(Ratio b); // �������������� �������� � �����
bool INT_Q_Z(Ratio R); // ���� ������������ ����� - �����, �� 1, ����� 0
// ����� ������ ��� ������