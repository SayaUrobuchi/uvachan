#include <stdio.h>
#include <string.h>

int dp[31];

int main()
{
	int count, n, m, i, j, value, weight, wtmp, vtmp, ans;
	scanf("%d", &count);
	while(count--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &value, &weight);
			for(j=30-weight; j; j--)
			{
				wtmp = j + weight;
				vtmp = dp[j] + value;
				if(dp[wtmp] < vtmp)
				{
					dp[wtmp] = vtmp;
				}
			}
			if(dp[weight] < value)
			{
				dp[weight] = value;
			}
		}
		scanf("%d", &m);
		for(i=0, ans=0; i<m; i++)
		{
			scanf("%d", &j);
			for(j; j; j--)
			{
				if(dp[j])
				{
					ans += dp[j];
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
