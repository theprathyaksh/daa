#include<stdio.h>
int bin(int n,int k)
{
	if(n==k||k==0)
	return 1;
	else
	return bin(n-1,k-1)+bin(n-1,k);
}
void main()
{
	int n,k;
	printf("enter the n value");
	scanf("%d",&n);
	printf("enter the k value");
	scanf("%d",&k);
	int result=bin(n,k);
	printf("result is %d",result);
}
