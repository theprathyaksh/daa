#include<stdio.h>
#include<stdlib.h>
int a[10][10];
int cc(int wt[],int w,int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0)
			a[i][j]=0;
			else if(j==0)
			a[i][j]=1;
			else if(wt[i-1]<=j)
			a[i][j]=a[i][j-wt[i-1]]+a[i-1][j];
			else
			a[i][j]=a[i-1][j];
		}
	}
	return a[n][w];
}
void main()
{
    int i,n,w,wt[10];
	printf("enter the n value");
	scanf("%d",&n);
	printf("enter the w value");
	scanf("%d",&w);
	printf("enter the weight values");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	int result=cc(wt,w,n);
	printf("total ways are %d ",result);
}
