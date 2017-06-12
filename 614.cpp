#include <stdio.h>
#include <string.h>

int n, m, gx, gy;
int used[15][15];
int map[15][15];
int dis[15][15];
char buf[1005];

int valid(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

int recursion(int x, int y, int step)
{
	used[x][y] = 1;
	dis[x][y] = step;
	if(x == gx && y == gy)
	{
		return 1;
	}
	if(valid(x, y-1) && !used[x][y-1] && !(map[x][y-1] & 1))
	{
		if(recursion(x, y-1, step+1))
		{
			return 1;
		}
	}
	if(valid(x-1, y) && !used[x-1][y] && !(map[x-1][y] & 2))
	{
		if(recursion(x-1, y, step+1))
		{
			return 1;
		}
	}
	if(valid(x, y+1) && !used[x][y+1] && !(map[x][y] & 1))
	{
		if(recursion(x, y+1, step+1))
		{
			return 1;
		}
	}
	if(valid(x+1, y) && !used[x+1][y] && !(map[x][y] & 2))
	{
		if(recursion(x+1, y, step+1))
		{
			return 1;
		}
	}
	dis[x][y] = -1;
	return 0;
}

int main()
{
	int cas, i, j, sx, sy;
	char *ptr;
	cas = 0;
	while(scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &gx, &gy) == 6)
	{
		if(!n && !m && !sx && !sy && !gx && !gy)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		memset(dis, 0, sizeof(dis));
		memset(used, 0, sizeof(used));
		recursion(sx, sy, 1);
		printf("Maze %d\n\n", ++cas);
		printf("+");
		for(j=1; j<=m; j++)
		{
			printf("---+");
		}
		printf("\n");
		for(i=1; i<=n; i++)
		{
			printf("|");
			ptr = buf;
			*ptr++ = '+';
			for(j=1; j<=m; j++)
			{
				if(dis[i][j] == -1)
				{
					printf("???");
				}
				else if(dis[i][j])
				{
					printf("%3d", dis[i][j]);
				}
				else
				{
					printf("   ");
				}
				if(j == m || (map[i][j] & 1))
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
				if(i == n || (map[i][j] & 2))
				{
					strcpy(ptr, "---+");
					ptr += 4;
				}
				else
				{
					strcpy(ptr, "   +");
					ptr += 4;
				}
			}
			printf("\n%s\n", buf);
		}
		printf("\n\n");
	}
	return 0;
}
