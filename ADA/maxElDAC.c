#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int c=0;
int maximum(int a[], int l, int r,int *count) {
   //c++;
   if (r==l)
   {  
      return a[l];
   }
   int m=(l+r)/2;
   int u=maximum(a,l,m,count);
   int v=maximum(a,m+1,r,count);
   *count+=1;
   return u>v?u:v;    
}

int main() {
    int a[100],n;
    srand(time(NULL));
    FILE *ptr,*fptr;
    ptr=fopen("Maxcount.txt","a");
    for(n=10;n<=100;n=n+10)
    {  for(int j=0;j<n;j++)
         {
             a[j]=rand()%100+1;
         }
    //int n = sizeof(a)/sizeof(int);
    int count=0;
    printf("Maximum Value is->%d\n",maximum(a,0,n-1,&count));
    printf("Count is->%d    c==%d",count,c);
    fprintf(ptr,"%d\t%d\n",n,count);   
    }     
    return 0;
}
