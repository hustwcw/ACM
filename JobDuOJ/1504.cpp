#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;



long long catInt(int a, int b)
{
    if (a <= 0 || b <= 0) {
        return 0;
    }

    int temp = b;
    long long result = a;
    while(temp > 0)
    {
        result *= 10;
        temp /= 10;
    }
    return (result+b);
}


int intCompare(const void *a, const void *b)
{
    int va = *(int *)a;
    int vb = *(int *)b;

    if (catInt(va, vb) > catInt(vb, va)) {
        return 1;
    }
    else
    {
        return -1;
    }
}


int main()
{
    int m;
    int *array = NULL;

    while(scanf("%d", &m) != EOF)
    {
        array = new int[m];
        for(int i = 0; i < m; ++i)
        {
            scanf("%d", array+i);
        }

        qsort(array, m, sizeof(int), intCompare);

        for (int i = 0; i < m; i++) {
            printf("%d", array[i]);
        }
        printf("\n");

        if (array) {
            delete array;
            array = NULL;
        }
    }
}
