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

using namespace std;


int main()
{
  stack<int> sta;
  int val;
  while(true)
  {
      scanf("%d", &val);
      if(val == -1)
        break;
      sta.push(val);
    }
  while(!sta.empty())
  {
      printf("%d\n", sta.top());
      sta.pop();
  }
  return 0;
}

