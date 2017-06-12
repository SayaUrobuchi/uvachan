#include <stdio.h>
#include <string.h>

unsigned long long dp[61][61];
char chk[61][61];

unsigned long long trib(int n, int m)
{
	int i;
	if(n < 2)
	{
		return 1;
	}
	if(chk[n][m])
	{
		return dp[n][m];
	}
	dp[n][m] = chk[n][m] = 1;
	for(i=1; i<=m; i++)
	{
		dp[n][m] += trib(n-i, m);
	}
	return dp[n][m];
}

int main()
{
	int cas, n, m;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n > 60 || m > 60)
		{
			break;
		}
		memset(chk, 0, sizeof(chk));
		printf("Case %d: %llu\n", ++cas, trib(n, m));
	}
	return 0;
}
