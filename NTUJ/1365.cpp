#include <stdio.h>
#include <string.h>

#define N 100000007

long long dp[1005][15005];

int main()
{
	int n, m, o, i, j;
	long long t;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(dp, 0, sizeof(dp));
		for(i=0; i<=o; i++)
		{
			dp[0][i] = 1;
		}
		for(i=1; i<=n; i++)
		{
			for(j=1, t=dp[i-1][0]; j<=o; j++)
			{
				dp[i][j] = (t+dp[i][j-1])%N;
				t += dp[i-1][j];
				if(j-m >= 0)
				{
					t += N-dp[i-1][j-m];
					t += N-(dp[i-1][j-m]+(j-m-1>=0?N-dp[i-1][j-m-1]:0))*m%N;
				}
				t %= N;
			}
		}
		printf("%d\n", (int)((dp[n][o]+N-dp[n][o-1])%N));
	}
	return 0;
}
