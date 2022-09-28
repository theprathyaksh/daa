#include<stdio.h>
int fib(n)
{
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else
	return fib(n-1)+fib(n-2);
}
void main()
{
	int n;
	printf("enter the n value");
	scanf("%d",&n);
	int result=fib(n);
	printf("result =%d",result);
}

