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
  int expandAroundCenter(char *s, int c1, int c2)
  {
    int l = c1-1, r = c2+1;
    int n = strlen(s);
    while(l > -1 && r < n && s[l] == s[r])
    {
      l--;
      r++;
    }
    return r-l-1;
  }
  int longestPalindrome(char *s) {
    int n = strlen(s);
    if(n < 2) return n;
    int maxLen = 1;
    for(int i = 0; i < n; i++)
    {
      int l1 = expandAroundCenter(s, i, i);
      if(l1 > maxLen)
        maxLen = l1;

      if(s[i] == s[i+1])
      {
        int l2 = expandAroundCenter(s, i, i+1);
        if(l2 > maxLen)
          maxLen = l2;
      }
    }
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
