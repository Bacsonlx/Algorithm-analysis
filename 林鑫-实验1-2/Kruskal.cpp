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
	int from,to,dis;//结构体储存边 
}edge[maxn];
bool cmp(const node &a,const node &b)//sort排序
{
	return a.dis<b.dis;
}
int father(int x)//找团体并查集 
{
	if(fat[x]!=x)
	return father(fat[x]);
	else return x;
}
void unionn(int x,int y)//加入团体，并查集的一部分 
{
	fat[father(y)]=father(x);
}
int Kruskal()
{
	sort(edge+1, edge+1+m, cmp);//按权值排序
	for(int i=1; i<=n; i++) 
	fat[i] = i;//并查集初始化
	for(int i=1; i<=m; i++)//从小到大遍历 
	{
		if(k==n-1) break;//n个点需要n-1条边连接 
		if(father(edge[i].from) != father(edge[i].to))//假如不在一个团体 
		{
			unionn(edge[i].from, edge[i].to);//加入 
			tot += edge[i].dis;//记录边权 
			k++;//已连接边数+1 
		}
	}
	return tot;
}
int main()
{
//	scanf("%d%d",&n,&m);//输入点数，边数 
	fin >> n >> m; 
	for(int i=1; i<=m; i++)
	{
//		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].dis);//输入边的信息 
		fin >> edge[i].from >> edge[i].to >> edge[i].dis;
	}
//	cout << Kruskal() << endl;
	fout << Kruskal();
	return 0;
}

