#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[10],count=0;
int place(int pos){
	int i;
	for( i=1;i<pos;i++){
		if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos)))){
			return 0;
		}
	}
	return 1;
}
void printsol(int n){
	count++;
	printf("%d",count);
	int i,j;
	for( i=1;i<=n;i++){
		for( j=1;j<=n;j++){
			if(a[i]==j){
				printf("Q\t");
			}
			else
			{
				printf("*\t");
			}
		}
		printf("\n");
	}
}
void nqueens(int n){
	int k=1;
	a[k]=0;
	while(k!=0){
		
			a[k]=a[k]+1;
		while(a[k]<=n && !place(k))
			a[k]++;
		if(a[k]<=n){
			if(k==n){
				printsol(n);
			
			}
			else{
				k++;
				a[k]=0;
			}
		}
		else
		{
			k--;
		}
	}
}
int main(){
	int n;
	printf("enter n");
	scanf("%d",&n);
	nqueens(n);
	printf("%d",count);
	
	
}
