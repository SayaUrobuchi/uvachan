#include <iostream>
using namespace std;

const int M = 998244353;

int tbl[16][1024], dp[1024];
char buf[1024];

int main()
{
	int n, i, j, t, ans;
	while (scanf("%d%s", &n, buf+1) == 2)
	{
		for (i=0; i<10; i++)
		{
			for (j=0; j<(1<<10); j++)
			{
				tbl[i][j] = 0;
			}
		}
		for (i=1; i<(1<<10); i++)
		{
			dp[i] = 0;
		}
		dp[0] = 1;
		for (i=1; i<=n; i++)
		{
			t = buf[i] - 'A';
			for (j=(1<<10)-1; j; j--)
			{
				if ((j>>t) & 1)
				{
					dp[j] = (dp[j] + tbl[t][j]) % M;
					dp[j] = (dp[j] + dp[j-(1<<t)]) % M;
					tbl[t][j] = (tbl[t][j] << 1) % M;
					tbl[t][j] = (tbl[t][j] + dp[j-(1<<t)]) % M;
				}
			}
		}
		for (j=1, ans=0; j<(1<<10); j++)
		{
			ans = (ans + dp[j]) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}

