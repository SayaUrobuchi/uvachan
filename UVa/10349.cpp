#include <stdio.h>
#include <string.h>

int n, m;
int used[45][15];
int sused[45][15];
int conn[45][15];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
char map[45][15];

int fill(int, int);

int counter(int now)
{
	return (now+2) % 4;
}

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int assign(int x, int y)
{
	int tx, ty;
	tx = x + wayx[conn[x][y]-1];
	ty = y + wayy[conn[x][y]-1];
	return !sused[tx][ty] && fill(tx, ty);
}

int fill(int x, int y)
{
	int i, tx, ty;
	sused[x][y] = 1;
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty) && map[tx][ty] == '*' && !used[tx][ty])
		{
			used[tx][ty] = 1;
			conn[x][y] = i + 1;
			conn[tx][ty] = counter(i) + 1;
			return 1;
		}
	}
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty) && map[tx][ty] == '*' && !sused[tx][ty])
		{
			sused[tx][ty] = 1;
			if(assign(tx, ty))
			{
				conn[x][y] = i + 1;
				conn[tx][ty] = counter(i) + 1;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, i, j, c;
	scanf("%d", &count);
	while(count--)
	{
		memset(used, 0, sizeof(used));
		memset(conn, 0, sizeof(conn));
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0, c=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(!used[i][j] && map[i][j] == '*')
				{
					used[i][j] = 1;
					memset(sused, 0, sizeof(used));
					fill(i, j);
					c++;
				}
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
