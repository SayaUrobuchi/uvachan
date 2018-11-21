#include <stdio.h>
#include <string.h>

long lcd(int p, int q)
{
	if(p%q) return lcd(q, p % q);
	else return q;
}

int main()
{
	int n, x, i, j, k;
	long sum[24], dp[24][150], tmp;
	sum[0] = 6;
	memset(dp, 0, sizeof(long) * 3600);
	for(i=1; i<7; i++) dp[0][i] = 1;
	for(i=1; i<24; i++)
	{
		sum[i] = 0;
		for(j=i, n=i*6+1; j<n; j++)
		{
			for(k=1; k<7; k++)
			{
				dp[i][j+k] += dp[i-1][j];
				sum[i] += dp[i-1][j];
			}
		}
		for(j=(i+1)*6-1, n=i; j>n; j--)
		{
			dp[i][j] += dp[i][j+1];
		}
		for(j; j>-1; j--) dp[i][j] = sum[i];
	}
	while(scanf("%d%d", &n, &x)==2)
	{
		if(!n && !x) break;
		if(dp[n-1][x] > sum[n-1]) printf("1\n");
		else if(dp[n-1][x] % sum[n-1])
		{
			tmp = lcd(dp[n-1][x], sum[n-1]);
			printf("%lld/%lld\n", dp[n-1][x] / tmp, sum[n-1] / tmp);
		}
		else printf("%lld\n", dp[n-1][x] / sum[n-1]);
	}
	return 0;
}
