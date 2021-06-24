#include <iostream>
#include <cstring>

long long dp[131072];

int main()
{
	int n, m, i, j, w, v, best;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0x7A, sizeof(dp));
		dp[0] = 0;
		for (i=0, best=0; i<n; i++)
		{
			scanf("%d%d", &w, &v);
			for (j=1e5; j>=v; j--)
			{
				dp[j] = std::min(dp[j], dp[j-v]+w);
				if (dp[j] <= m && j > best)
				{
					best = j;
				}
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
