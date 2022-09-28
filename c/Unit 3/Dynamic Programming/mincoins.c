#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int cc(int wt[],int w,int n)
{
	if(n==0)
	{
		return 100;
	}
	else if(w==0)
	{
		return 0;
	}
	else if(n==1)
	{
		if(w%wt[n-1]==0)
		{
			return w/wt[n-1];
		}
		else
		{
			return 100;
		}
	}
	else if(wt[n-1]<=w)
	{
		return min(1+cc(wt,w-wt[n-1],n),cc(wt,w,n-1));
	}
	else
	{
		return cc(wt,w,n-1);
	}
}
void main()
{
	int wt[10],n,i,w;
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the coin change you need ");
	scanf("%d",&w);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	int min;
	min=cc(wt,w,n);
	printf("min number of the coins %d ",min);
}
