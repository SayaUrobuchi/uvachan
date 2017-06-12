#include <stdio.h>
#include <string.h>

int c;
int tbl[67] = {	 1,  2,  3,  4,  5,  6,  7,  0,  0,  0, 
				 2,  8,  9, 10, 11, 12, 13,  0,  0,  0, 
				 3,  9, 14, 15, 16, 17, 18,  0,  0,  0, 
				 4, 10, 15, 19, 20, 21, 22,  0,  0,  0, 
				 5, 11, 16, 20, 23, 24, 25,  0,  0,  0, 
				 6, 12, 17, 21, 24, 26, 27,  0,  0,  0, 
				 7, 13, 18, 22, 25, 27, 28};
int used[29], board[7][8], map[7][8];

void dfs(int x, int y)
{
	int i, j, now;
	if(y == 8)
	{
		y = 0;
		x++;
		if(x == 7)
		{
			for(i=0; i<7; i++)
			{
				printf(" ");
				for(j=0; j<8; j++)
				{
					printf("%4d", board[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			c++;
			return;
		}
	}
	if(board[x][y])
	{
		dfs(x, y+1);
	}
	else
	{
		if(x < 6)
		{
			now = tbl[map[x][y]*10+map[x+1][y]];
			if(!used[now])
			{
				used[now] = 1;
				board[x][y] = board[x+1][y] = now;
				dfs(x, y+1);
				board[x][y] = board[x+1][y] = 0;
				used[now] = 0;
			}
		}
		if(y < 7 && board[x][y+1] == 0)
		{
			now = tbl[map[x][y]*10+map[x][y+1]];
			if(!used[now])
			{
				used[now] = 1;
				board[x][y] = board[x][y+1] = now;
				dfs(x, y+1);
				board[x][y] = board[x][y+1] = 0;
				used[now] = 0;
			}
		}
	}
}

int main()
{
	int cas, i, j;
	cas = 0;
	while(scanf("%d", &map[0][0]) == 1)
	{
		for(i=0; i<7; i++)
		{
			for(j=0+(!i); j<8; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		c = 0;
		if(cas)
		{
			printf("\n\n\n");
		}
		printf("Layout #%d:\n\n", ++cas);
		for(i=0; i<7; i++)
		{
			for(j=0; j<8; j++)
			{
				printf("%4d", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("Maps resulting from layout #%d are:\n\n", cas);
		memset(board, 0, sizeof(board));
		dfs(0, 0);
		printf("There are %d solution(s) for layout #%d.\n", c, cas);
	}
	return 0;
}
