#include <stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *fp1;
int binomialCoeff(int n, int k,int *count)
{
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;
    *count+=1;
	return binomialCoeff(n - 1, k - 1,count)
		+ binomialCoeff(n - 1, k,count);
}
int main()
{
	remove("Binomial.txt");
    fp1=fopen("Binomial.txt","a");
    srand(time(NULL));
	int n , k,count;
	for(int i=1;i<=20;i++)
	 {
	    n=rand()%20+1;
	    k=rand()%n+1;
	    count=0;
	    fprintf(fp1,"Value of C(%d, %d) is %d\n", n, k,binomialCoeff(n, k,&count));
	     fprintf(fp1,"Count of operations is %d\n\n",count);
	 }
	
	return 0;
}

