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
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        string result;
        while(true)
        {
            auto iter = strs.begin();
            if(i == iter->length())
            {
                return result;
            }
            char c = (*iter)[i];
            iter++;
            for(; iter != strs.end(); iter++)
            {
                if(i == iter->length() || (*iter)[i] != c)
                {
                    return result;
                }
            }
            result += c;
            i++;
        }
    }
};
int main()
{
	Solution s;

	vector<string> vec;
	vec.push_back("wang");
	vec.push_back("wan");
	vec.push_back("wanchang");
	cout << s.longestCommonPrefix(vec) << endl;

	return 0;
}
