#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

#define MAX 100
int i,n;
bool isBipartite(int  adj[][MAX], int v,
				bool visited[],int color[])
{
    
//printf("Hi....%d",i);
for(int i=0;i<n;i++)
{
  for(int j=0;j<n;j++)
    {
       printf("%d ",adj[i][j]);
    }
  printf("\n");
}
	for (int u=0;u<n;u++) {

		// if vertex u is not explored before
		if (visited[u] == false && adj[v][u] == 1) {

			// mark present vertic as visited
			visited[u] = true;

			// mark its color opposite to its parent
			color[u] = 1 - color[v];
            //printf("%d<--->%d\n",color[u],color[v]);
			// if the subtree rooted at vertex v is not bipartite
			if (!isBipartite(adj, u, visited, color))
				return false;
		}

		// if two adjacent are colored with same color then
		// the graph is not bipartite
		else if (adj[v][u] == 1 && color[u] == color[v] && u != v )
            {printf("dsfdf");
			return false;}
	}
	return true;
}

// Driver Code
int main()
{
	// no of nodes
	int max_edges,origin,destin;

	int adj[MAX][MAX]; 
    bool visited[MAX]; 
    int color[MAX];
   
	printf("\nEnter number of vertices : ");
        scanf("%d",&n);
        max_edges = n*(n-1)/2;

        for(i=1;i<=max_edges;i++)
        {
                printf("\nEnter edge %d( -1 -1 to quit ) : ",i);
                scanf("%d %d",&origin,&destin);

                if((origin == -1) && (destin == -1))
                        break;

                if( origin >= n || destin >= n || origin<0 || destin<0)
                {
                        printf("\nInvalid edge!\n");
                        i--;
                }
                else
                {
                        adj[origin][destin]=1;
                        adj[destin][origin]=1;
                }
        }
        
     memset(&color, 0, sizeof(*color) * (i+1));
    memset(&visited, false, sizeof(*visited) * (i+1));
	visited[0] = true;

	// marking the source node with a color
	color[0] = 0;

	// Function to check if the graph
	// is Bipartite or not
	if (isBipartite(adj, 0, visited, color)) {
		//cout << "Graph is Bipartite";
		printf("Graph is Biaprtite");
	}
	else {
	   printf("Graph is not bipartite");
		//cout << "Graph is not Bipartite";
	}

	return 0;
}
