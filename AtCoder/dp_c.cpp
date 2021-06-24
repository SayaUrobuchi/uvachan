#include <iostream>

int dp[131072][4];

int main()
{
	int n, i, j, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			for (j=0; j<3; j++)
			{
				scanf("%d", &t);
				dp[i][j] = std::max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + t;
			}
		}
		printf("%d\n", std::max(dp[n][0], std::max(dp[n][1], dp[n][2])));
	}
	return 0;
}
