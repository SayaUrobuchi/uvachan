#include <iostream>
using namespace std;

const int N = 128;

char s0[N], s1[N];
long long dp[N][N*2];

int main()
{
	int n, m, o, i, j;
	scanf("%d%d%d", &m, &n, &o);
	scanf("%s%s", s0+1, s1+1);
	dp[0][0] = 1;
	for (i=1; i<=n; i++)
	{
		for (j=0; j<=o; j++)
		{
			dp[i][j] = 0;
			if (s0[i] == s1[i])
			{
				dp[i][j] += dp[i-1][j];
				if (j >= 2)
				{
					dp[i][j] += dp[i-1][j-2] * (m-1);
				}
			}
			else
			{
				if (j >= 1)
				{
					dp[i][j] += dp[i-1][j-1] * 2;
				}
				if (j >= 2)
				{
					dp[i][j] += dp[i-1][j-2] * (m-2);
				}
			}
		}
	}
	printf("%lld\n", dp[n][o]);
	return 0;
}
