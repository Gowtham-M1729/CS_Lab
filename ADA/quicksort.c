#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
FILE *fp1,*fp2;
int c,count=0;
int n;
void printArray(int arr[])
{
	int i;
	for (i = 0; i < n; i++)
	    printf("%d ",arr[i]);
	printf("\n");
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		count++;
		if (arr[j] > pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);
		printArray(arr);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/*
void bestcase(int arr[],int i)
  {  int l=1,k=16,m=0;
     int a[1000];
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
	       printArray(arr,  i);   
	       count=0;
	       quickSort(arr, 0, i-1);
	       printf("No of Counts is->%d\n",count);
           fprintf(fp2,"%d\n",count);
	       
	          
	 }
void worstcase(int arr[],int i)       
{ fp2 = fopen("Quickcount1.txt","a");
          for(int j=0;j<i;j++)
	          {
	             
	             arr[j]=(j+1);
	          }
  printArray(arr,  i);   
  count=0;
  quickSort(arr, 0, i-1);
  printf("No of Counts is->%d\n",count);
  fprintf(fp2,"%d\t%d\n",i,count);
  bestcase(arr,i);
  
  
}
*/
int main()
{
	int arr[]={ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int l;
	n= sizeof(arr) / sizeof(arr[0]);
	/*remove("Quickcount1.txt");
	fp2 = fopen("Quickcount.txt","a");
	 for(int i=0;i<=180;i=i+8)
	  {   
	      //worstcase(arr,i);
	      bestcase(arr,i);
	      
	          
	           
	   }*/
	   quickSort(arr, 0, n-1);
	   printf("%d---\n",count);
	return 0;
}
