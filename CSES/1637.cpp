#include <iostream>
using namespace std;

int dp[1048576];

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		dp[0] = 0;
		for (i=1; i<=n; i++)
		{
			dp[i] = 2e9;
			for (j=i; j; j/=10)
			{
				dp[i] = min(dp[i-j%10]+1, dp[i]);
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}

