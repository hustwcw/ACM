#include<stdio.h>
#include<string.h>
void main()
{
	int n,m,g;
	int i,j;
	int num;
	struct
	{
		char id[21];/*¿¼ºÅ*/
		int sc;
	}temp,student[1000];
	int score[10];
	freopen("c:\\in.txt","r",stdin);
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%d%d",&m,&g);
		i=0;
		while(i<m)
		{
			scanf("%d",&score[i++]);
		}
		i=n;
		while(i>0)
		{
			strcpy(student[--i].id,"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
			student[i].sc=0;
			scanf("%s",student[i].id);
			scanf("%d",&j);
			while(j>0)
			{
				scanf("%d",&num);
				student[i].sc+=score[num-1];
				j--;
			}
		}
		/*ÅÅĞòÊä³ö*/

		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(student[i].sc<student[j].sc)
				{
					temp=student[i];
					student[i]=student[j];
					student[j]=temp;
				}
				else if(student[i].sc==student[j].sc)
				{
					if(strcmp(student[i].id,student[j].id)>0)
					{
						temp=student[i];
						student[i]=student[j];
						student[j]=temp;
					}
				}
			}

		}
		num=0;
		for(i=0;i<n;i++)
			{
				if(student[i].sc>=g)num++;
			}
			printf("%d\n",num);
		for(i=0;i<num;i++)
		{
			printf("%s %d\n",student[i].id,student[i].sc);
		}
		scanf("%d",&n);
	}
}