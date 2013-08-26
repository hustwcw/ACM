#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int main()
{
    int letter[26] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int maxlen = 0;
    int curlen = 0;
    int count = 0; // 当前读入的字符个数 
    char c;
    while(scanf("%c", &c) != EOF)
    {
        if(c == '\r' || c == '\n')
        {
            if(maxlen < curlen)
            {
                maxlen = curlen;
            }
            if(maxlen > 0)
                cout << maxlen << endl;
            maxlen = 0;
            count = 0;
            curlen = 0;
            // 重置letter数组为-1
            for (int i = 0; i < 26; ++i)
            {
                letter[i] = -1;
            }
            continue;
        }

        int pos = c - 'a';
        ++count;
        if (letter[pos] == -1)
        {
            curlen++;
            letter[pos] = count;
        }
        else
        {
            if (maxlen < curlen)
            {
                maxlen = curlen;
            }
            curlen = count - letter[pos];
            int tmp = letter[pos];
            letter[pos] = count;
            for(int i = 0; i < 26; ++i)
            {
                if(letter[i] < tmp)
                {
                    letter[i] = -1;
                }
            }
        }
    }
    if(curlen > 0)
        cout << ((maxlen>curlen)?maxlen:curlen) << endl;
    return 0;
}
