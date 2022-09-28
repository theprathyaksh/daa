#include<stdio.h>
int x[100];
 int n;
void print(int wt[]){
   int i;
   for(i=0;i<n;i++){
      if(x[i]==1){
          printf("%d\t",wt[i]);
      }
   }
   printf("\n");
}

void  ss(int wt[],int w,int n){
   if(w==0){
       print(wt);
       return;
   }
   if(n==0){
       return;
   }
   if(wt[n-1]<=w){
       x[n-1]=1;
        //print(wt);
       ss(wt,w-wt[n-1],n-1);
       //x[n-1]=1;
        //print(wt);
      
         
   }
 
      x[n-1]=0;
      ss(wt,w,n-1);
   
}
int main(){
  
   int w;
   printf("enter the number of items");
   scanf("%d",&n);
   printf("enter the required sum");
   scanf("%d",&w);
   int i,  . wt[n];
   for(i=0;i<n;i++){
      scanf("%d",&wt[i]);
   }
   ss(wt,w,n);
 return 0;
}
