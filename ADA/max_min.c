// Maximum and Minimum element using Divide and Conquer

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *f1,*f2;
int c;
struct pair
{
  int min;
  int max;
}; 
 
struct pair getMinMax(int arr[], int low, int high)
{
  struct pair minmax, mml, mmr;      
  int mid;
  
  // If there is only one element
  if (low == high)
  {   c++;
     minmax.max = arr[low];
     minmax.min = arr[low];    
     return minmax;
  }   
   
  /* If there are two elements */
  if (high == low + 1)
  { 
      c++;
     if (arr[low] > arr[high]) 
     {
        minmax.max = arr[low];
        minmax.min = arr[high];
     } 
     else
     {
        minmax.max = arr[high];
        minmax.min = arr[low];
     } 
     return minmax;
  }
   
  /* If there are more than 2 elements */
   c++;
  mid = (low + high)/2; 
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid+1, high); 
   //c=c+2;
  /* compare minimums of two parts*/
  if (mml.min < mmr.min)
  {
    minmax.min = mml.min;
  }
  else
  {
     
    minmax.min = mmr.min;    
  }
 
  /* compare maximums of two parts*/
  if (mml.max > mmr.max)
  {
    minmax.max = mml.max;
  }
  else
  {
    minmax.max = mmr.max;    
  }
  
  return minmax;
}

int main()
{
  int *arr;
  int arr_size;
  //remove("count.txt");
  srand(time(NULL));
  // printf("Enter n : ");
  // scanf("%d",&arr_size);
  f1 = fopen("count.txt","a");
  for(arr_size=10;arr_size<=100;arr_size+=10)
  {  
    c=0;
    arr = (int *)malloc(arr_size*sizeof(int));
    for(int i=0;i<arr_size;i++)
    {
      arr[i]=rand()%100;
      //fprintf(f2,"%d ",arr[i]);
    }
    struct pair minmax = getMinMax(arr, 0, arr_size-1);
  // printf("\nMinimum element is %d", minmax.min);
  // printf("\nnMaximum element is %d", minmax.max);
  //fprintf(f2,"\nMIN : %d\nMAX : %d\n\n",minmax.min,minmax.max);
 // fprintf(f1,"%d\t%d\n",arr_size,c);
 printf("%d\n",c);
  }
  //fclose(f1);
  //fclose(f2);
}
