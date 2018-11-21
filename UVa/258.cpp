#include <stdio.h>
#include <string.h>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int n, m, used[55][55];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
char map[55][55];

int getdir(char mirr, int dir)
{
	if(mirr == '\\')
	{
		if(dir == LEFT)
		{
			return UP;
		}
		if(dir == UP)
		{
			return LEFT;
		}
		if(dir == RIGHT)
		{
			return DOWN;
		}
		return RIGHT;
	}
	else if(mirr == '/')
	{
		if(dir == LEFT)
		{
			return DOWN;
		}
		if(dir == UP)
		{
			return RIGHT;
		}
		if(dir == RIGHT)
		{
			return UP;
		}
		return LEFT;
	}
}

int dfs(int x, int y, int dir)
{
	int i, d;
	if(x < 0 || x >= n || y < 0 || y >= m)
	{
		for(i=0; i<n; i++)
		{
			printf("%s\n", map[i]);
		}
		return 1;
	}
	if(map[x][y] == '*')
	{
		return 0;
	}
	if(map[x][y] == '.')
	{
		return dfs(x+wayx[dir], y+wayy[dir], dir);
	}
	if(used[x][y])
	{
		dir = getdir(map[x][y], dir);
		return dfs(x+wayx[dir], y+wayy[dir], dir);
	}
	else
	{
		d = dir;
		used[x][y] = 1;
		map[x][y] = '\\';
		dir = getdir('\\', d);
		if(dfs(x+wayx[dir], y+wayy[dir], dir))
		{
			return 1;
		}
		map[x][y] = '/';
		dir = getdir('/', d);
		if(dfs(x+wayx[dir], y+wayy[dir], dir))
		{
			return 1;
		}
		used[x][y] = 0;
	}
	return 0;
}

int main()
{
	int cas, i;
	cas = 0;
	while(scanf("%d%d", &m, &n) == 2)
	{
		if(n == -1 && m == -1)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		memset(used, 0, sizeof(used));
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		for(i=0; i<n; i++)
		{
			if(map[i][0] == '.')
			{
				dfs(i, 0, RIGHT);
				break;
			}
			if(map[i][m-1] == '.')
			{
				dfs(i, m-1, LEFT);
				break;
			}
		}
		if(i == n)
		{
			for(i=0; i<m; i++)
			{
				if(map[0][i] == '.')
				{
					dfs(0, i, DOWN);
					break;
				}
				if(map[n-1][i] == '.')
				{
					dfs(n-1, i, UP);
					break;
				}
			}
		}
	}
	return 0;
}
