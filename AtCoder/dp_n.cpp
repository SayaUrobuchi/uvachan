#include <iostream>
using namespace std;

int ary[512];
long long dp[512][512], sum[512];

int main()
{
	int n, i, j, k, l;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			sum[i] = sum[i-1] + ary[i];
			dp[i][i] = 0;
		}
		for (k=1; k<n; k++)
		{
			for (i=1, j=i+k; j<=n; i++, j++)
			{
				dp[i][j] = 1e18;
				for (l=i; l<j; l++)
				{
					dp[i][j] = min(dp[i][j], dp[i][l]+dp[l+1][j]+sum[j]-sum[i-1]);
				}
			}
		}
		printf("%lld\n", dp[1][n]);
	}
	return 0;
}
