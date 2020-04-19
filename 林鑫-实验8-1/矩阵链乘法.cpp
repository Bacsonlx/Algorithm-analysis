#include <iostream>
#include<fstream>
using namespace std;
int const M = 10;
int m[M][M], s[M][M];
int P[M] = { 0 };

ifstream fin("input.txt");
ofstream fout("output.txt");

void print(int s[][M],int i,int j) {
	if (i == j) cout << "A" << i;
	else
	{
		cout << "(";
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		cout << ")";
	}
}
void init(int n)
{
	/*����m[i, j]��ֵΪ0��s[i, j]�ĳ�ֵΪi  1��i��j��n*/
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			m[i][j] = 0;
			s[i][j] = 1;
		}
	}
}
void MatrixChain(int n)
{
	for (int r = 2; r <= n; r++) {	              //rΪ��ǰ�����ģ�����ȣ�
		for (int i = 1; i <= n - r + 1; i++) {    //i����㲻�ϱ仯������r��
			int j = i + r - 1;                    //��ͬ�յ�
			m[i][j] = m[i + 1][j] + P[i - 1] * P[i] * P[j];//����ΪAi(Ai+1...Aj),��ʱk=i
			s[i][j] = i;
			for (int k = i+1; k <= j - 1; k++){
				int t = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
				if (t < m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
int main()
{
	cout << "����������P���ȣ�С��" << M << "����";
	int length;//�����ģ�����ȣ�
//	cin >> length;
	fin >> length;
	cout << length << endl;
	cout << "����������P��";
	for (int i = 0; i < length; i++) {
//		cin >> P[i];
		fin >> P[i];
		cout << P[i] << " ";
	}
	cout << endl;
	
	int n = length - 1;

	//��ʼ��
	init(n);
	//���������
	MatrixChain(n);
	
	cout << "����������ģΪ" << length << "ʱ��" << endl;
	cout << "��С�ܴ���Ϊ" << m[1][n] << endl;
	cout << "���Ż�����Ϊ��"<<endl;

	print(s, 1, n);
	cout << endl;

}

