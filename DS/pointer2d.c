#include<stdio.h> 
int main() 
{ int a[100][100],i,j,n;
  char *p="hvjgv";
  printf("%d\n",*p);
  scanf("%d",&n);
for(i=0;i<n;i++)
   { for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
   }
for(i=0;i<n;i++)
   { for(j=0;j<n;j++)
        printf("%d-%p\n",*(*(a+i)+j),((*(a+i)+j)));
   }
 return 0; 
} 

