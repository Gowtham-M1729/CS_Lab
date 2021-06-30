#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef long long int ll;
FILE *fp1,*fp2;
void InsertSort(ll arr[],ll n,ll *count)
{ ll i,j,key;
   for(i=1;i<=n;i++)
     {
        j=i-1;
        key=arr[i];
        while(j>=0 && arr[j]>key)
        { *count+=1;
          arr[j+1]=arr[j];
          j--;
        }
        *count+=1;
        //printf("----->%lld\n", *count);
        arr[j+1]=key;
      }
}
void printArray(ll A[], ll size)
{
	ll i;
	for (i = 0; i < size; i++)
		printf("%lld ", A[i]);
	printf("\n");
}
void worstcase(ll arr[],ll i)
  {   ll k=0;
      arr=(long long int *)malloc(i*sizeof(ll));
	          for(int j=0;j<i;j++)
	          { 
	               
	               arr[j]=2*i-j+1;
	              
	               
	              
	          }
	       //printf("Before Sort for Worst Case\n");
	      // printArray(arr,  i);   
	       ll count=0;
	       InsertSort(arr, i-1,&count);
	       //printf("No of Counts is->%lld\n",count);
	       //printf("After Sort for Worst Case\n");
           //printArray(arr,  i);  
	       fprintf(fp2,"%lld\t",count);
	          
	 }
void bestcase(ll arr[],ll i)       
{ 
  arr=(long long int*)malloc(i*sizeof(ll));
          for(int j=0;j<i;j++)
	          {
	             
	             arr[j]=(j+1);
	          }
  //printf("Before Sort for Best case\n\n");
  //printArray(arr,  i);   
  ll count=0;
  InsertSort(arr,i-1,&count);
  //printf("After Sort for Best case\n");
  //printArray(arr,  i);
  fprintf(fp2,"%lld\t%lld\t",i,count);
  
}
void avgcase(ll arr[],ll i)       
{ 
  arr=(long long int*)malloc(i*sizeof(ll));
          for(int j=0;j<i;j++)
	          {
	             
	             arr[j]=rand()%10000;
	          }
  //printf("Before Sort for Best case\n\n");
  //printArray(arr,  i);   
  ll count=0;
  InsertSort(arr,i-1,&count);
  //printf("After Sort for Best case\n");
  //printArray(arr,  i);
  fprintf(fp2,"%lld\n",count);
  
}
int main()
{   
	ll *arr;
	ll l;
	remove("Insertcount.txt");
	fp2 = fopen("Insertcount.txt","a");
	 for(ll i=0;i<=40000;i=i+1000)
	  {   
	      bestcase(arr,i);
	      worstcase(arr,i);
	      avgcase(arr,i);
	      
	          
	           
	   }
	return 0;
}

