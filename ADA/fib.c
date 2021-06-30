#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int c;
int fib(int n)
{
if (n <= 1)
	return n;
	c++;
return fib(n-1) + fib(n-2);
}

int main ()
{
int i,j,k,n,l=2;
   FILE *ptr,*fptr;
   ptr=fopen("Fibcount.txt","a");
   srand(time(NULL));
   for(i=1;i<=10;i++)
     {
        c=0;
        j=fib(i);
        fprintf(ptr,"%d\t%d\n",i*2,c);
        printf("Number of Bits required to reprsent %dare %d\n",k,j);
     }
return 0;
}

