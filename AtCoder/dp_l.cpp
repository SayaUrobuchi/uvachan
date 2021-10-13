#include <iostream>
using namespace std;

int ary[4096];
long long dp[4096][4096], sum[4096];

int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			sum[i] = sum[i-1] + ary[i];
			dp[i][i] = ary[i];
		}
		for (k=2; k<=n; k++)
		{
			for (i=1, j=i+k-1; j<=n; i++, j++)
			{
				dp[i][j] = sum[j] - sum[i-1] - min(dp[i+1][j], dp[i][j-1]);
			}
		}
		printf("%lld\n", dp[1][n] - (sum[n]-dp[1][n]));
	}
	return 0;
}
