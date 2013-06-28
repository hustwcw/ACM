#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int m, n, t;
	char maze[8][8];
	int state[51][3];
	cin >> m >> n >> t;
	while (m!=0)
	{
		int cur_x;
		int cur_y;
		int d_x;
		int d_y;
		int step = 0;
		for (int i = 0; i < m+2; i++)
		{
			for (int j = 0; j < n+2; j++)
			{
				if (i==0 || j==0 || i==(m+1) || j==(n+1))
				{
					maze[i][j] = 'X';
				}
				else
				{
					cin >> maze[i][j];
					if (maze[i][j] == 'S')
					{
						cur_x = i;
						cur_y = j;
						maze[i][j] = 'X';
						state[0][0]=cur_x;
						state[0][1] = cur_y;
						state[0][2] = 0;
					}
					else if (maze[i][j] == 'D')
					{
						d_x = i;
						d_y = j;
					}
				}
			}
		}

			while (true)
			{
				// 当前位置与目标位置的最短距离
				int s = abs(d_x-cur_x)+abs(d_y-cur_y);
				if ((t-step-s)%2 == 1 || t < s)
				{
					cout << "NO" << endl;
					break;
				}
				if (t-step < s)
				{
					--step;
					cur_x = state[step][0];
					cur_y = state[step][1];
					maze[cur_x][cur_y] = '.';
				}
				if (state[step][2] == 0)
				{
					state[step][2] = 1;
					if (maze[cur_x-1][cur_y] != 'X')
					{
						step++;
						maze[cur_x][cur_y] = 'X';
						--cur_x;
						state[step][0] = cur_x;
						state[step][1] = cur_y;
						state[step][2] = 0;
					}
					else
					{
						continue;
					}
				}
				else if (state[step][2] == 1)
				{
					state[step][2] = 2;
					if (maze[cur_x][cur_y-1] != 'X')
					{
					step++;
					maze[cur_x][cur_y] = 'X';
					--cur_y;
					state[step][0] = cur_x;
					state[step][1] = cur_y;
					state[step][2] = 0;
					}
					else
					{
						continue;
					}
				}
				else if (state[step][2] == 2)
				{
					state[step][2] = 3;
					if (maze[cur_x+1][cur_y] != 'X')
					{
					step++;
					maze[cur_x][cur_y] = 'X';
					++cur_x;
					state[step][0] = cur_x;
					state[step][1] = cur_y;
					state[step][2] = 0;
					}
					else
					{
						continue;
					}
				}
				else if (state[step][2] == 3)
				{
					state[step][2] = 4;
					if (maze[cur_x][cur_y+1] != 'X')
					{
					step++;
					maze[cur_x][cur_y] = 'X';
					++cur_y;
					state[step][0] = cur_x;
					state[step][1] = cur_y;
					state[step][2] = 0;
					}
					else
					{
						continue;
					}
				}
				else if (state[step][2] == 4 && step!=0)
				{
					// 周围的四个相邻位置都遍历过，回溯
					--step;
					cur_x = state[step][0];
					cur_y = state[step][1];
					maze[cur_x][cur_y] = '.';
				}
				
				if (step == 0 && (state[step][2] == 4))
				{
					cout << "NO" << endl;
					break;
				}
				if (step == t)
				{
					if (maze[cur_x][cur_y] == 'D')
					{
						cout << "YES" << endl;
						break;
					}
					else
					{
						--step;
						cur_x = state[step][0];
						cur_y = state[step][1];
						maze[cur_x][cur_y] = '.';
					}
				}
				else
				{
					if (maze[cur_x][cur_y] == 'D')
					{
						--step;
						cur_x = state[step][0];
						cur_y = state[step][1];
						maze[cur_x][cur_y] = '.';
					}
				}
			}

		cin >> m >> n >> t;
	}

	return 0;
}
