#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX  1002


using namespace std;

//char memorize[1001][1001][10][10];

// 递归解法，严重超时
// 其中matrix为读入的原始01矩阵
int Solution(int (*matrix)[1001], int row_s, int row_e, int colm_s, int colm_e, int start_i, int start_j)
{
    cout << row_s << "\t" << row_e << "\t" << colm_s << "\t" << colm_e << "\t" << start_i << "\t" << start_j << endl;
    if (row_s >= row_e || colm_s >= colm_e) {
        return 0;
    }
    int rowlen = row_e - row_s;
    int colmlen = colm_e - colm_s;
    // if (rowlen < 10 && colmlen < 10)
    // {
    //     if (memorize[row_s][colm_s][rowlen][colmlen] > -1)
    //     {
    //         return memorize[row_s][colm_s][rowlen][colmlen];
    //     }
    // }

    for(int i = start_i; i < row_e; i++)
    {
        for(int j = start_j; j < colm_e; j++)
        {
            // cout << matrix[i][j] << endl;
            if(matrix[i][j] == 0)
            {
                int result1 = max( (row_s - i) * (colm_s - colm_e), Solution(matrix, i+1, row_e, colm_s, colm_e, i+1, colm_s));
                int result2 = max(Solution(matrix, row_s, row_e, colm_s, j, i+1, colm_s), Solution(matrix, row_s, row_e, j+1, colm_e, i, j+1));
                int result = max(result1, result2);
                // if (rowlen < 10 && colmlen < 10)
                // {
                //     memorize[row_s][colm_s][rowlen][colmlen] = result;
                // }
                return result;
            }
        }
    }

    // if (rowlen < 10 && colmlen < 10)
    // {
    //     memorize[row_s][colm_s][rowlen][colmlen] = rowlen*colmlen;
    // }
    return rowlen*colmlen;
}


// 动态规划解法
// 其中matrix为经过处理的矩阵，对每一个非零元素x[i][j]，将其更新为：在本行，它前面的连续的1的个数+1（+1表示算入自身）
int DPSolution(int (*matrix)[MAX], int m, int n)
{
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (result < matrix[i][j] * m)
            {
                int count = 1;
                for (int k = i-1; k > -1 && matrix[k][j] >= matrix[i][j]; k--)
                {
                    count++;
                }
                for (int k = i+1; k < m && matrix[k][j] >= matrix[i][j]; k++)
                {
                    count++;
                }
                int tmp = count*matrix[i][j];
                if (result < tmp) {
                    result = tmp;
                }
            }
        }
    }
    return result;
}


int main()
{
    int m, n;
    int matrix[MAX][MAX];

    while(scanf("%d%d", &m, &n) != EOF)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 1)
                {
                    matrix[i][j] = matrix[i][j-1]+1;
                }
            }
        }

        printf("%d\n", DPSolution(matrix, m, n));
    }
    /*
     * 读入原始01矩阵
    while(scanf("%d%d", &m, &n) != EOF)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }

        cout << Solution(matrix, 0, m, 0, n, 0, 0) << endl;
    }
    */
	return 0;
}
