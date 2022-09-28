#include<stdio.h>
#include<stdlib.h>
int cc(int wt[],int w,int n)
{
	if(n==0)
	return 0;
	else if(w==0)
	return 1;
	else if(wt[n-1]<=w)
	{
		return cc(wt,w-wt[n-1],n)+cc(wt,w,n-1);
	}
	else
	return cc(wt,w,n-1);
}
void main()
{
    int i,n,w,wt[10];
	printf("enter the n value");
	scanf("%d",&n);
	printf("enter the w value");
	scanf("%d",&w);
	printf("enter the weight values");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	int result=cc(wt,w,n);
	printf("total ways are %d ",result);
}
