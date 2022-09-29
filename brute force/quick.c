#include<stdio.h>
int n;
int partition(int a[],int l,int h)
{
	int pivot=l;
	int s=l,e=h;
	int temp;
	while(a[s]<=a[pivot])
	{
		s++;
	}
	while(a[e]>a[pivot])
	{
		e--;
	}
	if(s<e)
	{
		temp=a[s];
		a[s]=a[e];
		a[e]=temp;
	}
	temp=a[l];
	a[l]=a[e];
	a[e]=temp;
	return e;
}
void quicksort(int a[],int l,int h)
{
	int p;
	if(l<h)
	{
		p=partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
	}
}
int main()
{
	printf("Enter the size of array:");
	scanf("%d",&n);
	int a[n],i;
	printf("Enter the elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("array after sort:");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
