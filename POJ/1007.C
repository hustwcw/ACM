#include<stdio.h>

void main()
{
	struct DNA
	{
		char * DNA;
		int inversions;
	}*p;
	int m,n;
	int i,j,k;
	freopen("c:\\in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	p=(struct DNA*)malloc((m+1)*sizeof(struct DNA));
	/*≥ı ºªØ */
	for(i=1;i<=m;i++)
	{
		p[i].DNA=(char*)malloc((n+1)*sizeof(char));
		scanf("%s",p[i].DNA);
		p[i].inversions=0;
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(p[i].DNA[k]<p[i].DNA[j])p[i].inversions++;
			}
		}
	}
	/*InsertSort*/
	for(i=2;i<=m;i++)
	if(p[i].inversions<p[i-1].inversions)
	{
		p[0]=p[i];
		p[i]=p[i-1];
		for(j=i-2;p[0].inversions<p[j].inversions;j--)
			p[j+1]=p[j];
		p[j+1]=p[0];
	}
	for(i=1;i<=m;i++)
	{
		printf("%s\n",p[i].DNA);
	}
}