#include <stdio.h>

int ary[16384];
long long dp[16384];

int main()
{
	int n, i, j;
	long long k;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			dp[i] = ary[i]*ary[i] + dp[i-1];
			for (j=i-1, k=ary[i]; j>0; j--)
			{
				k += ary[j];
				if (k*k + dp[j-1] < dp[i])
				{
					dp[i] = k*k + dp[j-1];
				}
			}
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}
