#include<stdio.h>
int binomial(int n,int k)
{
	if(k==0||n==k)
		return 1;
	else 
		return binomial(n-1,k-1)+binomial(n-1,k);
}
int main()
{
	int n,k;
	printf("Enter the n value:");
	scanf("%d",&n);
	printf("Enter the k value:");
	scanf("%d",&k);
	printf("Binomial coeffecient is:%d",binomial(n,k));
}

