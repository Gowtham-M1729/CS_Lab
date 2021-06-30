#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int min(int a, int b);
FILE *fp1;
int binomialCoeff(int n, int k,int *count)
{   
	int C[n + 1][k + 1];
	int i, j;

	
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= min(i,k); j++) {
		    *count+=1;
			if (j == 0 || j == i)
				C[i][j] = 1;

		
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
    for (i = 0; i <= n; i++) {
		for (j = 0; j <= min(i,k); j++)
		printf("%d ",C[i][j]);
	    printf("\n");
		}
	
		for (j = 0; j <= k; j++)
		  printf("%d-",C[5][j]);
	return C[n][k];
	
}

int min(int a, int b) { return (a < b) ? a : b; }

int main()
{   remove("Binomial.txt");
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

