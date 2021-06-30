#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
FILE *f1,*f2;
void print(int H[],int n)
{
    for(int i=1;i<=n;i++)
        printf("%d ",H[i]);
    printf("\n");
}
int *bottomUpHeap(int H[],int n)
{
    int i,j,k,v,c=0;
    bool heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=false;
        //c+=1;
        while(!heap && 2*k<=n)
        {
           
            j=2*k;
            if(j<n)
            {    c+=1;
                if(H[j]>H[j+1])
                    j+=1;
            }
            if(v<=H[j])
            {   c++;
                heap=true;
            }
            else
            {   c++;
                H[k]=H[j];
                k=j;
            }
            print(H,n);
            
        }
        H[k]=v;
        print(H,n);
    }
    fprintf(f1,"%d\t%d\n",n,c);
    return H;
}

int main()
{
    int *H,n,i,k;
    remove("Heap_count.txt");
    remove("Heap_value.txt");
    f1 = fopen("Heap_count.txt","a");
    f2 = fopen("Heap_value.txt","a");
    srand(time(NULL));
    n=7;
   // for(n=10;n<=100;n+=10)
    {
        H = (int *)malloc((n+1)*sizeof(int));
        for(i=1;i<=n;i++)
        {
             //int k=rand()%100+2;
             scanf("%d",&k);
            H[i]=k;
            fprintf(f2,"%d ",H[i]);
        }
        fprintf(f2,"\n");
        bottomUpHeap(H,n);
        
        for(i=1;i<=n;i++)
            fprintf(f2,"%d ",H[i]);
        
        fprintf(f2,"\n\n");
    }    
    fclose(f1);
    fclose(f2);
    return 0;
}
