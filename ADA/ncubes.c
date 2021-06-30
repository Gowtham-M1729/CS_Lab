#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int bit(int n,int *count)
  {   if(n==0)
        return 0;
      else if(n==1)
        return 1;
      *count+=1;
      return n*n*n+bit(n-1,count);
  }
void main()
{  int i,j,k,n,l=2,count=0;
   FILE *ptr,*fptr;
   ptr=fopen("count.txt","a");
   srand(time(NULL));
   for(i=0;i<=10;i++)
     {
        l=(rand()%10)+1;
        //scanf("%d",&l);
        count=0;
        printf("%d->\n",l);
       
        j=bit(l,&count);
         fprintf(ptr,"%d\t%d\n",l,count);
        printf("%d %d\n",j,2*count);
     }
}

   
