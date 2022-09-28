#include<stdio.h>
int a[10][10];
int bin(int n,int k)
{
	if(n==k||k==0)
	return a[n][k]=1;
	else if(a[n][k]!=-1)
	return a[n][k];
	else
	return a[n][k]=bin(n-1,k-1)+bin(n-1,k);
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
	printf("result =%d",result);
	
}
