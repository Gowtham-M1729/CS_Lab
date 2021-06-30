#include<stdio.h> 
#include<stdlib.h>
int main() 
{ int i,n,j;
  scanf("%d",&n);
  int b[]={1,2,3,4};
  int *k;
  k=b;
  int *l;
  l=&b[0];
  printf("----%d-%d %p %p\n",*l,*k,l,k);
  int *p=malloc(n*(sizeof(int)));;
  int *a = malloc(n*(sizeof(int)));
  printf("True %p-%p %ld\n",p,a,sizeof(*a));
for(i=0;i<n;i++)
   { 
     scanf("%d",(p+i));
     
   }
for(i=0;i<n;i++)
   { 
     scanf("%d",(a+i));
     
   }
while(i>0)
 { if(*p!=*a)
     { printf("Not equal");
       exit(0);
     }
   printf("True %d-%d\n",*p,*a);
   p++;
   a++;
   i--;
 }
 printf("True %d-%p\n",*p+n,p+n);	
 return 0; 
} 

