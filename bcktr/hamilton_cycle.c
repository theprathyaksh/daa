#include<stdio.h>
int display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");
}
void fill_vertex(int k,int a[],int n,int adj[][n])
{
	do
	{
		a[k]=(a[k]+1)%(n+1);
		if(a[k]==0)
			return;
		if(adj[a[k-1]][a[k]]!=0)
		{
			int flag=0,j;
			for(j=0;j<k;j++)
			{
				if(a[j]==a[k])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				if(k<n-1 || k==n-1&&adj[a[k]][a[0]])
				{
					return;
				}
			}
		}
	}while(1);
}
void hamilton_cycle(int k,int a[],int n,int adj[n][n])
{
	while(3)
	{
		fill_vertex(k,a,n,adj);
		if(a[k]==0)
			return;
		if(k==n-1)
			display(a,n);
		else
			hamilton_cycle(k+1,a,n,adj);
		
	}
}


/*
0 1 1 0 1
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
1 1 0 1 0
*/
int main()
{
	int n,i,j;
	printf("enter the  number of nodes:");
	scanf("%d",&n);
	int adj[n][n],a[n];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adj[i][j]);
     	}
    }
	a[0]=1;
	
	hamilton_cycle(1,a,n,adj);
	return 0;
	
}
