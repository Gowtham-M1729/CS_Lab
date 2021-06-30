#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int bit(int n)
  {
      if(n<=1)
        return 1;
      return 1+bit(n/2);
  }
void main()
{  int i,j,k,n,l=2;
   FILE *ptr,*fptr;
   ptr=fopen("Bitcount.txt","a");
   srand(time(NULL));
   for(i=0;i<=10;i++)
     {
        //k=(rand()%100)+1;
        l=l*2;
        j=bit(l);
        fprintf(ptr,"%d\t%d\n",l,j);
        printf("Number of Bits required to reprsent %dare %d\n",k,j);
     }
}

   
