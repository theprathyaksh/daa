#include<stdio.h>
int m;
void printx(int x[],int wt[]){
	int i;
	for(i=0;i<m;i++){
		if(x[i]==1){
			printf("%d ",wt[i]);
		}
	}
	printf("\n");
}
int subset(int wt[],int x[],int sum,int n,int rs){
	if(sum==0){
		printx(x,wt);
		return 0;
	}

	if(n==0 || rs<sum){
		return 0;
	}
	if(wt[n-1]<=sum){
		x[n-1]=1;
		subset(wt,x,sum-wt[n-1],n-1,rs-wt[n-1]);
	}
	x[n-1]=0;
	subset(wt,x,sum,n-1,rs-wt[n-1]);
}
int main(){
	int n;
	printf("enter n");
	scanf("%d",&n);
	int sum,wt[n],rs=0,i;
	printf("enter sum");
	scanf("%d",&sum);
	printf("\nenter array elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&wt[i]);
		rs=rs+wt[i];
	}
	int x[n];
	for(i=0;i<n;i++){
		x[i]=0;
	}
	m=n;
	subset(wt,x,sum,n,rs);
	return 0;
}
