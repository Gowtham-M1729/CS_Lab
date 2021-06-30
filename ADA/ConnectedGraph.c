#include <stdio.h>

int a[20][20], reach[20], n,count = 1;
void dfs(int v)
{
	//count++;
	int i;
	reach[v] = 1;
	if(v != 0){printf("%d ",v);}
	
	for (i = 1; i <= n; i++)
		if (a[v][i] && !reach[i])
		{
			//printf("\n %d->%d", v, i);
			dfs(i);
		}

	printf("kk\n\n");
	count++;
    for(int j=0;j<n;j++)
        if(!reach[j])
			{//count = 0;
            dfs(j);}
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
	dfs(1);
	printf("\n");
	/*for (i = 1; i <= n; i++)
	{
		if (reach[i])
			count++;
	}*/
	printf("%d ",count);
	if (count == 1)
	{
		printf("%d ",count);
		printf("\n Graph is connected");
	}		
	else if(count > 1)
	{
		printf("e%d ",count);
		printf("\n Graph is not connected");
	}
		
}
