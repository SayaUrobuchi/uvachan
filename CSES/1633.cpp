#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[1048576];

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		dp[0] = 1;
		for (i=1; i<=n; i++)
		{
			dp[i] = 0;
			for (j=1; j<=6&&i-j>=0; j++)
			{
				dp[i] = (dp[i]+dp[i-j]) % M;
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}

