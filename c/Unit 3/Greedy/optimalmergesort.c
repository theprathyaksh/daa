#include<stdio.h>
void heapify(int a[],int n,int i)
{
	int largest=i;
	int left=2*i+1,right=2*i+2;
	while(a[left]<a[largest]&&left<n)
	{
		largest=left;
	}
	while(a[right]<a[largest]&&right<n)
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
    for(i=0;i<n;i++)
   {
       printf("%d ",a[i]);
   }
    int sum=0,count=0,maxsum=0;
	for(i=n-1;i>=0;i--)
	{
		int temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		sum=sum+a[i];
		count++;
		if(count==2)
		{
			maxsum=maxsum+sum;
			//printf("maxsum=%d\tsum=%d",maxsum,sum);
			count=0;
			a[i]=sum;
			sum=0;
			i++;
		}
		heapify(a,i,0);
	}
	printf("maxsum %d",maxsum);
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
}
