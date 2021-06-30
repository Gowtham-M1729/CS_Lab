#include <stdio.h>

int a[20][20], reach[20], n,counts=1,i;
int flag=0;
void dfs(int v)
{
	int i;
	reach[v] = 1;
	printf(" %d ", v);
	for (i = 1; i <= n; i++)
		if (a[v][i] && !reach[i])
		{
			dfs(i);
		}
    printf("\n");
}
int count()
{
  if(counts==n || i==n )
    {
       return 0;
    }
  for (i = counts; i <= n; i++)
	{
		if (reach[i])
			counts++;
	    else
	    {
            flag=1;
            dfs(i);
        }
       count();
    }
}

void main()
{
	int i, j;

	printf("\n Enter number of vertices:");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		reach[i] = 0;
		for (j = 1; j <= n; j++)
			a[i][j] = 0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

    printf("Connected Components : ");
	dfs(1);
    count();
	printf("\n");
	if (counts-1 == n && flag==0)
		printf("\n Graph is connected");
	else
	{
		printf("\n Graph is not connected");
	}	
}
