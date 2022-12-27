#include <iostream>
using namespace std;

const int MOD = 998244353;
const int N = 3000;

int ary[N+5], bry[N+5], dp[N+5][N+5];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1; i<=n; i++)
	{
		scanf("%d", &bry[i]);
	}
	fill(dp[0], dp[0]+N+1, 1);
	for (i=1; i<=n; i++)
	{
		for (j=ary[i]; j<=bry[i]; j++)
		{
			dp[i][j] = dp[i-1][j];
			if (j > 0)
			{
				dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
			}
		}
		for (j=bry[i]+1; j<=N; j++)
		{
			dp[i][j] = dp[i][j-1];
		}
	}
	printf("%d\n", dp[n][N]);
	return 0;
}