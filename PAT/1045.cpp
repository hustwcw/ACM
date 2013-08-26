/*
动态规划，类似最长公共子序列(LCS)的方法
*/

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
    int count;
    int m, n;
    int dp[201][10001];
    int X[201];
    int Y[10001];
    scanf("%d", &count);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &X[i]);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &Y[i]);
    }

    // start dynamic programming
    for(int i = 0; i < m; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (X[i] == Y[j]) {
                dp[i][j] = dp[i][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[m][n] << endl;
	return 0;
}
