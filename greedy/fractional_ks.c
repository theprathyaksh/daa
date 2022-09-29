#include<stdio.h>
int ks(float wt[],float val[],float w,int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(w>wt[i])
		{
			sum=sum+val[i];
			w=w-wt[i];
		}
		else
		{
			sum=sum+((w*val[i])/wt[i]);
			break;
		}
	}
	return sum;
}
int main()
{
	int n,i,j;
	float w;
	printf("Enter the array size:");
	scanf("%d",&n);
	printf("Enter the weight of knapsack:");
	scanf("%f",&w);
	float val[n],wt[n];
	printf("Enter the value array:");
	for(i=0;i<n;i++)
		scanf("%f",&val[i]);
	printf("Enter the weight array:");
	for(i=0;i<n;i++)
		scanf("%f",&wt[i]);
	float x,y,temp,temp1;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			x=val[j]/wt[j];
			y=val[j+1]/wt[j+1];
			if(x<y)
			{
				temp=val[j+1];
				temp1=wt[j+1];
				val[j+1]=val[j];
				val[j]=temp;
				wt[j+1]=wt[j];
				wt[j]=temp1;
			}
		}
	}
	/*for(i=0;i<n;i++)
		printf("%.1f ",val[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%.1f ",wt[i]);*/
	printf("%d",ks(wt,val,w,n));
}
