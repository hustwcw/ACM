#include <iostream>
#include <string>
#include <map>

using namespace std;


int digitsum(int m)
{
	int sum = 0;
	while (m > 0)
	{
		sum += (m%10);
		m /= 10;
		if (m == 0 && sum > 9)
		{
			m = sum;
			sum = 0;
		}
	}

	return sum;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	string str;
	cin >> str;
	while (str != "0")
	{
		int sum = 0;
		for (int i = 0; i < str.length(); i++)
		{
			sum += (str.at(i)-'0');
		}
		int root = digitsum(sum);
		cout << root << endl;

		cin >> str;
	}

	return 0;
}
