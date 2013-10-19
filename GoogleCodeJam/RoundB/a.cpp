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


class Solution {
public:
    bool isValidSudoku(vector<vector<int> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int n = board.size();
    	int m = sqrt(n);
        vector<vector<bool> > rows(n, vector<bool>(n, false));
        vector<vector<bool> > cols(n, vector<bool>(n, false));
        vector<vector<bool> > blocks(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = board[i][j];
                if (rows[i][c] || cols[j][c] || blocks[i - i % m + j / m][c])
                    return false;
                rows[i][c] = cols[j][c] = blocks[i - i % m + j / m][c] = true;
            }
        }
        return true;
    }
};


int main()
{
  int t;
  int n;
  Solution s;
  scanf("%d", &t);
  vector<vector<int> > matrix;
  for(int k = 0; k < t; k++)
  {
  	bool flag = true;
  	scanf("%d", &n);
  	n *= n;
  	matrix.clear();
  	vector<int> row;
  	for(int i = 0; i < n; i++)
  	{
  		int val;
  		row.clear();
  		for(int j = 0; j < n; j++)
  		{
  			scanf("%d", &val);
  			if(val > n)
  			{
  				flag = false;
  				break;
  			}
  			row.push_back(val);
  		}
  		if(flag == false)
  		{
  			break;
  		}
  		matrix.push_back(row);
  		
  	}
  	cout << flag << endl;
  	if(flag == true)
  	{
  		flag = s.isValidSudoku(matrix);
  	}
  	printf("Case #%d: %s\n", k+1, ((flag)?"Yes":"No"));
  }
	return 0;
}
