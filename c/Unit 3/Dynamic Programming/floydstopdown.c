#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int a[10][10];
void addedge(int c,int b,int cos)
{
	a[c][b]=cos;
	a[b][c]=cos;
}
void main()
{
	int i,j,n;
	printf("enter the number of vertices");
	scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				a[i][j]=0;
			}
			else
			a[i][j]=50;
		}
		
	}
	int e,c,b,cos;
	printf("enter the number of edges");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		printf("enter the edges");
		scanf("%d%d",&c,&b);
		printf("enter the cost");
		scanf("%d",&cos);
		addedge(c,b,cos);
	}
	int k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				/*if(i==j)
				{
					a[i][j]=0;
				}
				else if(i==k||j==k)
				{
					a[i][j]=a[i][j];
				}
				else
				{*/
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
	}
	printf("\n");
}

