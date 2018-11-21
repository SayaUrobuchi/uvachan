#include <stdio.h>

int tim[3005], fac[3005], sum[3005];
long long dp[3005][3005];

int main()
{
	int n, s, i, j, k;
	long long temp, summ, ans;
	for(i=1; i<3005; i++)
	{
		dp[0][i] = (1ll<<60);
	}
	while(scanf("%d%d", &n, &s)==2)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &tim[i], &fac[i]);
			sum[i] = sum[i-1] + tim[i];
		}
		for(k=1; k<=n; k++)
		{
			for(i=k; i<=n; i++)
			{
				dp[k][i] = (1llu<<63)-1;
				for(j=i, temp=s*k+sum[i], summ=0; j>=k; j--)
				{
					summ += fac[j];
					if(k-1 == 0 && j-1)
					{
						continue;
					}
					if(dp[k-1][j-1]+summ*temp < dp[k][i])
					{
						dp[k][i] = dp[k-1][j-1]+summ*temp;
					}
					else
					{
						//break;
					}
				}
			}
			if(dp[k][n] > dp[k-1][n])
			{
				break;
			}
			ans = dp[k][n];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
