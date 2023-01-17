#include <iostream>
using namespace std;

int dp[25];

int main()
{
	int n, i;
	scanf("%d", &n);
	dp[0] = 1;
	for (i=1; i<=n; i++)
	{
		dp[i] = dp[i-1];
		if (i >= 2)
		{
			dp[i] += dp[i-2];
		}
		if (i >= 3)
		{
			dp[i] += dp[i-3];
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
