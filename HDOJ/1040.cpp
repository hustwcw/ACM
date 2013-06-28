#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    int T;
	//int data[1000];
	int *data;
	cin >> T;
	while ((T--) > 0)
	{
		int num;
		int temp;
		cin >> num;
		data = (int *)malloc(num*sizeof(int));
		for (int i = 0; i < num; i++)
		{
			cin >> data[i];
		}
		for (int i = 0; i < num; i++)
		{
			for (int j = i+1; j < num; j++)
			{
				if (data[i] > data[j])
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			cout << data[i];
			if (i!=num-1)
			{
				cout << " ";
			}
			else
			{
				cout << endl;
			}
		}
	}

	return 0;
}
