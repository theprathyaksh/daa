#include<stdio.h>
int swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int sort(int s[],int d[],int w[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(w[j]>w[j+1])
			{
				swap(&w[j],&w[j+1]);
				swap(&s[j],&s[j+1]);
				swap(&d[j],&d[j+1]);
			}
		}
	}
}
int findparent(int i,int a[])
{
	while(a[i]!=-1)
	{
		i=a[i];
	}
	return i;
}
int krushkals(int s[],int d[],int w[],int n,int parent[])
{
	int i,j,l,k,sum=0;
	for(i=0;i<n;i++)
	{
		l=findparent(s[i],parent);
		k=findparent(d[i],parent);
		if(k!=l)
		{
			parent[k]=l;
			printf("%d->%d:%d\n",s[i],d[i],w[i]);
			sum+=w[i];
		}
	}
	
	return sum;

}
int main()
{
	int n,e,i;
	printf("enter no.of nodes:");
	scanf("%d",&n);
	printf("Enter no.of edges:");
	scanf("%d",&e);
	int s[e],d[e],w[e],parent[n];
	for(i=0;i<e;i++)
	{
		parent[i]=-1;
	}
	for(i=0;i<e;i++)
	{
		printf("Enter the source,destination,weight:");
		scanf("%d %d %d",&s[i],&d[i],&w[i]);
	}
	sort(s,d,w,e);
	printf("%d\n",krushkals(s,d,w,e,parent));
	for(i=0;i<n;i++)
	{
		printf("%d ",parent[i]);
	}
}
//6 8 0 1 3 0 2 5 1 3 4 1 4 2 2 3 4 2 4 3 3 5 5 4 5 6
/*
void swap(int i,int j,int a[])
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void sort(int n,int ar[],int s[],int d[])
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i;j<n;j++) if(ar[j]<ar[min]) min=j;
		swap(min,i,ar); 
		swap(min,i,s); 
		swap(min,i,d); 				
	}
}
*/
