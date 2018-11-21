#include <stdio.h>
#include <string.h>

#define UNDETERMINED 0
#define BLACK 1
#define WHITE 2
#define AMBIGUOUS 3

int c, edge;
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
int used[10][10];
char board[10][10];

int valid(int x, int y)
{
	return x >= 0 && x < 9 && y >= 0 && y < 9 && !used[x][y];
}

void floodfill(int x, int y)
{
	int i, tx, ty;
	used[x][y] = 1;
	c++;
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty))
		{
			if(board[tx][ty] == '.')
			{
				floodfill(tx, ty);
			}
			else if(board[tx][ty] == 'X')
			{
				edge |= BLACK;
			}
			else
			{
				edge |= WHITE;
			}
		}
	}
}

int main()
{
	int count, i, j, b, w;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0; i<9; i++)
		{
			scanf("%s", board[i]);
		}
		memset(used, 0, sizeof(used));
		for(i=0, b=w=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				if(board[i][j] == 'X')
				{
					b++;
				}
				else if(board[i][j] == 'O')
				{
					w++;
				}
				else if(!used[i][j])
				{
					edge = 0;
					c = 0;
					floodfill(i, j);
					if(edge == BLACK)
					{
						b += c;
					}
					else if(edge == WHITE)
					{
						w += c;
					}
				}
			}
		}
		printf("Black %d White %d\n", b, w);
	}
	return 0;
}
