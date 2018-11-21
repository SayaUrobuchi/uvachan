#include <stdio.h>

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int dp[1500], dp2[1500];

int main()
{
	int count, n, m, t, i, j, k, time, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &t, &m);
		for(i=1; i<=m; i++)
		{
			scanf("%d", &time);
			dp[i] = 2147483647;
			for(j=i-1, k=0; j>-1&&k<n; j--, k++)
			{
				temp = max(dp[j], time);
				if(temp < dp[i])
				{
					dp[i] = temp;
					dp2[i] = dp2[j] + 1;
				}
				else if(temp == dp[i])
				{
					if(dp2[i] > dp2[j] + 1)
					{
						dp2[i] = dp2[j] + 1;
					}
				}
			}
			dp[i] += t + t;
		}
		printf("%d %d\n", dp[i-1]-t, dp2[i-1]);
	}
	return 0;
}
