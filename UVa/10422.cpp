#include <stdio.h>
#include <string.h>

int id;
int tbl[5][5] = {{1, 1, 1, 1, 1}, {0, 1, 1, 1, 1}, {0, 0, 2, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}};
int wayx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int wayy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
char map[5][6];

int valid(int x, int y)
{
	return x > -1 && x < 5 && y > -1 && y < 5;
}

int dfs(int x, int y, int depth, int state)
{
	int i, tx, ty, temp;
	/*printf("%d\n%s\n%s\n%s\n%s\n%s\n\n", state, map[0], map[1], map[2], map[3], map[4]);*/
	if(!state)
	{
		/*printf("XD\n%s\n%s\n%s\n%s\n%s\n\n", map[0], map[1], map[2], map[3], map[4]);*/
		return 1;
	}
	if(depth + state > id)
	{
		return 0;
	}
	if(depth == id)
	{
		return 0;
	}
	for(i=0; i<8; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty))
		{
			temp = map[tx][ty];
			map[tx][ty] = map[x][y];
			map[x][y] = temp;
			if(tbl[x][y] != tbl[tx][ty])
			{
				if(tbl[x][y] == map[x][y] - 48)
				{
					if(dfs(tx, ty, depth+1, state-1))
					{
						return 1;
					}
				}
				else if(tbl[tx][ty] == map[x][y] - 48)
				{
					if(dfs(tx, ty, depth+1, state+1))
					{
						return 1;
					}
				}
				else
				{
					if(dfs(tx, ty, depth+1, state))
					{
						return 1;
					}
				}
			}
			else
			{
				if(dfs(tx, ty, depth+1, state))
				{
					return 1;
				}
			}
			map[x][y] = map[tx][ty];
			map[tx][ty] = temp;
		}
	}
	return 0;
}

int main()
{
	int count, n, i, j, sx, sy, state;
	scanf("%d", &count);
	gets(map[0]);
	while(count--)
	{
		for(i=0, id=0; i<5; i++)
		{
			gets(map[i]);
			for(j=0; j<5; j++)
			{
				if(map[i][j] == ' ')
				{
					sx = i;
					sy = j;
				}
				else
				{
					id += (map[i][j] - 48 != tbl[i][j]);
				}
			}
		}
		for(state=id; id<11; id++)
		{
			/*printf("%d\n", id);*/
			if(dfs(sx, sy, 0, state))
			{
				printf("Solvable in %d move(s).\n", id);
				break;
			}
		}
		if(id > 10)
		{
			printf("Unsolvable in less than 11 move(s).\n");
		}
	}
	return 0;
}
