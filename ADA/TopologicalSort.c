#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 4;
    /*int adjacency_matrix[][4] = {
        {0, 1, 1, 0},  
        {0, 0, 0, 1},   
        {0, 0, 0, 1}, 
        {1, 0, 0, 0}    
    };*/
    int adjacency_matrix[10][10];
    printf("Enter the Number of Vertices\n");
    scanf("%d",&n);
    printf("Enter the Matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&adjacency_matrix[i][j]);
        }
    }
    int indegrees[n];
    bool visited[n];
    memset(&indegrees, 0, sizeof(*indegrees) * n);
    memset(&visited, false, sizeof(*visited) * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            indegrees[i] += adjacency_matrix[j][i];
        }
    }
    printf("Topological Sort Will be\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!indegrees[j] && !visited[j]) {
                visited[j] = true;
                printf("%d ", j + 1);

                for (int k = 0; k < n; k++) {
                    if (adjacency_matrix[j][k]) {
                        adjacency_matrix[j][k] = 0;
                        indegrees[k]--;
                    }
                }

                break;
            }
        }
    }

    return 0;
}
