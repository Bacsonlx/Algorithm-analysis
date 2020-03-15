#include<iostream>
using namespace std;
const int MAXN = 1e7 + 10;
int T[MAXN];
//Ë³Ğò²éÕÒ
int Sequential_Search(int n, int x) 
{
	for (int i = 1; i <= n; i++) {
		if (T[i] == x) {
			return i;
		}
	}
	return 0;
}
//Ë³Ğò²éÕÒ£¨µİ¹é£©
int Sequential_Search_recursive(int n, int x) 
{
	if (n > 0) {
		if (T[n] == x) {
			return n;
		}else {
			return Sequential_Search_recursive(n - 1, x);
		}
	}
	else {
		return 0;
	}
}
//¶ş·Ö²éÕÒ
int Binary_Search(int n, int x) 
{
	int mid;
	int low = 1, high = n;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (T[mid] == x) {
			return mid;
		}else {
			if (x < T[mid]) high = mid - 1;
			else low = mid + 1;
		}
	}
	return 0;
}
int main()
{
	int N[10] = { 10, 50000, 100000, 200000, 400000, 600000, 800000, 1000000 };
	int n = N[0];
	
	for (int i = 1; i <= n; i++) {
		T[i] = i;
	}
	for(int i = 1; i <= n + 1; i++)
	{
		int search_number = i;
		cout << "The search number is: " << search_number << endl;
		cout << "The result of Sequential search is: " << Sequential_Search(n, search_number) << endl;
		cout << "The result of Binary search search is: " << Binary_Search(n, search_number) << endl;
		cout << "--------------------------------------------" << endl;
	}
	
	return 0;
}
