#include <stdio.h>

#define M 1000000007

int dp[200005], ary[1005];

int main()
{
	int count, n, m, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			//ary[i] <<= 1;
		}
		if (m & 1)
		{
			printf("0\n");
			continue;
		}
		m >>= 1;
		dp[0] = 1;
		for (i=1; i<=m; i++)
		{
			dp[i] = 0;
			for (j=0; j<n; j++)
			{
				if (i >= ary[j])
				{
					dp[i] = (dp[i] + dp[i-ary[j]]) % M;
				}
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}
