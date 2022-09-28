#include<stdio.h>
int a[10][10];
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
			a[i][j]=0;
			else if(wt[i-1]<=j)
			a[i][j]=max(val[i-1]+a[i-1][j-wt[i-1]],a[i-1][j]);
			else
			a[i][j]=a[i-1][j];
		}
	}
	return a[n][w];
}
void main()
{
	int n,w,val[10],wt[10],i,j;
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
	printf("result=%d",result);
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=w;j++)
		{
			printf("%d ",a[i][j]);
		}
	}
}
