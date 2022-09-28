#include<stdio.h>
int a[10][10];
int bin(int n,int k)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(i==j||j==0)
			a[i][j]=1;
			else
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	return a[n][k];
	
}
void main()
{
	int n,k,i,j;
	printf("enter n and k value");
	scanf("%d%d",&n,&k);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			a[i][j]=-1;
		}
	}
	int result=bin(n,k);
	printf("result =%d\n",result);
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=k;j++)
		{
			printf("%d\t",a[i][j]);
		}
	}
	
}
