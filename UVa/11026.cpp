#include <stdio.h>

long long ary[1001];
long long dp[1001];

int main()
{
	int n, m, i, j, ans;
	long long temp, sum;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=1, sum=0; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			sum += (dp[i] = ary[i]);
		}
		for(i=1, ans=0; i<=n; i++)
		{
			for(j=i+1, sum=dp[i]; j<=n; j++)
			{
				temp = ary[j] * sum;
				sum += dp[j];
				dp[j] = temp % m;
				sum %= m;
			}
			if(sum > ans)
			{
				ans = sum;
			}
		}
		if(dp[n] > ans)
		{
			ans = dp[n];
		}
		printf("%d\n", ans);
	}
	return 0;
}
