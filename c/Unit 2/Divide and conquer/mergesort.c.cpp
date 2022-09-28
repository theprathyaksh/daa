#include<stdio.h>
void merge(int a[],int l,int mid,int h)
{
	int i,j,k,b[10];
	i=l;
	j=mid+1;
	k=0;
	while(i<=mid&&j<=h)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			k++;
			i++;
		}
		else
		{
			b[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
	     b[k]=a[i];
	     k++;
	     i++;
	}
	while(j<=h)
	{
		b[k]=a[j];
		k++;
		j++;
	}
	 for(i=l,j=0;i<=h;i++,j++)
   {
        a[i]=b[j];
   }
}
void mergesort(int a[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}
int main()
{
	int i,n,a[10];
	printf("enter the array size");
	scanf("%d",&n);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
