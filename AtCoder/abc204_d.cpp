#include <iostream>
#include <cstring>

int ary[128];
int dp[65536];

int main()
{
	int n, i, j, m, sum, half, mx;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		half = (sum >> 1);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		mx = 0;
		for (i=0, m=0; i<n; i++)
		{
			m += ary[i];
			if (m >= half)
			{
				m = half;
			}
			for (j=m; j>=ary[i]; j--)
			{
				dp[j] |= dp[j-ary[i]];
			}
		}
		for (i=half; i>=0; i--)
		{
			if (dp[i])
			{
				break;
			}
		}
		printf("%d\n", sum-i);
	}
	return 0;
}
