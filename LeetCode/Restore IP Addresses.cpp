#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string.h>

using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if(s.length() < 4)
        {
            return ret;
        }
        int n = s.length();
        string str1, str2, str3, str4;
        for(int i = 1; i < 4; i++)
        {
        	if(n-i < 3 || n-i > 9)
        	{
        		continue;
        	}
            if(i == 3 && (s.substr(0, 3) > "255"))
            {
            	continue;
            }
            str1 = s.substr(0, i);
            if(str1.length() > 1 && str1[0] == '0')
            	continue;

            for(int j = 1; j < 4; j++)
            {
            	if(n-i-j < 2 || n-i-j > 6)
            	{
            		continue;
            	}
            	if(j == 3 && (s.substr(i, 3) > "255"))
            	{
            		continue;
            	}
            	str2 = s.substr(i, j);
            	if(str2.length() > 1 && str2[0] == '0')
            		continue;

            	for(int k = 1; k < 4; k++)
            	{
            		if(n-i-j-k < 1 || n-i-j-k > 3)
            		{
            			continue;
            		}
            		if(k == 3 && (s.substr(i+j, 3) > "255"))
            		{
            			continue;
            		}
            		str3 = s.substr(i+j, k);
            		str4 = s.substr(i+j+k, n-i-j-k);
            		if((str3.length() > 1 && str3[0] == '0') || (str4.length() > 1 && str4[0] == '0'))
            			continue;
            		if(str4.length() < 3 ||(str4 <= "255"))
            		{
            			ret.push_back(str1+'.'+str2+'.'+str3+'.'+str4);
            		}
            	}
            }
        }
        return ret;
    }
};

int main()
{
  Solution s;
  string str;
  while(cin >> str)
  {
  	vector<string> vec = s.restoreIpAddresses(str);
  	cout << vec.size() << endl;
  	for(auto iter = vec.begin(); iter != vec.end(); iter++)
  	{
  		cout << *iter << endl;
  	}
  }
  

  return 0;
}
