#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    short A,B;
	int n;
    cin >> A >> B >> n;
	while (n!=0)
	{
		int i;
		short s1=1,s2=1;
		short temp;
		bool flag = true;
		char f[101];
		f[0]=f[1]=1;
		//n = (n%49)+49;
		for (i = 2; i < 101; i++)
		{
			if (flag)
			{
				temp = (A*s2+B*s1)%7;
				s1=temp;
				flag = false;
			}
			else
			{
				temp = (A*s1+B*s2)%7;
				s2=temp;
				flag = true;
			}
			f[i] = temp;
		}

		/* 根据数组f中的数字发现数字循环节 */
		int cycle;
		for (i = 0; i < 99; i++)
		{
			int j;
			for (j = 0; j < i+1; j++)
			{
				if (f[i]==f[j] && f[i+1]==f[j+1])
				{
					cycle = i-j;
					break;
				}
			}
		}
		
		cout << (int)f[(n%cycle)-1] << endl;

		cin >> A >> B >> n;
	}

	return 0;
}
