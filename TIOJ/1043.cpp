#include <stdio.h>
#include <string.h>

unsigned long long dp[10001];

int main()
{
	int n, m, i, j, in;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(i=0; i<n; i++)
		{
			scanf("%d", &in);
			for(j=in; j<=m; j++)
			{
				dp[j] += dp[j-in];
			}
		}
		printf("%I64u\n", dp[m]);
	}
	return 0;
}
