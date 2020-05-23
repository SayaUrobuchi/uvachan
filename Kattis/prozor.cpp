#include <stdio.h>

int dp[256][256];
char board[256][256];

int main()
{
	int n, m, o, i, j, t, ax, ay, ans;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%s", board[i]+1);
			for (j=1; j<=m; j++)
			{
				dp[i][j] = (board[i][j] == '*' ? 1 : 0) + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
		for (i=o, ans=0; i<=n; i++)
		{
			for (j=o; j<=m; j++)
			{
				t = dp[i-1][j-1] - dp[i-o+1][j-1] - dp[i-1][j-o+1] + dp[i-o+1][j-o+1];
				if (t > ans)
				{
					ans = t;
					ax = i;
					ay = j;
				}
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
