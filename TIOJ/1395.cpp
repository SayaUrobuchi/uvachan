#include <stdio.h>

int ary[70000];
long long dp[70000];

int main()
{
	int n, i;
	long long ans;
	while(scanf("%d", &ary[1]) == 1)
	{
		dp[0] = 0;
		dp[1] = ary[n=1];
		if(ary[1])
		{
			for(n=2; ; n++)
			{
				scanf("%d", &ary[n]);
				for(i=n-1, dp[n]=(1ll<<60); i>=0&&i>=n-3; i--)
				{
					if(dp[i] < dp[n])
					{
						dp[n] = dp[i];
					}
				}
				dp[n] += ary[n];
				if(ary[n] == 0)
				{
					break;
				}
			}
		}
		ans = dp[n];
		printf("%I64d\n", (ans+n*10)*10);
	}
	return 0;
}
