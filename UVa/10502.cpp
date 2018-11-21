#include <stdio.h>

char map[100][101], dp[100][100];

int main()
{
	int n, m, i, j, k, min, ans;
	while(scanf("%d", &n, &m) == 1)
	{
		if(!n) break;
		scanf("%d", &m);
		ans = 0;
		for(i=0; i<n; i++) scanf("%s", map[i]);
		for(i=0; i<m; i++)
		{
			dp[0][i] = map[0][i] - 48;
			for(k=i, min=1; k>-1; k--)
			{
				min = dp[0][k] < min ? dp[0][k] : min;
				if(!min) break;
				ans += min;
			}
		}
		for(i=1; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == 49) dp[i][j] = dp[i-1][j] + 1;
				else dp[i][j] = 0;
				for(k=j, min=dp[i][j]; k>-1; k--)
				{
					min = dp[i][k] < min ? dp[i][k] : min;
					if(!min) break;
					ans += min;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
