#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int i,j,d;
	int x[10],y[10],n;
	printf("enter the array size");
	scanf("%d",&n);
	printf("array elements");
	for(i=0;i<n;i++)
	{
	 	scanf("%d%d",&x[i],&y[i]);
	}
	int midst=INT_MAX;
	int index1;
	int index2;
	for(i=0;i<n;i++)
	{
	 	for(j=i+1;j<n;j++)
	 	{
	 	 	d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	 	 	if(midst>d)
	 	 	{
	 	 		midst=d;
	 	 		index1=i;
	 	 		index2=j;
			}
		}
	}
	printf("closest distance %d \n",midst);
	printf("coordinates are %d %d and %d %d",x[index1],y[index1],x[index2],y[index2]);
}
