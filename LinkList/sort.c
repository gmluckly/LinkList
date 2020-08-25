#include "sort.h"


//��������
void InsertSort(int a[], int n){
	int i, j;
	for (i = 0; i < n; i++){
		int tmp = a[i];
		for (j = i; j>0 && a[j - 1] > tmp; --j){
			a[j] = a[j - 1];
		}
		a[j] = tmp;
		//printf("a[%d]: %d \n", i, a[j]);
	}
}


//ð������
void BubbleSort(int a[], int n){
	int i, j ,t = 0;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n -i - 1; j++){
			if (a[j] > a[j + 1]){
				t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
		printf("\n");
		for (int index = 0; index < n; index++){
			printf(" %d ", a[index]);
		}
	}
}

void QuickSort(int a[], int start, int end)
{
	if (start < end){
		int i = start, j = end, x = a[start];
		while (i<j)
		{
			while (i < j && a[j]>=x) //���ҵ����ҳ���һ��С��x����
				j--;
			if (i < j)
				a[i++] = a[j];
			while (i < j && a[i] <= x) // �������ң��ҳ���һ������x����
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		printf(" a[%d]: %d  ", i, x);
		QuickSort(a, start, i - 1);
		QuickSort(a, i + 1, end);
	}
}

void test()
{
	printf("This is a test")
}
