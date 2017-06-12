#include <stdio.h>
#include <string.h>

int n, m;
int visited[100][100];
int wayx[4] = {1, 0, -1, 0};
int wayy[4] = {0, 1, 0, -1};
int tbl[5];
char map[100][101];

int wall(int x, int y)
{
	return x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '1';
}

int main()
{
	int i, j, x, y, tx, ty, dir, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		memset(visited, 0, sizeof(visited));
		for(x=n-1, y=0, dir=1; ; )
		{
			visited[x][y]++;
			temp = dir + 3;
			if(temp >= 4)
			{
				temp -= 4;
			}
			if(!wall(tx=x+wayx[temp], ty=y+wayy[temp]))
			{
				x = tx;
				y = ty;
				dir = temp;
			}
			else
			{
				for(; ; dir++)
				{
					if(dir == 4)
					{
						dir = 0;
					}
					tx = x + wayx[dir];
					ty = y + wayy[dir];
					if(!wall(tx, ty))
					{
						x = tx;
						y = ty;
						break;
					}
				}
			}
			if(x == n-1 && y == 0)
			{
				break;
			}
		}
		memset(tbl, 0, sizeof(tbl));
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '0')
				{
					if(visited[i][j] < 5)
					{
						tbl[visited[i][j]]++;
					}
				}
			}
		}
		printf("%3d%3d%3d%3d%3d\n", tbl[0], tbl[1], tbl[2], tbl[3], tbl[4]);
	}
	return 0;
}
