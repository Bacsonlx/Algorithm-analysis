#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100;
const int N = 4;
double minlen = 10000, x[maxn], r[maxn];//分别为最小圆排列长度，每个圆心横坐标，每个圆半径
double bestr[maxn];//最小圆排列的半径顺序
double center(int t)//得到每个圆的圆心坐标
{
	double temp = 0;
	for(int j = 1; j < t; ++j)//因为目标圆有可能与排在它之前的任一圆相切，故需一一判断
	{
		//计算圆横坐标
		double xvalue = x[j] + 2.0 * sqrt(r[t] * r[j]);
		if(xvalue > temp)
			temp = xvalue;
	}
	return temp;
}

void compute() //根据每种排列计算其对应的长度
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
		minlen = high - low; //记录最小长度
		for(int i = 1; i < N; ++i)
			bestr[i] = r[i]; //记录最小半径下的圆排列
	}
}
void backtrack(int t) //回溯过程构造出排列树
{
	if(t == N)
	{
		compute();
	}
	else
	{
		//计算当前最优排列长度
		for(int j = t; j < N; ++j)
		{
			swap(r[t], r[j]);
			double centerx = center(t);
			//剪纸
			if(centerx + r[t] + r[1] < minlen)
			{
				x[t] = centerx;
				backtrack(t + 1);
			}
			//回溯，开始下一种排列
			swap(r[t], r[j]);
		}
	}
}
int main()
{
	cout << "圆的个数为: " << N - 1 << endl;
	//	r[1] = 1, r[2] = 1, r[3] = 2;
	cout << "请输入圆的半径长度: " << endl;
	for(int i = 1; i < N; ++i)
	{
		cin >> r[i];
	}
	cout<<"每个圆的半径分别为：";
	for(int i = 1; i < N; ++i)
		cout << r[i] << ' ';
	cout << endl;
	backtrack(1);
	cout << "最小圆排列长度为：" << minlen << endl;
	cout << "最优圆排列的顺序对应的半径分别为：";
	for(int i = 1; i < N; ++i)
		cout << bestr[i] << ' ';
	cout << endl;
	return 0;
}
