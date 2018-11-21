#include <stdio.h>

int n;
int ary[512], dp[512];

int solve(int dir, int k)
{
	int i, j, m;
	m = 0;
	for (i=k+1; i<n; i++)
	{
		for (j=m; j>0; j--)
		{
			if (dir && ary[i] >= dp[j])
			{
				break;
			}
			else if (!dir && ary[i] <= dp[j])
			{
				break;
			}
		}
		if ((dir && ary[i] >= dp[j]) || (!dir && ary[i] <= dp[j]))
		{
			dp[j+1] = ary[i];
			if (j+1 > m)
			{
				m = j+1;
			}
		}
	}
	return m;
}

int main()
{
	int m, i, j, k, t, ans;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ans = 1;
		for (k=0; k<n&&k+ans<=n; k++)
		{
			/* ---- upper ---- */
			{
				/* increasing */
				dp[0] = ary[k];
				t = solve(1, k)+1;
				/* decreasing */
				dp[0] = ary[k]-1;
				m = solve(0, k);
				if (t+m > ans)
				{
					ans = t+m;
				}
			}
			/* ---- lower ---- */
			{
				/* increasing */
				dp[0] = ary[k]+1;
				t = solve(1, k)+1;
				/* decreasing */
				dp[0] = ary[k];
				m = solve(0, k);
				if (t+m > ans)
				{
					ans = t+m;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
