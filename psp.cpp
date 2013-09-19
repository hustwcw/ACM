#include <stdio.h>
#include <iostream>
#include <set>



using namespace std;

bool isPalindrome(long long n)
{
	long long result = 0;
	long long number = n;
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
	long long n;
	long long from, to;
	set<long long> pspSet;
	
	for(int i = 1; i < 10000001; i++)
	{
		if(isPalindrome(i) && isPalindrome(i*i))
		{
			pspSet.insert(i*i);
		}
	}
	
	cout << pspSet.size() << endl;
  for (auto iter = pspSet.begin(); iter != pspSet.end(); iter++)
  {
    cout << *iter << endl;
  }
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> from >> to;
	}
}
