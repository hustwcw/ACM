/*
* Problem C. Sorting
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

int oddPatition(int *data, int n)
{
	int x;
	int end = n-1;
	while(data[end] % 2 == 0)
		end--;
	x = data[end];

}

void oddQuickSort(int *data, int n)
{
	if(n < 2)
		return;

	int q = oddPatition(data, n);
	oddQuickSort(data, q);
	oddQuickSort(data+q+1, n-q-1);
}



int evenPatition(int *data, int n)
{

}

void evenQuickSort(int *data, int n)
{
	if(n < 2)
		return;

	int q = evenPatition(data, n);
	evenQuickSort(data, q);
	evenQuickSort(data+q+1, n-q-1);
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int t;
	int n;
	int data[1000];
	int copy[1000];
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &data[j]);
		}

		memcpy(copy, data, n*sizeof(int));
	    sort(copy, copy+n);
	    int begin = 0; 
	    int end = n-1;
	    for(int j = 0; j < n; j++)
	    {
	    	if(data[j]%2 == 0)
	    	{
	    		while(end >= 0)
	    		{
	    			if(copy[end]%2 == 0)
	    			{
	    				data[j] = copy[end];
	    				end--;
	    				break;
	    			}
	    			else
	    			{
	    				end--;
	    			}
	    		}
	    	}
	    	else
	    	{
	    		while(begin < n)
	    		{
	    			if(copy[begin]%2 != 0)
	    			{
	    				data[j] = copy[begin];
	    				begin++;
	    				break;
	    			}
	    			else
	    			{
	    				begin++;
	    			}
	    		}
	    	}
	    }
/*
		// sort the odd number in position
		oddQuickSort(data, n);
		// sort the even number in position
		evenQuickSort(data, n);
*/
		printf("Case #%d:", i+1);
		for(int j = 0; j < n; j++)
		{
			printf(" %d", data[j]);
		}
		printf("\n");
	}
	return 0;
}
