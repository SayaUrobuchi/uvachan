#include <stdio.h>

int n, m, o, h;
char map[150][150];

void dfs(int x, int y)
{
	if(x < 0 || x >= n || y < 0 || y >= m)
	{
		return;
	}
	map[x][y]++;
	if(map[x][y] > h)
	{
		map[x][y] -= 4;
		dfs(x-1, y);
		dfs(x+1, y);
		dfs(x, y-1);
		dfs(x, y+1);
	}
}

int main()
{
	int count, i, x, y;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &n, &m, &o, &h);
		h += 48;
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		while(o--)
		{
			scanf("%d%d", &x, &y);
			dfs(x-1, y-1);
		}
		for(i=0; i<n; i++)
		{
			puts(map[i]);
		}
	}
	return 0;
}
