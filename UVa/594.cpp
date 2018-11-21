#include <stdio.h>

unsigned int dp[32];

int main()
{
	int n, i, j, neg, ans;
	dp[0] = 1;
	for(i=1; i<32; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%d converts to ", n);
		ans = 0;
		if(n < 0)
		{
			n += dp[31];
			ans = 128;
		}
		for(i=24; i>-1; i-=8)
		{
			for(j=0; j<8; j++)
			{
				if(n % 2)
				{
					ans += dp[i+j];
				}
				n /= 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
