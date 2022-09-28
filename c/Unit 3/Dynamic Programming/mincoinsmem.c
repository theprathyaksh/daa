#include<stdio.h>
#include<stdlib.h>
int dp[10][10];
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int cc(int wt[],int w,int n)
{
	if(n==0)
	{
		return dp[n][w]=100;
	}
	if(w==0)
	{
		return dp[n][w]=0;
	}
	if(dp[n][w]!=-1)
	{
		return dp[n][w];
	}
	if(n==1)
	{
		if(w%wt[n-1]==0)
		{
			return dp[n][w]=w/wt[n-1];
		}
		else
		{
			return dp[n][w]=100;
		}
	}
	else if(wt[n-1]<=w)
	{
		return dp[n][w]=min(1+cc(wt,w-wt[n-1],n),cc(wt,w,n-1));
	}
	else
	{
		return dp[n][w]=cc(wt,w,n-1);
	}
}
void main()
{
	int wt[10],n,i,w,j;
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the coin change you need ");
	scanf("%d",&w);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0)
			dp[i][j]=100;
			else
			dp[i][j]=-1;
		}
	}
	int m;
	m=cc(wt,w,n);
	printf("min number of the coins %d ",m);
}
