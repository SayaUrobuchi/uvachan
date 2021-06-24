#include <iostream>
#include <cstring>

long long dp[131072];

int main()
{
	int n, m, i, j, w, v;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &w, &v);
			for (j=m; j>=w; j--)
			{
				dp[j] = std::max(dp[j], dp[j-w]+v);
			}
		}
		printf("%lld\n", dp[m]);
	}
	return 0;
}
