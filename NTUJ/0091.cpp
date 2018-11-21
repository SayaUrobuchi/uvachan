#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[35];
unsigned int dp[35][1005];

int comp(const void *p, const void *q)
{
	return *(int*)q-*(int*)p;
}

int main()
{
	int cas, count, n, m, i, j, r;
	unsigned int ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary+1, n, sizeof(int), comp);
		for(i=1; i<=n; i++)
		{
			r = ary[i];
			for(j=m; j>=r; j--)
			{
				dp[i][j] = dp[i-1][j]+dp[i-1][j-r];
			}
			for(; j>=0; j--)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
		for(i=m, ans=0; i>m-r; i--)
		{
			ans += dp[n][i];
		}
		for(; i>m-r-r; i--)
		{
			ans += dp[n-1][i-r];
		}
		ans += !ans;
		printf("%d %u\n", ++cas, ans);
	}
	return 0;
}
