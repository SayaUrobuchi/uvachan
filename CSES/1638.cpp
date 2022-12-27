#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[1024][1024];
char board[1024][1024];

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		dp[0][1] = 1;
		for (i=1; i<=n; i++)
		{
			scanf("%s", board[i]+1);
			for (j=1; j<=n; j++)
			{
				if (board[i][j] == '*')
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % M;
				}
			}
		}
		printf("%d\n", dp[n][n]);
	}
	return 0;
}

