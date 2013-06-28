#include <stdio.h>


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    int t;
	scanf("%d", &t);
	char c = getchar();
	while (t>0)
	{
		char ch;
		char temp='\0';
		int num=0;
		while ((ch=getchar()))
		{
			if (ch==temp)
			{
				num++;
			}
			else
			{
				if (num>1)
				{
					printf("%d%c", num, temp);
				}
				else if (temp > 0)
				{
					printf("%c", temp);
				}
				temp = ch;
				num = 1;
			}
			if (ch=='\n' || ch == EOF)
			{
				printf("\n");
				break;
			}
		}
		t--;
	}

	return 0;
}
