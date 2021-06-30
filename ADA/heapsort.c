#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
FILE *f1,*f2;
int count=0;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int *heapify(int H[],int n)
{
    int j,k,v;
    bool heap;
    for(int i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=false;
        while(!heap && 2*k<=n)
        {
           
            j=2*k;
            if(j<n)
            {   count++;
                if(H[j]<H[j+1])
                    j+=1;
            }
            if(v>=H[j])
            {   count++;
                heap=true;
            }
            else
            {   count++;
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
    return H;
}
void print(int H[],int n)
{
    for(int i=1;i<=n;i++)
        printf("%d ",H[i]);
    printf("\n");
}
int *heapsort(int H[],int n)
{
        heapify(H,n);

    for(int i=n;i>=1;)
    {
        swap(&H[1],&H[i]);
         print(H,n);
         i=i-1;
        heapify(H,i);
        print(H,n);
    }
    return H;
}

int main()
{
    int *H,i,n;
    remove("Heap_count.txt");
    remove("Heap_value.txt");
    f1 = fopen("Heap_count.txt","a");
    f2 = fopen("Heap_value.txt","a");
    srand(time(NULL));
    for(n=10;n<=100;n+=10)
    {
        H = (int *)malloc((n+1)*sizeof(int));
        for(i=1;i<=n;i++)
        {
             int k=rand()%100+2;
            H[i]=k;
            fprintf(f2,"%d ",H[i]);
        }
        fprintf(f2,"\n");
        count=0;
        heapsort(H,n);
        fprintf(f1,"%d %d\n",n,count);
        for(i=1;i<=n;i++)
            fprintf(f2,"%d ",H[i]);
        
        fprintf(f2,"\n\n");
    }    
    fclose(f1);
    fclose(f2);
    return 0;
}
