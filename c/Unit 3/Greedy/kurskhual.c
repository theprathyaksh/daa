#include <stdio.h>
int findparent(int i, int a[])
{

	while (a[i] != -1)
	{
		i = a[i];
	}
	return i;
}
int kruskul(int s[], int d[], int wt[], int n, int par[])
{
	int i, l, k, sum = 0;
	for (i = 0; i < n; i++)
	{
		l = findparent(s[i], par);
		k = findparent(d[i], par);
		if (k != l)
		{
			par[k] = l;
			printf("%d %d %d\n", s[i], d[i], wt[i]);
			sum = sum + wt[i];
		}
	}
	return sum;
}
void main()
{
	int s[10], d[10], par[10], wt[10], i, n, j, v;
	printf("enter the edges");
	scanf("%d", &n);
	printf("enter the veritices");
	scanf("%d", &v);
	for (i = 0; i < v; i++)
	{
		par[i] = -1;
	}
	printf("enter the source values\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	printf("enter the destination values\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &d[i]);
	}
	printf("enter the weight values\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &wt[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (wt[j] > wt[j + 1])
			{
				int temp = wt[j];
				wt[j] = wt[j + 1];
				wt[j + 1] = temp;
				int temp1 = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp1;
				int temp2 = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp2;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", d[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", wt[i]);
	}
	printf("\n");
	int total = kruskul(s, d, wt, n, par);
	printf("total cost =%d", total);
}
