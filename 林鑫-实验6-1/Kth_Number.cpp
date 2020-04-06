#include<iostream>
#include<stdio.h>
using namespace std;

int Partition( int a[], int start, int end, int pivot )
{
	int target = a[pivot];
	int low = start, high = end;
	a[pivot] = a[low];
	while ( high > low )
	{
		for ( ; a[high] <= target && high > low; ) {
				high--;
		}
		a[low] = a[high];
		for ( ; a[low] >= target && high > low;  ) {
				low++;
		}
  		a[high] = a[low];
 	}
	a[low] = target;
	return low;
}
int Select( int a[], int start, int end, int k )
{
	if (  end - start < 0 || start < 0 || k < 0 || a == NULL )
	{
		return -1; //表示出错了
	}
	if ( start == end || k == 0 )
	{
		return start;
	}
	int min, i, iKthIndex;
	if ( end - start  < k ) //k比数组下标小1, 当数组覆盖范围<k时候，直接返回里面最小的一个数字
	{
		min = a[ iKthIndex=start ];
		i = start+1;
		for ( ; i <= end; i++ )
		{
			if( a[i] < min ){ //输出最小的一个，它是第kth大的数
			min = a[ iKthIndex=i ];
			}
		}
	}
	else{
		i = Partition( a, start, end, start+k-1 );   //pivot 可以自由选择，这里选取a[start+k-1] 为基准值
		if ( k-1 < i-start ) //k比数组下标小1
		{
			iKthIndex = Select( a, start, i-1, k );
		}
		else if ( k-1 == i-start ){
			iKthIndex = i;
		}
		else { //k+1 > i-start
			iKthIndex = Select( a, i+1, end, k-(i-start+1)  );
		}
	}
 return iKthIndex;
}


int main()
{
	int n = 11;
	int arr[n] = { 4,1,3,2,5,7,8,6,9,0,-7 };
	int k;
	cout << "寻找数组第k大的元素，请输入k(输入0结束)：" << endl;
	while(1){
		cin >> k;
		if(k == 0){
			cout << "Bye";
			break;
		}
		int pivot_index = Select( arr, 0, sizeof(arr)/sizeof(arr[0])-1, k );
		cout << "数组的第" << k << "大的数是" << arr[pivot_index] << endl;
	}
}
