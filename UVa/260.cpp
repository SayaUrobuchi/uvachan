#include <stdio.h>

int n;
int wayx[6]={-1, -1, 0, 0, 1, 1};
int wayy[6]={-1, 0, -1, 1, 0, 1};
char map[201][201];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < n;
}

int floodfill(int x, int y)
{
	int i, tx, ty;
	map[x][y] = 'b';
	if(y == n-1)
	{
		return 1;
	}
	for(i=0; i<6; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty) && map[tx][ty] == 'w')
		{
			if(floodfill(tx, ty))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int cas, i;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0; i<n; i++)
		{
			if(map[i][0] == 'w')
			{
				if(floodfill(i, 0))
				{
					break;
				}
			}
		}
		if(i < n)
		{
			printf("%d W\n", ++cas);
		}
		else
		{
			printf("%d B\n", ++cas);
		}
	}
	return 0;
}
