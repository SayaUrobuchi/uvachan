#include <iostream>
#include <algorithm>
using namespace std;

const long long INFI = (1LL << 62);

int ary[1024][1024];
long long dp[1024][1024];

int main()
{
	int n, m, i, j, cost;
	long long ans;
	for (i=0; i<1024; i++)
	{
		dp[0][i] = dp[i][0] = INFI;
	}
	while (scanf("%d%d%d", &n, &m, &cost) == 3)
	{
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=m; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (i=1, ans=INFI; i<=n; i++)
		{
			for (j=1; j<=m; j++)
			{
				ans = min(ans, min(dp[i-1][j], dp[i][j-1])+cost+ary[i][j]);
				dp[i][j] = min((long long)ary[i][j], min(dp[i-1][j], dp[i][j-1])+cost);
			}
		}
		for (i=1; i<=n; i++)
		{
			reverse(ary[i]+1, ary[i]+m+1);
			for (j=1; j<=m; j++)
			{
				ans = min(ans, min(dp[i-1][j], dp[i][j-1])+cost+ary[i][j]);
				dp[i][j] = min((long long)ary[i][j], min(dp[i-1][j], dp[i][j-1])+cost);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
