#include<stdio.h>
#include<stdlib.h>
int a[10][10];
int sum(int freq[],int i,int j )
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
	if(i>j)
	{
		return a[i][j]=0;
	}
	else if(i==j)
	{
		return a[i][j]=freq[i];
	}
	else if(a[i][j]!=-1)
	{
		return a[i][j];
	}
	int mincost=INT_MAX-1,cost,l;
	for(l=i;l<=j;l++)
	{
		cost=obst(freq,i,l-1)+obst(freq,l+1,j);
		if(cost<mincost)
		{
			mincost=cost;
		}
	}
	return a[i][j]=mincost+sum(freq,i,j);
}
void main()
{
	int i,j,freq[10],c,d;
	printf("enter the i value");
	scanf("%d",&i);
	printf("enter the j value");
	scanf("%d",&j);
	printf("enter the frequency values");
	for(c=0;c<=j;c++)
	{
		scanf("%d",&freq[c]);
	}
	for(c=0;c<=j;c++)
	{
		for(d=0;d<=j;d++)
		{
			a[c][d]=-1;
		}
	}
	int result=obst(freq,i,j);
	printf("result=%d",result);
}
