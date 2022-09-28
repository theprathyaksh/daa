#include<stdio.h>
void heapify(int a[],int n,int i)
{
	int largest=i;
	int left=2*i+1,right=2*i+2;
	while(a[left]>a[largest]&&left<n)
	{
		largest=left;
	}
	while(a[right]>a[largest]&&right<n)
	{
		largest=right;
	}
	if(largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}
void heapsort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		int temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapify(a,i,0);
	}
}
void main()
{
	int n,a[10],i;
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	printf("after sorting");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
