#include <stdio.h>

#define NO_ANS 1048576

int n, best;
int board[16][16], bb[16][16], cc[16][16];

void dfs(int now, int cnt)
{
	int i, j, t;
	if (now == n)
	{
		for (i=0; i<n; i++)
		{
			cc[0][i] = 0;
			if (i+1 < n)
			{
				cc[0][i] += bb[0][i+1];
			}
			if (i-1 >= 0)
			{
				cc[0][i] += bb[0][i-1];
			}
		}
		for (i=1; i<n&&cnt<best; i++)
		{
			for (j=0; j<n&&cnt<best; j++)
			{
				t = (cc[i-1][j]&1);
				if (!t && board[i][j])
				{
					break;
				}
				if (t && !board[i][j])
				{
					++cnt;
				}
				bb[i][j] = t;
			}
			if (j < n)
			{
				break;
			}
			for (j=0; j<n; j++)
			{
				cc[i][j] = bb[i-1][j];
				if (j+1 < n)
				{
					cc[i][j] += bb[i][j+1];
				}
				if (j-1 >= 0)
				{
					cc[i][j] += bb[i][j-1];
				}
				if (i == n-1 && (cc[i][j] & 1))
				{
					break;
				}
			}
			if (j < n)
			{
				break;
			}
		}
		if (i >= n)
		{
			if (cnt < best)
			{
				best = cnt;
			}
		}
		return;
	}
	bb[0][now] = board[0][now];
	dfs(now+1, cnt);
	if (!board[0][now])
	{
		bb[0][now] = 1;
		dfs(now+1, cnt+1);
	}
}

int main()
{
	int cas, count, i, j;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}
		best = NO_ANS;
		dfs(0, 0);
		printf("Case %d: %d\n", ++cas, best==NO_ANS?-1:best);
	}
	return 0;
}
