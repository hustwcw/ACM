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

void readPhoneNumber(int a, int num)
{
	string str1, str2;
	bool flag = true;
	switch(a)
	{
		case 0:
		str1 = " zero";
		break;
		case 1:
		str1 = " one";
		break;
		case 2:
		str1 = " two";
		break;
		case 3:
		str1 = " three";
		break;

		case 4:
		str1 = " four";
		break;

		case 5:
		str1 = " five";
		break;

		case 6:
		str1 = " six";
		break;

		case 7:
		str1 = " seven";
		break;

		case 8:
		str1 = " eight";
		break;

		case 9:
		str1 = " nine";
		break;

		default:
		break;
	}

	switch(num)
	{
		case 1:
		str2 = "";
		break;

		case 2:
		str2 = " double";
		break;

		case 3:
		str2 = " triple";
		break;

		case 4:
		str2 = " quadruple";
		break;

		case 5:
		str2 = " quintuple";
		break;

		case 6:
		str2 = " sextuple";
		break;

		case 7:
		str2 = " septuple";
		break;

		case 8:
		str2 = " octuple";
		break;

		case 9:
		str2 = " nonuple";
		break;

		case 10:
		str2 = " decuple";
		break;

		default:
		flag = false;
		break;
	}

	if(flag)
	{
		printf("%s%s", str2.c_str(), str1.c_str());
	}
	else
	{
		for(int i = 0; i < num; i++)
		{
			printf("%s", str1.c_str());
		}
	}
}
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int t;
	int n;
	string number;
	int count;

	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		cin >> number;
		printf("Case #%d:", i+1);
		n = number.length();
		scanf("%d", &count);
		char last = number[0];
		int num = 1;
		count--;
		for(int j = 1; j < n; j++)
		{
			if(count == 0)
			{
				readPhoneNumber(last-'0', num);
				getchar();
				scanf("%d", &count);
				last = number[j];
				num = 1;
			}
			else
			{
				if(number[j] == last)
				{
					num++;
				}
				else
				{
					readPhoneNumber(last-'0', num);
					last = number[j];
					num=1;
				}
			}
			count--;
		}
		readPhoneNumber(last-'0', num);
		printf("\n");

	}
	return 0;
}
