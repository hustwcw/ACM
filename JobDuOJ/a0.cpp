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


char trans[] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', 
'6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};

int main()
{
	char c;
	while(scanf("%c", &c) != EOF)
	{
		if(c != '\n')
			c = trans[c-'a'];
		printf("%c", c);
	}
	return 0;
}
