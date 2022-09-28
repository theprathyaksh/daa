#include<stdio.h>
#include<stdlib.h>
int dp[10][10];
int cc(int wt[],int w,int n)
{
	if(n==0)
	return dp[n][w]=0;
	else if(w==0)
	return dp[n][w]=1;
	else if(dp[n][w]!=-1)
	return dp[n][w];
	else if(wt[n-1]<=w)
	{
		return dp[n][w]=cc(wt,w-wt[n-1],n)+cc(wt,w,n-1);
	}
	else
	return dp[n][w]=cc(wt,w,n-1);
  return dp[n][w];
}
void main()
{
    int i,n,w,wt[10],j;
	printf("enter the n value");
	scanf("%d",&n);
	printf("enter the w value");
	scanf("%d",&w);
	printf("enter the weight values");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	int result=cc(wt,w,n);
	printf("total ways are %d ",result);
}
