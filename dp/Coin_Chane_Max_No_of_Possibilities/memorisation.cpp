#include<stdio.h>

int a[100][100];
int CC(int,int,int[100]);
int main()
{
	int i,j,n,w,wt[100];
	printf("Enter the no of coins:");
	scanf("%d",&n);
	printf("Enter the weight:");
	scanf("%d",&w);
	printf("Enter the weights :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			a[i][j]=-1;
		}
	}
	printf("%d",CC(n,w,wt));
	return 0;
}
int CC(int n,int w,int wt[100])
{
	if(n==0)
		return a[n][w]=0;
	if(w==0)
		return a[n][w]=1;
	if(a[n][w]!=-1)
		return a[n][w];
	else if(wt[n-1]<=w)
		return a[n][w]=CC(n,w-wt[n-1],wt)+CC(n-1,w,wt);
	else
		return a[n][w]=CC(n-1,w,wt);
}

