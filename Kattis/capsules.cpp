#include <iostream>

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
int board[64][64], len[64], idd[64][64];
bool used[64][64], gameover;
char buf[16];

void dfs(int x, int y)
{
	int i, j, id, nx, ny;
	bool gg;
	if (y >= m)
	{
		y = 0;
		++x;
		if (x >= n)
		{
			gameover = true;
			return;
		}
	}
	if (board[x][y])
	{
		dfs(x, y+1);
	}
	else
	{
		id = idd[x][y];
		for (i=1; i<=len[id]; i++)
		{
			if (!used[id][i])
			{
				gg = false;
				for (j=0; j<8&&!gg; j++)
				{
					nx = x + dx[j];
					ny = y + dy[j];
					if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == i)
					{
						gg = true;
					}
				}
				if (!gg)
				{
					used[id][i] = true;
					board[x][y] = i;
					dfs(x, y+1);
					if (gameover)
					{
						return;
					}
					used[id][i] = false;
					board[x][y] = 0;
				}
			}
		}
	}
}

int main()
{
	int i, j, o, a, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%s", buf);
				if (*buf == '-')
				{
					board[i][j] = 0;
				}
				else
				{
					sscanf(buf, "%d", &a);
					board[i][j] = a;
				}
			}
		}
		scanf("%d", &o);
		for (i=0; i<o; i++)
		{
			scanf("%d", &len[i]);
			for (j=1; j<=len[i]; j++)
			{
				used[i][j] = false;
			}
			for (j=0; j<len[i]; j++)
			{
				scanf(" (%d,%d)", &a, &b);
				--a, --b;
				if (board[a][b])
				{
					used[i][board[a][b]] = true;
				}
				else
				{
					idd[a][b] = i;
				}
			}
		}
		gameover = false;
		dfs(0, 0);
		for (i=0; i<n; i++)
		{
			printf("%d", board[i][0]);
			for (j=1; j<m; j++)
			{
				printf(" %d", board[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
