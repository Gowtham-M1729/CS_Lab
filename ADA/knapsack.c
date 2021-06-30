#include<stdio.h>
#include<stdlib.h>

#define row 10
#define col 10

int max(int i, int j)
{
    return ((i > j) ? i : j);
}

int arr[row][col],values[10],weight[10],n,value,x[10];

void set_table(int capacity)
{
    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=capacity; ++j)
        {
            if(i == 0 || j == 0)
            {
                arr[i][j] == 0;
            }
            
            else
            {
                arr[i][j] = -1;
            }
        }
    }
}

void printArray(int capacity)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=capacity ; j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n\n");
    }
    int i=n;
	int j=capacity;
	while(j!=0&&i!=0) {
		if(arr[i][j]!=arr[i-1][j]) {
			x[i]=1;
			j=j-weight[i];
			i--;
		} else
		   i--;
	}
	int k=1;
	while(k<=n)
	{
	   printf("%d ",x[k4]); 
	   k++;
	   }
}

int MFKnapsack(int i,int j)
{
    if (arr[i][j] < 0)
    {
        if(j < weight[i])
        {
            value = MFKnapsack(i-1,j);
        }
        else
        {
            value = max(MFKnapsack(i-1,j), values[i]+MFKnapsack(i-1,j-weight[i]));
        }
        arr[i][j] = value;
    }
    return arr[i][j];
}

void main()
{

    int capacity;
    //printArray();
     printf("\nEnter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the value and weights of the elements:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("For item no %d\n", i);
        scanf("%d%d", &values[i], &weight[i]);
    }
    printf("\nEnter the capacity :\n");
    scanf("%d", &capacity);
    set_table(capacity);
    value = MFKnapsack(n,capacity);
    printf("max value: %d\n\n",value);
    printf("Knapsack matrix:\n");
    printArray(capacity);
}
