#include <stdio.h>

int used[505][505];
long long sum, dp[505][505];

long long calc(int n, int m)
{
	int i;
	if(used[n][m])
	{
		return dp[n][m];
	}
	used[n][m] = 1;
	if(n < m || n < 1 || (1+m)*m/2 < n)
	{
		return dp[n][m]=0;
	}
	if(n == m)
	{
		return dp[n][m]=1;
	}
	for(i=1; i<m; i++)
	{
		dp[n][m] += calc(n-m, i);
	}
	return dp[n][m];
}

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		for(i=1, sum=0; i<n; i++)
		{
			sum += calc(n, i);
		}
		printf("%I64d\n", sum);
	}
	return 0;
}
