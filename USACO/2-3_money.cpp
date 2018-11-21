/*
	ID: sa072682
	LANG: C
	TASK: money
*/
#include <stdio.h>

int ary[26];
long long dp[10001];

int main()
{
	int n, m, i, j;
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d%d", &m, &n);
	dp[0] = 1;
	for(i=0; i<m; i++)
	{
		scanf("%d", &ary[i]);
		for(j=0; j+ary[i]<=n; j++)
		{
			if(dp[j])
			{
				dp[j+ary[i]] += dp[j];
			}
		}
	}
	printf("%lld\n", dp[n]);
	scanf(" ");
	return 0;
}
