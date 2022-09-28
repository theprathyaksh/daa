#include<stdio.h>
int dp[10];
int fib(int n)
{
	if(n==0)
	return dp[n]=0;
	else if(n==1)
	return dp[n]=1;
	else
	return dp[n]=fib(n-1)+fib(n-2);
  return dp[n];
}
void main()
{
	int n;
	printf("enter n");
	scanf("%d",&n);
	printf("result is %d",fib(n));
}
