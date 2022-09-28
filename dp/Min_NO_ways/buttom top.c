#include<stdio.h>
int a[100][100];
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int CC(int,int,int[]);
int main()
{
	int i,j,n,w,wt[100];
	printf("Enter the no of coins:");
	scanf("%d",&n);
	printf("Enter the weight :");
	scanf("%d",&w);
	printf("Enter the weights");
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
}
int CC(int n,int w,int wt[100])
{
	if(n==0)
		return a[n][w]=12356;
	if(w==0)
		return a[n][w]=0;
	if(a[n][w]!=-1)
	{
		return a[n][w];
	}
	if(wt[n-1]<=w)
		return a[n][w]=min(1+CC(n,w-wt[n-1],wt),CC(n-1,w,wt));
	else
		return a[n][w]=CC(n-1,w,wt);
}
