#include<stdio.h>
#include<stdlib.h>
int a[10][10];
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int cc(int wt[],int w,int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0)
			{
				a[i][j]=100;
			}
			else if(j==0)
			a[i][j]=0;
			else if(i==1)
			{
				   if(j%wt[i-1]==0)
				   {
				   	a[i][j]=j/wt[i-1];
				   }
				   else
				   {
				   	a[i][j]=100;
				   }
			}
			else if(wt[i-1]<=j)
			{
				a[i][j]=min(1+a[i-1][j-wt[i-1]],a[i-1][j]);
			}
			else
			{
				a[i][j]=a[i-1,j];
			}
		}
	}
	return a[i][j];
}
void main()
{
	int wt[10],i,j,n,w;
	printf("enter the n value");
	scanf("%d",&n);
	printf("enter the w value");
	scanf("%d",&w);
	printf("enter the array elemnts");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	int min=cc(wt,w,n);
	printf("min number of coins %d",min);
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=w;j++)
		{
			printf("%d ",a[i][j]);
		}
	}
	
}

