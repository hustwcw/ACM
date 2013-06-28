#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int d = 5000;
		string strA, strB;
		cin >> strA >> strB;
		int lenA = strA.length();
		int lenB = strB.length();
		for (int j = 0; j < lenA - lenB + 1; j++)
		{
			int tempD = 0;
			for (int k = 0; k < lenB; k++)
			{
				if (strA[j+k] != strB[k])
				{
					tempD ++;
				}
			}
			if (tempD < d)
			{
				d = tempD;
			}
		}

		cout << "Case #" << i << ": " << d << endl;
	}
	return 0;
}
