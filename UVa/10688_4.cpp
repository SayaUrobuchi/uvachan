#include <stdio.h>

int dp[1024][1024], cri[1024][1024];

int main()
{
	int cas, count, n, m, i, j, k, b, t, mid, cur;
	cas = 0;
	for (i=1; i<=500; i++)
	{
		cri[i][i] = i;
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (k=1; k<n; k++)
		{
			for (i=1, j=i+k; j<=n; i++, j++)
			{
				for (mid=i, t=2147483647; mid<=j; mid++)
				{
					cur = dp[i][mid-1] + (mid+m)*(k+1) + dp[mid+1][j];
					if (cur < t)
					{
						t = cur;
						b = mid;
					}
				}
				dp[i][j] = t;
				cri[i][j] = b;
				printf("%d %d => %d\n", i, j, b);
			}
		}
		printf("Case %d: %d\n", ++cas, dp[1][n]);
	}
	return 0;
}
