#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;



bool isPrime(int n)
{
	if (n==3 || n==5 || n==7 || n==11 || n==13 || n==17 || n==19 || n==23 || n==29 || n==31 || n==37)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	int result[20];
	bool sta[20];
	int k = 1;
	while (cin >> n)
	{
		cout << "Case " << k++ << ":"<< endl;
		for (int i = 0; i < n; i++)
		{
			sta[i] = true;
			result[i] = 1;
		}
		
		int start = 1;
		for (int i = 1; i < n&&i>0; i++)
		{
			for (int j = start; j < n; j++)
			{
				if (sta[j] && isPrime(result[i-1]+j+1))
				{
					result[i] = j+1;
					sta[j] = false;
					start = 1;
					break;
				}
				else if (j == (n-1))
				{
					// backtrace
					sta[result[i-1]-1] = true;
					start = result[i-1];
					i-=2;
					while (start == n)
					{
						
						sta[result[i] -1] = true;
						start = result[i];
						--i;
					}
					break;
				}
			}
			if (i==(n-1))
			{
				if(isPrime(result[0] + result[i]))
				{
					// output result
					for (int i = 0; i < n; i++)
					{
						cout << result[i];
						if (i == (n-1))
						{
							cout << endl;
						}
						else
						{
							cout << " ";
						}
					}

					// backtrace
					sta[result[i] -1] = true;
					start = result[i];
					--i;
					while (start == n)
					{
						
						sta[result[i] -1] = true;
						start = result[i];
						--i;
					}
				}
				else
				{
					// backtrace
					sta[result[i]-1] = true;
					start = result[i];
					i--;
					while (start == n)
					{
						
						sta[result[i] -1] = true;
						start = result[i];
						--i;
					}
				}
			}
		}

		cout << endl;
	}
	return 0;
}
