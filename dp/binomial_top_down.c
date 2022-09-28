#include<stdio.h>
int a[100][100];
int binomial(int n,int k)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i==j || j==0)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	return a[n][k];
}
int main()
{
	int n,k;
	printf("Enter the n value:");
	scanf("%d",&n);
	printf("Enter the k value:");
	scanf("%d",&k);
	printf("%d",binomial(n,k));
}
