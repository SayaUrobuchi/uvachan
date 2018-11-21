#include <stdio.h>

int tim[3005], fac[3005], sum[3005];
long long dp[3005][3005];

int main()
{
	int n, s, i, j, k;
	long long temp, summ;
	while(scanf("%d%d", &n, &s)==2)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &tim[i], &fac[i]);
			sum[i] = sum[i-1] + tim[i];
		}
		for(i=1; i<=n; i++)
		{
			dp[i][0] = (1ll<<60);
			for(k=1; k<=i; k++)
			{
				dp[i][k] = (1llu<<63)-1;
				for(j=i, temp=s*k+sum[i], summ=0; j>=k; j--)
				{
					summ += fac[j];
					if(dp[j-1][k-1]+summ*temp < dp[i][k])
					{
						dp[i][k] = dp[j-1][k-1]+summ*temp;
					}
				}
			}
		}
		for(i=1, temp=(1llu<<63)-1; i<=n; i++)
		{
			if(dp[n][i] < temp)
			{
				temp = dp[n][i];
			}
		}
		printf("%lld\n", temp);
	}
	return 0;
}
