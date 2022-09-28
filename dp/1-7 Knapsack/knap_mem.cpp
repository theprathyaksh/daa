#include <stdio.h>
#include <stdlib.h>
int a[100][100];
int max(int x,int y){
	if(x>y)
	{
		return x;
	}
	else
		return y;
}
int ks(int wt[],int val[],int n,int w)
{
	
	int x,y;
	if(n==0||w==0)
	{
		return a[n][w] = 0;
	}
	else if(a[n][w]!=-1)
		return a[n][w];
	
	else if(wt[n-1]<=w)
	{
		x=val[n-1]+ks(wt,val,n-1,w-wt[n-1]);
		y=ks(wt,val,n-1,w);
		return a[n][w] = max(x,y);
	}
	else 
	{
		return a[n][w]=ks(wt,val,n-1,w);
	}
	
}
int main()
{
	int n,w,i,j;
	printf("Enter the no of items:");
	scanf("%d",&n);
	printf("Enter the weight of Knapsack:");
	scanf("%d",&w);
	printf("Enter the weight of knapsack:\n");
	int wt[n],val[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("Enter the value of knapsack:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			a[i][j] = -1;
		}
	}
	int max;
	ks(wt,val,n,w);
	printf("MAX PROFIT IS: %d",a[n][w]);
}
