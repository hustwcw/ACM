#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>

using namespace std;


class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        permute(num, 0);
        return result;
    }
    
    void permute(vector<int> &num, int start)
    {
        if(start == num.size())
        {
            result.push_back(num);
        }
        for(int i = start; i < num.size(); ++i)
        {
            if(i==start || num[i] != num[start])
            {
                swap(num[i], num[start]);
                permute(num, start+1);
                swap(num[i], num[start]);
            }

        }
    }
};


int main(void)
{
    int a[] = {1, 1, 1};
vector<int> vec;
int n = sizeof(a)/4;
cout << n << endl;
for(int i = 0; i < sizeof(a)/4; i++)
{
    vec.push_back(a[i]);
}
	Solution s;
	vector<vector<int> > result = s.permute(vec);
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
