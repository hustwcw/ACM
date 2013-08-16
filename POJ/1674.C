#include<stdio.h>

void main()
{
	int t,n;
	int count;
	int first,next,last;
	int *p;
	int i;
	freopen("c:\\in.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		p =(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)scanf("%d",&p[i]);
		/*for(i=0;i<n;i++)printf("%d\t",p[i]);
		for(j=n-1;j>0;j--)
		for(k=0;k<j;k++)
		{
			if(p[k]>p[k+1])
			{
				temp=p[k];
				p[k]=p[k+1];
				p[k+1]=temp;
				count++;
			}
		}
		*/
		for(i=0;i<n;i++)
		{
			if(p[i]>0)
			{
				first=next=last=i;
				while((next=p[next]-1)!=first)
				{
					p[last]=-1;
					last=next;
				}
				p[last]=-1;
				count++;
			}
		}
		printf("%d\n",n-count);
		free(p);
	}
}
