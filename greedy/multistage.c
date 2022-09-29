#include<stdio.h>
#include<limits.h>
int main()
{
	int n,i,start,end,e,w,j;
	printf("Enter no.of vertices:");
	scanf("%d",&n);
	printf("Enter the no.of edges:");
	scanf("%d",&e);
	int a[n][n];
	int cost[n];
	cost[n-1]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			a[i][j]=-1;
	}
	for(i=0;i<e;i++)
	{
		printf("Enter the starting vertex:");
		scanf("%d",&start);
		printf("Enter the ending vertex:");
		scanf("%d",&end);
		printf("Enter the weight");
		scanf("%d",&w);
		a[start][end]=w;		
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	for(i=n-2;i>=0;i--)
	{
	int min,c;
		min=INT_MAX;
		for(j=i+1;j<n;j++)
		{
			if(a[i][j]!=-1)
			{
				c=a[i][j]+cost[j];
				if(c<min)
					min=c;
			}
		}
		cost[i]=min;
	}
	printf("%d",cost[0]);
}
//7 10 0 1 3 0 2 4 1 3 2 1 4 3 2 3 4 2 4 5 2 5 4 3 6 5 4 6 4 5 6 3
