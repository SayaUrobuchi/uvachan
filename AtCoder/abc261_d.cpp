#include <iostream>
using namespace std;

const int N = 5005;

int ary[N], cost[N];
long long dp[N][N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		cost[a] = b;
	}
	for (i=1; i<=n; i++)
	{
		dp[i][0] = dp[i-1][0];
		for (j=1; j<=i; j++)
		{
			dp[i][j] = dp[i-1][j-1] + ary[i] + cost[j];
			dp[i][0] = max(dp[i][0], dp[i-1][j]);
		}
	}
	long long ans = dp[n][0];
	for (i=1; i<=n; i++)
	{
		ans = max(ans, dp[n][i]);
	}
	printf("%lld\n", ans);
	return 0;
}
