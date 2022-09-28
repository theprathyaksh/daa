#include<stdio.h>
#include<stdlib.h>
struct points
{
	int x,y;
}ar[10];
int main()
{
	int n,i;
	printf("enter the number of points");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter the x ");
	scanf("%d",&ar[i].x);
	printf("enter the y ");
	scanf("%d",&ar[i].y);
	}
     int a,b,c,j,k,nn,np,l;
    for(i=0;i<n-1;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		a=ar[i].y-ar[j].y;
    		b=ar[j].x-ar[i].x;
    		c=ar[j].y*ar[i].x-ar[i].y*ar[j].x;
    		np=0;
			nn=0;
    		for(k=0;k<n;k++)
    		{
    			l=ar[k].x*a+ar[k].y*b+c;
    			if(l>0)
    			{
    				np++;
				}
				else if(l<0)
				{
					nn++;
				}
				
			}
		    if(np==0||nn==0)
		    {
			printf("%d %d and %d %d are convexhall points\n",ar[i].x,ar[i].y,ar[j].x,ar[j].y);
		    }
}
}
    return 0;
}
