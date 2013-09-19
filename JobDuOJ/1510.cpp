/*
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */
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


int main()
{
	char ch;
	while((ch=getchar()) != '\n')
	{
		if(ch != ' ')
		{
			printf("%c", ch);
		}
		else
		{
			printf("%%20");
		}
	}
	return 0;
}
