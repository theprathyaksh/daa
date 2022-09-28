#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[10],sub[10];
	printf("enter string\n");
	//scanf("%s",str);
	gets(str);
	printf("enter the sub string\n");
	//scanf("%s",sub);
	gets(sub);
    int l1,flag=0,k,j,l2,i;
    l1=strlen(str);
    l2=strlen(sub);
    for(i=0;i<l1-l2;i++)
    {
    	for(j=1;j<i+l2;j++)
    	{
    		if(str[j]!=sub[j-i])
    		{
    			break;
			}
		}
		if(j==i+l2)
		{
			flag=1;
			k=i;
			break;
		}
	}
	if(flag==1)
	{
		printf("string is found at %d",k);
	}
	else
	{
		printf("string is not found");
	}
	return 0;
}
