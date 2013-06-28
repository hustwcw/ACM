#include <stdio.h>


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    int n;
	while (scanf("%d", &n) != EOF)
	{
		if ((n-2)%4 == 0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	return 0;
}
