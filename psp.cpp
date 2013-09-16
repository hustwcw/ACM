#include <stdio.h>
#include <iostream>
#include <set>



using namespace std;

bool isPalindrome(int n)
{
	int result = 0;
	int number = n;
	if(n < 0)
	{
		return false;
	}
	while(n)
	{
		result = result*10+n%10;
		n = n/10;
	}
	if(result == number)
	{
		return true;
	}
	return false;
}


int main()
{
	int n;
	int from, to;
	set<int> pspSet;
	
	for(int i = 1; i < 100000000000001; i++)
	{
		if(isPalindrome(i) && isPalindrome(i*i))
		{
			pspSet.insert(i*i);
		}
	}
	
	cout << pspSet.size() << endl;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> from >> to;
	}
}
