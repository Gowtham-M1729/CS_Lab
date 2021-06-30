#include<stdio.h>
void DFS(int);
int G[10][10],visited[10],n,deadend[10],k=0;    
void main()
{
    int i,j;
    printf("Enter number of vertices:");

	scanf("%d",&n);
  printf("\nEnter adjecency matrix of the graph:");
for(i=0;i<n;i++)
   for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);

   for(i=0;i<n;i++)
        visited[i] = 0;
    DFS(0);

    printf("Deadends:");

    for(int i=0; i<n; ++i)
    {
        printf("%d ",deadend[i]);
    }
}

void DFS(int i)
{
    int j;
	printf("\n%d",i+1);
    visited[i]=1;
   for(j=0;j<n;j++)
    {       
        if(!visited[j]&&G[i][j]==1)
            DFS(j);
           
    }
 deadend[k++] = i+1;

//the code below is printing components of a disconnected graph
printf("disconnected matrix\n");
    for(j=0;j<n;j++)
        if(!visited[j])
            DFS(j);
}
