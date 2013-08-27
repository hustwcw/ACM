#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


// 快速排序无法找出逆序对个数
int InversePairs(int *a, int *copy, int len)
{
    if (len == 0)
    {
        return 0;
    }
    else if (len == 1)
    {
        copy[0] = a[0];
        return 0;
    }

    int x = len >> 1;
    int left = InversePairs(copy, a, x);
    int right = InversePairs(copy, a, len-x);

    return  left+ right + count;
}

int Manli(int *a, int n)
{
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if (a[i] > a[j]) {
                    count++;
                }
            }
        }
        return count;
}

int main()
{
    int n;
    int a[100001];
    int copy[100001];

    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            copy[i] = a[i];
        }

        printf("%d\n", InversePairs(a, copy, n));
    }

    /*
    n = 10000;
    srand((unsigned)time(0));
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand()+rand();
    }
    printf("%d\t", Manli(a, n));
    printf("%d\n", InversePairs(a, n));
*/
	return 0;
}
