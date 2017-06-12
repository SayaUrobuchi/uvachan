#include <stdio.h>
#include <string.h>

int dp[1024];

int main()
{
	int count, n, m, i, j, l, mx;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		mx = 0;
		for (i=0; i<m; i++)
		{
			scanf("%d", &l);
			mx += l;
			if (mx > n)
			{
				mx = n;
			}
			for (j=mx; j>=l; j--)
			{
				dp[j] |= dp[j-l];
			}
		}
		puts(dp[n] ? "YES" : "NO");
	}
	return 0;
}
