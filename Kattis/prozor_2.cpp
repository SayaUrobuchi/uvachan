#include <stdio.h>

int dp[256][256], ary[256][256], col[256];
char board[256][256];

int main()
{
	int n, m, o, i, j, k, l, t, ax, ay, ans;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%s", board[i]+1);
			for (j=1; j<=m; j++)
			{
				ary[i][j] = (board[i][j] == '*' ? 1 : 0);
			}
		}
		for (j=1; j<=m; j++)
		{
			col[j] = 0;
			for (i=2; i<o; i++)
			{
				col[j] += ary[i][j];
			}
		}
		for (l=2, i=o, ans=0; i<=n; i++, l++)
		{
			for (j=2, t=0; j<o; j++)
			{
				t += col[j];
			}
			for (k=2; j<=m; j++, k++)
			{
				if (t > ans)
				{
					ans = t;
					ax = i;
					ay = j;
				}
				t -= col[k];
				t += col[j];
			}
			for (j=1; j<=m; j++)
			{
				col[j] -= ary[l][j];
				col[j] += ary[i][j];
			}
		}
		printf("%d\n", ans);
		for (i=ax-o+1; i<=ax; i++)
		{
			board[i][ay-o+1] = board[i][ay] = '|';
		}
		for (j=ay-o+1; j<=ay; j++)
		{
			board[ax][j] = board[ax-o+1][j] = '-';
		}
		board[ax][ay] = board[ax][ay-o+1] = board[ax-o+1][ay] = board[ax-o+1][ay-o+1] = '+';
		for (i=1; i<=n; i++)
		{
			puts(board[i]+1);
		}
	}
	return 0;
}
