#include <stdio.h>
#include <string.h>

#define SYUZOKU 5
#define TOKUSEI 10
#define TOKUSEI_MSK 1024
#define N 10005
#define MOD 1000000007

int an[SYUZOKU+1], ary[SYUZOKU+1][N];
int dp[SYUZOKU+1][TOKUSEI_MSK];

int main()
{
	int n, i, j, k, t, u;
	while (scanf("%d", &n) == 1)
	{
		memset(an, 0, sizeof(an));
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			for (j=0, u=0; j<TOKUSEI; j++)
			{
				scanf("%d", &k);
				u = (u<<1) + k;
			}
			ary[t][an[t]++] = u;
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (i=1; i<=SYUZOKU; i++)
		{
			for (j=0; j<an[i]; j++)
			{
				for (k=0; k<TOKUSEI_MSK; k++)
				{
					dp[i][k|ary[i][j]] += dp[i-1][k];
					dp[i][k|ary[i][j]] %= MOD;
				}
			}
		}
		printf("%lld\n", dp[SYUZOKU][TOKUSEI_MSK-1]);
	}
	return 0;
}
