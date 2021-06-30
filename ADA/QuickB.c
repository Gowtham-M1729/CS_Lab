#include <stdio.h>

int n = 16,i;
void print(int arr[])
{
    for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
    printf("\n");
}
void recurse(int arr[], int l, int r) {
	if (l > r) return;
	int mid = l + (r - l)/2, i;
	int tmp = arr[mid];
	for (i = mid - 1; i >= l; i--)
		arr[i+1] = arr[i];
	arr[l] = tmp;
	print(arr);
	recurse(arr, l + 1, mid);
	recurse(arr, mid+1, r);
}

void qbest(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) arr[i] = i+1;
	recurse(arr, 0, n-1);
}

int main() {
	int arr[1000];
	int  i;
	qbest(arr, n);
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}
