#include <stdio.h>
#include <string.h>

#define N 60005
#define M 70010
#define MOD 200003

int dp[10][200000];

int main()
{
	int count, i, j, n, m, p, q, st;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=M; i<(M<<1); i++)
		{
			dp[0][i] = 1;
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &p, &q);
			st = i*10000;
			if(st > 60000)
			{
				st = 60000;
			}
			for(j=-st; j<=st; j++)
			{
				dp[i][j+M] = (dp[i-1][j-p+M]+(MOD-dp[i-1][j-q-1+M])+dp[i][j-1+M])%MOD;
				/*if(dp[i][j+M])
				{
					printf("!!!! %d => %d\n", j, dp[i][j+M]);
				}*/
			}
			for(; j<st+10000; j++)
			{
				dp[i][j] = dp[i][j-1];
			}
		}
		printf("%d\n", (dp[n][m+M]+MOD-dp[n][m-1+M])%MOD);
	}
	return 0;
} 
