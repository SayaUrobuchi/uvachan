#include <stdio.h>

#define MX 2147483647

int dp[5005][1005], used[5005][1005], ary[5005];

int main()
{
	int n, m, i, k, c, t, last, cnt;
	cnt = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=m; i>0; i--)
		{
			scanf("%d", &ary[i]);
		}
		++n;
		++cnt;
		dp[0][0] = 0;
		used[0][0] = cnt;
		for (i=1; i<=m; i++)
		{
			dp[i][0] = 0;
			used[i][0] = cnt;
			if (i > 1)
			{
				c = (ary[i]-ary[i-1])*(ary[i]-ary[i-1]);
				for (k=1; k<=n; k++)
				{
					if (k*3 > i)
					{
						break;
					}
					dp[i][k] = (used[i-1][k] == cnt ? dp[i-1][k] : MX);
					if (used[i-2][k-1] == cnt && dp[i-2][k-1]+c < dp[i][k])
					{
						dp[i][k] = dp[i-2][k-1] + c;
					}
					if (dp[i][k] != MX)
					{
						used[i][k] = cnt;
					}
				}
			}
		}
		printf("%d\n", dp[m][n]);
	}
	return 0;
}
