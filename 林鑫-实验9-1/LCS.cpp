#include <iostream>
#include <string>
#include <vector>
using namespace std;
//算法2：f（B, i, j）输出最长子串
void LCS(vector< vector<int> > &B, string X, int X_len, int Y_len) {
	if (X_len == 0 || Y_len == 0) {
		return;
	}
	if (B[X_len][Y_len] == 3) {
		LCS(B, X, X_len - 1, Y_len - 1);
		cout << X[X_len - 1];
	}
	else if (B[X_len][Y_len] == 2) {
		LCS(B, X, X_len - 1, Y_len);
	}
	else if (B[X_len][Y_len] == 1) {
		LCS(B, X, X_len, Y_len - 1);
	}
}
int main()
{
	string X = "ABCDC";
	string Y = "BDCB";
	int m = X.size();
	int n = Y.size();
	cout << "X: " << X << endl;
	cout << "Y: " << Y << endl;
	vector< vector<int> > C(m + 1, vector<int>(n + 1));
	vector< vector<int> > B(m + 1, vector<int>(n + 1));//1：删除y；2：删除x；3：删除两个
	//算法1：给出最长子串长度
	//初始化
	for (int i = 0; i <= m; i++)
	{
		C[i][0] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		C[0][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 3;//删除两个
			}
			else {
				if (C[i][j - 1] >= C[i - 1][j]) {
					C[i][j] = C[i][j - 1];
					B[i][j] = 1;//删除y
				}
				else {
					C[i][j] = C[i - 1][j];
					B[i][j] = 2;//删除x
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	cout << "最长公共子序列长度为：" << C[m][n] << endl;
	LCS(B, X, m, n);
	cout << endl;
}

