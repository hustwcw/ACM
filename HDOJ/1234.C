#include<stdio.h>
#include<string.h>
void main()
{
	char identifier[16];
	char tempcometime[9];
	char templeavetime[9];
	char cometime[9]="23:59:59";
	char leavetime[9]="00:00:00";
	char comeid[16];
	char leaveid[16];
	int n;
	int m;
	int i,j;
	freopen("c:\\in.txt","r",stdin);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%s%s%s",identifier,tempcometime,templeavetime);
			if(strcmp(tempcometime,cometime)<=0)
			{
				strcpy(comeid,identifier);
				strcpy(cometime,tempcometime);
			}
			if(strcmp(templeavetime,leavetime)>=0)
			{
				strcpy(leaveid,identifier);
				strcpy(leavetime,templeavetime);
			}
		}
		printf("%s %s\n",comeid,leaveid);
		strcpy(leavetime,"00:00:00");
		strcpy(cometime,"23:59:59");
	}
}