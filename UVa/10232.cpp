#include <stdio.h>

int times[32], dp[32][32];

int main()
{
	int n, i, j, k, ans, sum, temp;
	times[0] = 1;
	for(i=1; i<32; i++)
	{
		times[i] = times[i-1] * 2;
	}
	dp[0][0] = 1;
	for(i=1; i<32; i++)
	{
		dp[i][0] = 1;
		for(j=1; j<32; j++)
		{
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	while(scanf("%d", &n) == 1)
	{
		ans = 0;
		if(!n)
		{
			printf("0\n");
			continue;
		}
		for(i=1, sum=0; i<32; i++)
		{
			sum += dp[31][i];
			if(n <= sum)
			{
				n -= sum - dp[31][i];
				break;
			}
		}
		j = 32;
		while(i)
		{
			for(k=i; k<j; k++)
			{
				if(n <= dp[k][i])
				{
					n -= dp[k-1][i];
					break;
				}
			}
			ans += times[k-1];
			j = k;
			i--;
		}
		printf("%d\n", ans);
	}
	return 0;
}
