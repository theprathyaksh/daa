#include<stdio.h>
int dp[10][10];
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int ks(int wt[],int val[],int w,int n)
{
	if(n==0)
	return dp[n][w]=0;
	else if(w==0)
	return dp[n][w]=0;
	else if(dp[n][w]!=-1)
	return dp[n][w];
	else if(wt[n-1]<=w)
	return dp[n][w]=max(val[n-1]+ks(wt,val,w-wt[n-1],n-1),ks(wt,val,w,n-1));
	else
	return dp[n][w]=ks(wt,val,w,n-1);
 return dp[n][w];
	
}
void main()
{
	int n,w,wt[10],val[10],i,j;
	printf("enter n value");
	scanf("%d",&n);
	printf("enter w value");
	scanf("%d",&w);
	printf("enter the weights");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("enter the profits");
	for(i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			dp[i][j]=-1;
		}
	}
	int m=ks(wt,val,w,n);
	printf("maximum profit is %d",m);
}
