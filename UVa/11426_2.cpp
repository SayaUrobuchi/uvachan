#include <stdio.h>

int tbl[4000001];
long long dp[4000001];

int main()
{
	int n, i, j, k;
	long long ans;
	for(i=1; i<=4000000; i++)
	{
		tbl[i] = i;
	}
	tbl[2] = 1;
	dp[2] = 1;
	for(i=4; i<=4000000; i+=2)
	{
		tbl[i] >>= 1;
	}
	for(i=3; i<=2000000; i+=2)
	{
		if(tbl[i] == i)
		{
			tbl[i]--;
			for(j=i+i; j<=4000000; j+=i)
			{
				tbl[j] = (tbl[j] / i) * (i-1);
			}
		}
		dp[i] = dp[i-1] + tbl[i];
		dp[i+1] = dp[i] + tbl[i+1];
	}
	for(; i<=4000000; i+=2)
	{
		tbl[i] -= (tbl[i] == i);
		dp[i] = dp[i-1] + tbl[i];
		dp[i+1] = dp[i] + tbl[i+1];
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=1, j=(n>>1), ans=0; i<=j; i++)
		{
			ans += (long long)i * dp[n/i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
