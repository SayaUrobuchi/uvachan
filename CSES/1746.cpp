#include <iostream>
using namespace std;

const int M = 1000000007;

int ary[131072];
int dp[131072][128];

int main()
{
	int n, m, i, j, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=1; i<=m; i++)
		{
			dp[0][i] = (!ary[0] || i==ary[0] ? 1 : 0);
		}
		for (i=1; i<n; i++)
		{
			dp[i][0] = dp[i][m+1] = 0;
			for (j=1; j<=m; j++)
			{
				dp[i][j] = 0;
				if (!ary[i] || ary[i] == j)
				{
					dp[i][j] = ((dp[i-1][j-1]+dp[i-1][j+1]) % M + dp[i-1][j]) % M;
				}
			}
		}
		for (i=1, ans=0; i<=m; i++)
		{
			ans = (ans + dp[n-1][i]) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}

