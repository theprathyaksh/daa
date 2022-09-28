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
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else if(wt[i-1]<=j)
			dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][w];
}
void main()
{
	int w,n,val[10],wt[10],i,j;
	printf("enter n");
	scanf("%d",&n);
	printf("enter w");
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
	int result=ks(wt,val,w,n);
	printf("maximum profit is %d",result);
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=w;j++)
		{
			printf("%d",dp[i][j]);
		}
	}
}
