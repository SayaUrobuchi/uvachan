#include <stdio.h>
#include <string.h>

long long dp[51][51];

int main()
{
	int n, l, m;
	char i, j, k, tmp;
	while(scanf("%d%d%d", &l, &n, &m) == 3)
	{
		memset(dp, 0, sizeof(dp));
		for(i=0; i<m; i++) dp[0][i] = 1;
		for(i=1; i<n; i++)
		{
			for(j=i; j<l; j++)
			{
				for(k=0, tmp=j-1; k<m && tmp>-1; k++, tmp--)
				{
					dp[i][j] += dp[i-1][tmp];
				}
				if(!dp[i][j]) break;
			}
		}
		printf("%lld\n", dp[n-1][l-1]);
	}
	return 0;
}
