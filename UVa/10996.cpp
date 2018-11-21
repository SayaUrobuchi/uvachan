#include <stdio.h>
#include <string.h>

#define EMPTY 0
#define UNDETERMINED 0
#define BLACK 1
#define WHITE 2
#define AMBIGUOUS 3

int n, m, c, edge, step, bound, complete;
int qx[400], qy[400];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
char used[20][20];
char board[20][20];
char buf[2008];

int valid(int x, int y)
{
	return x >= 0 && x <= bound && y >= 0 && y <= bound && !used[x][y];
}

char getchess(int now)
{
	if(now == 'B')
	{
		return BLACK;
	}
	return WHITE;
}

void getarea(int x, int y, char color)
{
	int i, tx, ty;
	used[x][y] = 1;
	qx[c] = x;
	qy[c] = y;
	c++;
	for(i=0; i<4; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(valid(tx, ty))
		{
			if(board[tx][ty] == color)
			{
				getarea(tx, ty, color);
			}
			else if(board[tx][ty] == EMPTY)
			{
				complete = 0;
			}
		}
	}
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
			if(board[tx][ty] == EMPTY)
			{
				floodfill(tx, ty);
			}
			else
			{
				edge |= board[tx][ty];
			}
		}
	}
}

int main()
{
	int i, j, b, w, x, y, tx, ty;
	char color, chess;
	/*freopen("1.txt", "w", stdout);*/
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		step = -((1-n)/2);
		bound = (n-1)/2 + step;
		memset(board, 0, sizeof(board));
		b = w = 0;
		while(m--)
		{
			scanf("%s", buf);
			sscanf(buf, "%c(%d,%d)", &color, &x, &y);
			x += step;
			y += step;
			board[x][y] = (chess=getchess(color));
			memset(used, 0, sizeof(used));
			for(i=0; i<4; i++)
			{
				tx = x + wayx[i];
				ty = y + wayy[i];
				if(valid(tx, ty))
				{
					if(!used[tx][ty] && board[tx][ty] == 3-chess)
					{
						c = 0;
						complete = 1;
						getarea(tx, ty, board[tx][ty]);
						if(complete)
						{
							for(j=0; j<c; j++)
							{
								board[qx[j]][qy[j]] = EMPTY;
							}
							if(chess == WHITE)
							{
								w += c;
							}
							else
							{
								b += c;
							}
						}
					}
				}
			}
			/*printf("put %d %d\n", x, y);
			for(i=0; i<=bound; i++)
			{
				for(j=0; j<=bound; j++)
				{
					if(board[i][j] == EMPTY)
					{
						printf(".");
					}
					else if(board[i][j] == BLACK)
					{
						printf("B");
					}
					else
					{
						printf("W");
					}
				}
				printf("\n");
			}
			printf("\n");*/
		}
		memset(used, 0, sizeof(used));
		for(i=0; i<=bound; i++)
		{
			for(j=0; j<=bound; j++)
			{
				/*if(board[i][j] == EMPTY)
				{
					printf(".");
				}
				else if(board[i][j] == BLACK)
				{
					printf("B");
				}
				else
				{
					printf("W");
				}*/
				if(!used[i][j] && board[i][j] == EMPTY)
				{
					c = 0;
					edge = UNDETERMINED;
					floodfill(i, j);
					if(edge == WHITE)
					{
						w += c;
					}
					else if(edge == BLACK)
					{
						b += c;
					}
				}
			}
			/*printf("\n");*/
		}
		/*printf("\n");*/
		printf("%d %d\n", b, w);
	}
	return 0;
}
