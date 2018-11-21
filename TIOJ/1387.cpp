#include <stdio.h>
#include <string.h>

int w[55], m[55], c[55], dp[10005];

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int n, i, j, t;
	while(scanf("%d", &n) == 1)
	{
		memset(dp, 0, sizeof(dp));
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &w[i], &m[i], &c[i]);
		}
		scanf("%d", &t);
		for(i=0; i<n; i++)
		{
			while(c[i]--)
			{
				for(j=t; j>=w[i]; j--)
				{
					dp[j] = max(dp[j-w[i]]+m[i], dp[j]);
				}
			}
		}
		printf("%d\n", dp[t]);
	}
	return 0;
}
