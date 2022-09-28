#include<stdio.h>
#include<stdlib.h>
int sum(int freq[],int i,int j)
{
	int k,sum=0;
	for(k=i;k<=j;k++)
	{
	  sum=sum+freq[k];	
	}
	return sum;
}
int obst(int freq[],int i,int j)
{
	int l;
	if(i>j)
	{
		return 0;
	}
	else if(i==j)
	{
		return freq[i];
	}
	int mincost=INT_MAX,cost;
	for(l=i;l<=j;l++)
	{
		cost=obst(freq,i,l-1)+obst(freq,l+1,j);
		if(cost<mincost)
		{
			mincost=cost;
		}
	}
	return mincost+sum(freq,i,j);
}
void main()
{
	int i,j,freq[10],c;
	printf("enter the i value");
	scanf("%d",&i);
	printf("enter the j value");
	scanf("%d",&j);
	printf("Enter the frequency values");
	for(c=0;c<=j;c++)
	{
		scanf("%d",&freq[c]);
	}
	int result;
	result=obst(freq,i,j);
	printf("result=%d",result);
}
