#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int c;
int* comparison(int a[],int count[],int n)
{  int *S,i;
   for(i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                c+=1;
                if(a[i]<a[j])  
                 count[j]+=1;
                else  
                  count[i]+=1;
            }
        }
        S = (int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)    S[count[i]]=a[i];
        return S;
}

int main(void)
{
    FILE *f1,*f2;
    int *a,n,i,j,*count,*S;
    remove("count.txt");
    remove("value.txt");
    f1 = fopen("value.txt","a");
    f2 = fopen("count.txt","a");
    for(n=10;n<=100;n+=10)
    {
        c=0;
        a = (int *)malloc(n*sizeof(int));
        count = (int *)malloc(n*sizeof(int));
        fprintf(f1,"INPUT : ");
        for(i=0;i<n;i++)
        {
            a[i] = rand()%100;
            fprintf(f1,"%d ",a[i]);
            count[i]=0;
        }
        
        S=comparison(a,count,n);
        fprintf(f1,"\nSORTED : ");
        for(i=0;i<n;i++)    fprintf(f1,"%d ",S[i]);

        fprintf(f1,"\n\n");
        fprintf(f2,"%d\t%d\n",n,c);
    }
}
