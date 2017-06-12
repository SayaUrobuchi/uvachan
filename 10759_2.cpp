#include <stdio.h>

long long dp[25][151];

long long getgcd(long long p, long long q)
{
	if(p % q)
	{
		return getgcd(q, p%q);
	}
	return q;
}

int main()
{
	int n, m, i, j, k;
	long long sum, ans, gcd;
	dp[0][0] = 1;
	for(i=1; i<=24; i++)
	{
		for(j=1; j<=150; j++)
		{
			for(k=1; k<=6; k++)
			{
				if(j >= k)
				{
					dp[i][j] += dp[i-1][j-k];
				}
			}
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0, sum=0; i<=150; i++)
		{
			sum += dp[n][i];
		}
		for(i=m, ans=0; i<=150; i++)
		{
			ans += dp[n][i];
		}
		if(sum == ans)
		{
			printf("1\n");
		}
		else if(!ans)
		{
			printf("0\n");
		}
		else
		{
			gcd = getgcd(ans, sum);
			printf("%lld/%lld\n", ans/gcd, sum/gcd);
		}
	}
	return 0;
}
