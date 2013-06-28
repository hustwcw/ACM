#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void caculate(char *a, int an, char *b, int bn)
{
	int max = an>bn?an:bn;int i;
	char *result = (char *)malloc(max+2); /* ½øÎ»¼°Ä©Î²\0 */
	memset(result, 0, max+2);
	for (i = 0; i < max; i++)
	{
		int temp;
		int ta, tb;
		if (an>0)
		{
			ta = a[--an]-48;
		}
		else
		{
			ta=0;
		}
		if (bn>0)
		{
			tb = b[--bn]-48;
		}
		else
		{
			tb=0;
		}
		if (result[max-i] > 0)
		{
			temp = result[max-i]+ta+tb;
		}
		else
		{
			temp = ta+tb+48;
		}
		if (temp > '9')
		{
			result[max-i] = temp-10;
			result[max-i-1] = '1';
		}
		else
		{
			result[max-i] = temp;
		}
	}

	if (result[0]>0)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("%s\n", result+1);
	}
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=0;
	char a[1001]={0};
	char b[1001]={0};
	int an=0;
	int bn=0;
	scanf("%d", &t);
	int i=1;
	while (t>0)
	{
		scanf("%s", a);
		scanf("%s", b);
		an = strlen(a);
		bn = strlen(b);
		printf("Case %d:\n%s + %s = ", i++, a, b);
		caculate(a, an, b, bn);
		t--;
		if (t>0)
		{
			printf("\n");
		}
	}

	return 0;
}