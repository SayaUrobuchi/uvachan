#include <iostream>
using namespace std;

long long val[512], cnt[512];
long long sum[512][512], dp[512][512];

int main()
{
	int n, m, i, j, k, l;
	long long t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%lld%lld", &val[i], &cnt[i]);
			for (j=0; j<=255; j++)
			{
				sum[j][i] = sum[j][i-1] + (val[i]-j)*(val[i]-j)*cnt[i];
			}
			dp[i][0] = 1e18;
		}
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=m&&j<i; j++)
			{
				dp[i][j] = 1e18;
			}
			for (k=1; k<=i; k++)
			{
				for (l=val[k], t=1e18; l<=val[i]; l++)
				{
					t = min(t, sum[l][i]-sum[l][k-1]);
				}
				//printf(".. %d %d: %lld\n", i, k, t);
				for (j=1; j<=m&&j<i; j++)
				{
					dp[i][j] = min(dp[i][j], dp[k-1][j-1]+t);
				}
			}
		}
		printf("%lld\n", dp[n][m]);
	}
	return 0;
}
