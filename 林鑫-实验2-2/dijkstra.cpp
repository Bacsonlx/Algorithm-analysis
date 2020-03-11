#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include<fstream>
using namespace std;
const int inf=0x3f3f3f3f;
int map[110][110]; //�����map���飬�洢ͼ
int dis[10010]; //dis���飬�洢����ֵ
int book[10010]; //book[i]�����������û�б�����Դ��ȥ��������1Ϊ�У�0Ϊû�С������Ͳ����ظ������ˡ�
int n,m;
ifstream fin("input.txt");
ofstream fout("output.txt");
void dijkstra(int u)  //��������������Դ����
{
	memset(dis, inf, sizeof(dis));//��dis���鸽���ֵ
	int start = u;//�ȴ�Դ������
	book[start] = 1;//���Դ���Ѿ�������
	for(int i = 1; i <= n; i++) 
	{
		dis[i] = min(dis[i], map[start][i]);//�ȸ���һ��
	}
	for(int i = 1; i <= n-1; i++) 
	{
		int minn = inf; //����Ǹղ���˵��minn
		for(int j = 1; j <= n; j++)
		{ 
			if(book[j] == 0 && minn > dis[j]) 
			{
				minn = dis[j];
				start = j;//�ҵ���Դ�� ����ĵ㣬Ȼ��ѱ�ż�¼����������������
			}
		} 
		book[start] = 1;
		for(int j = 1; j <= n; j++)
		{
			dis[j] = min(dis[j], dis[start]+map[start][j]);//���µĵ�������dis��
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
		
	dijkstra(1);//��1ΪԴ��
	fout << "��a��h����̾���Ϊ��" << dis[8];
	fin.close();
	fout.close();
}
