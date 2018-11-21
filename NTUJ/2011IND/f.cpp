#include <stdio.h>

int dp[100005], ary[100005];

int main()
{
	int count, n, i, j, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		ary[0] = -10;
		for(i=1, ans=0; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			dp[i] = 0;
			for(j=i-1; j>=0; j--)
			{
				if(ary[j] < ary[i] && dp[j]+1 > dp[i])
				{
					dp[i] = dp[j]+1;
				}
			}
			if(dp[i] > ans)
			{
				ans = dp[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
