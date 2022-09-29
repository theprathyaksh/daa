#include<stdio.h>
struct point
{
	int x;
	int y;
};
struct point p[100];
int main()
{
	int n,i,j,k,l,np=0,nn=0,a,b,c;
	printf("Enter the number of points:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			a=p[i].y-p[j].y;
			b=p[j].x-p[i].x;
			c=(p[j].y*p[i].x)-(p[i].y*p[j].x);
			np=0;
			nn=0;
			for(k=0;k<n;k++)
			{
				l=(a*p[k].x)+(b*p[k].y)+c;
				if(l>0)
					np++;
				else if(l<0)
					nn++;
			}
			if(np==0 || nn==0)
			{
				printf("\nco ordinates that form covexhull edge:(%d,%d),(%d,%d)",p[i].x,p[i].y,p[j].x,p[j].y);
			}
		}
	}
}
