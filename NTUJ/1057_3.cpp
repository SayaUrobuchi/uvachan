#include <stdio.h>

int tim[10005], fac[10005];
long long dp[10005], tsum[10005], fsum[10005];

int main()
{
	int n, s, i, j, k;
	long long temp, sum, ans;
	while(scanf("%d%d", &n, &s)==2)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &tim[i], &fac[i]);
			tsum[i] = tsum[i-1] + tim[i];
			fsum[i] = fsum[i-1] + fac[i];
		}
		dp[n] = 0;
		for(i=n-1; i>0; i--)
		{
			dp[i] = 0;
			for(j=i; j<n; j++)
			{
				temp = -(fsum[j]-fsum[i-1])*(tsum[n]-tsum[j])+s*(fsum[n]-fsum[j])+dp[j+1];
				if(temp < dp[i])
				{
					dp[i] = temp;
				}
			}
		}
		ans = dp[1] + (s+tsum[n])*fsum[n];
		printf("%llu\n", ans);
	}
	return 0;
}
