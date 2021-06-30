// Program to generate worst case input for merge sort
#include<stdio.h>
#include<stdlib.h>

void print(int x[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d\t",x[i]);
    printf("\n");
 }

void  join(int arr[],int left[],int right[],int l,int m,int r)
{
	int i,j;
	for(i=0;i<=m-l;i++)
	arr[i]=left[i];

	for(j=0;j<r-m;j++)
	arr[i+j]=right[j];
}

void split(int arr[],int left[],int right[],int l,int r,int m)
{
	int i;
	for(i=0;i<=m-l;i++)
	    left[i]=arr[i*2];

	for(i=0;i<r-m;i++)
	    right[i]=arr[i*2+1];
}

void generate(int arr[],int l,int r)
{
	if(l<r)
	{
	 int m=(l+r)/2;

	 int left[m-l+1];
	 int right[r-m];

	 split(arr,left,right,l,r,m);

	 generate(left,l,m);
	 generate(right,m+1,r);

     join(arr,left,right,l,m,r);


	}
}

int main()
{
	int *arr,n,i;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	arr[i]=i+1;
    printf("Sorted array is \n");
    print(arr,n);
    generate(arr,0,n-1);
    printf("\n Worst case input for merge sort:\n");
    print(arr,n);
    return 0;
  } 
