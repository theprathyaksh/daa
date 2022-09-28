#include<stdio.h>
#include<stdlib.h>
int knapsack(int wt[],int val[],int w,int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(w>=wt[i])
		{
			sum=sum+val[i];
			w=w-wt[i];
		}
		else
		{
			sum=sum+w*val[i]/wt[i];
			break;
		}
	}
	return sum;
}
void main()
{
	int wt[10],val[10],i,j,n,w,vlwt[10];
	printf("enter the n value");
	scanf("%d",&n);
	printf("enter the knpasck value");
	scanf("%d",&w);
	printf("enter the weight values");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("enter the values");
	for(i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	for(i=0;i<n;i++)
	{
		vlwt[i]=val[i]/wt[i];
	}
	printf("val by weight array");
	for(i=0;i<n;i++)
	{
		printf("%d ",vlwt[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(vlwt[j]<vlwt[j+1])
			{
				int temp=vlwt[j];
				vlwt[j]=vlwt[j+1];
				vlwt[j+1]=temp;
				int temp1=val[j];
				val[j]=val[j+1];
				val[j+1]=temp1;
				int temp2=wt[j];
				wt[j]=wt[j+1];
				wt[j+1]=temp2;
			}
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",wt[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",val[i]);
	}
	int maxcost=knapsack(wt,val,w,n);
	printf("maximum cost is %d",maxcost);
}
