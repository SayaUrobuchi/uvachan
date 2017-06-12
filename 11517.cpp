#include <stdio.h>
#include <string.h>

int dp[20005];

int main()
{
	int count, n, m, i, j, p;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		memset(dp, 1, sizeof(dp));
		dp[0] = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &p);
			for(j=20000; j>=p; j--)
			{
				if(dp[j] > dp[j-p] + 1)
				{
					dp[j] = dp[j-p] + 1;
				}
			}
		}
		for(i=m; ; i++)
		{
			if(dp[i] < 1000)
			{
				printf("%d %d\n", i, dp[i]);
				break;
			}
		}
	}
	return 0;
}
