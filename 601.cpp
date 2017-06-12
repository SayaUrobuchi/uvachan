#include <stdio.h>
#include <string.h>

int n, flag;
int wayx[4] = {0, 0, 1, -1};
int wayy[4] = {1, -1, 0, 0};
int chk[82][82];
char map[82][82];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < n;
}

int floodfill(int x, int y, int type, int used)
{
	int i, tx, ty;
	chk[x][y] = 1 + used;
	if(!used && map[x][y] == type)
	{
		if(type == 'W' && y == n-1)
		{
			return 1;
		}
		else if(type == 'B' && x == n-1)
		{
			return 1;
		}
	}
	else if((used && map[x][y] == type) || map[x][y] == 'U')
	{
		if(type == 'W' && y == n-1)
		{
			flag = 1;
			return 0;
		}
		else if(type == 'B' && x == n-1)
		{
			flag = 1;
			return 0;
		}
	}
	used |= (map[x][y] == 'U');
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty) && ((!used && chk[tx][ty] == 2) || !chk[tx][ty]))
		{
			if(map[tx][ty] == type)
			{
				if(floodfill(tx, ty, type, used))
				{
					return 1;
				}
			}
			else if(map[tx][ty] == 'U' && !used)
			{
				floodfill(tx, ty, type, 1);
			}
		}
	}
	return 0;
}

int main()
{
	int i;
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
		memset(chk, 0, sizeof(chk));
		for(i=0, flag=0; i<n; i++)
		{
			if(map[i][0] != 'B' && floodfill(i, 0, 'W', 0))
			{
				printf("White has a winning path.\n");
				break;
			}
		}
		if(i == n)
		{
			if(flag)
			{
				printf("White can win in one move.\n");
			}
			else
			{
				memset(chk, 0, sizeof(chk));
				for(i=0, flag=0; i<n; i++)
				{
					if(map[i][0] != 'W' && floodfill(0, i, 'B', 0))
					{
						printf("Black has a winning path.\n");
						break;
					}
				}
				if(i == n)
				{
					if(flag)
					{
						printf("Black can win in one move.\n");
					}
					else
					{
						printf("There is no winning path.\n");
					}
				}
			}
		}
	}
	return 0;
}
