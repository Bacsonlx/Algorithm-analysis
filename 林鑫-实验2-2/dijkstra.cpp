#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include<fstream>
using namespace std;
const int inf=0x3f3f3f3f;
int map[110][110]; //这就是map数组，存储图
int dis[10010]; //dis数组，存储估计值
int book[10010]; //book[i]代表这个点有没有被当做源点去搜索过，1为有，0为没有。这样就不会重复搜索了。
int n,m;
ifstream fin("input.txt");
ofstream fout("output.txt");
void dijkstra(int u)  //主函数，参数是源点编号
{
	memset(dis, inf, sizeof(dis));//把dis数组附最大值
	int start = u;//先从源点搜索
	book[start] = 1;//标记源点已经搜索过
	for(int i = 1; i <= n; i++) 
	{
		dis[i] = min(dis[i], map[start][i]);//先更新一遍
	}
	for(int i = 1; i <= n-1; i++) 
	{
		int minn = inf; //这就是刚才所说的minn
		for(int j = 1; j <= n; j++)
		{ 
			if(book[j] == 0 && minn > dis[j]) 
			{
				minn = dis[j];
				start = j;//找到离源点 最近的点，然后把编号记录下来，用于搜索。
			}
		} 
		book[start] = 1;
		for(int j = 1; j <= n; j++)
		{
			dis[j] = min(dis[j], dis[start]+map[start][j]);//以新的点来更新dis。
		} 	
	}
}
int main() {
	fin >> n >> m;
	memset(map, inf, sizeof(map));
	for(int i = 1; i <= m; i++) 
	{
		char u, v;
		int w;
		fin >> u >> v >> w;
		int a = u - 96, b = v - 96;
		map[a][b] = w;
	}
	
	for(int i = 1; i <= n; i++)
	{
		map[i][i] = 0;
	} 
		
	dijkstra(1);//以1为源点
	fout << "从a到h的最短距离为：" << dis[8];
	fin.close();
	fout.close();
}
