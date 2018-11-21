#include <stdio.h>

int dp[1000005];

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int cas, count, n, i, j, k, pp, sk, tt, ttt;
	cas = 0;
	/*while(scanf("%d", &k) == 1)
	{
		dp[0] = 2147483647;
		dp[1] = 0;
		for(i=2; i<=100; i++)
		{
			dp[i] = 0;
			for(j=1; j<(i-1)/(k+1)+1; j++)
			{
				if(dp[i-j] == 0 || dp[i-j] > j*k)
				{
					dp[i] = j;
					break;
				}
			}
			printf("%d: %d\n", i, dp[i]);
		}
	}*/
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &k);
		printf("Case %d: ", ++cas);
		if(n < k+1)
		{
			printf("lose\n");
			continue;
		}
		dp[0] = 1;
		dp[1] = 2;
		for(i=2, tt=1, ttt=1, pp=1; pp<n; )
		{
			while(pp+dp[tt-1] > dp[tt-1]*(k+1))
			{
				while(dp[ttt-1] * k < dp[tt])
				{
					ttt++;
				}
				dp[tt+1] = dp[tt] + dp[ttt-1];
				tt++;
			}
			pp += dp[tt-1];
			//printf("pp %d\n", pp);
		}
		/*for(i=0; i<tt; i++)
		{
			printf("%d: %d\n", i, dp[i]);
		}*/
		if(pp == n)
		{
			printf("lose\n");
			continue;
		}
		while(dp[tt] < n)
		{
			while(dp[ttt-1] * k < dp[tt])
			{
				ttt++;
			}
			dp[tt+1] = dp[tt] + dp[ttt-1];
			tt++;
		}
		for(i=tt; i>=0; i--)
		{
			if(n == dp[i])
			{
				printf("%d\n", dp[i]);
				break;
			}
			else if(n > dp[i])
			{
				n -= dp[i];
			}
		}
	}
	return 0;
}
