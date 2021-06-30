#include<stdio.h>
int w[10],v[10],a[10][10],n,i,j,cap,x[10]= {0};
int max(int i,int j) {
	return ((i>j)?i:j);
}
int knapsack() {
	int i,j;
	for(i=1;i<=cap;i++){
	   for(j=1;j<=cap;j++){
		if(j<w[i])
		   a[i][j]=a[i-1][j]; 
		else
		   a[i][j]=max(a[i-1][j],v[i]+a[i-1][j-w[i]]);
	  }
	}
	return(a[cap][cap]);
}
void main(){
	int value,count=0;
	printf("\nEnter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the value and weights of the elements:\n");
	for (i=1;i<=n;i++) {
		printf("For item no %d\n",i);
		scanf("%d%d",&v[i],&w[i]);
	}
	printf("\nEnter the capacity :\n");
	scanf("%d",&cap);
	for (i=0;i<=n;i++)
	  for (j=0;j<=cap;j++)
	   if((i==0)||(j==0))
	    a[i][j]=0; 
	value=knapsack();
	i=n;
	j=cap;
	while(j!=0&&i!=0) {
		if(a[i][j]!=a[i-1][j]) {
			x[i]=1;
			j=j-w[i];
			i--;
		} else
		   i--;
	}
	printf("Items included are:\n");
	printf("Sl.no\tweight\tvalue\n");
	for (i=1;i<=n;i++)
	  if(x[i])
	   printf("%d\t%d\t%d\n",++count,w[i],v[i]);
	printf("Total value = %d\n",value);
	printf("Knapsack optimized solution:\n<");
	for(int i=1;i<=n;i++){
	    printf("%d ",x[i]);
	}
	printf("\b>");
	for (i=0;i<=n;i++)
	{
	  for (j=0;j<=cap;j++)
	  { printf("%d ",a[i][j]);
	  }
	  printf("\n");
	  }
	       
}
