#include<stdio.h>
#include<limits.h>
int sum(int freq[],int i,int j)
{
	int sum=0,k;
	for(k=i;k<=j;k++)
	{
		sum=sum+freq[k];
	}
	return sum;
}
int obst(int freq[],int i,int j)
{
	int min_cost=INT_MAX;
	if(i>j)
		return 0;
	if(i==j)
		return freq[i];
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
	return min_cost+sum(freq,i,j);
}
int main()
{
	int n,i;
	printf("Enter the n value:");
	scanf("%d",&n);
	int freq[n],key[n];
	printf("Enter the keys:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&key[i]);
	}
	//printf("Enter the frequencies of respect keys:");
	for(i=0;i<n;i++)
	{
		printf("Enter the frequency of %d:",key[i]);
		scanf("%d",&freq[i]);
	}
	printf("%d",obst(freq,0,n-1));
}
