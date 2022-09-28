#include<stdio.h>
#include<limits.h>
int a[100][100];
int sum(int freq[],int i,int j)
{
	int sum=0;
	for(int k=i;k<=j;k++)
	{
		sum=sum+freq[k];
	}
	return sum;
}
int obst(int freq[],int i,int j)
{
	int min_cost=INT_MAX;
	if(i>j)
		return a[i][j]=0;
	if(a[i][j]!=-1)
		return a[i][j];
	else
	{
		if(i==j)
			return a[i][j]=freq[i];
		else
		{
			int l,cost;
			for(l=i;l<=j;l++)
			{
				cost=obst(freq,i,l-1)+obst(freq,l+1,j);
				if(cost<min_cost)
					min_cost=cost;
			}
		}
	}
	return a[i][j]=min_cost+sum(freq,i,j);
}
int main()
{
	int n;
	printf("Enter the n value:");
	scanf("%d",&n);
	int freq[n],key[n];
	printf("Enter the keys:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&key[i]);
	}
	//printf("Enter the frequencies of respect keys:");
	for(int i=0;i<n;i++)
	{
		printf("Enter the frequency of %d:",key[i]);
		scanf("%d",&freq[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=-1;
		}
	}
	printf("%d\n",obst(freq,0,n-1));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
