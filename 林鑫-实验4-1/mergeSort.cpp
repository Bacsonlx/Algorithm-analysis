#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100
#define ARR_SIZE 8
#define START 1

typedef struct{
	int key;
}element;

void merge(element a[], int left, int middle, int right)
{
	element* map = (element *)malloc(sizeof(int) * MAX_SIZE);
	int index = 0;
	int i = left, j = middle + 1;
	while (i <= middle && j <= right) {
		if (a[i].key < a[j].key) {
			map[index++].key = a[i++].key;
		}
		else {
			map[index++].key = a[j++].key;
		}
	}
	while (i <= middle) {
		map[index++].key = a[i++].key;
	}
	while (j <= right) {
		map[index++].key = a[j++].key;
	}
	for (int k = left; k <= right; k++) {
		a[k].key = map[k - left].key;
	}
}
void mergeSort(element a[], int left, int right)
{
	if (left >= right) {
		return;
	}
	int middle = (left + right) / 2;
	mergeSort(a, left, middle);
	mergeSort(a, middle+1, right);
	merge(a, left, middle, right);
}
int main()
{
	int i;
	element arr[MAX_SIZE];
	//FILE* fpRead = fopen("input.txt", "r");
	//FILE* fpWrite = fopen("output.txt", "w");
	srand(time(NULL));
	for (i = 1; i <= ARR_SIZE; i++)
	{
		arr[i].key = rand() / 100;
		//fscanf_s(fpRead, "%d", &arr[i].key);
	}
	for (i = 1; i <= ARR_SIZE; i++)
	{
		printf("%d ", arr[i].key);
	}
	printf("\n");
	
	/*----------SortFunction-----------*/
	mergeSort(arr, START, ARR_SIZE);

	//fprintf(fpWrite, "排序后的序列为；\n");
	for (i = 1; i <= ARR_SIZE; i++)
	{
		//fprintf(fpWrite, "%d  ", arr[i].key);
		printf("%d ", arr[i].key);
	}
	printf("\n");
	return 0;
}
