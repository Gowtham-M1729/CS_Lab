#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
FILE *fp1,*fp2;
int c,count=0;
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
		if (arr[j] < pivot)
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
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void printArray(int arr[], int size)
{
	int i;
	//for (i = 0; i < size; i++)
		//cout << arr[i] << " ";
	//cout << endl;
}
void worstcase(int arr[],int i)       
{ fp2 = fopen("Quickcount.txt","a");
  arr=(int *)malloc(i*sizeof(int));
          for(int j=0;j<i;j++)
	          {
	             
	             arr[j]=(j+1);
	          }
  //printArray(arr,  i);   
  count=0;
  quickSort(arr, 0, i-1);
  //printf("No of Counts is->%d\n",count);
  fprintf(fp2,"%d\t%d\t",i,count);
  free(arr);
}
void bestcase(int arr[],int i)
  {  int k=0;
      arr=(int *)malloc(i*sizeof(int));
	          for(int j=0;j<i;j++)
	          {  if(j<i/2)
	             arr[j]=2*j;
	             else
	             {
	               
	               arr[j]=2*k+1;
	               k++;
	               }
	            
	               
	              
	          }
	       //printArray(arr,  i);   
	       count=0;
	       quickSort(arr, 0, i-1);
	       //printf("No of Counts is->%d\n",count);
	       fprintf(fp2,"%d\n",count);
	       free(arr);
	          
	 }
int main()
{
	int *arr;
	int l,i;
	remove("Quickcount.txt");
	//fp2 = fopen("Quickcount.txt","a");
	 for(i=2;i<=100;i=i*2)
	  {   
	      worstcase(arr,i);
	      bestcase(arr,i);
	          
	           
	   }
	return 0;
}
