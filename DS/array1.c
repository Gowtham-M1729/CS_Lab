#include<stdio.h>
#include<stdlib.h>
int* create();
void display(int *,int a[]);
void insert(int *,int a[]);
void delete(int *,int a[]);
void mergeSort(int [], int i, int j, int k);
int partition(int [],int i, int j);
void main()
{   int choice,n;
    int *a;
    while(1)
      { 
        printf("Enter your choice\n");
        printf("1.create\n");
        printf("2.Display\n");
        printf("3.Insert\n");
        printf("4.Delete\n");
        printf("5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {   case 1:
                printf("Enter the array size : ");
                scanf("%d",&n);
                a=create(&n);
                break;
            case 2:
                display(&n,a);
                break;
            case 3:
                insert(&n,a);
                break;
            case 4:
                delete(&n,a);
                break;
            case 6:
                partition(a,0,n-1);
                break;
            case 5:
                exit(0);
            default:
                printf("Enter a valid choice");
                break;
        }
    }
}
int* create(int *n)
 { int choice,i;
    int *a = malloc(*n*(sizeof(int)));
    printf("Enter the elements : \n");
    for(i=0;i<*n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",a+i);
    }
   return a;
 }
void display(int *n,int a[])
{   int i;
    printf("Elements present in the array :\n");
    for(i=0;i<*n;i++)
    {
        printf(" %d ",a[i]);
    }
}

void insert(int *n,int a[])
{
        int x,pos,i;
	printf("Enter the element to be inserted : ");
	scanf("%d",&x);
	printf("Enter the position : ");
	scanf("%d",&pos);
	for(i=*n;i>=pos;i--)
	{
		a[i]=a[i-1];
	}
	a[pos-1]=x;
	printf("\nUpdated array : ");
        *n=*n+1;
}
void delete(int *n,int a[])
{
        int pos,i;
	printf("Enter the location to delete : ");
	scanf("%d",&pos);
	if(pos>=*n+1)
	{
		printf("Deletion is not possible... \n");
	}
	else
	{
		for(i=pos-1;i<*n-1;i++)
		{
			a[i]=a[i+1];
		}
	}
        *n=*n-1;
}
int partition(int list[],int low,int high)
{
    int mid,i;
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(list, low, mid);
        partition(list, mid + 1, high);
        mergeSort(list, low, mid, high);
    }
    else
       return 1000;
}
void mergeSort(int list[],int low,int mid,int high)
{
    int i, mi, k, lo, temp[50];
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
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
    
}
