#include <stdio.h>

#define EMPTY -1

int n, m;
int map[11][41];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && map[x][y] != EMPTY;
}

int lonely(int x, int y)
{
	int i;
	for(i=0; i<4; i++)
	{
		if(valid(x+wayx[i], y+wayy[i]) && map[x][y] == map[x+wayx[i]][y+wayy[i]])
		{
			return 0;
		}
	}
	return 1;
}

void floodfill(int x, int y, int color)
{
	int i, tx, ty;
	map[x][y] = EMPTY;
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty) && map[tx][ty] == color)
		{
			floodfill(tx, ty, color);
		}
	}
}

void adjust()
{
	int i, j, k, len;
	int queue[45];
	for(j=0, len=0; j<m; j++)
	{
		for(i=0, k=0; i<n; i++)
		{
			if(map[i][j] != EMPTY)
			{
				map[k++][j] = map[i][j];
			}
		}
		if(!k)
		{
			queue[len++] = j;
		}
		for(; k<n; k++)
		{
			map[k][j] = EMPTY;
		}
	}
	for(i=len-1; i>-1; i--)
	{
		for(j=queue[i]; j+1<m; j++)
		{
			for(k=0; k<n; k++)
			{
				map[k][j] = map[k][j+1];
			}
		}
		for(k=0; k<n; k++)
		{
			map[k][j] = EMPTY;
		}
	}
}

int main()
{
	int cas, i, j, p, q;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n || !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		while(scanf("%d%d", &p, &q) == 2)
		{
			if(!p && !q)
			{
				break;
			}
			p--;
			q--;
			if(valid(p, q) && !lonely(p, q))
			{
				floodfill(p, q, map[p][q]);
				adjust();
			}
		}
		printf("Grid %d.\n", ++cas);
		if(map[0][0] == EMPTY)
		{
			printf("    Game Won\n\n");
		}
		else
		{
			for(i=n-1; i>-1; i--)
			{
				printf("   ");
				for(j=0; j<m; j++)
				{
					if(map[i][j] == EMPTY)
					{
						printf("  ");
					}
					else
					{
						printf(" %d", map[i][j]);
					}
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}
