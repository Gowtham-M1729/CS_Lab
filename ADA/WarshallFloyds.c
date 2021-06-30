#include<stdio.h>
int V;
void printSolution(int dist[][V]);
void floydWarshall (int graph[][V]){
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++){
        printf("D(%d):\n",k);
        printSolution(dist);
        for (i = 0; i < V; i++){ 
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printf ("D(%d):The following matrix shows the shortest distances between every pair of vertices \n",k);
    printSolution(dist);
}
void printSolution(int dist[][V])
{
    
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == 99)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
int main(){   
    int i,j;
    printf("Enter the no of vertices:\n");
    scanf("%d",&V);
    int graph[V][V];
    printf("Enter the weighted adj matrix,if no edge input 99 as weight:\n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    floydWarshall(graph);
    return 0;
}

