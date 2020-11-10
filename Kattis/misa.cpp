#include <iostream>

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char board[64][64];

int main()
{
	int n, m, i, j, k, tx, ty, t, best, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		for (i=0, best=0, ans=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				if (board[i][j] == '.')
				{
					for (k=0, t=0; k<8; k++)
					{
						tx = i + dx[k];
						ty = j + dy[k];
						if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] != '.')
						{
							++t;
						}
					}
					if (t > best)
					{
						best = t;
					}
				}
				else
				{
					for (k=0; k<8; k++)
					{
						tx = i + dx[k];
						ty = j + dy[k];
						if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] != '.')
						{
							++ans;
						}
					}
				}
			}
		}
		printf("%d\n", best+(ans>>1));
	}
	return 0;
}
