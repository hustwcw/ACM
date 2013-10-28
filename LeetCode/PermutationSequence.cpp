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
#include <limits.h>
#include <assert.h>


using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        assert(n <= 9);
        int fact[10];
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i < 10; ++i)
        {
            fact[i] = (i)*fact[i-1];
        }
        assert(k >= 1 && k <= fact[9]);
        
        string s; 
        vector<int> index(n,1);
        vector<bool> used(n, false); // 0~n-1是否使用过

        for(int i = n-1; i > -1; --i)
        {
            if(k <= fact[i])
            {
                int j = index[i];
                while(used[j-1]) ++j;
                index[i] = j;
            }
            else
            {
                while(k > fact[i])
                {
                    int j = index[i];
                    while(used[j-1]) ++j;
                    ++j;
                    while(used[j-1]) ++j;
                    index[i] = j;
                    k -= fact[i];
                }
            }

            used[index[i] - 1] = true;
        }
        
        for(int i = n-1; i > -1; i--)
        {
            s.push_back(index[i]+'0');
        }

        return s;
    }
};


int main()
{
    Solution s;
    //for(int i = 1; i <= 24; ++i)
        cout << s.getPermutation(9, 54494) << endl;

    return 0;
}