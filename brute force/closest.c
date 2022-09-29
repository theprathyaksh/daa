#include<stdio.h>
#include<math.h>
struct point{
	int x;
	int y;
};
struct point p[50];
int main()
{
	int i,j,mx,my,n;
	float d,min=9999;
	printf("Enter the number of coordinates you enter:");
	scanf("%d",&n);
	printf("Enter the coordinates of each point:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d point co-ordinates:",i+1);
		scanf("%d",&p[i].x);
		scanf("%d",&p[i].y);
	}
	printf("entered points are:");
	for(i=0;i<n;i++)
	{
		printf("(%d,%d),",p[i].x,p[i].y);
	}
	for(i=0;i<n;i++)
	{
		struct point a;
		a.x=p[i].x;
		a.y=p[i].y;
		int x1=a.x;
		int y1=a.y;
		for(j=i+1;j<n;j++)
		{
			struct point b;
			b.x=p[j].x;
			b.y=p[j].y;
			int x2=b.x;
			int y2=b.y;
			d=((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
			if(d<min)
			{
				min=d;
				mx=i;
				my=j;
			}
		}
	}
	printf("\nminimum distance is: %f",min);
	printf("\nclosest pair is (%d,%d),(%d,%d)",p[mx].x,p[mx].y,p[my].x,p[my].y);
	printf("\n");
}
