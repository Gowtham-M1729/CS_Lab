#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int c;
int fib(int n)
{
if (n <= 1)
	return n;
	c++;
return n*fib(n-1);
}

int main ()
{
int i,j,k,n,l=2;
   FILE *ptr,*fptr;
   ptr=fopen("Factcount.txt","a");
   srand(time(NULL));
   for(i=0;i<=6;i++)
     {
        c=0;
        j=fib(i*2);
        fprintf(ptr,"%d\t%d\n",i*2,c);
        printf("Number of Bits required to reprsent %dare %d\n",k,j);
     }
return 0;
}

