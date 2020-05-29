#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int n, m;   //n个顶点 m种颜色
int a = 1, b = 1;   //输入时的顶点
int count = 0;  //记录总方案数
int graph[20][20] = {0};    //记录无向图
int color[20] = {0};    //颜色

bool ok(int c) //判断是否可以涂上该颜色
{
    for(int k = 1; k <= n; k++)
	{
        if(graph[c][k] && color[c] == color[k]){
            return false;
        }
    }
    return true;
}

void backtrack(int cur) //回溯的过程
{
    if(cur > n){
        for(int i = 1; i <= n; i++){
            printf("%d ",color[i]);
        }
        count++;
        printf("\n");
    }else{
        for(int i = 1; i <= m; i++)
		{
            color[cur] = i;
            if(ok(cur)){
                backtrack(cur + 1);
            }
            color[cur] = 0;
        }
    }
}

int main()
{
	ifstream fin("input.txt");
	fin >> n >> m;
//	cin >> n >> m;
	cout << "输入的无向图为:" << endl;
    while(fin >> a >> b && a != 0 && b != 0){
    	cout << a << " " << b << endl;
        graph[a][b] = 1;
        graph[b][a] = 1; //无向图记录两边
    }
    cout << "*******************" << endl;
    backtrack(1);
    cout << "总共的方案数为:" << endl;
    cout << count << endl;
	system("pause");
	return 0;
}
