#include<stdio.h>
int fib(int n);
int pfib(int *n);
void main()
{ int i,j,k,a[100],n;
  scanf("%d",&n);
  fib(n+1);
  printf("%d ",fib(n));
  pfib(a);
    
}
int fib(int n)
{  static int a[100];
   if(n==2)
      return 1;
   else if(n==1)
      return 0;
    else
       return fib(n-1)+fib(n-2);
    
}
int pfib(int *a)
{ int i;
   for(i=0;i<10;i++)
     printf("%d ",*(a+i));
}
    
