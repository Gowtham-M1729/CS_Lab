#include <stdio.h>
typedef long long int ll;
ll  maximum(ll  a,ll  n,ll  *count) {
   if (n==1)
   {  
      return a;
   }
   *count+=1;
   printf("Maximum Value\n");
   if(n%2==0)
     return maximum(a*a,n/2,count);
   else 
     return a*maximum(a*a,n/2,count);
}

int main() {
  ll  i,j,a,count;
  FILE *ptr,*fptr;
  ptr=fopen("Expcount.txt","a");
  for(i=2;i<=1000;i=i*2)
   {   
       a=2;
       count=0;
       printf("Maximum Value is->%lld\t", maximum(a,i,&count));
       printf("Count is->%lld\n",count);
       fprintf(ptr,"%lld\t%lld\n",i,count);
     
    }        
    return 0;
}
