#include<stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;
const int maxn = 100;
typedef struct {
	int index;
	int s;
	int f;
}action;
bool cmp(action a, action b)
{
	if(a.f == b.f){
		return a.s <= b.s;
	}
	return a.f < b.f;
}
int main()
{
	action list[maxn];
	int n;
	cout << "活动总数: " << endl;
	cin >> n;
	cout << "输入活动的开始和截至时间: " << endl;
	for (int i = 0; i < n; i++)
	{
		list[i].index = i;
		cin >> list[i].s >> list[i].f;
	}
	sort(list, list + n, cmp);

	int j = 0;
	action A[maxn];
	A[0] = list[0];
	for (int i = 1; i < n; i++)
	{
		if (list[i].s >= A[j].f){
			A[++j] = list[i];
		}
	}
	cout << "最大相容活动数为: " << j + 1 << endl;
	for(int i = 0; i <= j; i++)
	{
		printf("活动%d: %d -> %d\n", A[i].index + 1, A[i].s, A[i].f);
	}
	return 0;
}
