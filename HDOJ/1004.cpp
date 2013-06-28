#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    int N;
    cin >> N;
	while (N > 0)
	{
		map<string, int> color_map;
		for (int i = 0; i < N; i++)
		{
			string color;
			cin >> color;
			color_map[color]++;
		}
		string key; int max=0;
		for (map<string, int>::iterator it = color_map.begin(); it != color_map.end(); it++)
		{
			if (it->second > max)
			{
				max = it->second;
				key = it->first;
			}
		}
		cout << key << endl;
		cin >> N;
	}

	return 0;
}
