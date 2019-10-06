#include <stdio.h>

int ary[200005];

long long dp[200005];

int main()
{
	int n, k, i, j;
	long long sum, mx, prev, ans;
	while (scanf("%d%d", &n, &k) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		mx = 0;
		ans = 0;
		for (i=0, sum=0; i<n; i++)
		{
			dp[i] = 0;
			sum += ary[i];
			if (i >= k-1)
			{
				prev = (i >= k+1 ? mx : 0);
				dp[i] = prev + sum;
				if (dp[i] > ans)
				{
					ans = dp[i];
				}
				sum -= ary[i-k+1];
			}
			if (i-k >= 0)
			{
				if (dp[i-k] > mx)
				{
					mx = dp[i-k];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
