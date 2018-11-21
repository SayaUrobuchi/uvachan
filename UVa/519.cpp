#include <stdio.h>
#include <string.h>

#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3
#define FLAT 'F'

int n, m, o;
int used[36];
int board[6][6];
char shape[36][5];

int dfs(int x, int y)
{
	int i;
	if(y >= m)
	{
		x++;
		y = 0;
	}
	if(x >= n)
	{
		return 1;
	}
	for(i=0; i<o; i++)
	{
		if(!used[i])
		{
			if((!x && shape[i][TOP] == FLAT) || (x && shape[i][TOP] != FLAT && shape[i][TOP] != shape[board[x-1][y]][BOTTOM]))
			{
				if((!y && shape[i][LEFT] == FLAT) || (y && shape[i][LEFT] != FLAT && shape[i][LEFT] != shape[board[x][y-1]][RIGHT]))
				{
					if((x == n - 1 && shape[i][BOTTOM] == FLAT) || (x < n - 1 && shape[i][BOTTOM] != FLAT))
					{
						if((y == m - 1 && shape[i][RIGHT] == FLAT) || (y < m - 1 && shape[i][RIGHT] != FLAT))
						{
							used[i] = 1;
							board[x][y] = i;
							if(dfs(x, y+1))
							{
								return 1;
							}
							used[i] = 0;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0, o=n*m; i<o; i++)
		{
			scanf("%s", shape[i]);
		}
		memset(used, 0, sizeof(used));
		memset(board, 0, sizeof(board));
		if(dfs(0, 0))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
