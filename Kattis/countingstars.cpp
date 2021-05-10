#include <iostream>

const char STAR = '-';

struct nod
{
	int x, y;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
int ucnt;
int used[128][128];
char board[128][128];
nod qq[16384];

void bfs(int sx, int sy)
{
	int i, j, k;
	qq[0].x = sx;
	qq[0].y = sy;
	used[sx][sy] = ucnt;
	for (i=0, j=1; i<j; i++)
	{
		nod now = qq[i];
		for (k=0; k<4; k++)
		{
			nod nxt = now;
			nxt.x += dx[k];
			nxt.y += dy[k];
			if (nxt.x >= 0 && nxt.x < n && nxt.y >= 0 && nxt.y < m && used[nxt.x][nxt.y] != ucnt)
			{
				if (board[nxt.x][nxt.y] == STAR)
				{
					qq[j] = nxt;
					used[nxt.x][nxt.y] = ucnt;
					++j;
				}
			}
		}
	}
}

int main()
{
	int cas, i, j, ans;;
	cas = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		++ucnt;
		for (i=0, ans=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				if (used[i][j] != ucnt && board[i][j] == STAR)
				{
					bfs(i, j);
					++ans;
				}
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
