#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;


int main()
{
	multiset<string>  stringSet;
	int n;
	while (scanf("%d", &n) != EOF)
	{
		string temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			stringSet.insert(temp);
		}
		for (set<string>::iterator iter = stringSet.begin(); iter!=stringSet.end(); iter++)
		{
			printf("%s", (*iter).c_str());
		}
		stringSet.clear();
		cout << endl;
	}
	return 0;
}


//
//#include <stdio.h>
//
//
////using namespace std;
//
//struct node
//{
//	int value;
//	struct node *lnode;
//	struct node *rnode;
//};
//int main()
//{
//	struct node *root;
//	struct node *p;
//	int n;
//	int nodeArray[1000];
//	while(scanf("%d", &n)!=EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", nodeArray+i);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			char child;
//			scanf("%c", &child);
//			if (child == 'd')
//			{
//				struct node aNode = {nodeArray[i], NULL, NULL};
//			}
//			else if (child == 'l')
//			{
//
//			}
//			else if (child == 'r')
//			{
//
//			}
//			else// if (child == 'z')
//			{
//
//			}
//		}
//	}
//
//
//	return 0;
//}
