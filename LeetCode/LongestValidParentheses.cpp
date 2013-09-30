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


class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxLen = 0;
        int last = -1;
        stack<int> sta;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
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
};
int main()
{
	Solution s;
    string str;
	while(cin >> str)
	cout << s.longestValidParentheses(str) << endl;

	return 0;
}
