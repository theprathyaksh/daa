#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[100][100];
int ks(int wt[], int val[], int n, int w)
{
	int a[n+1][w+1];
	int x, y;
	if (n==0 || w==0)
	{
		return a[n][w]=0;
	}
	else if(a[n][w]!=-1)
	  return a[n][w];
	
	else if (wt[n-1]<=w)
	{
		x=val[n-1]+ks(wt, val, n-1, w-wt[n-1]);
		y=ks(wt, val, n-1, w);
		return a[n][w]=max(x, y);
	}

	else
	{
		return a[n][w]=ks(wt, val, n-1, w);
	}
}

int max (int x, int y)
{
	if (x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int main()
{
	int n, w, i, j;
	printf ("Enter no. of items : ");
	scanf ("%d", &n);
	printf ("Enter the weight of the Bag : ");
	scanf ("%d", &w);
	int wt[n], val[n]; 
	printf ("Enter the weight and value of the each item :\n");
	for (i=0; i<n; i++)
	{
		scanf ("%d %d", &wt[i], &val[i]);
	}
	//	printf ("Print");
//	for (j=0; j<n; j++)
//	{
//		printf ("%d -> %d\n", wt[j], val[j]);
//	}

	for (i=0; i<=n; i++)
	{
		for (j=0; j<=w; j++)
		{
			a[i][j]=-1;
		}
	}
	int mx;
	mx=ks(wt, val, n, w);
	printf ("Maximum Profit on selling items is : %d", mx);
}
