#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	vector<int> vec(300);
	char c;
	int num = -1;
	vector<int>::iterator iter = vec.begin();
	while ((c=getchar()))
	{
		if (c == '5')
		{
			if (num >= 0)
			{
				*iter = num;
				++iter;
				num = -1;
			}
		}
		else if (c == '\n' || c == EOF)
		{
						if (num >= 0)
			{
				*iter = num;
				++iter;
				num = -1;
			}
			// ���������ݽ�������
			sort(vec.begin(), iter);
			for (vector<int>::iterator i = vec.begin(); i != iter; i++)
			{
				cout << *i;
				if (iter-i != 1)
				{
					cout << ' ';
				}
				else
				{
					cout << endl;
				}
			}
			if (c == EOF)
			{
				break;
			}
			iter = vec.begin();
		}
		else
		{
			if (num < 0)
			{
				num = 0;
			}
			num = num*10+c-'0';
		}
	}
	return 0;
}
