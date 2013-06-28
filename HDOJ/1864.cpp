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
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    float f[30]; // N最大为30
    float Q;
    int N;
    scanf("%f %d", &Q, &N);
    while (N > 0) {
        for (int i = 0; i < N; i++) {
            int m;
            string item;
            scanf("%d", &m);
            while (m > 0) {
                cin >> item;
                --m;
            }
        }
    }
    

	return 0;
}
