#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;


int Solution(int (*a)[8], int r_start, int c_start, int limit)
{
    if (limit < a[r_start][c_start]) {
        return -1;
    }
    if (r_start > 7 || c_start > 7) {
        return -1;
    }
    if (r_start == 7 && c_start == 7) {
        return a[r_start][c_start];
    }

    int r1 = Solution(a, r_start+1, c_start, limit-a[r_start][c_start]);
    int r2 = Solution(a, r_start, c_start+1, limit-a[r_start][c_start]);
    if (r1 == -1 && r2 == -1) {
        return -1;
    }
    else
        return max(r1, r2) + a[r_start][c_start];
}


int main()
{
    int limit;
    int a[8][8];
    while(scanf("%d", &limit) != EOF)
    {
        int sum = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        sum = Solution(a, 0, 0, limit);
        cout << sum << endl;
    }
    return 0;
}
