#include <stdio.h>


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    int t,n;
	int num;
	int i,j,k;
    scanf("%d",&t);
	for (k = 1; k <= t; k++)
    {
		int sum=0;
		int max=-1001;
		int begin=1;
		int end=1;
        scanf("%d",&n);
		for (i=j= 1; j <= n; j++)
		{
			scanf("%d", &num);
			sum+=num;
			if (sum>max)
			{
				max=sum;
				begin = i;
				end=j;
			}
			if (sum < 0)
			{
				sum=0;
				i=j+1;
			}
		}
		printf("Case %d:\n%d %d %d\n", k, max, begin, end);

		if (k!=t)
		{
			printf("\n");
		}
    }

	return 0;
}
