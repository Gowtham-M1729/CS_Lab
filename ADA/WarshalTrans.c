#include<stdio.h> 
#define MAX 20
void display(int matrix[MAX][MAX],int n){
          int i,j;
          for(i=0;i<n;i++){
                   for(j=0;j<n;j++)
                             printf("%3d",matrix[i][j]);
                   printf("\n");
          }

}
void main(){
          int i,j,k,n;
          int A[MAX][MAX];
          printf("==================== WARSHALL'S ALGORITHM ===================\n");
          printf("\nEnter number of vertices : ");
          scanf("%d",&n);
          printf("\nEnter Adjacency matrix(Boolean matrix) :\n");
          for(i=0;i<n;i++)
             for(j=0;j<n;j++)
                   scanf("%d",&A[i][j]);
          for(k=0;k<n;k++)
          {
                   printf("\nR%d is :\n",k);
                   display(A,n);
                   for(i=0;i<n;i++)
                     for(j=0;j<n;j++)
                         A[i][j]=( A[i][j] || ( A[i][k] && A[k][j] ) );
          }
          printf("Path matrix R%d of the given graph is :\n",k);
          display(A,n);
}
