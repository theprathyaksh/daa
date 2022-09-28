#include<stdio.h>
#include<stdlib.h>
int count=0;
void print(int b[],int n){
   int j,a[n+1][n+1],i;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
         a[i][j]=0;
      }
      //printf("\n");
   }
   for(i=1;i<=n;i++){
      printf(" %d \t",b[i]);
      a[i][b[i]]=1;
   }
   printf("\n");
   printf("matrix representation\n");
  
   for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
         printf("%d\t",a[i][j]);
      }
      printf("\n");
   }
    printf("\n");
    count++;
}
/*int abs(int a,int b){
    int x=a-b;
    if(b<a){
        return x; 
    }
    else{
           return -x;
    }
}*/
int feasible(int row,int col,int b[]){
    int k;
	for(k=1;k<row;k++){
        if(col==b[k]){
           return 0;
        }
        if(abs(k-row)==abs(col-b[k])){
            return 0;
        }
    }

}
void nqueen(int row,int n,int b[]){
      int col;
      for(col=1;col<=n;col++){
         if(feasible(row,col,b)){
              b[row]=col;
              if(row==n){
                   print(b,n);
                   return;
              }
              nqueen(row+1,n,b);
         }
      }


}
int main(){
   int n;
   scanf("%d",&n);
   int b[n+1];
   nqueen(1,n,b);
   printf("total solutiosns :  %d",count);
return 0;
}
