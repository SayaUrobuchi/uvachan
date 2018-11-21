#include <stdio.h>

int dp[1000005], ary[1005];

int main()
{
	int cnt, n, i, j, k, sum, half;
	while (scanf("%d", &n) == 1)
	{
		++cnt;
		dp[0] = cnt;
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		half = (sum>>1);
		for (i=0, j=0; i<n; i++)
		{
			for (k=j; k>=0; k--)
			{
				if (dp[k] == cnt)
				{
					dp[k+ary[i]] = cnt;
					if (k+ary[i] > j)
					{
						j = k+ary[i];
						if (j > half)
						{
							j = half;
						}
					}
				}
			}
		}
		for (i=half; i>=0; i--)
		{
			if (dp[i] == cnt)
			{
				break;
			}
		}
		printf("%d %d\n", i, sum-i);
	}
	return 0;
}
