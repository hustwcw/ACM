#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>
#include <stdio.h>


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
            swap(num[i], num[start]);
            permute(num, start+1);
            swap(num[i], num[start]);
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
	vector<vector<int> > result = s.permute(vec);
    cout << result.size() << endl;
    // for(int i = 0; i < result.size(); i++)
    // {
    //     for(int j = 0; j < result[0].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int> > result2;
    char c;
    int count = 0;
    while(scanf("%c", &c) != EOF)
    {
        ++count;
        vector<int> tmp;
        int val;
        for(int i = 0; i < 6; i++)
        {
            scanf("%d", &val);
            tmp.push_back(val);
            getchar();
        }
        result2.push_back(tmp);
        getchar();
    }

    cout << count << endl;
    cout << "result2 size: " << result2.size() << endl;
    for(int i = 0; i < result2.size(); ++i)
    {
        auto iter = find(result.begin(), result.end(), result2[i]);
        if(iter == result.end())
        {
            cout << "error" << endl;
            for(int k = 0; k < result2[i].size(); ++k)
            {
                cout << result2[i][k] << " ";
            }
            cout << endl;
        }
    }

	return 0;
}
