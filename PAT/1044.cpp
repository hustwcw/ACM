#include <iostream>
#include <cstdlib>
#include <cstdio>


using namespace std;


int main()
{
    unsigned int N, M;
    unsigned short *D;
    cin >> N >> M;
    D = (unsigned short *)malloc(N * sizeof(unsigned short));
    for (int i = 0; i < N; i++) {
        scanf("%hu", D+i);
    }
    unsigned int min = 0xffffffff;

L:
    int sum = 0;
    int i = 0, j = 0;
    while (i < N)
    {
        while (j < N)
        {
            sum += D[j];
L2:
            if (sum == M) {
                // output i and j
                //cout << i+1 << "-" <<  j+1 << endl;
		printf("%d-%d\n", i+1, j+1);
                min = M;
                sum -= D[i];
                ++j;
                break;
            }
            else if (sum > M)
            {
                if (min > sum) {
                    min = sum;
                }
                sum -= (D[i]);
                ++i;
                goto L2;
            }
            ++j;
        }
	++i;
    }

    if (min > M) {
        M = min;
        goto L;
    }
/*
    if (min > M) {
        for (int i = 0; i < N; ++i) {
            int sum = 0;
            for (int j = i; j < N; ++j) {
                sum += D[j];
                if (sum == min) {
                    cout << i+1 << "-" << j+1 << endl;
                    break;
                }
            }
        }
    }
*/
    return 0;
}
