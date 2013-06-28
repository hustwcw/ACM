#include <iostream>
#include <string>
#include <map>

#define ROW 20
#define COLUM 20
using namespace std;


long long m_count = 0, n_count = 0;
long long M,N;
long long A[ROW+1][COLUM+1];

long long f(long long m, long long n)
{
	m_count = M-m;
	n_count = N-n;
	if (A[m][n] != 0)
	{
		return A[m][n];
	}
	if (m==0)
	{
		long long result=1;
		while (n>0)
		{
			result = result*n;
			n--;
		}
		return result;
		
	}
	if (n==0)
	{
				long long result=1;
		while (m>0)
		{
			result = result*m;
			m--;
		}
		return result;
	}
	if (m_count > n_count || m < n)
	{
		return m*f(m-1, n) + n*f(m, n-1);
	}
	else
	{
		return m*f(m-1, n);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int i,j;
	for (i = 0; i <= ROW; i++)
	{
		for (j = 0; j <= COLUM; j++)
		{
			M = i;
			N = j;
			A[i][j] = f(i,j);
		}
	}
	cin >> M >> N;
	i = 1;
	while (M!=0)
	{
		cout << "Test #" << i << ":\n" << f(M, N) << endl;
		cin >> M >> N;
		i++;
	}
	return 0;
}
