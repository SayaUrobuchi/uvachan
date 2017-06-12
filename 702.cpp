#include <stdio.h>

#define UP 0
#define DOWN 1

int used[23][23][2];
long long dp[23][23][2];

long long calc(int small, int big, int dir)
{
	int i;
	if(small < 0 || big < 0)
	{
		return 1;
	}
	if(used[small][big][dir])
	{
		return dp[small][big][dir];
	}
	used[small][big][dir] = 1;
	if(!small && !big)
	{
		return dp[small][big][dir]=1;
	}
	dp[small][big][dir] = 0;
	if(dir == DOWN)
	{
		for(i=0; i<small; i++)
		{
			dp[small][big][dir] += calc(i, big+small-i-1, UP);
		}
	}
	else
	{
		for(i=0; i<big; i++)
		{
			dp[small][big][dir] += calc(small+i, big-i-1, DOWN);
		}
	}
	return dp[small][big][dir];
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(m == 1)
		{
			printf("%lld\n", calc(1, n-3, DOWN));
		}
		else
		{
			printf("%lld\n", calc(m-1, n-m, DOWN));
		}
	}
	return 0;
}
