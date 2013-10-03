#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


int longestValidParentheses(char *str)
{
  int n = strlen(str);
  stack<int> sta;
  int maxLen = 0;
  int last = -1;

  for(int i = 0; i < n; i++)
  {
    if(str[i] == '(')
    {
      sta.push(i);
    }
    else
    {
      if(!sta.empty())
      {
        sta.pop();
        if(sta.empty())
        {
          maxLen = max(maxLen, i-last);
        }
        else
        {
          maxLen = max(maxLen, i-sta.top());
        }
      }
      else
      {
        last = i;
      }
    }
  }

  return maxLen;
}
int main()
{
  char str[10000];
  while(scanf("%s", str) != EOF)
  {
    printf("%d\n", longestValidParentheses(str));
  }
	return 0;
}
