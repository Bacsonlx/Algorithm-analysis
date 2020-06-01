#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100;
const int N = 4;
double minlen = 10000, x[maxn], r[maxn];//�ֱ�Ϊ��СԲ���г��ȣ�ÿ��Բ�ĺ����꣬ÿ��Բ�뾶
double bestr[maxn];//��СԲ���еİ뾶˳��
double center(int t)//�õ�ÿ��Բ��Բ������
{
	double temp = 0;
	for(int j = 1; j < t; ++j)//��ΪĿ��Բ�п�����������֮ǰ����һԲ���У�����һһ�ж�
	{
		//����Բ������
		double xvalue = x[j] + 2.0 * sqrt(r[t] * r[j]);
		if(xvalue > temp)
			temp = xvalue;
	}
	return temp;
}

void compute() //����ÿ�����м������Ӧ�ĳ���
{
	double low = 0, high = 0;
	for(int i = 1; i < N; ++i)
	{
		if(x[i] - r[i] < low) {
			low = x[i] - r[i];
		}
		if(x[i] + r[i] > high) {
			high = x[i] + r[i];
		}
	}
	if(high - low < minlen) {
		minlen = high - low; //��¼��С����
		for(int i = 1; i < N; ++i)
			bestr[i] = r[i]; //��¼��С�뾶�µ�Բ����
	}
}
void backtrack(int t) //���ݹ��̹����������
{
	if(t == N)
	{
		compute();
	}
	else
	{
		//���㵱ǰ�������г���
		for(int j = t; j < N; ++j)
		{
			swap(r[t], r[j]);
			double centerx = center(t);
			//��ֽ
			if(centerx + r[t] + r[1] < minlen)
			{
				x[t] = centerx;
				backtrack(t + 1);
			}
			//���ݣ���ʼ��һ������
			swap(r[t], r[j]);
		}
	}
}
int main()
{
	cout << "Բ�ĸ���Ϊ: " << N - 1 << endl;
	//	r[1] = 1, r[2] = 1, r[3] = 2;
	cout << "������Բ�İ뾶����: " << endl;
	for(int i = 1; i < N; ++i)
	{
		cin >> r[i];
	}
	cout<<"ÿ��Բ�İ뾶�ֱ�Ϊ��";
	for(int i = 1; i < N; ++i)
		cout << r[i] << ' ';
	cout << endl;
	backtrack(1);
	cout << "��СԲ���г���Ϊ��" << minlen << endl;
	cout << "����Բ���е�˳���Ӧ�İ뾶�ֱ�Ϊ��";
	for(int i = 1; i < N; ++i)
		cout << bestr[i] << ' ';
	cout << endl;
	return 0;
}
