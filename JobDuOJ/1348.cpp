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
long long InversePairs(int *a, int *copy, int len)
{
    if (len < 2)
    {
        return 0;
    }

    int x = len >> 1;
    long long left = InversePairs(a, copy, x);
    long long right = InversePairs(a+x, copy+x, len-x);
    long long count = 0;

    for(int i = 0; i < len; i++)
    {
        copy[i] = a[i];
    }
    int i = 0;
    int j = x;
    int k = 0;
    while(i < x && j < len)
    {
        if (copy[i] > copy[j]) {
            a[k++] = copy[j++];
            count += (x-i);
        }
        else
        {
            a[k++] = copy[i++];
        }
    }
    while(i < x)
    {
        a[k++] = copy[i++];
    }
    while(j < len)
    {
        a[k++] = copy[j++];
    }
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

        printf("%lld\n", InversePairs(a, copy, n));
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
