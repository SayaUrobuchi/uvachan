#include <stdio.h>

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char board[16][16];

int main()
{
	int i, j, k, x, y, ans;
	for (i=0; i<7; i++)
	{
		scanf("%s", board[i]+(i<2||i>4?2:0));
	}
	for (i=0, ans=0; i<7; i++)
	{
		for (j=0; j<7; j++)
		{
			if (board[i][j] == 'o')
			{
				for (k=0; k<4; k++)
				{
					x = i + dx[k]*2;
					y = j + dy[k]*2;
					if (x >= 0 && x < 7 && y >= 0 && y < 7 && board[x][y] == '.')
					{
						if (board[i+dx[k]][j+dy[k]] == 'o')
						{
							++ans;
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
