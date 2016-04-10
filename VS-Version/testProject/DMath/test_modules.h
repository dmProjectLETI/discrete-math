#include <vector>
using namespace std;

//������ ����������� �����
struct Natural
{
	vector<unsigned int> A;
};
struct Integer
{
	bool pos;
	Natural A;
};
struct Ratio
{
	Integer num;
	Natural denum;
};
struct Polynomial
{
	vector<Ratio>C;
	unsigned int n;
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
//---------------------------------------------------------------------------------------------------------
												   // ������ ��� �����
int POZ_Z_D(Integer num); //����������� ����� ������ �����, ���������.
Natural ABS_Z_N(Integer num); //������ ������.
Integer MUL_Z_NEGZ(Integer num); //��������� ������ �� -1.
Integer ADD_ZZ_Z(Integer first, Integer second); //�������� ���� �����.
Integer SUB_ZZ_Z(Integer first, Integer second); //��������� ���� �����.

												 // ����� ������ ��� �����
//---------------------------------------------------------------------------------------------------------
												 // ������ ��� ������
Ratio ADD_QQ_Q(Ratio A, Ratio B); // ������� �������� ���� ������������ �����
Ratio TRAN_Z_Q(Integer A); // �������, ������� ����������� ����� � �������(�� ������������ = 1)
Ratio RED_Q_Q(Ratio A); // ������� ���������� �����
Integer TRAN_Q_Z(Ratio b); // �������������� �������� � �����
bool INT_Q_Z(Ratio R); // ���� ������������ ����� - �����, �� 1, ����� 0

					   // ����� ������ ��� ������
//---------------------------------------------------------------------------------------------------------
					   // ������ ��� �����������
Polynomial MUL_Pxk_P(Polynomial M, int k); //�������� ��������� �� x^k
Ratio LED_P_Z(Polynomial B); //���������� ������� ����������� ����������
int DEG_P_N(Polynomial B); //���������� ������� ����������
Polynomial DIV_PP_P(Polynomial dividend, Polynomial denominator);
Polynomial DER_P_P(Polynomial B);
Polynomial MUL_Pxk_P(Polynomial M, int k);
Polynomial MUL_PP_P(Polynomial M, Polynomial N);
						   // ����� ������ ��� �����������