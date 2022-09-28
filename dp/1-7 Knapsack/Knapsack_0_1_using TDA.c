#include <stdio.h>
#include <stdlib.h>
#include <math.h>

ks(int wt[], int val[], int n, int w, int a[n+1][w+1])
{
	int x, y, i,j;
	printf ("Knapsack DP Table :\n");
	for (i=0; i<=n; i++)
	{
		for (j=0; j<=w; j++)
		{
			if (i==0 || j==0)
			{
				a[i][j]=0;
			}
			else if (wt[i-1]>j)
			{
				a[i][j]=a[i-1][j];
			}
			else 
			{
//				x=val[i-1]+a[i-1][j-wt[i-1]];
//				y=a[i-1][j];
				a[i][j]=max((val[i-1]+a[i-1][j-wt[i-1]]),a[i-1][j]);
			}
			
			printf ("%d  ", a[i][j]);
		}
		printf ("\n");
	}
	return a[n][w];
}

max (int x, int y)
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
	int a[n+1][w+1];
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
	int max;
	max=ks(wt, val, n, w, a);
	printf ("Maximum Profit on selling items is : %d", max);
}
