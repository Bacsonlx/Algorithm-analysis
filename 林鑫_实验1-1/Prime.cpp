#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;
const int maxn=1e3;
const int inf=0x3f3f3f3f;
int mp[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int N, M;
ifstream fin("input.txt");
ofstream fout("output.txt");
int prime() 
{
	for(int i=2; i<=N; ++i) 
	{
		vis[i] = 0;
		dis[i] = mp[i][1];
	}
	vis[1] = 1;
	int sum = 0;
	for(int i=1; i<=N-1; ++i) 
	{
		int temp = inf, pos;
		for(int j=1; j<=N; ++j) 
		{
			if(!vis[j] && dis[j] < temp) {
				temp = dis[j];
				pos = j;
			}
		}
		vis[pos] = 1;
		sum += dis[pos];
		for(int j=1; j<=N; ++j)
		{
			if(!vis[j] && dis[j] > mp[pos][j] && mp[pos][j] != inf){
				dis[j] = mp[pos][j];
			}
		}
	}
	return sum;
}
int main()
{
//	cin >> N >> M;
	fin >> N >> M;
	int u, v, w;
	for(int i = 1; i <= N; ++i)
	{
		dis[i]=inf;
		for(int j = 1; j <= N; ++j)
		{
			if(i != j)
				mp[i][j] = inf;
		}
	}
	for(int i = 1; i <= M; ++i){
//		scanf("%d%d%d",&u,&v,&w);
		fin >> u >> v >> w;
		mp[u][v]=mp[v][u]=w;
	}
	fout << prime();
//	cout<<prime()<<endl;
	fin.close();
	fout.close();
	return 0;
}

