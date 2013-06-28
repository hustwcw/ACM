#include <iostream>
#include <string>
#include <map>
#include <cmath>


#define D 300000
using namespace std;

typedef struct
{
	int data;
	int next;
}element;

element diamond[D];
int head;

void cut(int a, int b, int c)
{
	int ap,a_prior,bp, b_next, cp, c_next;
	int k = head;
	for (int i = 1; i < b; i++)
	{
		if (i==a-1)
		{
			ap = k;
		}
		k = diamond[k].next;
	}

}

void flip(int a, int b)
{
	
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for (int i = 0; i < D; i++)
	{
		diamond[i].data = i+1;
		diamond[i].next = i+1;
	}
	int m,n;
	cin >> m >> n;
	while (m > 0)
	{
		head = 0;
		diamond[m-1].next = -1;
		string op;
		int a, b, c;
		while (n>0)
		{
			cin >> op;
			if (op=="CUT")
			{
				cin >> a >> b >> c;
				cut(a, b, c);
			}
			else
			{
				cin >> a >> b;
				flip(a, b);
			}
			n--;
		}
		// output
		for (int i=head; i>=0; i=diamond[i].next)
		{
			cout << diamond[i].data;
			if (diamond[i].next>=0)
			{
				cout << " ";
			}else
			{
				cout << endl;
			}
		}
		cin >> m >> n;
	}

	return 0;
}
