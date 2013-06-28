#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int t;
	int m,n;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		map<string, string> voc;
		string word;
		char c;
		cin >> n >> m;
		for (int j = 0; j < m; j++)
		{
			string key,value;
			cin >> key >> value;
			voc[key] = value;
		}
		cout << "Case #"<< i <<": ";
		while (true)
		{
			cin >> word;
			for (int j = 1; j < n; j++)
			{
				if (voc.find(word) != voc.end())
				{
					word = voc[word];
				}
				else
				{
					break;
				}
			}
			cout << word;
			if ((c=getchar())=='\n' || c==EOF)
			{
				break;
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
