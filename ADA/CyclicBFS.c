#include<stdio.h>
#include<stdlib.h>
int a[20][20],q[20],visited[20],n,i,j,f=1,r=0;
void bfs(int v)
{
   for(i=1;i<=n;i++){
   if(a[v][i]==1 && visited[i]!=1){
      q[++r]=i;
      visited[q[r]]++;
     if(visited[i]==1){
           printf("Graph is cyclic%d %d\n",v,i);
           //exit(0);
       }
      }
   }
   visited[v]=1;
   while(f<=r)
   {
      bfs(q[++f]);
   }
}
void main(){
      int v;
      printf("Enter the no of vertices\n");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
         q[i]=0;
         visited[i]=-1;
      }
      printf("\n Enter undirected graph data in matrix form:\n");
      for(i=1;i<=n;i++)
         for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      printf("\n Enter the starting vertex:");
      scanf("%d",&v);
      visited[v]++;
      q[++r]=v;
      bfs(v);
      printf("Graph is acyclic");
            
}
