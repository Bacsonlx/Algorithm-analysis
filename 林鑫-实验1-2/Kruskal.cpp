#include<iostream>
#include<cstdio>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,tot=0,k=0; 
const int maxn = 200010;
int fat[maxn];
ifstream fin("input.txt");
ofstream fout("output.txt");
struct node
{
	int from,to,dis;//�ṹ�崢��� 
}edge[maxn];
bool cmp(const node &a,const node &b)//sort����
{
	return a.dis<b.dis;
}
int father(int x)//�����岢�鼯 
{
	if(fat[x]!=x)
	return father(fat[x]);
	else return x;
}
void unionn(int x,int y)//�������壬���鼯��һ���� 
{
	fat[father(y)]=father(x);
}
int Kruskal()
{
	sort(edge+1, edge+1+m, cmp);//��Ȩֵ����
	for(int i=1; i<=n; i++) 
	fat[i] = i;//���鼯��ʼ��
	for(int i=1; i<=m; i++)//��С������� 
	{
		if(k==n-1) break;//n������Ҫn-1�������� 
		if(father(edge[i].from) != father(edge[i].to))//���粻��һ������ 
		{
			unionn(edge[i].from, edge[i].to);//���� 
			tot += edge[i].dis;//��¼��Ȩ 
			k++;//�����ӱ���+1 
		}
	}
	return tot;
}
int main()
{
//	scanf("%d%d",&n,&m);//������������� 
	fin >> n >> m; 
	for(int i=1; i<=m; i++)
	{
//		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].dis);//����ߵ���Ϣ 
		fin >> edge[i].from >> edge[i].to >> edge[i].dis;
	}
//	cout << Kruskal() << endl;
	fout << Kruskal();
	return 0;
}

