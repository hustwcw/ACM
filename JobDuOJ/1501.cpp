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
    float max = -1;
    float tempMax = 0;
    float firstNeg = 0;
    float lastNeg = 0;
    int n;
    float tmp;
    while (scanf("%d", &n) != EOF)
    {
        while (n > 0)
        {
            scanf("%f", &tmp);
            if (tmp == 0) {
                if (tempMax < 0) {
                    if (firstNeg < 0 && lastNeg < 0) {
                        if (firstNeg < lastNeg) {
                            tempMax /= lastNeg;
                        }
                        else
                        {
                            tempMax /= firstNeg;
                        }
                    }
                    else
                    {
                        tempMax /= firstNeg;
                    }
                }
                if (max < tempMax) {
                    max = tempMax;
                }

                tempMax = 0;
                firstNeg = 0;
                lastNeg = 0;
            }
            else {
                if (tempMax == 0) {
                    tempMax = tmp;
                }
                else {
                    tempMax *= tmp;
                }

                if (tmp < 0)
                {
                    if (firstNeg == 0)
                    {
                        firstNeg = tempMax;
                    }
                    else
                    {
                        lastNeg = tmp;
                    }
                }
                else if (lastNeg < 0)
                {
                    lastNeg *= tmp;
                }
            }
            
            --n;
        }
        if (tempMax < 0) {
            if (firstNeg < 0 && lastNeg < 0) {
                if (firstNeg < lastNeg) {
                    tempMax /= lastNeg;
                }
                else
                {
                    tempMax /= firstNeg;
                }
            }
            else
            {
                tempMax /= firstNeg;
            }
        }
        if (max < tempMax) {
            max = tempMax;
        }
        if (max < 0) {
            max = -1;
        }

        if (max != (int)max)
        {
            if (max*10 != (int)(max*10))
            {
                printf("%.2f\n", max);
            }
            else
            {
                printf("%.1f\n", max);
            }
        }
        else
        {
            printf("%.0f\n", max);
        }
        
        max = -1;
        tempMax = 0;
        firstNeg = 0;
        lastNeg = 0;
    }

	return 0;
}
