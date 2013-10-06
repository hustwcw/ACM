#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>
#include <stdio.h>


using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string result;
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        while(i>-1 && j>-1)
        {
            int tmp = a[i]+b[j]-'0'-'0'+carry;
            carry = tmp>>1;
            result.insert(0, 1, (tmp%2) + '0');
            --i;
            --j;
        }
        while(i>-1)
        {
            int tmp = a[i]-'0'+carry;
            carry = tmp>>1;
            result.insert(0, 1, (tmp%2)+'0');
            --i;
        }
        while(j>-1)
        {
            int tmp = b[j]-'0'+carry;
            carry = tmp>>1;
            result.insert(0, 1, (tmp%2)+'0');
            --j;
        }
        if(carry > 0)
        {
            result.insert(0, 1, carry+'0');
        }
        return result;
    }
};


int main(void)
{
    Solution s;
    cout << s.addBinary("0", string("1")) << endl;

    return 0;
}
