#include<stdio.h>
void main()
{
	int first,last,tempfirst,templast,max,sum,n,num;
	int i;
	int flag=0;/*0:all numbers are negtive*/
/*flag=0 is similar to flag=2 ; flag=1 is similar to flag=3*/
	freopen("c:\\in.txt","r",stdin);
	scanf("%d",&n);
	while(n!=0)
	{
		max=sum=flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);
			if(num>=0)
			{
				sum+=num;
				if(flag==0)/*first positive number*/
				{
					tempfirst=num;
					templast=num;
					flag=1;
				}
				else if(flag==2)
				{
					tempfirst=num;
					templast=num;
					flag=3;
				}
				if(max<sum)
				{
					templast=num;
					if(flag==3)
					{
						first=tempfirst;
						last=templast;
					}
					max=sum;
				}
			}
			else if(num<0)
			{
				if(flag!=0&&flag!=2)sum+=num;
				if(sum<0&&flag==1)
				{
					first=tempfirst;
					last=templast;
					flag=2;
					sum=0;
				}
				if(sum<0&&flag==3)
				{
					flag=2;
					sum=0;
				}
			}
			if(i==0)
			{
				tempfirst=num;
			}
			if(i==n-1&&flag==0)
			{
				templast=num;
			}
		}
		if(flag==0||flag==1)
		{
			first=tempfirst;
			last=templast;
		}
		printf("%d %d %d\n",max,first,last);
		scanf("%d",&n);
	}
}
