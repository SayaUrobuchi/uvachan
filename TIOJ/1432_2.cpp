#include <stdio.h>
#include <string.h>

int used[1005][1005], dp[1005][1005], sum[1005];

int max(int p, int q)
{
	return p>q ? p : q;
}

int recursion(int, int);

void bisearch(int p, int q, int r, int t, int *ans)
{
	int c;
	if(p > q)
	{
		return;
	}
	c = ((p+q)>>1);
	if(recursion(c, t) < sum[r]-sum[c])
	{
		*ans = c;
		bisearch(c+1, q, r, t, ans);
	}
	else
	{
		bisearch(p, c-1, r, t, ans);
	}
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
	dp[n][m] = sum[n];
	tmp = n-1;
	bisearch(1, n-1, n, m-1, &tmp);
	if(max(recursion(tmp, m-1), sum[n]-sum[tmp]) < dp[n][m])
	{
		dp[n][m] = max(recursion(tmp, m-1), sum[n]-sum[tmp]);
	}
	tmp++;
	if(tmp < n && max(recursion(tmp, m-1), sum[n]-sum[tmp]) < dp[n][m])
	{
		dp[n][m] = max(recursion(tmp, m-1), sum[n]-sum[tmp]);
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
