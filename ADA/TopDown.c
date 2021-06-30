#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
FILE *f1,*f2;
int *bottomUpHeap(int H[],int n)
{
    int i,j,k,v,c=0;
    bool heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=false;
        c+=1;
        while(!heap && 2*k<=n)
        {
            c+=1;
            j=2*k;
            if(j<n)
            {
                if(H[j]<H[j+1])
                    j+=1;
            }
            if(v>=H[j])
                heap=true;
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
    fprintf(f1,"%d\t%d\n",n,c);
    return H;
}

int main()
{
    int *H,n,i;
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
            bottomUpHeap(H,n);
        }
        fprintf(f2,"\n");
        for(i=1;i<=n;i++)
            fprintf(f2,"%d ",H[i]);
        
        fprintf(f2,"\n\n");
    }    
    fclose(f1);
    fclose(f2);
    return 0;
}
