#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    int num;
	while (scanf("%d", &num) != EOF)
	{
		int cur,max, count = 0;
		for (int i = 0; i < num; i++)
		{
			cin >> cur;
			if (count == 0)
			{
				max = cur;
				count++;
			}
			else
			{
				if (cur != max)
				{
					count--;
				}
				else
				{
					count++;
				}
			}
		}
		cout << max << endl;
	}

	return 0;
}
