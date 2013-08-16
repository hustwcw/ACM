#include<stdio.h>
#define NUM (5*25)
void main()
{
	char s[6];
	unsigned int result[NUM];
	char result1[NUM],result2[NUM],result3[NUM],result4[NUM],result5[NUM];
	int n;int flag=0;int decimal=0;
	int i=0;int j=0;int k=0;
	int a,b,c;
	while(scanf("%s%d",s,&n)==2) /*to  see if the scanf read in as many items as you want*/
	/*while(scanf(%s%d",s,&n)!=EOF) //this also work    */
	{

		for(i=0;i<6;i++)
		{if(s[i]=='.')break;}
		i=5-i;
		for(j=6-i;j<6;j++)
		{s[j-1]=s[j];}
		for(j=0;j<5;j++)
		{
			s[j]-=48;
			}

		for(j=0;j<NUM;j++)
		{
			result[j]=0;result1[j]=0;result2[j]=0;result3[j]=0;result4[j]=0;result5[j]=0;
			}
		for(j=5;j>0;j--)
		{
				result[NUM+j-6]=s[j-1];
			}
		for(j=0;j<n-1;j++)
		{
				for(a=0;a<NUM;a++)
				{
					result1[a]=0;result2[a]=0;result3[a]=0;result4[a]=0;result5[a]=0;
				}
				for(a=NUM-1;a>=0;a--)
				{

					result1[a]=(result[a]*s[4]);
					}
				for(a=NUM-1;a>=1;a--)
				{

					result2[a-1]=(result[a]*s[3]);
					}
				for(a=NUM-1;a>=2;a--)
				{

					result3[a-2]=(result[a]*s[2]);
					}
				for(a=NUM-1;a>=3;a--)
				{

					result4[a-3]=(result[a]*s[1]);
					}
				for(a=NUM-1;a>=4;a--)
				{

					result5[a-4]=(result[a]*s[0]);
					}
				/*求和*/
				for(a=NUM-1;a>=0;a--)
				{
					result[a]=result1[a]+result2[a]+result3[a]+result4[a]+result5[a];
				}
				/*完成进位操作*/
					for(c=NUM-1;c>=0;c--)
					{
						if(result[c]>=10)
						{
							result[c-1]+=result[c]/10;
							result[c]= result[c]%10;
						}
					}
		}
/*
		for(c=0;c<NUM;c++)
		{
			printf("%d",result[c]);
		}
		printf("\n");
*/
		flag=0;decimal=1;a=0;
		for(c=0;c<NUM;c++)
		{
			if(c==NUM-n*i-1)/*输出小数点前面的一个数字*/
			{if(a>0)
					{
						for(;a>0;a--)
						printf("0");
					}
				if(result[c]!=0||flag==1)printf("%d",result[c]);
				flag=1;
			}
			else if(result[c]!=0)
			{
				if(c>NUM-n*i-1)
				{
					if(decimal==1)
					{
						printf(".");
						decimal=0;
					}
				}
				if(a>0)
					{
						for(;a>0;a--)
						printf("0");
					}
				printf("%c",result[c]+48);
				flag = 1;
			}
			else if(result[c]==0&&flag==1)
			{
				a++;
			}
		}
		printf("\n");
	}
}
