#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
FILE *fp1, *fp2;
int c, count = 0, countB = 0,countW=0;
void mergeSort(int list[], int low, int mid, int high)
{
	c = 0;
	int i, mi, k, lo, temp[10000];
	lo = low;
	i = low;
	mi = mid + 1;

	while ((lo <= mid) && (mi <= high))
	{
		c++;
		if (list[lo] <= list[mi])
		{
			temp[i] = list[lo];
			lo++;
		}
		else
		{
			temp[i] = list[mi];
			mi++;
		}
		i++;
	}
	if (lo > mid)
	{
		for (k = mi; k <= high; k++)
		{
			temp[i] = list[k];
			i++;
		}
	}
	else
	{
		for (k = lo; k <= mid; k++)
		{
			temp[i] = list[k];
			i++;
		}
	}
	for (k = low; k <= high; k++)
	{
		list[k] = temp[k];
	}
	count += c;
}
int partition(int list[], int low, int high)
{
	int mid, i;
	if (low < high)
	{
		mid = (low + high) / 2;
		partition(list, low, mid);
		partition(list, mid + 1, high);
		mergeSort(list, low, mid, high);
	}
	else
		return 0;
}
void print(int x[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\t", x[i]);
	printf("\n");
}
void join(int arr[], int left[], int right[], int l, int m, int r)
{
	int i, j;
	for (i = 0; i <= m - l; i++)
		arr[i] = left[i];

	for (j = 0; j < r - m; j++)
		arr[i + j] = right[j];
}

void split(int arr[], int left[], int right[], int l, int r, int m)
{
	int i;
	for (i = 0; i <= m - l; i++)
		left[i] = arr[i * 2];

	for (i = 0; i < r - m; i++)
		right[i] = arr[i * 2 + 1];
}

void generate(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;

		int left[m - l + 1];
		int right[r - m];

		split(arr, left, right, l, r, m);

		generate(left, l, m);
		generate(right, m + 1, r);

		join(arr, left, right, l, m, r);
	}
}
int worstcase(int arr[], int k)
{
	int i;
	for (i = 0; i < k; i++)
		arr[i] = i + 1;
	printf("Sorted array is \n");
	//print(arr,k);
	generate(arr, 0, k - 1);
	count = 0;

	partition(arr, 0, k - 1);
	printf("No of Counts is->%d\n", count);
	countW = count;
	return 0;
}

void bestcase(int n)
{
	int *arr, j;
	j = 0;
	arr = (int *)malloc(sizeof(int) * n);
	srand(time(NULL));
	int item = rand() % 1000;
	for (int i = 0; i < n; ++i)
	{
		arr[i] = item++;
	}
	print(arr, n);
	count = 0;
	partition(arr, 0, n - 1);
	countB = count;
}
int main()
{
	int a[10000];
	int i, size;
	remove("Mergecount.txt");
	for (int i = 16; i <= 10000; i = i * 2)
	{
		count = 0;
		printf("Entering array\n");

		worstcase(a, i);
		bestcase(i);
		fp2 = fopen("Mergecount.txt", "a");
		fprintf(fp2, "%d\t%d\t%d\n", i, countW,countB);
	}
	return 0;
}