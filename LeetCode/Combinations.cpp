#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>
#include <stdio.h>


using namespace std;


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tmp;
        vector<vector<int> > result;
        combine(result, n, 1, k, tmp);
        return result;
    }
    
    void combine(vector<vector<int> > &result, int n, int start, int k, vector<int> tmp)
    {
        if(k == 0)
        {
            result.push_back(tmp);
        }
        else if(start <= n)
        {
            combine(result, n, start+1, k, tmp);
            
            tmp.push_back(start);
            combine(result, n, start+1, k-1, tmp);
        }
    }
};


int main(void)
{
    int a[] = {1,3,8,0,2,-1};
vector<int> vec;
int n = sizeof(a)/4;
cout << n << endl;
for(int i = 0; i < sizeof(a)/4; i++)
{
    vec.push_back(a[i]);
}
    Solution s;
    vector<vector<int> > result = s.combine(4, 3);
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
