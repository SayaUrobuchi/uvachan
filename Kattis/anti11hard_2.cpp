#include <iostream>
#include <cstring>

const int M = 1000000007;

int dp[16384][16], jmp[16];
char s[1024];

int main()
{
	int count, n, m, i, j, k, t, b, msk, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%s", &n, s);
		for (i=0, b=0; s[i]; b=((b<<1)|(s[i]-'0')), i++);
		m = i;
		jmp[0] = -1;
		for (i=1, j=0; i<m; i++, j++)
		{
			jmp[i] = j;
			while (j >= 0 && s[i] != s[j])
			{
				j = jmp[j];
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (i=0; i+1<=n; i++)
		{
			for (j=0; j<m; j++)
			{
				for (k=0; k<2; k++)
				{
					t = j;
					while (t >= 0 && s[t] != k+'0')
					{
						t = jmp[t];
					}
					dp[i+1][t+1] = (dp[i+1][t+1] + dp[i][j]) % M;
				}
			}
		}
		for (i=0, ans=0; i<m; i++)
		{
			ans = (ans+dp[n][i]) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}
