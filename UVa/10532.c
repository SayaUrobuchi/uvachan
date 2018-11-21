#include <stdio.h>
#include <string.h>

int ary[60];
unsigned long long dp[60][60];

int main()
{
	int cas, n, m, r, i, j, k;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		memset(ary, 0, sizeof(ary));
		for(i=1; i<=n; i++)
		{
			scanf("%d", &j);
			ary[j]++;
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(i=1; i<=n; i++)
		{
			for(j=0; j<=n; j++)
			{
				for(k=0; k<=ary[i]&&k<=j; k++)
				{
					dp[i][j] += dp[i-1][j-k];
				}
			}
		}
		printf("Case %d:\n", ++cas);
		while(m--)
		{
			scanf("%d", &r);
			printf("%llu\n", dp[n][r]);
		}
	}
	return 0;
}
