#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>

using namespace std;


class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(num.size() < 3)
        {
            return vector<vector<int> >();
        };
        sort(num.begin(), num.end());
        return kSum(num, target, 0, 4);
    }
    
    vector<vector<int> > kSum(vector<int> &num, int target, int s, int k)
    {
        vector<vector<int> >result;
        if(k > 2)
        {
            vector<vector<int> > tmpResult;
            int last = INT_MIN;
            for(int i = s; i < num.size()-k+1; i++)
            {
                if(num[i] == last)
                {
                    continue;
                }
                last = num[i];
                tmpResult = kSum(num, target-num[i], i+1, k-1);
                for(int k = 0; k < tmpResult.size(); k++)
                {
                        tmpResult[k].insert(tmpResult[k].begin(), num[i]);
                    result.push_back(tmpResult[k]);
                }
            }
        }
        else
        {
            int start = s;
            int end = num.size()-1;
            vector<int> tmp;
            vector<int> old;
            while(start < end)
            {
                if(num[start]+num[end] > target)
                {
                    end--;
                }
                else if(num[start]+num[end] < target)
                {
                    start++;
                }
                else
                {
                    tmp.push_back(num[start]);
                    tmp.push_back(num[end]);
                    if(tmp != old)
                    {
                        result.push_back(tmp);
                        old = tmp;
                    }
                    tmp.clear();
                    start++;
                    end--;
                }
            }
        }
        
        return result;
    }
};
int main(void)
{
vector<int> vec;
vec.push_back(-3);vec.push_back(-3);vec.push_back(-3);
vec.push_back(-3);
vec.push_back(-1);
vec.push_back(-1);vec.push_back(-1);
vec.push_back(4);
vec.push_back(4);vec.push_back(4);
	Solution s;
	vector<vector<int> >result = s.fourSum(vec, 2);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j= 0; j< 4; j++)
		{
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}
