#include<stdio.h>
int a[100][100];
int cc(int ,int ,int []);
int min(int a,int b){
	if (a<b)return a;
	else return b;
}
int main()
{
	int i,j,n,w,wt[100];
	printf("Enter the no of coins:");
	scanf("%d",&n);
	printf("Enter the weight :");
	scanf("%d",&w);
	printf("Enter the weights");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("\nanswer is %d",cc(n,w,wt));
}
int cc(int n,int w,int wt[100]){
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0)
			{
				 a[i][j]=1000;
		
			}
			else if(j==0)
			   a[i][j]=0;
			else if(wt[i-1]<=j){
				
				a[i][j]=min(1+a[i][j-wt[i-1]],a[i-1][j]);
			}
			else 
			   a[i][j]=a[i-1][j];
		}
		
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return a[n][w];
}
