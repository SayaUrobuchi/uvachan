#include <stdio.h>
#include <string.h>

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char dp[44000000], udp[44000000];
int tbl[128], rev_tbl[128];

void floodfill(char board[][5], int used[][4], int x, int y, int ch)
{
	int i;
	if(x < 0 || x >= 4 || y < 0 || y >= 4 || board[x][y] != ch)
	{
		return;
	}
	board[x][y] = 'E';
	used[x][y] = 1;
	for(i=0; i<4; i++)
	{
		floodfill(board, used, x+dx[i], y+dy[i], ch);
	}
}

void adjust(char board[][5])
{
	int i, j, k, l, temp;
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(board[j][i] == 'E')
			{
				for(k=j+1; k<4; k++)
				{
					if(board[k][i] != 'E')
					{
						break;
					}
				}
				if(k >= 4)
				{
					break;
				}
				for(l=j; k<4; k++, l++)
				{
					temp = board[l][i];
					board[l][i] = board[k][i];
					board[k][i] = temp;
				}
			}
		}
	}
}

int get_code(char board[][5])
{
	int i, j, k, res;
	for(i=0, k=1, res=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			res += k * tbl[board[i][j]];
			k *= 3;
		}
	}
	return res;
}

void decode(int code, char board[][5])
{
	int i, j;
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			board[i][j] = rev_tbl[code % 3];
			code /= 3;
		}
	}
}

int recurs(int code, int player)
{
	int i, j, res;
	int hs, ls;
	int used[4][4];
	char temp_board[4][5], board[4][5];
	if(udp[code])
	{
		return dp[code];
	}
	udp[code] = 1;
	decode(code, board);
	for(i=0; i<4; i++)
	{
		if(board[0][i] != 'E')
		{
			break;
		}
	}
	if(i >= 4)
	{
		return dp[code]=0;
	}
	hs = 0;
	ls = 0;
	memset(used, 0, sizeof(used));
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(board[i][j] != 'E' && used[i][j] == 0)
			{
				memcpy(temp_board, board, sizeof(temp_board));
				floodfill(temp_board, used, i, j, temp_board[i][j]);
				adjust(temp_board);
				res = -recurs(get_code(temp_board), 1-player);
				if(res < 0)
				{
					if(res-1 < ls)
					{
						ls = res - 1;
					}
				}
				else
				{
					if(res+1 < hs || hs == 0)
					{
						hs = res+1;
					}
				}
			}
		}
	}
	if(hs > 0)
	{
		return dp[code]=hs;
	}
	return dp[code]=ls;
}

int main()
{
	int cas, count, i, res;
	char board[4][5];
	tbl['B'] = 0;
	tbl['R'] = 1;
	tbl['E'] = 2;
	rev_tbl[0] = 'B';
	rev_tbl[1] = 'R';
	rev_tbl[2] = 'E';
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0; i<4; i++)
		{
			scanf("%s", board[i]);
		}
		memset(udp, 0, sizeof(udp));
		res = recurs(get_code(board), 0);
		if(res > 0)
		{
			printf("Case %d: win %d\n", ++cas, res);
		}
		else
		{
			printf("Case %d: loss %d\n", ++cas, -res);
		}
	}
	return 0;
}
