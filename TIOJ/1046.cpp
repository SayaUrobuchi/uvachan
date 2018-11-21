#include <stdio.h>
#include <string.h>

int n, m, ans;
char map[10][10];

void change(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < m)
	{
		if(map[x][y] == 'O')
		{
			map[x][y] = 'X';
		}
		else
		{
			map[x][y] = 'O';
		}
	}
}

void press(int x, int y)
{
	change(x, y);
	change(x-1, y);
	change(x+1, y);
	change(x, y-1);
	change(x, y+1);
}

void dfs(int x, int y, int step)
{
	int i;
	if(y == m)
	{
		y = 0;
		x++;
		if(x == n)
		{
			for(i=0; i<m; i++)
			{
				if(map[n-1][i] == 'O')
				{
					break;
				}
			}
			if(i == m && step < ans)
			{
				ans = step;
			}
			return;
		}
	}
	if(x == 0)
	{
		dfs(x, y+1, step);
		press(x, y);
		dfs(x, y+1, step+1);
		press(x, y);
	}
	else if(x == n-1 && y && map[x-1][y] != map[x][y-1])
	{
		return;
	}
	else
	{
		if(map[x-1][y] == 'O')
		{
			press(x, y);
			dfs(x, y+1, step+1);
			press(x, y);
		}
		else
		{
			dfs(x, y+1, step);
		}
	}
}

int main()
{
	n = 0;
	while(1)
	{
		while(gets(map[n]))
		{
			if(*map[n] == 0)
			{
				break;
			}
			n++;
		}
		if(*map[0] == '#')
		{
			break;
		}
		m = strlen(map[0]);
		ans = 2147483647;
		dfs(0, 0, 0);
		if(ans == 2147483647)
		{
			printf("Another Skeleton in the Ancient Tomb!\n");
		}
		else
		{
			printf("Minimum Steps : %d\n", ans);
		}
		n = 0;
	}
	return 0;
}
