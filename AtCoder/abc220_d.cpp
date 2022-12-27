#include <iostream>
#include <cstring>
using namespace std;

int dp[131072][16];

int main()
{
	int n, i, j, t;
	while (scanf("%d%d", &n, &t) == 2)
	{
		memset(dp, 0, sizeof(dp));
		dp[1][t%10] = 1;
		for (i=2; i<=n; i++)
		{
			scanf("%d", &t);
			for (j=0, t%=10; j<10; j++)
			{
				dp[i][(j+t)%10] = (dp[i][(j+t)%10] + dp[i-1][j]) % 998244353;
				dp[i][(j*t)%10] = (dp[i][(j*t)%10] + dp[i-1][j]) % 998244353;
			}
		}
		for (i=0; i<10; i++)
		{
			printf("%d\n", dp[n][i]);
		}
	}
	return 0;
}

