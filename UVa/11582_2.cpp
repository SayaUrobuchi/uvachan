#include <stdio.h>

int ucnt;
int dp[1048576], tbl[1024][1024], used[1024][1024];

int bound(unsigned long long a, unsigned long long b, int n)
{
	int i;
	unsigned long long res;
	if (a <= 1)
	{
		return a;
	}
	if (!b)
	{
		return 1;
	}
	for (res=1, i=0; i<b&&res<=n; i++, res*=a);
	if (res > 2147483647)
	{
		res = 2147483647;
	}
	return res;
}

int main()
{
	int count, n, i, lim, len;
	unsigned long long a, b, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%llu%llu%d", &a, &b, &n);
		ucnt++;
		dp[0] = 0;
		dp[1] = 1 % n;
		lim = bound(a, b, n*n);
		for (i=2; i<=lim; i++)
		{
			dp[i] = (dp[i-1] + dp[i-2]) % n;
			if (used[dp[i-1]][dp[i-2]] == ucnt)
			{
				break;
			}
			tbl[dp[i-1]][dp[i-2]] = i;
			used[dp[i-1]][dp[i-2]] = ucnt;
		}
		if (i >= lim)
		{
			printf("%d\n", dp[lim]);
		}
		else
		{
			len = i - tbl[dp[i-1]][dp[i-2]];
			a %= len;
			for (ans=1; b; a=(a*a)%len, b>>=1)
			{
				if (b & 1)
				{
					ans = (ans * a) % len;
				}
			}
			ans = (ans - tbl[dp[i-1]][dp[i-2]]%len + len) % len;
			printf("%d\n", dp[tbl[dp[i-1]][dp[i-2]]+ans]);
		}
	}
	return 0;
}
