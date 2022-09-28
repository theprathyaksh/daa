#include<stdio.h>
#include<string.h>
void toh(int n,char a,char b,char c)
{
	 if(n<=0)
	 {
	 	 return;
	 }
	 else
	 {
	 toh(n-1,a,c,b);
	 printf("%c%c\n",a,b);
	 toh(n-1,c,b,a);
 }
}
void main()
{
	 int n;
	 printf("enter the number of the disks");
	 scanf("%d",&n);
	 char a,b,c;
	 toh(n,'a','b','c');
	 printf("\nprasanna");
}
