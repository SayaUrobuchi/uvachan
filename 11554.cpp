#include <stdio.h>

long long dp[1000001];

int main()
{
	int count, m, n;
	long long t;
	m = 3;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		if(m < n)
		{
			for(; m<=n; m++)
			{
				dp[m] = dp[m-1];
				t = m / 2 - 1;
				dp[m] += t * (t+1) / 2;
				t = (m-1) / 2 - 1;
				dp[m] += t * (t+1) / 2;
			}
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}
