#include<stdio.h>

int CC(int n,int w,int wt[100])
{
	if(n==0)
	{
		return 0;
	}
	if(w==0)
	{
		return 1;
	}
	if(wt[n-1]<=w)
	{	
		return CC(n,w-wt[n-1],wt)+CC(n-1,w,wt);
	}
	else
	{
		return CC(n-1,w,wt);
	}
}
int main()
{
	int n,w,wt[100],i;
	printf("Enter the n of coins:");
	scanf("%d",&n);
	printf("Enter the weight :");
	scanf("%d",&w);
	printf("Enter the weights:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("\nways:%d",CC(n,w,wt));
	
}
