/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
int count=0;
FILE *fp1,*fp2;
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
	   count++;
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
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
void worstcase(int arr[],int i)
  {  int l=1,k=16,m=0;
     int a[10000];
             
	          for(int j=0,k=0;j<i;j++)
	          {
	             if(j%2==0)
	             {  
	                a[m]=arr[j];
	                m++;
	              }
	              else
	              {
	               a[k+i/2]=arr[j];
	                k++;
	               }
	          }     
	          
	       printArray(a,  i);   
	       count=0;
	       mergeSort(a, 0, i-1);
	       printf("No of Counts is->%d\n",count);
	       fprintf(fp2,"%d\n",count);
	          
	 }
void bestcase(int arr[],int i)       
{ fp2 = fopen("Mergecount.txt","a");
          for(int j=0;j<i;j++)
	          {
	             
	             arr[j]=(j+1);
	          }
  printArray(arr,  i);   
  count=0;
  mergeSort(arr, 0, i-1);
  
  printf("No of Counts is->%d\n",count);
  fprintf(fp2,"%d\t%d\t",i,count);
  worstcase(arr,i);
  
}
  

/* UTILITY FUNCTIONS */
/* Function to print an array */


/* Driver code */
int main()
{   
	int arr[10000];
	int l;
	remove("Mergecount.txt");
	 for(int i=1;i<=4000;i=i*2)
	  {   
	      bestcase(arr,i);
	      
	      
	          
	           
	   }
	return 0;
}

