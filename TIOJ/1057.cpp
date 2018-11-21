#include <stdio.h>

int ary[200], dp[200];

int main()
{
	int len, dis, n, i, j;
	while(scanf("%d%d%d", &len, &dis, &n) == 3)
	{
		ary[0] = 0;
		dp[0] = 1;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			dp[i] = 0;
		}
		ary[i] = dis;
		dp[i] = 0;
		for(i=1, n++; i<=n; i++)
		{
			for(j=i-1; j>-1; j--)
			{
				if(ary[i] - ary[j] > len)
				{
					break;
				}
				if(dp[j] && (!dp[i] || dp[j] + 1 < dp[i]))
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		if(dp[n])
		{
			printf("%d\n", dp[n]-2);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
