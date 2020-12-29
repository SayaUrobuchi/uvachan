#include <iostream>
#include <cstring>

const int M = 1000000007;

int dp[16384][2048];
const char *s = "11";

int main()
{
	int count, n, m, i, j, k, t, b, msk, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, b=0; s[i]; b=((b<<1)|(s[i]-'0')), i++);
		m = i;
		msk = (1<<m) - 1;
		if (n < m)
		{
			printf("%d\n", 1<<n);
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for (i=0; i<=msk; i++)
		{
			dp[m][i] = (i == b ? 0 : 1);
		}
		for (i=m; i+1<=n; i++)
		{
			for (j=0; j<=msk; j++)
			{
				for (k=0; k<2; k++)
				{
					t = (((j << 1) | k) & msk);
					if (t != b)
					{
						dp[i+1][t] = (dp[i+1][t] + dp[i][j]) % M;
					}
				}
			}
		}
		for (i=0, ans=0; i<=msk; i++)
		{
			ans = (ans+dp[n][i]) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}
