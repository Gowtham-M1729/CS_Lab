#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int pos,c;
FILE *f1,*f2;
bool binarySearch(int a[],int l,int r,int x)
{
    if(r>=l)
    {
        c+=1;
        int mid = l+(r-l+1)/2;

        if(a[mid]==x)
        {
            pos = mid;
            return true;
        }

        if(a[mid]>x)    return binarySearch(a,l,mid-1,x);

        return binarySearch(a,mid+1,r,x);
    }
    return false;
}

int main(void)
{
    int *a,n,i,x,y;
    remove("value.txt");
    remove("count.txt");
    f1 = fopen("value.txt","a");
    f2 = fopen("count.txt","a");
    srand(time(NULL));
    for(n=10;n<=100;n+=10)
    {   
        c=0;
        a = (int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            a[i]=i+1;
            fprintf(f1,"%d ",a[i]);
        }
        x = a[n/2];
        y = rand()%100;
        fprintf(f1,"\nbest case key : %d\nworst case key : %d\n\n",x,y);
        binarySearch(a,0,n-1,x);
        fprintf(f2,"%d\t%d\t",n,c);
        c=0;
        binarySearch(a,0,n-1,y);
        fprintf(f2,"%d\n",c);
    }
    fclose(f1);
    fclose(f2);
}
