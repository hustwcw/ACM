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

using namespace std;



class Solution2 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> used(num.size(), false);
        vector<int> path;
        vector<vector<int> > ret;

        sort(num.begin(), num.end());
        sub(num, used, path, ret);
        return ret;
    }

    void sub(vector<int> &num, vector<bool> &used, vector<int> &path, vector<vector<int> > &ret) {
        if (num.size() == path.size()) {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < num.size(); ++i) {
            if (used[i] || (i != 0 && num[i] == num[i - 1] && used[i - 1])) continue;
            used[i] = true;
            path.push_back(num[i]);
            sub(num, used, path, ret);
            used[i] = false;
            path.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        permute(num, 0, result);
        return result;
    }
    
    void permute(vector<int> &num, int start, vector<vector<int> > &result)
    {
        if(start == num.size())
        {
            result.push_back(num);
        }
        for(int i = start; i < num.size(); ++i)
        {
            if(i==start || (num[i] != num[i-1] && num[i] != num[start]))
            {
                swap(num[i], num[start]);
                permute(num, start+1, result);
                swap(num[i], num[start]);
            }

        }
    }
};


int main()
{
    Solution s;
    vector<int> num;
    num.push_back(0); num.push_back(0); num.push_back(1); num.push_back(1); num.push_back(2);
    //num.push_back(2); num.push_back(3);
    vector<vector<int> > result1 = s.permuteUnique(num);
    cout << "result num:" << result1.size() << endl;

    Solution2 s2;
    vector<vector<int> > result2 = s2.permuteUnique(num);
    cout << "num2:" << result2.size() << endl;
    //return 0;
    for(int i = 0; i < result2.size(); ++i)
    {
        for(int j = 0; j < num.size(); ++j)
        {
            cout << result2[i][j];
        }
        cout << endl;
    }
    return 0;
}


