#include <cstdio>
#include <algorithm>
using namespace std;

int jmp[128], dp[1024][128];
char s0[128], s1[1024];

int main()
{
	int n, m, i, j, k, ans;
	while (scanf("%s%s", s0, s1) == 2)
	{
		for (m=0; s0[m]; m++);
		for (n=0; s1[n]; n++);
		jmp[0] = -1;
		for (i=1, j=-1; i<m; i++)
		{
			jmp[i] = ++j;
			while (j >= 0 && s0[j] != s0[i])
			{
				j = jmp[j];
			}
		}
		dp[0][0] = 0;
		for (j=1; j<m; j++)
		{
			dp[0][j] = 1048576;
		}
		for (i=1; i<=n; i++)
		{
			if (s0[0] == s1[i-1])
			{
				dp[i][0] = dp[i-1][0] + 1;
			}
			else
			{
				dp[i][0] = dp[i-1][0];
			}
			for (j=1; j<=m; j++)
			{
				if (s1[i-1] == s0[j-1])
				{
					dp[i][j] = min(dp[i-1][j] + 1, dp[i-1][j-1]);
				}
				else
				{
					dp[i][j] = dp[i-1][j] + 1;
				}
				for (k=j-1; k>=0; k=jmp[k])
				{
					if (s1[i-1] != s0[k])
					{
						dp[i][0] = min(dp[i][0], dp[i-1][k]);
					}
				}
			}
			for (j=0; j<m; j++)
			{
				printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
			}
		}
		for (j=0, ans=2147483647; j<m; j++)
		{
			if (dp[n][j] < ans)
			{
				ans = dp[n][j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
