#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;



int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int p[22][22];
	int value[22][22];
	int M, N;
	cin >> M >> N;
	while (M != 0)
	{
		memset(*p, 0, 22*22*sizeof(int));
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> p[i][j];
			}
		}
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				value[i][j] = 0;
				(p[i][j]*p[i-1][j] > 0)?(value[i][j]-=abs(p[i-1][j])):(value[i][j]+=abs(p[i-1][j]));
				(p[i][j]*p[i][j-1] > 0)?(value[i][j]-=abs(p[i][j-1])):(value[i][j]+=abs(p[i][j-1]));
				(p[i][j]*p[i+1][j] > 0)?(value[i][j]-=abs(p[i+1][j])):(value[i][j]+=abs(p[i+1][j]));
				(p[i][j]*p[i][j+1] > 0)?(value[i][j]-=abs(p[i][j+1])):(value[i][j]+=abs(p[i][j+1]));
			}
		}

		int max=-1000;
		int m, n;
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (value[i][j] > max)
				{
					max = value[i][j];
					m = i;
					n = j;
				}
			}
		}
		cout << m << " " << n << " " << max << endl;

		cin >> M >> N;
	}

	return 0;
}
