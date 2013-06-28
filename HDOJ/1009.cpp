#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BF
{
public:
	BF(int b, int f)
	{
		bean = b;
		food = f;
	}
	bool operator < (const BF &other)
	{
		if (this->bean/(float)this->food > other.bean/(float)other.food)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	int bean;
	int food;
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int m,n;
	cin >> m >> n;
	while (m!=-1)
	{
		vector<BF> vec;
		int bean;
		int food;
		for (int i = 0; i < n; i++)
		{
			cin >> bean >> food;
			vec.push_back(BF(bean, food));
		}
		sort(vec.rbegin(), vec.rend());
		float beanSum=0;
		for (vector<BF>::iterator iter = vec.begin(); iter!=vec.end() && m > 0; ++iter)
		{
			if (m>iter->food)
			{
				beanSum+=iter->bean;
				m-=iter->food;
			}
			else
			{
				beanSum += m*iter->bean/(float)iter->food;
				m=0;
			}
		}
		printf("%.3f\n", beanSum);
		cin >> m >> n;
	}

	return 0;
}