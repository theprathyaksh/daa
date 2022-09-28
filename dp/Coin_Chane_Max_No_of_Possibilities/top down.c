#include<stdio.h>

int main()
{
	int i,j,n,w,wt[100],a[100][100];
	printf("Enter the no of coins:");
	scanf("%d",&n);
	printf("Enter the Weight:");
	scanf("%d",&w);
	printf("Enter weight of the coins");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0)
				a[i][j]=0;
			else if(j==0)
				a[i][j]=1;
			else if(wt[i-1]<=j)
			{
				a[i][j]=a[i][j-wt[i-1]]+a[i-1][j];
			}
			else{
				a[i][j]=a[i-1][j];
			}
		}
	}
	printf("\n%d",a[n][w]);
}
