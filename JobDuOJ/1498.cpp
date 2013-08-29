#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;



int expresstionValue(int *state, int len)
{
    int result = 0;
    int tmp = 1;
    int lastState = 2;
    for (int i = 0; i < len; i++) {
        if (state[i] == 1) {
            if (i+2 < 10)
            {
                tmp = tmp*10 + (i+2);
            }
            else
            {
                tmp  = tmp*100 + (i+2);
            }
        }
        else 
        {
            if (lastState == 2)
            {
                result += tmp;
            }
            else if (lastState == 3)
            {
                result -= tmp;
            }
            lastState = state[i];
            tmp = i+2;
        }
    }
    return result;
}


void printExpresstion(int *state, int len)
{
    for (int i = 0; i < len-1; i++) {
        if (state[i] == 1) {
            printf("%d ", i+1);
        }
        else if (state[i] == 2)
        {
            printf("%d+", i+1);
        }
        else if (state[i] == 3) {
            printf("%d-", i+1);
        }
    }
    printf("%d\n", len);
}

int main()
{
    int state[15];
    int pos = 1;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(state, 0, sizeof(state));
        for (int i = 0; i < n-1; )
        {
            if (state[i] == 0) {
                state[i++] = 1;   // 空格
            }
            else if (state[i] == 1) {
                state[i++] = 2; // +
            }
            else if (state[i] == 2) {
                state[i++] = 3; // -
            }
            else{
                state[i--] = 0;
            }
            
            if (i == n-1) {
                if (expresstionValue(state, n) == 0)
                {
                    printExpresstion(state, n);
                }
                i--;
            }
            if (i == -1) {
                break;
            }
        }
    }

	return 0;
}
