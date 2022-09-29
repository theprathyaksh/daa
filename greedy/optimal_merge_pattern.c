#include<stdio.h>
int c;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int arr[], int n, int i) {
    int smallest=i;
    int left=2*i;
    int right=2*i+1;
    if (left<=n && arr[left]<arr[smallest])
      smallest = left;
    if (right<=n && arr[right]<arr[smallest])
      smallest = right;
    if (smallest!=i) {
      swap(&arr[i],&arr[smallest]);
      heapify(arr,n,smallest);
    }
}
void insert(int a[],int val){
	c++;
	a[c]=val;
	int i=c;
	while(i>1){
		int parent=i/2;
		if(a[parent]>a[i]){
			swap(&a[parent],&a[i]);
			i=parent;
		}
		else return;
	}
}
int delete(int a[]){
	int val=a[1];
	a[1]=a[c];
	c--;
	heapify(a,c,1);
 	return val;
}
int main()
{
	int n,i,a[1000];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int sum=0;
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		insert(a,a[i]);
	}
	for (i = 1; i < n; i++)
	{
		int min1=delete(a);
		int min2=delete(a);
		sum+=(min1+min2);
		insert(a,min1+min2);
	}
	printf("SUM=%d\n",sum);
	return 0;
}
