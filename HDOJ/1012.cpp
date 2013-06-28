#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int i;
	double e=0,k=1,t;
	printf("n e\n");
	printf("- ----------\n");
	for(i=0;i<=9;i++)
	{
		if(i==0)
			e=1;
		else
		{
			k*=i;
			e+=1.0/k;
		}
		if(i==0||i==1)
			printf("%d %.0f\n",i,e);
		else if(i==2)
			printf("%d %.1lf\n",i,e);
		else
			printf("%d %.9lf\n",i,e);
	}

	return 0;
}
