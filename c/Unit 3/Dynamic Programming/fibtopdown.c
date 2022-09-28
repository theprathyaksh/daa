#include<stdio.h>
int a[10];
int fib(int n)
{
	int i;
	a[0]=0;
	a[1]=1;
	for(i=2;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a[n-1];
}
void main()
{
	int n;
	printf("enter the n value");
	scanf("%d",&n);
	printf("%d ",fib(n));
}
