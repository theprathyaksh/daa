#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100],s2[50];
	printf("Enter the main string:");
	scanf("%s",s1);
	printf("Enter the sub string:");
	scanf("%s",s2);
	int m,n,i,j,f=-1;
	m=strlen(s1);
	n=strlen(s2);
	for(i=0;i<=m-n;i++)
	{
		for(j=i;j<i+n;j++)
		{
			if(s1[j]!=s2[j-i])
			{
				break;
			}
		}
		if(j==i+n)
		{
			f=i;
		}
	}
	if(f==-1)
	{
		printf("String not matched");
	}
	else
	{
		printf("string matched at %d index",f);
	}
}
