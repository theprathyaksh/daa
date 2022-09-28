#include<stdio.h>
int a[100][100];
int binomial(int n,int k)
{
	if(k==0||n==k)
		return a[n][k]=1;
	if(a[n][k]!=-1)
		return a[n][k];
	else 
		return a[n][k]=binomial(n-1,k-1)+binomial(n-1,k);
}
int main()
{
	int n,k;
	printf("Enter the n value:");
	scanf("%d",&n);
	printf("Enter the k value:");
	scanf("%d",&k);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			a[i][j]=-1;
		}
	}
	printf("Binomial coeffecient is:%d",binomial(n,k));
}

