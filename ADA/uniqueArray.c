#include<stdio.h>
#include<stdlib.h>
int uniqArr(int arr[],int n,int *count)
{
   for(int i=0;i<n-1;i++)
      {
         for(int j=i+1;j<n-1;j++)
            {   *count+=1;
                if(arr[i]==arr[j])
                   {  printf("%d is Repeated\n",arr[j]);
                      return 0;
                   }
            }
      }
  return 1;
}
void print(int arr[],int n)
{
   for(int i=0;i<n;i++)
      {  
         printf("%d ",arr[i]);
      }
   printf("\n");
}
int main()
{
   int i,j,k,*a,n;
   for(n=10;n<=100;n=n+10)
   {   a=(int*)malloc(n*sizeof(int));
       for(i=0;i<n;i++)
         {
            a[i]=rand()%1000;
         }
       int  count=0;
      print(a,n);
      if( uniqArr(a,n,&count))
        {
            printf("Array is unique\n");
        }
        else{
          printf("Array is Not unique\n");
          
       printf("Number of basic operation (Comparison) is %d \n",count);
      }
   }
}
       
         
