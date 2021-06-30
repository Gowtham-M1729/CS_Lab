#include<stdio.h>
#define MAX 5
int a[MAX][MAX];
int print(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int n,i,j,k,count=0,sum=0;
    printf("Enter n : ");
    scanf("%d",&n);
    printf("Enter the %dX%d digraph : \n",n,n);
    for(i=1;i<=n;i++)
    {
        printf("Enter row %d : ",i);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(k=1;k<=n;k++)
    {   
        print(n);
        printf("\n\n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                count+=1;
                sum = a[i][k]+a[k][j];
                if(sum < a[i][j])
                    a[i][j] = sum;
            }
        }
    }

    printf("\nPath Matrix : \n");
    
    printf("\ncount : %d\n",count);
}