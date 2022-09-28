#include<stdio.h>
#include<stdlib.h>
int adj[10][10];
void addedge(int a,int b,int cost)
{
   adj[a][b]=cost;
}
void main()
{
    int i,j,n,c[10];
    printf("enter the number of the vertices ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
           adj[i][j]=-1;
      }
    }
   for(i=0;i<n;i++)
   {
   	if(i<n-1)
    {
    	c[i]=INT_MAX;
    }
	else
	{
	   c[i]=0;
	}
   }
    int a,b,e,cost;
    printf("enter the number of edges  ");
    scanf("%d",&e);
    for(i=0;i<e;i++)
    {
        printf("enter the edges ");
        scanf("%d%d",&a,&b);
        printf("enter the cost");
        scanf("%d",&cost);
        addedge(a,b,cost);
    }
    printf("graph representaion by adjacency matrix ");
    for(i=0;i<n;i++)
    {
       printf("\n");
       for(j=0;j<n;j++)
       {
            printf("%d ",adj[i][j]);
       }
   }
   printf("\n");
   int cos,min;
   for(i=n-2;i>=0;i--)
   {
   	min=INT_MAX;
   	for(j=i+1;j<n;j++)
   	{
   	   if(adj[i][j]!=-1)
		  {
		  	cos=adj[i][j]+c[j];
		  	if(cos<min)
		  	{
		  		min=cos;
			  }
		    }	
	      }
    c[i]=min;
   } 
   printf("\n");
   for(i=0;i<n;i++)
   {
   	printf("%d ",c[i]);
   }
}
