#include <stdio.h>

unsigned int n, l, r, ans;
unsigned int dp[35];

int main()
{
	int i;
	dp[1] = 1;
	for(i=2; i<33; i++)
	{
		dp[i] = dp[i-1] + dp[i-1];
	}
	while(scanf("%u%u%u", &n, &l, &r) == 3)
	{
		for(i=32, ans=0; i>0; i--)
		{
			if(n >= dp[i])
			{
				n -= dp[i];
				if(ans + dp[i] - 1 < l)
				{
					ans += dp[i];
				}
			}
			else
			{
				if(ans + dp[i] <= r)
				{
					ans += dp[i];
				}
			}
		}
		printf("%u\n", ans);
	}
	return 0;
}
