#include <stdio.h>

int n, m;
int tbl[] = {1, 2, 4, 6, 10, 12, 14, 16, 18, 20};
int wayx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int wayy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char map[600][600];

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void floodfill(int x, int y)
{
	int i, tx, ty;
	map[x][y] = '0';
	for(i=0; i<8; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty) && map[tx][ty] == '1')
		{
			floodfill(tx, ty);
		}
	}
}

int main()
{
	int i, j, c;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0, c=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '1')
				{
					c++;
					floodfill(i, j);
				}
			}
		}
		for(i=0; i<10; i++)
		{
			if(tbl[i] >= c)
			{
				break;
			}
		}
		if(i < 10)
		{
			i++;
		}
		printf("%d\n", i);
	}
	return 0;
}
