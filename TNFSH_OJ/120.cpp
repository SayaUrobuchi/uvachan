#include <stdio.h>

int ary[1048576];
long long dp[1048576];

int main()
{
	int n, m, i, p, q;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		dp[i] = dp[i-1] + ary[i];
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d", &p, &q);
		if (p > q)
		{
			p ^= q ^= p ^= q;
		}
		printf("%lld\n", dp[q]-dp[p-1]);
	}
	return 0;
}
