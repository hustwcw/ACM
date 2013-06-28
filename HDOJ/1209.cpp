#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class MyClock
{
public:
    MyClock(char *t)
	{
        hour = (t[0]-'0')*10 + t[1]-'0';
        minute = (t[3]-'0')*10 + t[4]-'0';
        float angleM = 360.0*minute/60;
        float angleH = 360.0*(hour%12 + minute/60.0)/12.0;
        angle = abs(angleH - angleM);
		if (angle > 180.0)
		{
            angle = 360.0 - angle;
		}
	}
    bool operator < (const MyClock &other)
	{
		if (this->angle < other.angle)
		{
            return true;
		}
		else if (this->angle == other.angle)
		{
			if (this->hour < other.hour || (this->hour == other.hour && this->minute < other.minute))
			{
                return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
            return false;
		}
	}
    int hour;
    int minute;
    float angle;
};


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    char str[6];
    vector<MyClock> vec;
	while (t-- > 0)
	{
		for (int i = 0; i < 5; i++)
		{
            scanf("%s", str);
            vec.push_back(MyClock(str));
		}
        sort(vec.begin(), vec.end());
        printf("%02d:%02d\n", vec[2].hour, vec[2].minute);
        vec.clear();
	}

	return 0;
}
