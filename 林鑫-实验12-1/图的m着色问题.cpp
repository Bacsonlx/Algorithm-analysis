#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int n, m;   //n������ m����ɫ
int a = 1, b = 1;   //����ʱ�Ķ���
int count = 0;  //��¼�ܷ�����
int graph[20][20] = {0};    //��¼����ͼ
int color[20] = {0};    //��ɫ

bool ok(int c) //�ж��Ƿ����Ϳ�ϸ���ɫ
{
    for(int k = 1; k <= n; k++)
	{
        if(graph[c][k] && color[c] == color[k]){
            return false;
        }
    }
    return true;
}

void backtrack(int cur) //���ݵĹ���
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
	cout << "���������ͼΪ:" << endl;
    while(fin >> a >> b && a != 0 && b != 0){
    	cout << a << " " << b << endl;
        graph[a][b] = 1;
        graph[b][a] = 1; //����ͼ��¼����
    }
    cout << "*******************" << endl;
    backtrack(1);
    cout << "�ܹ��ķ�����Ϊ:" << endl;
    cout << count << endl;
	system("pause");
	return 0;
}
