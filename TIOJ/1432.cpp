#include <stdio.h>
#include <string.h>

int used[1005][1005], dp[1005][1005], sum[1005];

int max(int p, int q)
{
	return p>q ? p : q;
}

int recursion(int n, int m)
{
	int i, tmp;
	if(used[n][m])
	{
		return dp[n][m];
	}
	used[n][m] = 1;
	if(n == 0)
	{
		return dp[n][m] = 0;
	}
	if(m == 0)
	{
		return dp[n][m] = sum[n];
	}
	dp[n][m] = 2147483647;
	for(i=n-1; i>=0; i--)
	{
		if((tmp=max(recursion(i, m-1), sum[n]-sum[i])) < dp[n][m])
		{
			dp[n][m] = tmp;
		}
		if(tmp == sum[n]-sum[i])
		{
			break;
		}
	}
	return dp[n][m];
}

int main()
{
	int n, m, i, tmp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		if(m > n)
		{
			m = n;
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d", &tmp);
			sum[i] = sum[i-1] + tmp;
		}
		memset(used, 0, sizeof(used));
		printf("%d\n", recursion(n, m));
	}
	return 0;
}
