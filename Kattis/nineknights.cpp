#include <iostream>

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
char board[16][16];

int main()
{
	int i, j, k, x, y, cnt;
	bool gg;
	while (scanf("%s", board[0]) == 1)
	{
		for (i=1; i<5; i++)
		{
			scanf("%s", board[i]);
		}
		for (i=0, gg=false, cnt=0; i<5&&!gg; i++)
		{
			for (j=0; j<5&&!gg; j++)
			{
				if (board[i][j] == 'k')
				{
					++cnt;
					for (k=0; k<8&&!gg; k++)
					{
						x = i + dx[k];
						y = j + dy[k];
						if (x >= 0 && x < 5 && y >= 0 && y < 5 && board[x][y] == 'k')
						{
							gg = true;
						}
					}
				}
			}
		}
		puts((gg||cnt!=9)?"invalid":"valid");
	}
	return 0;
}
