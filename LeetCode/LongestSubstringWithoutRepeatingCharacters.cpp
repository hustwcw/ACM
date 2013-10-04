#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s.length() == 0)
        {
            return 0;
        }
        
        int maxLen = 1;
        int letter[26];
        int start = 0;
        for(int i = 0; i < 26; i++)
        {
            letter[i] = -1;
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(letter[s[i]-'a'] > start-1)
            {
                if((i-start) > maxLen)
                {
                    maxLen = i-start;
                }
                start = letter[s[i]-'a']+1;
            }
            letter[s[i]-'a'] = i;
        }
        if(s.length()-start > maxLen)
        {
            maxLen = s.length()-start;
        }
        return maxLen;
    }
};

int main(void)
{
	Solution s;
	cout << s.lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar") << endl;

	return 0;
}
