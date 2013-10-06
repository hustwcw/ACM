#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>

using namespace std;


class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(ratings.size() == 0)
        {
            return 0;
        }
        int count = 1;
        int sum = 1;
        int last = ratings[0];
        int decCount = 1;
        bool isDec = false;
        int equalCount = 0;
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] < last)
            {
                // 递减
                --count;
                sum += count;
                isDec = true;
                ++decCount;
            }
            else if(ratings[i] > last)
            {
                if(isDec)
                {
                    if(count < 1)
                    {
                        sum += (1-count)*(decCount);
                        count = 1;
                    }
                    else if(count > 1)
                    {
                        sum -= (count-1)*(decCount-1+(equalCount>1?(equalCount-1):0));
                        count = 1;
                    }
                    isDec = false;
                    decCount = 1;
                    
                }
                else if(equalCount > 0 && count > 1)
                {
                    sum -= (count-1)*equalCount;
                    count = 1;
                }
                // 递增
                ++count;
                sum += count;
                equalCount= 0;
            }
            else
            {
                
                if(isDec)
                {
                    if(count < 1)
                    {
                        sum += (1-count)*(decCount);
                        count = 1;
                    }
                    else if(count > 1)
                    {
                        sum -= (count-1)*(decCount-1+(equalCount>1?(equalCount-1):0));
                        count = 1;
                    }
                    isDec = false;
                    decCount = 1;
                }
                else
                {
                    ++equalCount;
                }
                sum+= count;
            }
            last = ratings[i];
        }
        if(isDec)
        {
            if(count < 1)
                sum += (1-count)*decCount;
            else if (count > 1)
                sum -= (count-1)*(decCount-1+(equalCount>1?(equalCount-1):0));
        }
        else if(equalCount > 0 && count > 1)
        {
            sum -= (count-1)*equalCount;
        }
        
        return sum;
    }
};

int main(void)
{
    int a[] = {58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,
        76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,
        15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,
        51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,
        46,57,82,22,67,89};
vector<int> vec;
int n = sizeof(a)/4;
cout << n << endl;
for(int i = 0; i < sizeof(a)/4; i++)
{
    vec.push_back(a[i]);
}
	Solution s;
	cout << s.candy(vec) << endl;

	return 0;
}
