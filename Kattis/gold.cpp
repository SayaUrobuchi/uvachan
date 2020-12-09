#include <iostream>

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct dd
{
	int x, y;
};

int ucnt, used[64][64];
char board[64][64];
dd qq[4096];

int main()
{
	int n, m, i, j, k, ans;
	bool wana;
	dd st, now, nxt;
	while (scanf("%d%d", &m, &n) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<m; j++)
			{
				if (board[i][j] == 'P')
				{
					st.x = i;
					st.y = j;
				}
			}
		}
		qq[0] = st;
		used[st.x][st.y] = ++ucnt;
		for (i=0, j=1, ans=0; i<j; i++)
		{
			now = qq[i];
			if (board[now.x][now.y] == 'G')
			{
				++ans;
			}
			for (wana=false, k=0; k<4; k++)
			{
				nxt = now;
				nxt.x += dx[k];
				nxt.y += dy[k];
				if (nxt.x >= 0 && nxt.x < n && nxt.y >= 0 && nxt.y < m)
				{
					if (board[nxt.x][nxt.y] == 'T')
					{
						wana = true;
						break;
					}
				}
			}
			if (!wana)
			{
				for (k=0; k<4; k++)
				{
					nxt = now;
					nxt.x += dx[k];
					nxt.y += dy[k];
					if (nxt.x >= 0 && nxt.x < n && nxt.y >= 0 && nxt.y < m)
					{
						if (board[nxt.x][nxt.y] != '#' && used[nxt.x][nxt.y] != ucnt)
						{
							used[nxt.x][nxt.y] = ucnt;
							qq[j] = nxt;
							j++;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
