#include <stdio.h>

int ary[16384];
long long dp[16384];

int main()
{
	int n, i, j;
	long long k;
	while (scanf("%d", &n) == 1)
	{
		dp[n] = 0;
		for (i=n-1; i>=0; i--)
		{
			scanf("%d", &ary[i]);
			dp[i] = ary[i]*ary[i] + dp[i+1];
			for (j=i+1, k=ary[i]; j<n; j++)
			{
				k += ary[j];
				if (k*k + dp[j+1] < dp[i])
				{
					dp[i] = k*k + dp[j+1];
				}
			}
		}
		printf("%lld\n", dp[0]);
	}
	return 0;
}
