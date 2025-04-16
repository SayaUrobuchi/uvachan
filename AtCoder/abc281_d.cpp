#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;

long long dp[N][N][N];

int main()
{
	int n, m, o, i, j, k;
	scanf("%d%d%d", &n, &m, &o);
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	long long ans = -1;
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		dp[i][0][0] = 0;
		for (j=1; j<=i&&j<=m; j++)
		{
			for (k=0; k<o; k++)
			{
				dp[i][j][k] = dp[i-1][j][k];
				int nxt = (k-t%o+o)%o;
				if (dp[i-1][j-1][nxt] >= 0 && dp[i-1][j-1][nxt] + t > dp[i][j][k])
				{
					dp[i][j][k] = dp[i-1][j-1][nxt] + t;
				}
			}
		}
		ans = max(ans, dp[i][m][0]);
	}
	printf("%lld\n", ans);
	return 0;
}