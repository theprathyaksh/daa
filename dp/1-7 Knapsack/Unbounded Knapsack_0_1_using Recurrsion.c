#include <stdio.h>
#include <stdlib.h>
#include <math.h>

ks(int wt[], int val[], int n, int w)
{
	int a, b;
	if (n==0 || w==0)
	{
		return 0;
	}
	else if (wt[n-1]<=w)
	{
		a=val[n-1]+ks(wt, val, n, w-wt[n-1]);
		b=ks(wt, val, n-1, w);
		return max(a, b);
	}
	else
	{
		return ks(wt, val, n-1, w);
	}
}

max (int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
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

	int max;
	max=ks(wt, val, n, w);
	printf ("Maximum Profit on selling items is : %d", max);
}
