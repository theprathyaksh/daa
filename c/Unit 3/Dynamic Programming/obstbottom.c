#include<stdio.h>
#include<stdlib.h>
int dp[10][10];
int sum(int fre[],int i,int j)
{
	int k,sum=0;
	for(k=i;k<=j;k++)
	{
		sum=sum+fre[k];
	}
	return sum;
}
int obst(int fre[],int i,int j)
{
	int l;
	if(i>j)
	return dp[i][j]=0;
	if(i==j)
	return dp[i][j]=fre[i];
	if(dp[i][j]!=-1)
	return dp[i][j];
	int min=INT_MAX,cost;
	for(l=i;l<=j;l++)
	{
		cost=obst(fre,i,l-1)+obst(fre,l+1,j);
		if(cost<min)
		{
			min=cost;
		}
	}
	return dp[i][j]=min+sum(fre,i,j);
}
void main()
{
	int i,j,fre[10],k,m;
	printf("enter the i value");
	scanf("%d",&i);
	printf("enter the j value");
	scanf("%d",&j);
	printf("enter the frequency values");
	for(k=0;k<j;k++)
	{
		scanf("%d",&fre[k]);
	}
	for(k=0;k<=j;k++)
	{
		for(m=0;m<=j;m++)
		{
			dp[k][m]=-1;
		}
	}
	int res=obst(fre,i,j);
	printf("result =%d",res);
}
