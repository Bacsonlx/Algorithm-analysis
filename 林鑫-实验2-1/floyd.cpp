#include<iostream>
#include<fstream>
using namespace std;
int e[111][111];
int m, n, u, v, l;//n�����㣬m���ߣ�����m�У�һ���ж���u��v�Լ����ǵľ���l
const int inf=0x3f3f3f3f;
ifstream fin("input.txt");
ofstream fout("output.txt");
void init() 
{
	for(int i=1; i<=n; ++i) 
	{
		for(int j=1; j<=n; ++j) 
		{
			if(i == j)
				e[i][j] = 0;
			if(i != j) 
				e[i][j] = inf;

		}
	}
}
void floyd() 
{
	int i,j,k;
	for(k=1; k<=n; ++k) 
	{
		for(i=1; i<=n; ++i) 
		{
			for(j=1; j<=n; ++j) 
			{
				if(e[i][k] < inf && e[k][j] < inf && e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}
}
int main()
{
	fin >> n >> m;
	init();
	for(int i=1; i<=m; ++i) 
	{
		fin >> u >> v >> l;
		e[u][v] = l;
	}
	floyd();
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			fout << e[i][j] << " ";
		}
		fout << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
