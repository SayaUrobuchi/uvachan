#include <iostream>
#include <cstring>
using namespace std;

int dp[256][256][4];

int main()
{
	int n, m, i, j, a, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			//continue;
			break;
		}
		memset(dp, 0x80, sizeof(dp));
		dp[0][0][0] = 0;
		for (i=1; i<=n; i++)
		{
			scanf("%d%d", &a, &b);
			for (j=0; j<=i&&j<=m; j++)
			{
				dp[i][j][0] = dp[i-1][j][0] + a + b;
				if (j)
				{
					dp[i][j][0] = max(dp[i-1][j][0], max(dp[i-1][j][1], dp[i-1][j][2])) + a + b;
					dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j-1][1]) + b;
					dp[i][j][2] = max(dp[i-1][j-1][0], dp[i-1][j-1][2]) + a;
				}
			}
		}
		printf("%d\n", max(dp[n][m][0], max(dp[n][m][1], dp[n][m][2])));
	}
	return 0;
}
