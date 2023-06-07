#include <iostream>
using namespace std;

const int N = 1005;

int ary[N], dp[N][N];

int main()
{
	int n, i, j, ans;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		dp[0][i] = 1e9;
	}
	dp[0][1] = 0;
	for (i=1, ans=1e9; i<=n; i++)
	{
		for (j=n; j>=1; j--)
		{
			dp[i][j] = 1e9;
			if (j+i <= n)
			{
				dp[i][j] = min(dp[i][j], dp[i][j+i]+ary[j]);
			}
			if (j-i >= 1)
			{
				dp[i][j] = min(dp[i][j], dp[i-1][j-i]+ary[j]);
			}
		}
		ans = min(ans, dp[i][n]);
	}
	printf("%d\n", ans);
	return 0;
}