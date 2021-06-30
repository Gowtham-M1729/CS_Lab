#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *s,n,c=0;
int distrubutionCountingSort(int a[],int l,int u)
{
    int *d,j,i;
    s = (int *)malloc(n*sizeof(int));
    d = (int *)malloc(u*sizeof(int));
    for(j=0;j<=u-l;j++) 
    {
        c+=1;
        d[j]=0;
    }
    for(i=0;i<n;i++)
    {
        c+=1;
        d[a[i]-l]+=1;
    }
    for(j=1;j<=u-l;j++)
    {
        c+=1;    
        d[j]=d[j-1]+d[j];
    }
    for(i=n-1;i>=0;i--)
    {
        c+=1;
        j = a[i]-l;
        s[d[j]-1] = a[i];
        d[j]-=1;
    }
}

int main(void)
{
    FILE *f1,*f2;
    remove("count.txt");
    remove("value.txt");
    f1 = fopen("value.txt","a");
    f2 = fopen("count.txt","a");
    int *a,l,u,i,j,max=0;
    srand(time(NULL));
    for(n=10;n<=100;n+=10)
    {   
        c=0;
        a = (int *)malloc(n*sizeof(int));
        fprintf(f1,"Array : ");
        for(i=0;i<n;i++)
        {

            a[i] = rand()%9+1;
            fprintf(f1,"%d ",a[i]);
            if(a[i]>max)    max=a[i];
        }

        distrubutionCountingSort(a,0,max);
        fprintf(f1,"\nSorted : ");
        for(i=0;i<n;i++)
            fprintf(f1,"%d ",s[i]);

        fprintf(f1,"\n\n");
        fprintf(f2,"%d\t%d\n",n,c);
    }
    fclose(f1);
    fclose(f2);
}
