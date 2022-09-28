#include<stdio.h>
void quicksort(int a[],int l,int h)
{
	int i,j;
	if(l<h)
    {
    int piviot=l;
	i=l;
	j=h;
	while(i<j)
	{
		while(a[i]<=a[piviot]&&i<h)
		i++;
		while(a[j]>a[piviot])
		j--;
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
   int temp=a[piviot];
   a[piviot]=a[j];
   a[j]=temp;
   quicksort(a,l,j-1);
   quicksort(a,j+1,h);
}
}
void main()
{
	int i,n,a[10];
	printf("enter the array size");
	scanf("%d",&n);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
