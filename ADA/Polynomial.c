#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *fp1,*fp2;
int count=0;
int polynomial(int poly[], int n, int x)
{
	int result = poly[0]; 

	for (int i=1; i<n; i++)
	{   count++;
		result = result*x + poly[i];
    }

	return result;
}
void print(int arr[],int n,int x)
{
    for(int i=n-1;i>=0;i--)
    {
         fprintf(fp1,"+ (%d)%c^%d ",arr[n-i-1],'x',i);
    }
   fprintf(fp1,"\nX=%d\n",x);
}
int main()
{   
    remove("Value.txt");
    fp1=fopen("Value.txt","a");
    remove("Value1.txt");
    fp2=fopen("Value1.txt","a");
	int poly[100];
	int x,n;
    srand(time(NULL));
    for(n=2;n<=20;n=n+2)
      {   x=rand()%10;
          for(int i=0;i<n;i++)
            {
               poly[i]=rand()%10-rand()%10;
            }
        print(poly,n,x);
        count=0;
        fprintf(fp1,"Result=%d\n\n", polynomial(poly,n,x));
        fprintf(fp2,"%d\t%d\n",n,count);
      }
    
	return 0;
}

