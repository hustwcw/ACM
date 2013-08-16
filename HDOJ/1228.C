#include<stdio.h>
#include<string.h>
void main()
{
	int a=0,b=0;
	int flag=0;/*0:input a;1:input b.*/
	char num[6];
	freopen("c:\\in.txt","r",stdin);
	while(scanf("%s",num)!=EOF)
	{
		if(strcmp(num,"zero")==0)
		{
			if(flag==0)a=a*10;
			else if(flag==1)b=b*10;
		}
		else if(strcmp(num,"one")==0)
		{
			if(flag==0)a=a*10+1;
			else if(flag==1)b=b*10+1;
		}
		else if(strcmp(num,"two")==0)
		{
			if(flag==0)a=a*10+2;
			else if(flag==1)b=b*10+2;
		}
		else if(strcmp(num,"three")==0)
		{
			if(flag==0)a=a*10+3;
			else if(flag==1)b=b*10+3;
		}
		else if(strcmp(num,"four")==0)
		{
			if(flag==0)a=a*10+4;
			else if(flag==1)b=b*10+4;
		}
		else if(strcmp(num,"five")==0)
		{
			if(flag==0)a=a*10+5;
			else if(flag==1)b=b*10+5;
		}
		else if(strcmp(num,"six")==0)
		{
			if(flag==0)a=a*10+6;
			else if(flag==1)b=b*10+6;
		}
		else if(strcmp(num,"seven")==0)
		{
			if(flag==0)a=a*10+7;
			else if(flag==1)b=b*10+7;
		}
		else if(strcmp(num,"eight")==0)
		{
			if(flag==0)a=a*10+8;
			else if(flag==1)b=b*10+8;
		}
		else if(strcmp(num,"nine")==0)
		{
			if(flag==0)a=a*10+9;
			else if(flag==1)b=b*10+9;
		}
		else if(strcmp(num,"+")==0)
		{
			flag=1;
		}
		else if(strcmp(num,"=")==0)
		{
			if((a+b)!=0)
			{
				printf("%d\n",a+b);
				flag=a=b=0;
			}
			else break;
		}
	}
}