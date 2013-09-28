#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string.h>

using namespace std;


class Solution {
public:
    int longestPalindrome(char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strlen(s);
        if(n <= 1)
        {
            return n;
        }
        
        int maxLen = 1;
        int start = 0;
        char *arr = new char[3*n];
        memset(arr, 0, 3*n);

        for(int i = 0; i < n; i++)
        {
            arr[i] = 1;
            if(s[i] == s[i+1])
            {
                maxLen = 2;
                start = i;
                arr[i+n] = 1;
            }
        }
        
        char *cur = arr;
        char *newp = arr+2*n;
        for(int l = 0; l < n-2; l++)
        {
            for(int i = 1; i < n-l-1; i++)
            {
                if(cur[i] == 1 && s[i-1] == s[i+l+1])
                {
                    newp[i-1] = 1;
                    if(l+3 > maxLen)
                    {
                        maxLen = l+3;
                        start = i-1;
                    }
                }
            }
            // copy arr2 to arr1; copy arr3 to arr2;
            if(cur != (arr+2*n))
            {
                newp = cur;
                cur += n;
            }
            else
            {
                newp = cur;
                cur = arr;
            }
            memset(newp, 0, n);
        }
        
        delete[] arr;
        return maxLen;
    }
};

int main()
{
char str[200001];
Solution s;
while(scanf("%s", str) != EOF)
{
printf("%d\n", s.longestPalindrome(str));
}
}