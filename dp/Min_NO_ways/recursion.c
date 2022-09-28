#include<stdio.h>
int CC(int,int,int []);
int min(int a,int b)
{
	if(a<b)
		return a;
	else 
		return b;
}
int main()
{
	int n,w,i,wt[100];
	printf("Enter the n:");
	scanf("%d",&n);
	printf("Enter weight:");
	scanf("%d",&w);
	printf("Enter the weights of coins :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("Min :%d",CC(n,w,wt));
}
int CC(int n,int w,int wt[100])
{
	if(n==0)
		return 12345;
	if(w==0)
		return 0;
	if(wt[n-1]<=w)
		return min(1+CC(n,w-wt[n-1],wt),CC(n-1,w,wt));
	else 
		return CC(n-1,w,wt);
 } 
