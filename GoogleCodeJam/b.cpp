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

struct node
{
	node(unsigned long long a, unsigned long long b)
	{
		p = a;
		q = b;
	}
	unsigned long long p;
	unsigned long long q;
};


node fun1(unsigned long long n)
{
	if(n == 1)
	{
		return node(1, 1);
	}
	if(n%2 == 0)
	{
		node temp = fun1(n/2);
		return node(temp.p, temp.p+temp.q);
	}
	else
	{
		node temp = fun1(n/2);
		return node(temp.p+temp.q, temp.q);
	}
}

unsigned long long fun2(unsigned long long a, unsigned long long b)
{
	if(a==1&&b==1)
		return 1;
	if(a < b)
	{
		return fun2(a, b-a)*2;
	}
	else
	{
		return fun2(a-b, b)*2+1;
	}
}

int main()
{
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int t;
	unsigned long long n;
	unsigned long long  a, b;

	scanf("%d", &t);

	for(int i = 0; i < t; i++)
	{
		int type;
		scanf("%d", &type);
		printf("Case #%d: ", i+1);
		if(type == 1)
		{
			scanf("%llu", &n);
			node tmp = fun1(n);
			printf("%llu %llu\n", tmp.p, tmp.q);
		}
		else
		{
			scanf("%llu%llu", &a, &b);
			printf("%llu\n", fun2(a, b));
		}
	}
	return 0;
}

