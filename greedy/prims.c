#include<stdio.h>
#include<limits.h>
int findnode(int dist[],int visit[],int n)
{
	int min=INT_MAX;
	int i,k;
	for(i=0;i<n;i++)
	{
		if(visit[i]==0 && dist[i]<=min){
			min=dist[i];
			k=i;}
	}
	return k;
}
int prims(int n,int dist[],int visit[],int parent[],int a[][n])
{
	int k,i,j;	
	for(i=0;i<n;i++)
	{
		k=findnode(dist,visit,n);
		printf("%d",k);
		visit[k]=1;
		for(j=0;j<n;j++)
		{
			if(a[k][j]!=INT_MAX && visit[j]!=1)
			{
				if(dist[j]>a[k][j])
				{
					dist[j]=a[k][j];
					parent[j]=k;
				}
			} 
		}	
	}
}
int main()
{
	int n,e,i,j,start,end,w;
	printf("Enter the no.of vertices:");
	scanf("%d",&n);
	printf("Enter the no.of edges:");
	scanf("%d",&e);
	int a[n][n];
	int dist[n];
	int visit[n];
	int parent[n];
	for(i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
	}
	for(i=0;i<n;i++)
	{
		parent[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		visit[i]=0;
	}
	dist[0]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			a[i][j]=INT_MAX;
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d ",dist[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",visit[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",parent[i]);
	}*/
	for(i=0;i<e;i++)
	{
		printf("Enter the starting vertex:");
		scanf("%d",&start);
		printf("Enter the ending vertex:");
		scanf("%d",&end);
		printf("Enter the weight:");
		scanf("%d",&w);
		a[start][end]=a[end][start]=w;		
	}
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d	",a[i][j]);
		printf("\n");
	}*/
	prims(n,dist,visit,parent,a);
	int sum=0;
	/*for(i=0;i<n;i++)
	{
		printf("%d ",dist[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",visit[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",parent[i]);
	}*/
	for(i=0;i<n;i++)
	{
		sum+=dist[i];
	}
	printf("\n%d",sum);
}
//6 8 0 1 3 0 2 3 1 3 4 1 4 6 2 3 3 2 4 2 3 5 4 4 5 5
