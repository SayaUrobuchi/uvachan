#include <stdio.h>

int result, chk;
unsigned int n, l, r, ans;
int bit[35];
unsigned int dp[35];

void decode(unsigned int now)
{
	int i;
	for(i=32; i>0; i--)
	{
		if(now >= dp[i])
		{
			bit[i] = 1;
			now -= dp[i];
		}
		else
		{
			bit[i] = 0;
		}
	}
}

int dfs(unsigned int now, int depth)
{
	if(!depth)
	{
		if(now >= l && (!chk || (now | n) > result))
		{
			chk = 1;
			result = now | n;
			ans = now;
			return 1;
		}
		return 0;
	}
	if(now + dp[depth] - 1 + dp[depth] < l)
	{
		return 0;
	}
	if(dfs(now, depth-1))
	{
		if(bit[depth])
		{
			return 1;
		}
	}
	if(now + dp[depth] <= r)
	{
		return dfs(now+dp[depth], depth-1);
	}
	return 0;
}

int main()
{
	int i;
	dp[1] = 1;
	for(i=2; i<33; i++)
	{
		dp[i] = dp[i-1] + dp[i-1];
	}
	while(scanf("%u%d%d", &n, &l, &r) == 3)
	{
		chk = result = 0;
		decode(n);
		dfs(0, 32);
		printf("%d\n", ans);
	}
	return 0;
}
