#include <iostream>

const char AIR = '.';
const char STONE = '#';
const char WATER = 'V';

int n, m;
int qx[32768], qy[32768];
char board[128][128];

void bfs(int j)
{
	int i, k, x, y;
	for (i=0; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		if (x+1 < n)
		{
			if (board[x+1][y] == AIR)
			{
				board[x+1][y] = WATER;
				qx[j] = x+1;
				qy[j] = y;
				j++;
			}
			else if (board[x+1][y] == STONE)
			{
				for (k=-1; k<=1; k+=2)
				{
					if (y+k >= 0 && y+k < m && board[x][y+k] == AIR)
					{
						board[x][y+k] = WATER;
						qx[j] = x;
						qy[j] = y+k;
						j++;
					}
				}
			}
		}
	}
}

int main()
{
	int i, j, k;
	while (scanf("%d%d", &n, &m) == 2)
	{
		k = 0;
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<m; j++)
			{
				if (board[i][j] == WATER)
				{
					qx[k] = i;
					qy[k] = j;
					k++;
				}
			}
		}
		bfs(k);
		for (i=0; i<n; i++)
		{
			puts(board[i]);
		}
	}
	return 0;
}
