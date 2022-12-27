#include <iostream>
using namespace std;

long long dp[5005][5005], ps[5005];

int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%lld", &dp[i][i]);
			ps[i] = ps[i-1] + dp[i][i];
		}
		for (k=2; k<=n; k++)
		{
			for (i=1, j=i+k-1; j<=n; i++, j++)
			{
				dp[i][j] = (ps[j]-ps[i-1]) - min(dp[i+1][j], dp[i][j-1]);
			}
		}
		printf("%lld\n", dp[1][n]);
	}
	return 0;
}

