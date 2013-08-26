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
    int value;
    int count = 0;
    int matrix[8][8];
    int result[8][8];
    while(scanf("%d", &value) != EOF)
    {
        matrix[count >> 3][count%8] = value;
        count++;

        if (count == 64)
        {
            // finish input
            count = 0;
            
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if (i == 0 && j == 0) {
                        result[i][j] = matrix[0][0];
                    }
                    else if (i == 0)
                    {
                        result[i][j] = result[i][j-1] + matrix[i][j];
                    }
                    else if (j == 0)
                    {
                        result[i][j] = result[i-1][j] + matrix[i][j];
                    }
                    else
                    {
                        result[i][j] = max(result[i-1][j], result[i][j-1]) + matrix[i][j];
                    }
                }
            }
            cout << result[7][7] << endl;
        }
    }
	return 0;
}
