#include <iostream>
#include <string>
#include <map>

using namespace std;


bool isvowel(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	string password;
	cin >> password;
	while (password != "end")
	{
		int i;
		char last=0;
		int dupNum=1;
		bool acceptFlag = true;
		bool vowelFlag = false;
		int vowelNum=0;
		int consonantNum = 0;
		for (i = 0; i < password.length(); i++)
		{
			if (isvowel(password.at(i)) )
			{
				vowelFlag = true;
				vowelNum++;
				consonantNum=0;
			}
			else
			{
				vowelNum = 0;
				consonantNum++;
			}

			if (password.at(i) == last)
			{
				dupNum++;
			}
			else
			{
				dupNum=1;
				last = password.at(i);
			}

			if (((dupNum == 2) && (last != 'e') && (last != 'o')) || (vowelNum == 3) || (consonantNum == 3))
			{
				acceptFlag = false;
				break;
			}
		}

		if (vowelFlag && acceptFlag)
		{
			cout << "<" << password << "> is acceptable." << endl;
		}
		else
		{
			cout << "<" << password << "> is not acceptable." << endl;
		}

		cin >> password;
	}

	return 0;
}
