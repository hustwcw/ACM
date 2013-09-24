#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *p;
	TreeNode *left;
	TreeNode *right;
};


int main()
{
	int n;
	vector<pair> vec;

	while(scanf("%d", &n) != EOF)
	{
		int a, b;
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			vec.push_back(make_pair(a, b));
		}
		for(int i = 0; i < n; i++)
		{
			
		}
	}
	return 0;
}
