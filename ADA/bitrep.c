#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int bit(int n)
  {
      if(n<=1)
        return n%2;
      int k=bit(n/2);
      printf("%d ",k);
      return n%2;
  }
void main()
{  int i,j,k,n,l=2;
   FILE *ptr,*fptr;
   ptr=fopen("Bitcount.txt","a");
   srand(time(NULL));
   for(i=0;i<=10;i++)
     {
        l=(rand()%100)+20;
        //scanf("%d",&l);
        printf("%d->\n",l);
        j=bit(l);
        printf("%d\n",j);
     }
}

   
