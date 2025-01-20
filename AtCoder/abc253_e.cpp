#include <iostream>
using namespace std;

const int N = 1024;
const int M = 5005;
const int MOD = 998244353;

int dp[N][M];

int main()
{
	int n, m, o, i, j;
	scanf("%d%d%d", &n, &m, &o);
	for (i=1; i<=m; i++)
	{
		dp[1][i] = i;
	}
	for (i=2; i<=n; i++)
	{
		for (j=1; j<=m; j++)
		{
			dp[i][j] = dp[i-1][m];
			if (o)
			{
				int r = min(m, j+o-1);
				int l = max(1, j-o+1);
				dp[i][j] = dp[i-1][m] - dp[i-1][r] + dp[i-1][l-1];
			}
			dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
			dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}
