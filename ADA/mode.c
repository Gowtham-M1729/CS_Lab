//c program to calculate mode of an array (most repeating element of an array)
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int mode(int arr[],int n)
{
    int number = arr[0];
    int mode = number;
    int count = 1;
    int countMode = 1;

    for(int i=1; i<n-1; ++i)
    {
        //if we get the same element as number
        if(arr[i] == number)
        {   printf("%d==%d--\n",number,arr[i]);
            //count occcurences of the current number
            count++;
        }
        else
        {
            if(count > countMode)
            {
                countMode = count;//countMode keeps track of count of most frequent element
                mode = number;
                 printf("%d!=%d$$$\n",mode,number);
            }
            printf("%d!=%d\n",mode,arr[i]);
            count = 1; // reset count for the new number
                number = arr[i];
                printf("%d==%d\n",arr[i],number);
        }
    }
    if(count > countMode)
            {
                countMode = count;//countMode keeps track of count of most frequent element
                mode = number;
                 printf("%d!=%d$$$\n",mode,number);
            }
    return mode;
}

/* Driver code */
int main()
{
	int arr[] = { 11,11,12,12,12,12,13,13,14,14,14,15,15,15,16,16,15,8,7,2,6,4,5,9,1,7,2,3};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);

    int m = mode(arr,arr_size);
    printf("mode: %d",m);
	return 0;
}
