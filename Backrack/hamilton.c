#include<stdio.h>
#include<stdlib.h>
int x[10];
int n;
void print(){
	int i;
   for(i=0;i<n;i++){
     printf("%d\t",x[i]); 
   }
   printf("\n");
}
int isfeasible(int k,int i,int a[][n]){
    if(a[x[k-1]][i]==1){
       int j;
         for( j=0;j<k;j++){
            if(x[j]==i){
                return 0;
            }
         }
         return 1;
    }
 
         return 0;
    

}
void hamilton(int k,int n,int a[][n]){
   int i;
  /* for(i=0;i<n;i++){
      if(isfeasible(k,i,n,a));
      {
          x[k]=i;
          printf("k=%d\t",k);
          if(k==n-1){
                  if(a[x[k]][x[0]]==1){
                     print(n);
                     return;
                 }
                 else{
                   x[k]=-1;
                   return;
                 }
          }
           hamilton(k+1,n,a);
      }
     
   }*/
   
   
   for(i=0;i<n;i++)
	{
		if(isfeasible(k,i,a))
		{
			x[k]=i;
			if(k==n-1)
			{
				if(a[x[k]][x[0]]==1)
				{
					print();
					return;
				}
				else
				{
					x[k]=-1;
					return;
				}
			}
			hamilton(k+1,n,a);
		}
	}
}
int main(){
  
    scanf("%d",&n);		
    int a[n][n],i,j;
    for(i=0;i<n;i++){
           x[i]=-1;
    }
    x[0]=1;
    int k=1;
    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           scanf("%d",&a[i][j]);
       }
    }
    hamilton(k,n,a);

return 0;
}











