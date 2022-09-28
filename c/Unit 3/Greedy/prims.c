#include <stdio.h>
#include <stdlib.h>
int adj[10][10];
int findminnode(int dis[], int vis[], int n)
{
	int min, index, i;
	min = INT_MAX;
	for (i = 0; i < n; i++)
	{
		if (vis[i] == 0 && dis[i] < min)
		{
			min = dis[i];
			index = i;
		}
	}
	return index;
}
void prims(int adj[][10], int n, int dis[], int vis[], int par[])
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		k = findminnode(dis, vis, n);
		vis[k] = 1;
		for (j = 0; j < n; j++)
		{
			if (adj[k][j] != INT_MAX && vis[j] != 1)
			{
				if (dis[j] > adj[k][j])
				{
					dis[j] = adj[k][j];
					par[j] = k;
				}
			}
		}
	}
}
void addedge(int a, int b, int cost)
{
	adj[a][b] = cost;
	adj[b][a] = cost;
}
void main()
{
	int n, dis[10], vis[10], par[10], i, j;
	printf("enter the number of vertices");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			adj[i][j] = 50;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			dis[i] = 0;
		}
		dis[i] = 50;
	}
	for (i = 0; i < n; i++)
	{
		vis[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		par[i] = -1;
	}
	int a, b, e, cost;
	printf("enter the number of edges  ");
	scanf("%d", &e);
	for (i = 0; i < e; i++)
	{
		printf("enter the edges ");
		scanf("%d%d", &a, &b);
		printf("enter the cost");
		scanf("%d", &cost);
		addedge(a, b, cost);
	}
	/*printf("graph representaion by adjacency matrix ");
	for(i=0;i<n;i++)
	{
	   printf("\n");
	   for(j=0;j<n;j++)
	   {
			printf("%d ",adj[i][j]);
	   }
   }*/
	printf("\n");
	prims(adj, n, dis, vis, par);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", par[i]);
	}
	printf("\n");
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		if (dis[i] == 50)
			continue;
		else
			sum = sum + dis[i];
	}
	printf("minimum sum is %d", sum + 1);
}
