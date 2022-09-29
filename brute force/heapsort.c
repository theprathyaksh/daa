#include<stdio.h>
void swap(int a[],int i,int j)
{
	int temp;
	temp=a[j];
	a[j]=a[i];
	a[i]=temp;
}
void heapify(int a[],int n,int i)
{
	int l,r;
	l=(2*i)+1;
	r=(2*i)+2;
	int min=-1;
	if(r<n)
	{
		if(a[l]>a[r])
		{
			min=l;
		}
		else
		{
			min=r;
		}
	}
	else if(l<n)
	{
		min=l;
	}
	if(min!=-1 && a[i]<a[min])
	{
		swap(a,i,min);
		heapify(a,n,min);
	}
}
void heap(int a[],int n)
{
	int i;
	for(i=(n/2);i>=0;i--)
	{
		heapify(a,n,i);
	}
}
void heapsort(int a[],int n)
{
	int i;
	for(i=n;i>0;i--)
	{
		heap(a,i);
		swap(a,0,i-1);
	}
}
int main()
{
	int n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int a[n],i;
	printf("Enter the elements to sort:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
