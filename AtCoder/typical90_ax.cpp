#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[131072];

int main()
{
	int n, m, i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		dp[0] = 1;
		for (i=1; i<=n; i++)
		{
			dp[i] = dp[i-1];
			if (i >= m)
			{
				dp[i] = (dp[i]+dp[i-m]) % M;
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
