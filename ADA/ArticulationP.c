#include<stdio.h>
#include<stdbool.h>
int G[10][10];
 void DFS(int n,bool visited[],int i)
 {
     int j;
     visited[i]=true;

     for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
             DFS(n,visited,j);
 }
int totalArticulation_points(int V)
{int count = 0;
 bool visited[V];
 int copy[V];
 int i,j;
 for(i=0;i<V;i++){
    visited[i] = false;
 }
int initial_val = 0;
for(i=0;i<V;i++)
{
    if(visited[i] == false){
        DFS(V,visited, i);
        initial_val = initial_val+1;
        }
}
for(i=0;i<V;i++)
{for(j = 0;j<V;j++){
            visited[j] = false;
            copy[j] = G[i][j];
            G[i][j]=G[j][i]=0;
                   }
        int nval = 0;
        for(j=0;j<V;j++){
            if(visited[j] == false && j != i){
                nval = nval + 1;
                DFS(V, visited, j);
            }
        }
        if(nval > initial_val)
            count = count + 1;
        for(j=0;j<V;j++)
            G[i][j] = G[j][i] = copy[j];
}
return count;
}

void main()
 {
     int i,j,n;
     printf("Enter number of vertices:");

     scanf("%d",&n);
     printf("\nEnter adjecency matrix of the graph:");

     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
             scanf("%d",&G[i][j]);

      int x=totalArticulation_points(n);
      printf("total articulation point: %d",x);
 }
