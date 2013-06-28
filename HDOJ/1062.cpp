#include <iostream>
#include <string>
#include <map>


using namespace std;


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int t;
	int i;
	char text[1001];
	cin >> t;
	getchar();
	for (i = 0; i < t; i++)
	{
		memset(text, 0, 1001);
		gets(text);
		int start=0;
		int j;
		int len = strlen(text);
		for (j = 0; j <= len; j++)
		{
			if ((text[j] == ' ') || (j == len))
			{
				int k; int l;
				for (k = start, l=j-1; k < start + (j-start)/2; k++, l--)
				{
					char temp = text[k];
					text[k] = text[l];
					text[l] = temp;
				}
				start = j+1;
			}
		}
		cout << text << endl;
	}
	return 0;
}
